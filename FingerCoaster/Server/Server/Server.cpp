#include "Server.hpp"

Server::Server(QObject* parent) : QTcpServer(parent){
    serverStorage = Storage();
}

void Server::startServer(){
    if(!this->listen(QHostAddress::Any,8080)){
        std::cout << "Server could not start" << std::endl;
    }
    else{
        std::cout << "Server has been started " << this->serverAddress().toString().toStdString() << std::endl;
    }
}

int Server::numOfClients() const{
    return clients.size();
}

void Server::broadcast(QByteArray message){
    for(Thread* thread: clients){
        sendMessage(thread,message);
    }
}

void Server::sendMessage(Thread *thread, QByteArray message){
    thread->sendMessage(message);
}

void Server::incomingConnection(qintptr socketFd){
    if(unsigned(clients.size()) < serverStorage.getNumberOfPlayers()){
        Thread* thread = new Thread(socketFd,this);
        clients.append(thread);
        std::cout << "Accepted the socket ";
        std::cout << clients.size() << std::endl;
    }
    else{
        QTcpSocket *rejectedSocket = new QTcpSocket();
        rejectedSocket->setSocketDescriptor(socketFd);
        rejectedSocket->write("MAX_LIMIT_ABORT");
        rejectedSocket->close();
    }
}

