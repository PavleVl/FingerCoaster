#include "Headers/joinpopup.h"
#include "ui_joinpopup.h"
#include <arpa/inet.h>
#include "Headers/configuration.h"

JoinPopUp::JoinPopUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JoinPopUp)
{
    ui->setupUi(this);

    this->setWindowTitle("Join room");
    this->setObjectName("PopUp");
    this->setStyleSheet(QString::fromUtf8("#PopUp {border-image: url(:/images/prefix1/popup.jpg) 0 0 0 0 stretch stretch;}"));
    ui->key->setStyleSheet("font-weight: bold");

//<<<<<<< HEAD
//=======
//    //    connect(ui->joinButton,SIGNAL(clicked()),this,SLOT(on_joinButton_clicked()));
//>>>>>>> 7db8ad15debb9a39da1223d741b893a8be3ee399
    if(ui->joinButton->isChecked())
            on_joinButton_clicked();
}

JoinPopUp::~JoinPopUp()
{
    delete ui;
}

bool JoinPopUp::isValidIp4Address(const std::string& str){
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET,str.c_str(),&(sa.sin_addr));
    return result != 0;
}

bool JoinPopUp::isValidPort(int port){
    if(port >= 0 && port <= 65535)
            return true;
    return false;
}

void JoinPopUp::on_joinButton_clicked()
{
    QString key = ui->labelInsertKey->text();
    QStringList list = key.split(":");
    if(list.size() < 2){
            ui->lMessage->setText("IP address and port is needed");
            ui->lMessage->setStyleSheet("QLabel {background-color: lightgreen; color: red;}");
            return;
    }
    bool isIpAddr = isValidIp4Address(list[0].toStdString());
    int isPort = list[1].toInt();
    bool isVPort = isValidPort(isPort);
    if(!isIpAddr){
            ui->lMessage->setText("IPv4 address is not valid");
            ui->lMessage->setStyleSheet("QLabel {background-color: lightgreen; color: red;}");
    }
    else if(!isVPort){
            ui->lMessage->setText("Port not valid");
            ui->lMessage->setStyleSheet("QLabel {background-color: lightgreen; color: red;}");
    }
    else {
        ui->lMessage->setText("Client is connected.");
        this->close();
        emit startClient();
        emit openLobby();
    }
}

