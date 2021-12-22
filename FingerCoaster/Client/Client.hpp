#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
//#include "../Storage/Storage.hpp"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QString name,QObject *parent = nullptr);

signals:

private slots:
    void connectedCl();
    void disconnectedCl();
    void printError(QAbstractSocket::SocketError socketError);
    void bytesWritten();
    void readyRead();
private:
    QHostAddress address;
    quint16 port;
    QString username;
    QTcpSocket* tcpSocket;
};

#endif // CLIENT_H
