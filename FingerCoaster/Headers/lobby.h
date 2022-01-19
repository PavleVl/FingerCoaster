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
    void setIsClient();

signals:
    void closeServerConnections();
    void joinPopupForcedClose();
    void popUpForcedClose();
    void setGameScene();
    //Game signals
    void startGameForClients();
    void startClientGame();

public slots:
    //Addplayer se koristi za prvo dodavanje u lobby
    void addPlayer(QString username);
    void on_btStartGame_clicked();
    //Rewriteusernames
    //Brise sva imena iz lobby prozora
    //i upisuje sva imena iz usernames
    //Koristi se kada neki klijent izadje
    void rewriteUsernames(QVector<QString>* usernames);
    void closeEvent(QCloseEvent *event);
    void dontShowLobby();
    void closeLobbyStartGame();

private:
    bool isClient;
    Ui::Lobby *ui;
    int i;
    QStringList players;
    bool checkCloseFlag;
};

#endif // LOBBY_H
