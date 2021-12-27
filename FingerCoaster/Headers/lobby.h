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
    //void closeClientConnect();
    void popUpForcedClose();

    //Klijent ne otvara lobby prozor ako nije sklopio konekciju sa serverom

    //U readyRead treba da prepoznas kada ti je server napisao
    //start i ako je napisao start ti treba da pokrenes igru
    //i da zatvoris popup lobby(za to treba da se napravi slot)

    //Ako se klijent ugasi preko x tj ako udjemo u slot
    //closeEvent() tada treba i poslati signal u
    //gameEngine iz klijenta da treba da se klijent
    //namesti na nullptr;

private slots:
    //Addplayer se koristi za prvo dodavanje u lobby
    void addPlayer(QString username);
    void on_btStartGame_clicked();
    //Rewriteusernames
    //Brise sva imena iz lobby prozora
    //i upisuje sva imena iz usernames
    //Koristi se kada neki klijent izadje
    void rewriteUsernames(QVector<QString>* usernames);
    void closeEvent(QCloseEvent *event);

private:
    bool isClient;
    Ui::Lobby *ui;
    int i;
    QStringList players;
};

#endif // LOBBY_H
