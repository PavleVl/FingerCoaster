#include "Client.h"

Client::Client(QString name,QObject *parent)
    : QObject{parent},
      name(name)
{
    connect(socket,SIGNAL(socket->connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(socket->disconnected()),this,SLOT(disconnected()));
}

void Client::connectToHost(const QHostAddress &addr, quint16 port){
    socket->connectToHost(addr,port);
    address = addr;
    this->port = port;
}

void Client::disconnectFromHost(){
    socket->disconnectFromHost();
    qDebug()<<"Disconnected";
}

void Client::connected(){
    qDebug()<<"Connected to host";
}





