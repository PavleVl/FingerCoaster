#include "Client.hpp"
#include <QList>
Client::Client(QString name,QObject *parent)
    : QObject{parent},
      username(name),
      tcpSocket(new QTcpSocket(this)),
      alreadyClosed(false)
{
    clientStorage = new Storage();
    //treba postaviti putanju do fajla i randomTextFlag na false i pozvati f-ju loadText()



    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedCl()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(disconnectedCl()));
    connect(tcpSocket,&QAbstractSocket::errorOccurred,this,&Client::printError);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(tcpSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten()));

    std::cout<<"Connecting..."<<std::endl;

    tcpSocket->connectToHost("0.0.0.0",8080);
}


void Client::connectedCl(){
    std::cout<<"Connected!"<<std::endl;
}

void Client::disconnectedCl(){
    tcpSocket->close();
    tcpSocket->deleteLater();
    alreadyClosed = true;
    std::cout<<"Disconnected from host"<<std::endl;
}

void Client::bytesWritten(){
    std::cout<<"we wrote username to host"<<std::endl;
}
void Client::readyRead(){
    //Kada uhvatis usernamesList:username1:username2:username3:
    //Tada splitujes
    //Saljes signal da upalis slot rewriteUSernames();

    QByteArray byteBuff = tcpSocket->readAll();
    QString buff(byteBuff);
    QVector<QString> vUsernames;
    if(buff.contains("text")){
        std::cout << "I've caught text initialisation " << buff.toStdString() << std::endl;
        std::cout<<"Buffer: "<<buff.toStdString()<< std::endl;
        std::string filename = buff.split(":").last().toStdString();
        std::cout<<"Filename: "<<filename<<std::endl;
        clientStorage->setChoosenFile(filename);
        clientStorage->loadText(false);

        QByteArray br = "username:" + this->username.toUtf8();
        tcpSocket->write(br);
    }
    if(buff.contains("usernamesList:")){
       std::cout <<buff.toStdString()<<std::endl;
       QStringList usernames = buff.split(":");
       auto size = 0;
       std::cout<<"Username-ovi: "<<std::endl;
       for(auto it = usernames.begin()+1;it != usernames.end()-1;it++){
           size = (*it).size();
           if(strcmp((*it).toStdString().c_str(),"usernamesList")==0){
                continue;
           }
           vUsernames.push_back((*it).first(size));
           std::cout<<(*it).toStdString()<<" "<<"\n";
       }

        emit rewriteUsernames(&vUsernames);
    }
        qDebug()<<vUsernames;

}

void Client::printError(QAbstractSocket::SocketError socketError){
    switch(socketError){
        case QAbstractSocket::RemoteHostClosedError:std::cerr<<"Remote host closed"<<std::endl;break;
        case QAbstractSocket::HostNotFoundError:
              std::cerr<<"The host was not found,please check the hostname and port"<<std::endl;break;
        case QAbstractSocket::ConnectionRefusedError:
            std::cerr<<"The connection was refused. "
                      "Make sure the server is running "
                      "and check that the hostname and port settings are correct"<<std::endl;break;
        default:std::cerr<<"The following error occured: "<<tcpSocket->errorString().toStdString()<<std::endl;
    }
    emit dontShowLobby();
}

void Client::forceCloseClient(){
    if(!alreadyClosed){
        this->tcpSocket->close();
        this->tcpSocket->deleteLater();
    }
}
