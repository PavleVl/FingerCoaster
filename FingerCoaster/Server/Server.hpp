#ifndef SERVER_HPP
#define SERVER_HPP

#include "Thread.h"
#include "../Storage/Storage.hpp"
#include "../Scoreboard/ScoreboardBackend.hpp"
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
    void setGameStarted(bool gameStartedFlag);
    void broadcastUsernames();
    Storage* getServerStorage()const;

signals:
    //If we send 0 as targetSocketFd that means that we want every
    //single socket to send that message
    void sendMessage(QByteArray message,qintptr targetSocketFd);
    void updateLobbyList(QString username);
    void rewriteLobbyList(QVector<QString>* usernames);
    void endConnection();
    void softEndConnection();
    void serverShutdown();

public slots:
    void setClientsUsername(qintptr clientSocketFd,QString username);
    void deleteThread(qintptr clientSocketFd);
    void blockConnections();
    void forceCloseTheServer();
    //Softclose won't close the clients
    void softCloseTheServer();
    void startGameForClients();

protected:
    void incomingConnection(qintptr socketFd) override;

private:
    QMap<quintptr,Thread*> threads;
    QMap<qintptr,QString> usernames;
    Storage* serverStorage;
    bool inGame;
};

#endif
