#include "gameEngine.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <qwidget.h>

GameEngine::GameEngine(){
    windowWidth = WINDOW_WIDTH;
    windowHeight = WINDOW_HEIGHT;
    setWindowTitle(TITLE);

    levelScene = new QGraphicsScene();

    map = new Map();

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    menuScene = new mainMenu();
    connect(menuScene->getQuitButton(),SIGNAL(clicked()),this,SLOT(exit()));
    connect(menuScene->getScoreboardButton(),SIGNAL(clicked()),this,SLOT(showScore()));
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
    MainWindow* newScene = new MainWindow();
    newScene->show();
//    newScene->getU()->tableView->show();
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

//void playMusic(QString path){
//    musicPlayer->setMedia(QUrl(path));
//    musicPlayer->setVolume(100);
//    musicPlayer->play();
//}
