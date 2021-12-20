#ifndef THREAD_H
#define THREAD_H


#include <iostream>
#include <QThread>
#include <QTcpSocket>

class Thread : public QObject{
Q_OBJECT

public:
    explicit Thread(qintptr newSocketFd, QObject *parent = 0);

public slots:
    void readyRead();
    void sendMessage(QByteArray message);

private:
    QTcpSocket* threadSocket;
    qintptr socketFd;
};

#endif // THREAD_H
