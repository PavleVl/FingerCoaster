#include "Game/gameDialog.h"
#include "ui_gamedialog.h"

#define MAX_CHARS (100)

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog),isClient(false)
{
    ui->setupUi(this);
    this->setWindowTitle("Let's play the game");
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
    ui->lineEdit->installEventFilter(this);
    //Grouping groupBoxes
    groupBoxes[0] = ui->gb1;
    groupBoxes[1] = ui->gb2;
    groupBoxes[2] = ui->gb3;
    groupBoxes[3] = ui->gb4;

    //Grouping
    progressBars[0] = ui->pb1;
    progressBars[1] = ui->pb2;
    progressBars[2] = ui->pb3;
    progressBars[3] = ui->pb4;
}

void GameDialog::showEvent(QShowEvent *event){
//    event->type =
}

void GameDialog::setWordsOnScreen(std::vector<std::string> text){
    for(auto& word:text){
        ui->lwText->addItem(QString::fromStdString(word));
    }
   // std::cout<<ui->lineEdit->text().toStdString();
}

GameDialog::~GameDialog()
{
    delete ui;
}

void GameDialog::keyPressEvent(QKeyEvent* event){
    QString str;
}

bool GameDialog::eventFilter(QObject* obj,QEvent* event){
    if(obj == ui->lineEdit && event->type() == QEvent::KeyPress){
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        qDebug()<<"pressed"<<key->key();
    }
    return QObject::eventFilter(obj,event);
}

void GameDialog::closeEvent(QCloseEvent *){
    emit gameDialogClosing();

    if(!isClient){
       emit shutdownServer();
    }
}

void GameDialog::populateGame(QVector<QString>* usernames){

    int i = 0;
    for(;i<usernames->size();i++)
        groupBoxes[i]->setTitle(usernames->at(i));

       while(i <= 3){
           groupBoxes[i]->hide();
           progressBars[i]->hide();
           i++;
   }
}

