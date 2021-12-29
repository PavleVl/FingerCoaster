#include "../Headers/lobby.h"
#include "ui_lobby.h"
#include <qlistview.h>
#include <sstream>

Lobby::Lobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lobby)
{
    isClient = false;
    i = 0;
    ui->setupUi(this);
    this->setWindowTitle("Lobby");
    this->setObjectName("PopUp");
    this->setStyleSheet(QString::fromUtf8("#PopUp {border-image: url(:/images/prefix1/popup.jpg) 0 0 0 0 stretch stretch;}"));


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
    emit closeServerConnections();

        //TOIML
        //starting the game

    this->close();
}

void Lobby::rewriteUsernames(QVector<QString>* usernames){
    ui->playerList->clear();
    i = usernames->size();
    usernames->size();
    QString buff = "";
    for(int j = 0;j<usernames->size();j++){

        buff += QString::number(j+1) + ". " + usernames->at(j);
        ui->playerList->addItem(buff);
        buff = "";
    }
}

void Lobby::closeEvent(QCloseEvent *event){

    if(!isClient)
        emit popUpForcedClose();
    else
        emit joinPopupForcedClose();
}

void Lobby::setIsClient(){
    isClient = true;
    ui->btStartGame->hide();
}

void Lobby::dontShowLobby(){
    this->close();
}
