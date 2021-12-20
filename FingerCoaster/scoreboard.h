#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QMainWindow>
#include <QAbstractTableModel>
#include <QApplication>

#include <QDialog>

namespace Ui {
class Scoreboard;
}

class Model : public QAbstractTableModel
{
    Q_OBJECT

public:
    Model(QObject *parent = 0);

    void populateData(const QList<QString> &place,const QList<int> &wpm);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
private:
    QList<QString> tm_place;
    QList<int> tm_wpm;

};


class Scoreboard : public QDialog
{
    Q_OBJECT

public:
    explicit Scoreboard(QWidget *parent = nullptr);
    ~Scoreboard();

private:
    Ui::Scoreboard *ui;
};

#endif // SCOREBOARD_H
