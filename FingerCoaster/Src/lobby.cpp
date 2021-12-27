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
    if(client) {
        ui->btStartGame->hide();
    }
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

void Lobby::on_btStartGame_clicked()
{
    if(!client){
        emit closeServerConnections();

        //TOIML
        //starting the game

        this->close();
    }
}

void Lobby::on_Lobby_destroyed()
{
    //emit popUpForcedClose();
}

void Lobby::closeEvent(QCloseEvent *event){
    emit popUpForcedClose();
}


