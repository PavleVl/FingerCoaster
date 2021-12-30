#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include "menuBtn.h"
#include "configuration.h"


#include <QProgressBar>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMenuBar>
#include <QStatusBar>


class mainMenu:public QGraphicsScene{
public:
    mainMenu();
    ~mainMenu();
    menuBtn* getQuitButton()const;
    menuBtn* getScoreboardButton()const;
    menuBtn* getJoinButton() const;
    menuBtn* getCreateRoomButton() const;
    void setScene();
    void freeMemory();

private:
    menuBtn* QuitButton;
    menuBtn* scoreboardButton;
    menuBtn* joinButton;
    menuBtn* createRoomButton;
    QImage background;
    QFont font;
    QGraphicsTextItem* title;
};


#endif // MAINMENU_H
