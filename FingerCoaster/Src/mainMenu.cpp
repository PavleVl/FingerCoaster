#include "Headers/mainMenu.h"
#include <QGraphicsView>


mainMenu::mainMenu():QGraphicsScene(){
    int xMenuBtnStart = 1680;
    int yMenuBtnStart = 800;
    int i = 0;

    this->setSceneRect(0,0,MAP_WIDTH,MAP_HEIGHT);
    background = QImage(QString::fromStdString(":/images/prefix1/main-menu.jpg"));
    background = background.scaled(WINDOW_WIDTH,WINDOW_HEIGHT);
    this->setBackgroundBrush(background);

    scoreboardButton = new menuBtn(QString::fromStdString("Scoreboard"));
    scoreboardButton->move(xMenuBtnStart,yMenuBtnStart+i*(scoreboardButton->height() +  BTN_GAP));
    this->addWidget(scoreboardButton);

    createRoomButton = new menuBtn(QString::fromStdString("Create room"));
    createRoomButton->move(BTN_GAP,yMenuBtnStart+i*(createRoomButton->height() +  BTN_GAP));
    this->addWidget(createRoomButton);

    i++;
    QuitButton = new menuBtn(QString::fromStdString("Exit"));
    QuitButton->move(xMenuBtnStart,yMenuBtnStart + i*(QuitButton->height() + BTN_GAP));
    this->addWidget(QuitButton);

    joinButton = new menuBtn(QString::fromStdString("Join"));
    joinButton->move (BTN_GAP, yMenuBtnStart + i*(joinButton->height() + BTN_GAP));
    this->addWidget(joinButton);

    title = new QGraphicsTextItem();
    title->setPlainText(QString::fromStdString(TITLE));
    font = QFont(QString::fromStdString("Decorative"),50,2,true);
    font.setBold(true);
    title->setFont(font);
    title->setPos(650,20);
    this->addItem(title);
}
mainMenu::~mainMenu(){
    delete QuitButton;
    delete scoreboardButton;
    delete joinButton;
    delete createRoomButton;
}

menuBtn* mainMenu::getQuitButton() const{
    return QuitButton;
}

menuBtn* mainMenu::getScoreboardButton()const{
    return scoreboardButton;
}

menuBtn* mainMenu::getJoinButton() const{
    return joinButton;
}

menuBtn* mainMenu::getCreateRoomButton() const{
    return createRoomButton;
}
