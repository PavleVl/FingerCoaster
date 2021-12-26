#ifndef LOBBY_H
#define LOBBY_H

#include <QDialog>

namespace Ui {
class Lobby;
}

class Lobby : public QDialog
{
    Q_OBJECT

public:
    explicit Lobby(QWidget *parent = nullptr);
    ~Lobby();

signals:
    //TODO
    //Send signal when the game is started if its server lobby

private slots:
    void addPlayer(QString username);

private:
    Ui::Lobby *ui;
    bool isServer;
    //TODO
    //Implement way to check if you are server or client


};

#endif // LOBBY_H
