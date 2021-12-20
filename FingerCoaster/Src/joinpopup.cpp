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
