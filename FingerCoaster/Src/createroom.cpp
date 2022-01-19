#include "Headers/createroom.h"
#include "ui_createroom.h"
#include <stdlib.h>
#include <QGraphicsScene>
#include "Headers/mainMenu.h"


createroom::createroom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createroom)
{
    ui->setupUi(this);

    this->setWindowTitle(QString::fromStdString("Create room"));
    this->setObjectName(QString::fromStdString("PopUp"));
    this->setStyleSheet(QString::fromUtf8("#PopUp {border-image: url(:/images/prefix1/popup.jpg) 0 0 0 0 stretch stretch;}"));
    ui->diff_label->setStyleSheet(QString::fromStdString("font-weight: bold"));
    ui->num_players_label->setStyleSheet(QString::fromStdString("font-weight: bold"));
    ui->rb_easy->setStyleSheet(QString::fromStdString("font-weight: bold"));
    ui->rb_hard->setStyleSheet(QString::fromStdString("font-weight: bold"));
    ui->rb_medium->setStyleSheet(QString::fromStdString("font-weight: bold"));
}

bool createroom::noRBChecked(){

    if(!ui->rb_easy->isChecked() && !ui->rb_medium->isChecked() && !ui->rb_hard->isChecked())
        return true;

    return false;
}

unsigned createroom::choosenDifficulty(){

    if(ui->rb_easy->isChecked())
        return 0;
    if(ui->rb_medium->isChecked())
        return 1;

    return 2;
}

createroom::~createroom()
{
    delete ui;
}

void createroom::on_create_lobby_button_clicked(){

    if(noRBChecked()){
        ui->err_label->setText(QString::fromStdString("You need to select difficulty"));
        ui->err_label->setStyleSheet(QString::fromStdString("QLabel {background-color: "
                                                            "rgba(128,195,66,0.5); color: red;}"));

        return;
    }

    this->close();
    emit startServer(unsigned(ui->num_players_cb->currentIndex()) + 1,choosenDifficulty());
    emit openLobby();
}

