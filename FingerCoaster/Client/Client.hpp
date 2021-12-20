#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QString name,QObject *parent = nullptr);
    void connectToHost(const QHostAddress& addr,quint16 port);
    void disconnectFromHost();
signals:

private slots:
    void connected();
    void disconnected();
private:
    QHostAddress address;
    quint16 port;
    QString name;
    QTcpSocket* socket;
};

#endif // CLIENT_H
