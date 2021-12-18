#include "mainMenu.h"

mainMenu::mainMenu():QGraphicsScene(){
    int xBtn = 1680;
    int yStartBtn = 800;
    this->setSceneRect(0,0,MAP_WIDTH,MAP_HEIGHT);
    QImage background = QImage(":/images/prefix1/main-menu.jpg");
//    background = background.scaledToHeight(WINDOW_HEIGHT);
    background = background.scaled(WINDOW_WIDTH,WINDOW_HEIGHT);

    this->setBackgroundBrush(background);
    int index = 0;

    scoreboardButton = new menuBtn("Scoreboard");
    scoreboardButton->move(xBtn,yStartBtn+index*(scoreboardButton->height() +  BTN_GAP));
    this->addWidget(scoreboardButton);

    index++;
    QuitButton = new menuBtn("Exit");
    QuitButton->move(xBtn,yStartBtn + index*(QuitButton->height() + BTN_GAP));
    this->addWidget(QuitButton);



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
}

menuBtn* mainMenu::getQuitButton() const{
    return QuitButton;
}

menuBtn* mainMenu::getScoreboardButton()const{
    return scoreboardButton;
}
