#include "../Headers/lobby.h"
#include "ui_lobby.h"
#include <qlistview.h>
#include <sstream>

Lobby::Lobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lobby)
{

    i = 0;
    ui->setupUi(this);
    this->setWindowTitle("Lobby");
}

Lobby::~Lobby()
{
    delete ui;
}

void Lobby::addPlayer(QString username){
    players << username;
    i++;
    QString s = QString("%1. %2").arg(i).arg(username);
    ui->playerList->addItem(s);
}

//TODO
//Implement way to show a start button if you are server
//and hide if you are client

