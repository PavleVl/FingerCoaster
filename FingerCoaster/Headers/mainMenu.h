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
<<<<<<< HEAD
    void setScene();
    void freeMemory();
=======
>>>>>>> 7db8ad15debb9a39da1223d741b893a8be3ee399

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
