#include "Game/gameDialog.h"
#include "ui_gamedialog.h"
#include <QLabel>

#define MAX_CHARS (100)

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    isClient(false),
    ui(new Ui::GameDialog)
{
    ui->setupUi(this);
    this->setObjectName("GameWindow");
    this->setStyleSheet(QString::fromUtf8("#GameWindow {border-image: url(:/images/prefix1/board.jpeg) 0 0 0 0 stretch stretch;}"));

    ui->pb1->setObjectName("QProgressBar1");
    ui->pb2->setObjectName("QProgressBar2");
    ui->pb3->setObjectName("QProgressBar3");
    ui->pb4->setObjectName("QProgressBar4");

    ui->pb1->setStyleSheet(QString::fromUtf8("#QProgressBar1 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->pb2->setStyleSheet(QString::fromUtf8("#QProgressBar2 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->pb3->setStyleSheet(QString::fromUtf8("#QProgressBar3 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->pb4->setStyleSheet(QString::fromUtf8("#QProgressBar4 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));

    ui->lineEdit->setObjectName("lEdit");
    ui->lineEdit->setStyleSheet(QString::fromUtf8("#lEdit {border: 2px solid grey;border-radius: 5px}"));
    ui->lwText->setStyleSheet(QString::fromUtf8("#lwText {border: 2px solid grey;border-radius: 5px}"));
    ui->lwText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->lwText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



   //QLabel *labels = new QLabel*[10]{ui->pb1, ui->pb2, ui->pb3, ui->pb4,
     //                        ui->label_4, ui->label_5, ui->label_6,
       //                      ui->label_7, ui->label_8, ui->label_9
}

void GameDialog::setWordsOnScreen(std::vector<std::string> text){
    for(auto& word:text){
        ui->lwText->addItem(QString::fromStdString(word));
    }
    std::cout<<ui->lineEdit->text().toStdString();
}

GameDialog::~GameDialog()
{
    delete ui;
}

void GameDialog::closeEvent(QCloseEvent *){
    emit gameDialogClosing();

    if(!isClient){
       emit shutdownServer();
    }


}

