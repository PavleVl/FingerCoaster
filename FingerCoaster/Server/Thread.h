#ifndef THREAD_H
#define THREAD_H


#include <iostream>
#include <QThread>
#include <QTcpSocket>

class Thread : public QThread{
Q_OBJECT

public:
    explicit Thread(qintptr newSocketFd, QObject *parent = 0);


signals:
    void setClientsUsername(qintptr clientSocketFd,QString username);
    void deleteThread(qintptr clientSocketFd);

public slots:
    //Socket slots
    void readyRead();
    void onSendMessage(QByteArray message,qintptr targetSocketPtr);
    void disconnected();
    void forceCloseConnection();
    void softCloseConnection();
    //Thread slots

protected:
    void run() override;

private:
    QTcpSocket* threadSocket;
    qintptr socketFd;
    QString username;
};

#endif // THREAD_H
