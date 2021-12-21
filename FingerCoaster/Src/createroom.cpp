#include "Headers/createroom.h"
#include "ui_createroom.h"
#include <stdlib.h>

createroom::createroom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createroom)
{
    ui->setupUi(this);

    this->setWindowTitle("Create room");
}

createroom::~createroom()
{
    delete ui;
}


void createroom::on_create_lobby_button_clicked(){

}

void createroom::on_create_lobby_button_pressed(){

}

