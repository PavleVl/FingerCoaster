#include "Headers/gameEngine.h"
#include "ui_mainwindow.h"
#include "Headers/mainwindow.h"
#include <qwidget.h>
#include "Headers/createroom.h"
#include "Headers/joinpopup.h"
#include "Headers/scoreboard.h"
//#include "ui_joinpopup.h"
#include "enterusername.h"

GameEngine::GameEngine(){
    windowWidth = WINDOW_WIDTH;
    windowHeight = WINDOW_HEIGHT;
    setWindowTitle(TITLE);

    levelScene = new QGraphicsScene();

    map = new Map();

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
    openMenu();
//    showFullScreen();
}

GameEngine::~GameEngine(){
      delete menuScene;
      levelScene->clear();
      delete levelScene;
      //    delete musicPlayer;
      delete mainWindow;
}

void GameEngine::openMenu()
{
      QApplication::setOverrideCursor(Qt::ArrowCursor);
      setScene(menuScene);
//    playMusic(":/resources/sounds/Pesma.mp3");

}

void GameEngine::showScore(){
    Scoreboard sc;
    sc.setModal(true);
    sc.exec();

    /*MainWindow* newScene = new MainWindow();
    newScene->show();
*/
}

void GameEngine::joinRoom(){
    JoinPopUp joinPopup;
    joinPopup.setModal(true);
    joinPopup.exec();
}


void GameEngine::createRoom(){
    createroom cr;
    cr.setModal(true);
    cr.exec();
}

void GameEngine::exit()
{
    this->close();
}

void GameEngine::resizeEvent(QResizeEvent *event){
    if(levelScene)
            levelScene->setSceneRect(0,0,map->getWidth(),map->getHeight());
    QRect rect = QRect(0,0,WINDOW_WIDTH,map->getHeight());
    fitInView(rect);
}


//If its the first time application is opening and
//Scoreboard.txt is missing this will be run
void GameEngine::showUsernameInput(){
    enterUsername eu;
    eu.setModal(true);
    eu.exec();;
};

//void playMusic(QString path){
//    musicPlayer->setMedia(QUrl(path));
//    musicPlayer->setVolume(100);
//    musicPlayer->play();
//}
