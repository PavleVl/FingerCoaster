#include "Headers/gameEngine.h"
#include <qwidget.h>
#include "Headers/createroom.h"
#include "Headers/joinpopup.h"
#include "Headers/scoreboard.h"
#include "Headers/enterusername.h"
#include "../Headers/game.h"
#include <QDebug>


GameEngine::GameEngine(){
    setWindowTitle(QString::fromStdString(TITLE));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    menuScene = new mainMenu();
    //Ako smo prvi put usli i nije nam postavljen username
    auto* checkUsername = new ScoreboardBackend();
    if(checkUsername->isFirstTimeCheck())
        this->showUsernameInput();

    connect(menuScene->getQuitButton(),SIGNAL(clicked()),this,SLOT(exit()));
    connect(menuScene->getScoreboardButton(),SIGNAL(clicked()),this,SLOT(showScore()));
    connect(menuScene->getJoinButton(),SIGNAL(clicked()), this, SLOT(joinRoom()));
    connect(menuScene->getCreateRoomButton(), SIGNAL(clicked()), this, SLOT(createRoom()));
//    musicPlayer = new QMediaPlayer();

    //Initialisation
    ourServer = nullptr;
    ourLobby = nullptr;
    ourClient = nullptr;

    openMenu();

}

GameEngine::~GameEngine(){
      menuScene->clear();
      delete menuScene;
      //    delete musicPlayer;
}

void GameEngine::openMenu()
{
      QApplication::setOverrideCursor(Qt::ArrowCursor);
      setScene(menuScene);
}

void GameEngine::showScore(){
    Scoreboard sc;
    sc.setModal(true);
    sc.exec();
}

void GameEngine::joinRoom(){
    JoinPopUp joinPopup;
    connect(&joinPopup,SIGNAL(startClient(QString)),this,SLOT(startClient(QString)),Qt::DirectConnection);
    connect(&joinPopup,SIGNAL(openLobby()),this,SLOT(startLobby()),Qt::DirectConnection);
    joinPopup.setModal(true);
    joinPopup.exec();
}


void GameEngine::createRoom(){
    createroom cr;
    connect(&cr,SIGNAL(startServer(uint,uint)),this,SLOT(startServer(uint,uint)),Qt::DirectConnection);
    connect(&cr,SIGNAL(openLobby()),this,SLOT(startLobby()),Qt::DirectConnection);

    cr.setModal(true);
    cr.exec();
}



void GameEngine::exit()
{
    this->close();
}

void GameEngine::resizeEvent(QResizeEvent *event){
    QRect rect = QRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
    fitInView(rect);
}

void GameEngine::startClient(QString key){
    ScoreboardBackend sc;
    std::string username = sc.giveUsername();
    ourClient = new Client(QString::fromStdString(username));
    ourClient->connectToHost(key);

    connect(ourClient,SIGNAL(startGame()),this,SLOT(setGameScene()),Qt::DirectConnection);
}


//This will be run if we catch signal for starting the server
void GameEngine::startServer(unsigned maxPlayers,unsigned difficulty){
    ourServer = new Server();

    connect(ourServer,SIGNAL(serverShutdown()),this,SLOT(reInitServer()),Qt::DirectConnection);
    ourServer->setStorageDifficulty(difficulty);
    ourServer->setStorageMaxPlayers(maxPlayers);

    ourServer->startServer();
    //TODO SERVER IMPL
    //TODO SERVER SHUT DOWN SIGNAL TO DELETE POINTER TO IT
}


//This will be run if we catch signal for start lobby
void GameEngine::startLobby(){
    Lobby ourLobby;
    if(ourServer != nullptr){
        connect(ourServer,SIGNAL(updateLobbyList(QString)),&ourLobby,SLOT(addPlayer(QString)),Qt::DirectConnection);
        connect(&ourLobby,SIGNAL(closeServerConnections()),ourServer,SLOT(blockConnections()),Qt::DirectConnection);
        connect(&ourLobby,SIGNAL(popUpForcedClose()),ourServer,SLOT(forceCloseTheServer()),Qt::DirectConnection);
        connect(ourServer,SIGNAL(rewriteLobbyList(QVector<QString>*)),&ourLobby,
                SLOT(rewriteUsernames(QVector<QString>*)),Qt::DirectConnection);
        connect(&ourLobby,SIGNAL(setGameScene()),this,SLOT(setGameScene()),Qt::DirectConnection);
        connect(&ourLobby,SIGNAL(startGameForClients()),ourServer,SLOT(startGameForClients()),Qt::DirectConnection);
     }
    else{
        //Podeseno klijentsko okruzenje
        ourLobby.setIsClient();
        connect(&ourLobby,SIGNAL(joinPopupForcedClose()),this,SLOT(forceCloseTheClientConnection()),Qt::DirectConnection);
        connect(this,SIGNAL(forceCloseClient()),ourClient,SLOT(forceCloseClient()),Qt::DirectConnection);
        connect(ourClient,SIGNAL(dontShowLobby()),&ourLobby,SLOT(dontShowLobby()),Qt::DirectConnection);
        connect(ourClient,SIGNAL(rewriteUsernames(QVector<QString>*)),&ourLobby,SLOT(rewriteUsernames(QVector<QString>*)),Qt::DirectConnection);
        //connect(ourClient,SIGNAL(closeClientLobby()),&ourLobby,SLOT(dontShowLobby()),Qt::DirectConnection);
        connect(ourClient,&Client::closeClientLobby,&ourLobby,&Lobby::closeLobbyStartGame,Qt::DirectConnection);
        connect(&ourLobby,SIGNAL(startClientGame()),this,SLOT(setGameScene()),Qt::DirectConnection);
    }
    ourLobby.setModal(true);
    ourLobby.exec();
}

void GameEngine::setGameScene(){
    this->hide();
    gameDialog = new GameDialog();

    connect(gameDialog,SIGNAL(gameDialogClosing()),this,SLOT(reOpenMainMenu()),Qt::DirectConnection);

    if(ourServer != nullptr){
        connect(gameDialog,SIGNAL(shutdownServer()),ourServer,SLOT(forceCloseTheServer()),Qt::DirectConnection);
        connect(ourServer,SIGNAL(populateGame(QVector<QString>*)),gameDialog,SLOT(populateGame(QVector<QString>*)),Qt::DirectConnection);
        connect(gameDialog,SIGNAL(updateProgress(uint)),ourServer,SLOT(setMyProgress(uint)),Qt::DirectConnection);
        connect(ourServer,SIGNAL(changeCurGameProgress(QVector<uint>*)),gameDialog,SLOT(updateCurGameProgress(QVector<uint>*)),Qt::DirectConnection);

        ourServer->setGameStarted(true);
        ourServer->initializeGame();
        //If i don't want to close the clients i can call
        //softCloseTheServer in the slot
        Storage* st = ourServer->getServerStorage();
        std::vector<std::string> text = st->formatTextForGame();
        gameDialog->setWordsOnScreen(text);
    }
    if(ourClient != nullptr){
        connect(gameDialog,SIGNAL(gameDialogClosing()),this,SLOT(forceCloseTheClientConnection()),Qt::DirectConnection);
        connect(ourClient,SIGNAL(populateGame(QVector<QString>*)),gameDialog,SLOT(populateGame(QVector<QString>*)),Qt::DirectConnection);
        connect(gameDialog,SIGNAL(updateProgress(unsigned)),ourClient,SLOT(updateProgress(unsigned)),Qt::DirectConnection);

        ourClient->initGame();
        Storage* st = ourClient->giveClientStorage();
        std::vector<std::string> text = st->formatTextForGame();
        gameDialog->setWordsOnScreen(text);
    }
    gameDialog->setModal(true);
    gameDialog->exec();

}


//If its the first time application is opening and
//Scoreboard.txt is missing this will be run
void GameEngine::showUsernameInput(){
    enterUsername eu;
    eu.setModal(true);
    eu.exec();
};


void GameEngine::reInitServer(){
    ourServer->deleteLater();
    ourServer = nullptr;
}

void GameEngine::forceCloseTheClientConnection(){
    emit forceCloseClient();
    ourClient->deleteLater();
    ourClient = nullptr;
}

void GameEngine::reOpenMainMenu(){
    this->show();
}

