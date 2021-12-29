#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include "menuBtn.h"
#include "configuration.h"

class mainMenu:public QGraphicsScene{
public:
    mainMenu();
    ~mainMenu();
    menuBtn* getQuitButton()const;
    menuBtn* getScoreboardButton()const;
    menuBtn* getJoinButton() const;
    menuBtn* getCreateRoomButton() const;
<<<<<<< HEAD
    void setScene();
=======

>>>>>>> Obrisao mainwindow
private:
    menuBtn* QuitButton;
    menuBtn* scoreboardButton;
    menuBtn* joinButton;
    menuBtn* createRoomButton;
};


#endif // MAINMENU_H
