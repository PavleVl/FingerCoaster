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
    QList<menuBtn*> getButtonList()const;
    menuBtn* getQuitButton()const;
private:
    QList<menuBtn*> buttonList;
    menuBtn* QuitButton;
};


#endif // MAINMENU_H
