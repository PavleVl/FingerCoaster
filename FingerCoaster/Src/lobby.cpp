#include "../Headers/lobby.h"
#include "ui_lobby.h"
#include <qlistview.h>
#include <sstream>
#include <QMovie>
#include <iostream>

Lobby::Lobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lobby),
    checkCloseFlag(false)
{
    isClient = false;
    i = 0;
    ui->setupUi(this);
    this->setWindowTitle("Lobby");
    this->setObjectName("PopUp");
    this->setStyleSheet(QString::fromUtf8("#PopUp {border-image: url(:/images/prefix1/popup.jpg) 0 0 0 0 stretch stretch;}"));
    ui->label->setStyleSheet("font-weight: bold");
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
    checkCloseFlag = true;
    this->close();

    emit closeServerConnections();
    emit startGameForClients();
    emit setGameScene();
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

    if(checkCloseFlag)
        return;

    if(!isClient)
        emit popUpForcedClose();
    else
        emit joinPopupForcedClose();
}

void Lobby::setIsClient(){
    isClient = true;
    ui->btStartGame->hide();

    ui->label=new QLabel(this);
    QMovie *movie=new QMovie(":/images/prefix1/loading.gif");


    QLabel *gif_label = new QLabel(this);
    gif_label->setGeometry(155,140,40,40);
    gif_label->setMovie(movie);
    movie->start();
}

void Lobby::dontShowLobby(){
    checkCloseFlag = true;
    this->close();
}
