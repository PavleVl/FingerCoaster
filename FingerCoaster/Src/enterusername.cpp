#include "Headers/enterusername.h"
#include "ui_enterusername.h"

enterUsername::enterUsername(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enterUsername)
{
    ui->setupUi(this);

    this->setWindowTitle("Welcome");
    this->setObjectName("PopUp");
    this->setStyleSheet(QString::fromUtf8("#PopUp {border-image: url(:/images/prefix1/popup.jpg) 0 0 0 0 stretch stretch;}"));
    ui->label->setStyleSheet("font-weight: bold");

}

enterUsername::~enterUsername()
{
    delete ui;
}


void enterUsername::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    if(username.size() == 0){
        ui->err_label->setText("Username is required");
        ui->err_label->setStyleSheet("QLabel {background-color: rgba(128,195,66,0.5); color: red;}");
        return;
    }

    ScoreboardBackend* scoreboardWrite = new ScoreboardBackend();
    std::string name = username.toStdString();
    scoreboardWrite->writeUsername(name);

    this->close();
}

