#include "Headers/createroom.h"
#include "ui_createroom.h"
#include <stdlib.h>

createroom::createroom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createroom)
{
    ui->setupUi(this);

    this->setWindowTitle("Create room");
    ui->vr_key->setBackgroundRole(QPalette::Midlight);
}

createroom::~createroom()
{
    delete ui;
}

void createroom::on_create_key_button_clicked()
{
    ui->vr_key->setText(QString::number(random()/1000));
}


void createroom::on_create_lobby_button_clicked()
{

}

void createroom::on_create_lobby_button_pressed(){

}

