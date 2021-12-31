#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QProgressBar>
#include <QKeyEvent>
#include <QShowEvent>
#include <QTimer>
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
//  void getWordsFromServer();
    unsigned getCurrentProgress();
    void setWordsOnScreen(std::vector<std::string> text);

protected:
    void keyPressEvent(QKeyEvent* event)override;
    bool eventFilter(QObject* obj,QEvent* event)override;
signals:
    void gameDialogClosing();
    void shutdownServer();
    void updateProgress(unsigned curProgress);

public slots:
    void closeEvent(QCloseEvent *event)override;
    void populateGame(QVector<QString>* usernames);
    void timeoutSlot();
    void updateCurGameProgress(QVector<unsigned>* progresses);

public:
    void setWordsOnScreen(std::vector<std::string> text);
private:
    Ui::GameDialog *ui;
    QGroupBox *groupBoxes[4];
    QProgressBar *progressBars[4];
    Storage*  st;
    std::vector<std::string> words;
    bool isClient;
    unsigned currentProgress;
    QTimer* timer;
};

#endif // GAMEDIALOG_H

