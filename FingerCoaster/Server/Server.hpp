#ifndef SERVER_HPP
#define SERVER_HPP

#include "Thread.h"
#include "../Storage/Storage.hpp"
#include <QDebug>
#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtConcurrent>

class Server : public QTcpServer{
    Q_OBJECT
    Q_DISABLE_COPY(Server)

public:
    explicit Server(QObject* parent = nullptr);

    void startServer();
    int numOfClients() const;
    void setStorageDifficulty(unsigned difficulty);
    void setStorageMaxPlayers(unsigned maxPlayers);

signals:
    void sendMessage(QByteArray message,qintptr targetSocketFd);
    void updateLobbyList(QString username);

public slots:
    void setClientsUsername(qintptr clientSocketFd,QString username);
    void deleteThread(qintptr clientSocketFd);

protected:
    void incomingConnection(qintptr socketFd) override;

private:
    QMap<quintptr,Thread*> threads;
    QMap<qintptr,QString> usernames;
    Storage* serverStorage;
};

#endif
