#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>
#include "../Server/Server.hpp"
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


public:
    void setWordsOnScreen(std::vector<std::string> text);
private:
    Ui::GameDialog *ui;
    Storage*  st;
    std::vector<std::string> words;
};

#endif // GAMEDIALOG_H

