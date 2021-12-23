#ifndef CREATEROOM_H
#define CREATEROOM_H

#include <QDialog>

namespace Ui {
class createroom;
}

class createroom : public QDialog
{
    Q_OBJECT

public:
    explicit createroom(QWidget *parent = nullptr);
    ~createroom();

signals:
    void startServer(unsigned maxPlayers,unsigned difficulty);

private slots:
    void on_create_lobby_button_clicked();

private:
    bool noRBChecked();
    unsigned choosenDifficulty();

private:
    Ui::createroom *ui;
};

#endif // CREATEROOM_H
