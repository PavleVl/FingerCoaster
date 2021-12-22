#include "Thread.h"

Thread::Thread(qintptr newSocketFd, QObject *parent) : QThread(parent), threadSocket(new QTcpSocket(this)){
    socketFd = newSocketFd;
    std::cout << "I'm here!";
    if(!threadSocket->setSocketDescriptor(socketFd)){
        std::cout << threadSocket->error();
    }

   //Connects for the slots of the SOCKET!

   connect(threadSocket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
   connect(threadSocket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
   connect(parent,SIGNAL(sendMessage(QByteArray,qintptr)),this,SLOT(onSendMessage(QByteArray,qintptr)),Qt::DirectConnection);
}

void Thread::onSendMessage(QByteArray message,qintptr targetSocketFd){
    if(targetSocketFd == socketFd){
        threadSocket->write(message);
        threadSocket->flush();
    }
}

void Thread::readyRead(){
    QByteArray buff = threadSocket->readAll();

    QString text = QString(buff);
    std::cout << text.toStdString() << std::endl;
    //Ispaljujemo signal ako nam je klijent poslao username
    if(text.contains("username:"))
        emit setClientsUsername(socketFd,text.mid(9,text.size() - 9));
}

void Thread::disconnected(){
    std::cout << "The client has disconnected" << std::endl;
    threadSocket->deleteLater();

    emit deleteThread(socketFd);
    this->exit();
}

void Thread::run(){
    exec();
}
