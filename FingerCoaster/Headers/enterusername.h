#ifndef ENTERUSERNAME_H
#define ENTERUSERNAME_H

#include <QDialog>
#include "../Headers/ScoreboardBackend.hpp"

namespace Ui {
class enterUsername;
}

class enterUsername : public QDialog
{
    Q_OBJECT

public:
    explicit enterUsername(QWidget *parent = nullptr);
    ~enterUsername();

private slots:
    void on_pushButton_clicked();

private:
    Ui::enterUsername *ui;
};

#endif // ENTERUSERNAME_H
