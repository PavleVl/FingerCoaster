#include "Headers/mainMenu.h"

mainMenu::mainMenu():QGraphicsScene(){
    int xBtn = 1600;
    int yStartBtn = 900;
    this->setSceneRect(0,0,MAP_WIDTH,MAP_HEIGHT);
    QImage background = QImage(":/images/prefix1/main-menu.jpg");
//    background = background.scaledToHeight(WINDOW_HEIGHT);
    background = background.scaled(WINDOW_WIDTH,WINDOW_HEIGHT);

    this->setBackgroundBrush(background);

    QuitButton = new menuBtn("Exit");
    QuitButton->move(xBtn,yStartBtn + BTN_GAP);
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
}

menuBtn* mainMenu::getQuitButton() const{
    return QuitButton;
}
