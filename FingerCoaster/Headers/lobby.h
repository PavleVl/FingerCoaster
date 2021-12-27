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
    void closeServerConnections();
    void popUpForcedClose();

private slots:
    void addPlayer(QString username);
    void on_btStartGame_clicked();
    void rewriteUsernames(QVector<QString>* usernames);
    void closeEvent(QCloseEvent *event);

private:
    Ui::Lobby *ui;
    int i;
    QStringList players;
    bool client = false;
};

#endif // LOBBY_H
