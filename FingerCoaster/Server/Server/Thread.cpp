#include "Thread.h"

Thread::Thread(qintptr newSocketFd, QObject *parent) : QThread(parent), threadSocket(new QTcpSocket(this)){
    socketFd = newSocketFd;
    if(!threadSocket->setSocketDescriptor(socketFd)){
        std::cout << threadSocket->error();
    }

   //Connects for the slots of the SOCKET!

   connect(threadSocket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
   connect(threadSocket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
   connect(parent,SIGNAL(sendMessage(QByteArray,qintptr)),this,SLOT(onSendMessage(QByteArray,qintptr)),Qt::DirectConnection);
}

void Thread::onSendMessage(QByteArray message,qintptr targetSocketFd){
    if(targetSocketFd == socketFd)
        threadSocket->write(message);
}

void Thread::readyRead(){
    QByteArray buff = threadSocket->readAll();
    std::cout << buff.toStdString() << std::endl;
}

void Thread::disconnected(){
    std::cout << "The client has disconnected" << std::endl;
    threadSocket->deleteLater();
}

void Thread::run(){
    exec();
}
