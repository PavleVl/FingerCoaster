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
#include "joinpopup.h"
#include "createroom.h"
#include "map.h"
#include "../Scoreboard/ScoreboardBackend.hpp"
#include "../Server/Server.hpp"

class GameEngine:public QGraphicsView{
    Q_OBJECT
public:
    GameEngine();
    ~GameEngine();
//    void keyPressEvent(QKeyEvent* event)override;
    void resizeEvent(QResizeEvent* event)override;
    void playMusic();
    bool isFirstTime(ScoreboardBackend* sc);
    void showUsernameInput();
    mainMenu* menuScene;

public slots:
    void exit();
    void openMenu();
    void showScore();
    void joinRoom();
    void createRoom();
    void startServer(unsigned maxPlayers,unsigned difficulty);
    void startLobby();

private:
    QImage background;
    int windowWidth;
    int windowHeight;
    //mainMenu* menuScene;
    bool spacePressed;
    QGraphicsScene* levelScene;
    MainWindow* mainWindow;
    Map* map;
    Ui::MainWindow* gui;
    //    QMediaPlayer* musicPlayer;
//    Server
    Server* ourServer;

};

#endif // GAMEENGINE_ma
