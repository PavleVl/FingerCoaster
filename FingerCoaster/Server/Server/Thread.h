#ifndef THREAD_H
#define THREAD_H


#include <iostream>
#include <QThread>
#include <QTcpSocket>

class Thread : public QThread{
Q_OBJECT

public:
    explicit Thread(qintptr newSocketFd, QObject *parent = 0);

public slots:
    //Socket slots
    void readyRead();
    void onSendMessage(QByteArray message,qintptr targetSocketPtr);
    void disconnected();
    //Thread slots

protected:
    void run() override;

private:
    QTcpSocket* threadSocket;
    qintptr socketFd;
};

#endif // THREAD_H
