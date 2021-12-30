#include "gamedialog.h"
#include "ui_gamedialog.h"

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog)
{
    ui->setupUi(this);
    this->setObjectName("GameWindow");
    this->setStyleSheet(QString::fromUtf8("#GameWindow {border-image: url(:/images/prefix1/board.jpeg) 0 0 0 0 stretch stretch;}"));
    this->
    ui->progressBar->setObjectName("QProgressBar");
    ui->progressBar_3->setObjectName("QProgressBar1");
    ui->progressBar_5->setObjectName("QProgressBar2");
    ui->progressBar->setStyleSheet(QString::fromUtf8("#QProgressBar {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->progressBar_3->setStyleSheet(QString::fromUtf8("#QProgressBar1 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->progressBar_5->setStyleSheet(QString::fromUtf8("#QProgressBar2 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->lineEdit->setObjectName("lEdit");
    ui->lineEdit->setStyleSheet(QString::fromUtf8("#lEdit {border: 2px solid grey;border-radius: 5px}"));
    ui->lwText->setStyleSheet(QString::fromUtf8("#lwText {border: 2px solid grey;border-radius: 5px}"));
}

GameDialog::~GameDialog()
{
    delete ui;
}

