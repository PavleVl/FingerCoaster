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
   connect(parent,SIGNAL(endConnection()),this,SLOT(forceCloseConnection()),Qt::DirectConnection);
   //connect(parent,SIGNAL(),this,SLOT(softCloseConnection()),Qt::DirectConnection);
}

void Thread::onSendMessage(QByteArray message,qintptr targetSocketFd){
    if(threadSocket->isWritable() && (targetSocketFd == socketFd || targetSocketFd == 0)){
        threadSocket->write(message);
        threadSocket->flush();
    }
}

void Thread::readyRead(){
    QByteArray buff = threadSocket->readAll();

    QString text = QString(buff);
    //Ispaljujemo signal ako nam je klijent poslao username
    if(text.contains("clientProgress:")){
        std::cout << "Usao u clientProgress" << std::endl;

        text = text.split(":").at(1);
        username = text.split("-").at(0);
        unsigned curGameProgress = text.split("-").at(1).toUInt();

        emit updateClientsProgress(socketFd,curGameProgress);
        return;
    }
    if(text.contains("username:")){
        emit setClientsUsername(socketFd,text.mid(9,text.size() - 9));
        return;
    }

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

void Thread::softCloseConnection(){
    threadSocket->deleteLater();
}

void Thread::forceCloseConnection(){
        threadSocket->deleteLater();
        threadSocket->close();
}
