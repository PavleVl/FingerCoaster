#ifndef SERVER_HPP
#define SERVER_HPP

#include "Thread.h"
#include "../../Storage/Storage.hpp"
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
    int numOfClients() const;

signals:
    void sendMessage(QByteArray message,qintptr targetSocketFd);

protected:
    void incomingConnection(qintptr socketFd) override;

private:
    QVector<qintptr> clientSockets;
    Storage* serverStorage;
};

#endif
