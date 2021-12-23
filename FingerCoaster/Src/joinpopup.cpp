#include "Headers/joinpopup.h"
#include "ui_joinpopup.h"

JoinPopUp::JoinPopUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinPopUp)
{
    ui->setupUi(this);

    this->setWindowTitle("Join room");

    ui->vr_key->setText("Treba dohvatiti kljuc");
    ui->vr_key->setBackgroundRole(QPalette::Midlight);
}

JoinPopUp::~JoinPopUp()
{
    delete ui;
}

void JoinPopUp::insertKey(){
//    this->ui->vr_key->
}


void JoinPopUp::on_joinButton_clicked()
{

}

