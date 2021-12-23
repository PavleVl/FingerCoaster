#include "Headers/mainMenu.h"

mainMenu::mainMenu():QGraphicsScene(){
    int xBtn = 1680;
    int yStartBtn = 800;
    this->setSceneRect(0,0,MAP_WIDTH,MAP_HEIGHT);
    QImage background = QImage(":/images/prefix1/main-menu.jpg");
    background = background.scaled(WINDOW_WIDTH,WINDOW_HEIGHT);

    this->setBackgroundBrush(background);
    int index = 0;

    scoreboardButton = new menuBtn("Scoreboard");
    scoreboardButton->move(xBtn,yStartBtn+index*(scoreboardButton->height() +  BTN_GAP));
    this->addWidget(scoreboardButton);

    createRoomButton = new menuBtn("Create room");
    createRoomButton->move(BTN_GAP,yStartBtn+index*(createRoomButton->height() +  BTN_GAP));
    this->addWidget(createRoomButton);

    index++;
    QuitButton = new menuBtn("Exit");
    QuitButton->move(xBtn,yStartBtn + index*(QuitButton->height() + BTN_GAP));
    this->addWidget(QuitButton);

    joinButton = new menuBtn("Join");
    joinButton->move (BTN_GAP, yStartBtn + index*(joinButton->height() + BTN_GAP));
    this->addWidget(joinButton);

    QGraphicsTextItem* title = new QGraphicsTextItem();
    title->setPlainText(TITLE);
    QFont font = QFont("Decorative",50,2,true);
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
