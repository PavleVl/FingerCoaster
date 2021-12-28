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

    //    connect(ui->joinButton,SIGNAL(clicked()),this,SLOT(on_joinButton_clicked()));
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
            ui->lMessage->setText("Morate uneti ip adresu i port");
            return;
    }
    bool isIpAddr = isValidIp4Address(list[0].toStdString());
    int isPort = list[1].toInt();
    bool isVPort = isValidPort(isPort);
    if(!isIpAddr)
            ui->lMessage->setText("Nije validna IPv4 adresa");
    else if(!isVPort)
            ui->lMessage->setText("Nije validan port");
    else {
        ui->lMessage->setText("Klijent se konektovao.");
        this->close();
        emit startClient();
        emit openLobby();
    }
}

