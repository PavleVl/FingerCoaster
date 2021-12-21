#include "enterusername.h"
#include "ui_enterusername.h"

enterUsername::enterUsername(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enterUsername)
{
    ui->setupUi(this);

    this->setWindowTitle("Initial Username");
}

enterUsername::~enterUsername()
{
    delete ui;
}

void enterUsername::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    this->close();

}

