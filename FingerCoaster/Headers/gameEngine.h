#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QApplication>
#include <QDebug>
#include <QMediaPlayer>
#include <QUrl>
#include "configuration.h"
#include "mainMenu.h"
#include "map.h"

class GameEngine:public QGraphicsView{
    Q_OBJECT
public:
    GameEngine();
    ~GameEngine();
//    void keyPressEvent(QKeyEvent* event)override;
    void resizeEvent(QResizeEvent* event)override;
    void playMusic(QString path);
public slots:
    void exit();
    void openMenu();
private:
    QImage background;
    int windowWidth;
    int windowHeight;
    mainMenu* menuScene;
    bool spacePressed;
    QGraphicsScene* levelScene;
    Map* map;
    QMediaPlayer* musicPlayer;
};

#endif // GAMEENGINE_H
