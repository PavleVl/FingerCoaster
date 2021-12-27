#include "Client.hpp"

Client::Client(QString name,QObject *parent)
    : QObject{parent},
      username(name),
      tcpSocket(new QTcpSocket(this))
{
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedCl()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(disconnectedCl()));
    connect(tcpSocket,&QAbstractSocket::errorOccurred,this,&Client::printError);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(tcpSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten()));

    qDebug()<<"Connecting...";
//    tcpSocket->connectToHost(QHostAddress::LocalHost,12345);

    tcpSocket->connectToHost("192.168.10.90",8080);
}


void Client::connectedCl(){
    qDebug()<<"Connected!";
    QByteArray br = "username:" + this->username.toUtf8() + "\n";
    tcpSocket->write(br);
}

void Client::disconnectedCl(){
    tcpSocket->close();
    tcpSocket->deleteLater();
    qDebug()<<"Disconnected from host";
}

void Client::bytesWritten(){
    qDebug()<<"we wrote username to host";
}

void Client::readyRead(){
    //Kada uhvatis usernamesList:username1:username2:username3:
    //Tada splitujes
    //Saljes signal da upalis slot rewriteUSernames();

    qDebug()<<"Reading...";
    qDebug()<<tcpSocket->readAll();
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
        default:qDebug()<<"The following error occured: " + tcpSocket->errorString();
    }
}
