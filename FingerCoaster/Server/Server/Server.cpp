#include "Server.hpp"

#define SERVER_PORT 8080

Server::Server(QObject* parent) : QTcpServer(parent){
    serverStorage = new Storage();
    serverStorage->loadText(true);
    serverStorage->setNumberOfPlayers(3);

}

void Server::startServer(){
    if(!this->listen(QHostAddress::Any,SERVER_PORT)){
        std::cout << "Server could not start" << std::endl;
    }
    else{
        std::cout << "Server has been started " << this->serverAddress().toString().toStdString() << std::endl;
    }
}

int Server::numOfClients() const{
    return clientSockets.size();
}

void Server::incomingConnection(qintptr socketFd){
    if(unsigned(clientSockets.size()) < serverStorage->getNumberOfPlayers()){
        Thread* thread = new Thread(socketFd,this);
        clientSockets.append(socketFd);
        std::cout << "Accepted the socket ";
        thread->start();

        std::string choosenFile = serverStorage->getChoosenFile();
        QByteArray byteBuff(choosenFile.c_str(),choosenFile.length());
        emit sendMessage(byteBuff,socketFd);
    }
    else{
        QTcpSocket *rejectedSocket = new QTcpSocket();
        rejectedSocket->setSocketDescriptor(socketFd);
        rejectedSocket->write("MAX_LIMIT_ABORT");
        rejectedSocket->close();
        //TODO
        //deletelater blocks close
        //rejectedSocket->deleteLater();
    }
}

