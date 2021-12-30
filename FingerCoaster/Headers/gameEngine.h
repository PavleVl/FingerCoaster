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
#include "mainMenu.h"
#include "joinpopup.h"
#include "createroom.h"
#include "Game/gameDialog.h"
#include "map.h"
#include "../Scoreboard/ScoreboardBackend.hpp"
#include "../Server/Server.hpp"
#include "../Client/Client.hpp"

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
//<<<<<<< HEAD
//=======
//    void clearScene();
//>>>>>>> 7db8ad15debb9a39da1223d741b893a8be3ee399

signals:
    void forceCloseClient();

public slots:
    void exit();
    void openMenu();
    void showScore();
    void joinRoom();
    void createRoom();
    void startServer(unsigned maxPlayers,unsigned difficulty);
    void startClient();
    void startLobby();
    void reInitServer();
    void forceCloseTheClientConnection();
    void setGameScene();
private:
    QImage background;
    int windowWidth;
    int windowHeight;
    mainMenu* menuScene;
    bool spacePressed;
    QGraphicsScene* levelScene;
    Map* map;
    //    QMediaPlayer* musicPlayer;
//    Server
    //TREBA PAZITI ourServer i ourClient vrate na null;
    Server* ourServer;
    Lobby* ourLobby;
    Client* ourClient;
    GameDialog* gameDialog;
};

#endif // GAMEENGINE_ma
