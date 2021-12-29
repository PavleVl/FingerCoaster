#include "Headers/gameEngine.h"
#include "ui_mainwindow.h"
#include "Headers/mainwindow.h"
#include <qwidget.h>
#include "Headers/createroom.h"
#include "Headers/joinpopup.h"
#include "Headers/scoreboard.h"
#include "Headers/enterusername.h"
#include <QDebug>


GameEngine::GameEngine(){
    setWindowTitle(TITLE);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    menuScene = new mainMenu();

    //Ako smo prvi put usli i nije nam postavljen username
    ScoreboardBackend* checkUsername = new ScoreboardBackend();
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
      delete mainWindow;
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
    connect(&joinPopup,SIGNAL(startClient()),this,SLOT(startClient()),Qt::DirectConnection);
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

void GameEngine::startClient(){
    ScoreboardBackend sc;
    std::string username = sc.giveUsername();
    ourClient = new Client(QString::fromStdString(username));
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
     }
    else{
        //Podeseno klijentsko okruzenje
        ourLobby.setIsClient();
        connect(&ourLobby,SIGNAL(joinPopupForcedClose()),this,SLOT(forceCloseTheClientConnection()),Qt::DirectConnection);
        connect(this,SIGNAL(forceCloseClient()),ourClient,SLOT(forceCloseClient()),Qt::DirectConnection);
        connect(ourClient,SIGNAL(dontShowLobby()),&ourLobby,SLOT(dontShowLobby()),Qt::DirectConnection);
        connect(ourClient,SIGNAL(rewriteUsernames(QVector<QString>*)),&ourLobby,SLOT(rewriteUsernames(QVector<QString>*)),Qt::DirectConnection);
    }
    ourLobby.setModal(true);
    ourLobby.exec();
}


//If its the first time application is opening and
//Scoreboard.txt is missing this will be run
void GameEngine::showUsernameInput(){
    enterUsername eu;
    eu.setModal(true);
    eu.exec();
};

//void playMusic(QString path){
//    musicPlayer->setMedia(QUrl(path));
//    musicPlayer->setVolume(100);
//    musicPlayer->play();
//}

void GameEngine::reInitServer(){
    ourServer->deleteLater();
    ourServer = nullptr;
}

void GameEngine::forceCloseTheClientConnection(){
    emit forceCloseClient();
    ourClient->deleteLater();
    ourClient = nullptr;
}
