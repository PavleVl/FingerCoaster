#include "../Headers/lobby.h"
#include "ui_lobby.h"
#include <qlistview.h>
#include <sstream>
#include <QMovie>

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
    ui->label->setStyleSheet("font-weight: bold");
<<<<<<< HEAD
=======


>>>>>>> 7db8ad15debb9a39da1223d741b893a8be3ee399
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

//    emit openGameScene();
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

    ui->label=new QLabel(this);
    QMovie *movie=new QMovie(":/images/prefix1/loading.gif");


    QLabel *gif_label = new QLabel(this);
    gif_label->setGeometry(155,140,40,40);
    gif_label->setMovie(movie);
    movie->start();
<<<<<<< HEAD
=======




>>>>>>> 7db8ad15debb9a39da1223d741b893a8be3ee399
}

void Lobby::dontShowLobby(){
    this->close();
}
