#ifndef SERVER_HPP
#define SERVER_HPP

#include "Thread.h"
#include <QDebug>
#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>


class Server : public QTcpServer{
    Q_OBJECT
    Q_DISABLE_COPY(Server)

public:
    explicit Server(QObject* parent = nullptr);

    void startServer();
    void sendMessage(Thread* thread,QByteArray message);
    int numOfClients() const;

public slots:
    void broadcast(QByteArray message);

protected:
    void incomingConnection(qintptr socketFd) override;

private:
    QVector<Thread*> clients;

};

#endif
