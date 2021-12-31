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
#include <QPair>

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
    void initializeGame();
    void changeGameProgress();

signals:
    //If we send 0 as targetSocketFd that means that we want every
    //single socket to send that message
    void sendMessage(QByteArray message,qintptr targetSocketFd);
    void updateLobbyList(QString username);
    void rewriteLobbyList(QVector<QString>* usernames);
    void endConnection();
    void softEndConnection();
    void serverShutdown();
    void populateGame(QVector<QString>* usernames);
    void changeCurGameProgress(QVector<unsigned>* cuProgress);

public slots:
    void setClientsUsername(qintptr clientSocketFd,QString username);
    void deleteThread(qintptr clientSocketFd);
    void blockConnections();
    void forceCloseTheServer();
    //Softclose won't close the clients
    void softCloseTheServer();
    void startGameForClients();
    void setMyProgress(unsigned curProgress);
    void updateClientsGameProgress(qintptr socketFd,unsigned curClientProgress);

protected:
    void incomingConnection(qintptr socketFd) override;

private:
    QMap<quintptr,Thread*> threads;
    QMap<qintptr,QString> usernames;
    QMap<QPair<qintptr,QString>,unsigned> progress;
    Storage* serverStorage;
    bool inGame;
    QString myUsername;
};

#endif
