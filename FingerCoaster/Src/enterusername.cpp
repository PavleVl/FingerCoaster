#include "Headers/enterusername.h"
#include "ui_enterusername.h"

enterUsername::enterUsername(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enterUsername)
{
    ui->setupUi(this);

    this->setWindowTitle("Welcome");
}

enterUsername::~enterUsername()
{
    delete ui;
}

void enterUsername::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    if(username.size() == 0)
        return;

    ScoreboardBackend* scoreboardWrite = new ScoreboardBackend();
    std::string name = username.toStdString();
    scoreboardWrite->writeUsername(name);

    this->close();
}

