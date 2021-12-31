#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QProgressBar>
#include "../Server/Server.hpp"
#include "../Storage/Storage.hpp"

namespace Ui {
class GameDialog;
}

class GameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameDialog(QWidget *parent = nullptr);
    ~GameDialog();
//    void getWordsFromServer();

signals:
    void gameDialogClosing();
    void shutdownServer();

public slots:
    void closeEvent(QCloseEvent *event);
    void populateGame(QVector<QString>* usernames);

public:
    void setWordsOnScreen(std::vector<std::string> text);
private:
    Ui::GameDialog *ui;
    QGroupBox *groupBoxes[4];
    QProgressBar *progressBars[4];
    Storage*  st;
    std::vector<std::string> words;
    bool isClient;
};

#endif // GAMEDIALOG_H

