#include "Server.hpp"


Server::Server(QObject* parent) : QTcpServer(parent){
}

void Server::startServer(){

    if(!this->listen(QHostAddress::Any,8080)){
        std::cout << "Server could not start" << std::endl;
    }
    else{
        std::cout << "Server has been started" << this->serverAddress().toString().toStdString() << std::endl;
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

    Thread* thread = new Thread(socketFd,this);
    clients.append(thread);
}
