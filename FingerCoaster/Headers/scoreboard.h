#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QMainWindow>
#include <QAbstractTableModel>
#include <QApplication>

#include <QDialog>
#include "../Scoreboard/ScoreboardBackend.hpp"
#include "../Result/Result.hpp"
//---------------
#include<iostream>

namespace Ui {
class Scoreboard;
}

class Model : public QAbstractTableModel
{
    Q_OBJECT

public:
    Model(QObject *parent = 0);
        //OVDE JE STAJAO Model::populateData
    void populateData(const QVector<QString> &place, const QVector<QString> &date, const QVector<int> &wpm, const QVector<float> &acc);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    ScoreboardBackend* savedScoreboard;
private:
    QVector<QString> tm_place;
    QVector<int> tm_wpm;
    QVector<QString> tm_date;
    QVector<float> tm_acc;


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
