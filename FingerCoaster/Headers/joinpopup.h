#ifndef JOINPOPUP_H
#define JOINPOPUP_H

#include <QDialog>
#include "lobby.h"
namespace Ui {
class JoinPopUp;
}

class JoinPopUp : public QDialog
{
    Q_OBJECT

public:
    explicit JoinPopUp(QWidget *parent = nullptr);
    ~JoinPopUp();
    void insertKey();
    bool isValidIp4Address(const std::string& ipAddress);
    bool isValidPort(int port);

signals:
    void openLobby();

private slots:
    void on_joinButton_clicked();

private:
    Ui::JoinPopUp *ui;
};

#endif // JOINPOPUP_H
