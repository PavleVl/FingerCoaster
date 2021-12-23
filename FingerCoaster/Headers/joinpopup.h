#ifndef JOINPOPUP_H
#define JOINPOPUP_H

#include <QDialog>

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
private slots:
    void on_joinButton_clicked();

private:
    Ui::JoinPopUp *ui;
};

#endif // JOINPOPUP_H
