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
    if(targetSocketFd == socketFd || targetSocketFd == 0){
        threadSocket->write(message);
        //Ja bih trebalo da ukljucim Thread.hpp i da procitam odavde i samo parsiram tako da klijent ima info o
        //drugim username-ovima?Ovo bi meni zapravo bio signal da ja(Client) mogu da citam tj parsiram i dobijem usernamove?
        //Ovako si zamislio?
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
