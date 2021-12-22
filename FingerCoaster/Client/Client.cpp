#include "Client.hpp"

Client::Client(QString name,QObject *parent)
    : QObject{parent},
      name(name),
      tcpSocket(new QTcpSocket(this))
{
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedCl()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(disconnectedCl()));
    connect(tcpSocket,&QAbstractSocket::errorOccurred,this,&Client::printError);
    qDebug()<<" Connecting...";
    tcpSocket->connectToHost(QHostAddress::LocalHost,12345);

}


void Client::connectedCl(){
    qDebug()<<"Connected!";
}

void Client::disconnectedCl(){
    tcpSocket->close();
    qDebug()<<"Disconnected from host";
}


void Client::printError(QAbstractSocket::SocketError socketError){
    switch(socketError){
        case QAbstractSocket::RemoteHostClosedError:break;
        case QAbstractSocket::HostNotFoundError:
              qDebug()<<"The host was not found,please check the hostname and port";break;
        case QAbstractSocket::ConnectionRefusedError:
            qDebug()<<"The connection was refused. "
                      "Make sure the server is running "
                      "and check that the hostname and port settings are correct";break;
        default:qDebug()<<"The following error occured:%1."<<tcpSocket->errorString();
    }
}
