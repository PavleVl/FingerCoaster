#include "Thread.h"

Thread::Thread(qintptr newSocketFd, QObject *parent) : QObject(parent), threadSocket(new QTcpSocket(this)){
    std::cout << "New thread created " << newSocketFd << std::endl;
    socketFd = newSocketFd;
    if(!threadSocket->setSocketDescriptor(socketFd)){
        std::cout << threadSocket->error();
    }

    connect(threadSocket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
}

void Thread::sendMessage(QByteArray message){
    std::cout << socketFd << " sent : " << message.toStdString() << std::endl;
    threadSocket->write(message);
}

void Thread::readyRead(){
    QByteArray buff = threadSocket->readAll();
    std::cout << buff.toStdString() << std::endl;
}
