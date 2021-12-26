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
        ui->err_label->setText("You need to select difficulty");

        return;
    }

    lobby = new Lobby(this);
    lobby->show();
    emit startServer(unsigned(ui->num_players_cb->currentIndex()) + 1,choosenDifficulty());

}

