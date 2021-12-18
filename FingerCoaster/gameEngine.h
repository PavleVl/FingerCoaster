#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QApplication>
#include <QDebug>
#include "configuration.h"
#include "mainwindow.h"
#include "mainMenu.h"
#include "map.h"

class GameEngine:public QGraphicsView{
    Q_OBJECT
public:
    GameEngine();
    ~GameEngine();
//    void keyPressEvent(QKeyEvent* event)override;
    void resizeEvent(QResizeEvent* event)override;
    void playMusic();
public slots:
    void exit();
    void openMenu();
    void showScore();
private:
    QImage background;
    int windowWidth;
    int windowHeight;
    mainMenu* menuScene;
    mainMenu* newScene;
    bool spacePressed;
    QGraphicsScene* levelScene;
    MainWindow* mainWindow;
    Map* map;
    Ui::MainWindow* gui;
    //    QMediaPlayer* musicPlayer;
};

#endif // GAMEENGINE_H
