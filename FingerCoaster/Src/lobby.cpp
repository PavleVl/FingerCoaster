#include "../Headers/lobby.h"
#include "ui_lobby.h"

Lobby::Lobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
    this->setWindowTitle("Lobby");
}

Lobby::~Lobby()
{
    delete ui;
}

void Lobby::addPlayer(QString username){
     //TOIMPL
     //This function places username into list box
     //Format-> number. username

    //TODO
    //Implement how many people are connected
}

//TODO
//Implement way to show a start button if you are server
//and hide if you are client

