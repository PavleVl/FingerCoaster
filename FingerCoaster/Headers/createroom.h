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

private slots:
    void on_create_key_button_clicked();

    void on_create_lobby_button_pressed();

    void on_create_lobby_button_clicked();

private:
    Ui::createroom *ui;
};

#endif // CREATEROOM_H
