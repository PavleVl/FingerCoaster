#include "Headers/gameEngine.h"

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
//    musicPlayer = new QMediaPlayer();
    openMenu();
//    showFullScreen();
}

GameEngine::~GameEngine(){
      qDebug()<<"delete";
      delete menuScene;
      levelScene->clear();
      delete levelScene;
//      delete musicPlayer;
}

void GameEngine::openMenu()
{
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    setScene(menuScene);
//    playMusic(":/resources/sounds/Pesma.mp3");

}

void GameEngine::exit()
{
    this->close();
}

void GameEngine::resizeEvent(QResizeEvent *event){
    qDebug()<<"resize";
    if(levelScene)
            levelScene->setSceneRect(0,0,map->getWidth(),map->getHeight());
    QRect rect = QRect(0,0,WINDOW_WIDTH,map->getHeight());
    fitInView(rect);
}

//void GameEngine::playMusic(QString path){
//    musicPlayer->set
//    musicPlayer->setMedia(QUrl(path));
//    musicPlayer->setVolume(100);
//    musicPlayer->play();
//}
