#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <iostream>
#include "../Storage/Storage.hpp"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QString name,QObject *parent = nullptr);
    void initGame();
    Storage* giveClientStorage();
    void connectToHost(QString key);

signals:
    void dontShowLobby();
    void rewriteUsernames(QVector<QString>* usernames);
    void startGame();
    void closeClientLobby();
    void populateGame(QVector<QString>*);

private slots:
    void connectedCl();
    void disconnectedCl();
    void printError(QAbstractSocket::SocketError socketError);
    void bytesWritten();
    void readyRead();
    void forceCloseClient();
    void updateProgress(unsigned curProgress);

private:
    QHostAddress address;
    quint16 port;
    QString username;
    QTcpSocket* tcpSocket;
    Storage* clientStorage;
    QVector<QString> connectedUsers;
    bool alreadyClosed;
    unsigned curGameProgress;
};

#endif // CLIENT_H
