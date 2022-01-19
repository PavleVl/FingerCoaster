#include "Headers/scoreboard.h"
#include "ui_scoreboard.h"

Scoreboard::Scoreboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scoreboard)
{
    ui->setupUi(this);

    this->setWindowTitle(QString::fromStdString("Scoreboard"));



    auto *Scoreboard = new Model(this);
    Scoreboard->savedScoreboard = new ScoreboardBackend();

    QVector<QString> places;
    QVector<QString> wpm;
    QVector<QString> dates;
    QVector<QString> accuracy;

    wpm.fill(QString::fromStdString("-"),10);
    dates.fill(QString::fromStdString("-"),10);
    accuracy.fill(QString::fromStdString("-"),10);
    //Unosi se username u tabelu
    ui->vr_user->setText(QString::fromStdString(Scoreboard->savedScoreboard->giveUsername()));

    //Popunjavamo redna mesta
    for (int i=1; i<11; i++)
        places.append(QString::number(i) + QString::fromStdString("."));

   int index = 0;
   for(Result result : Scoreboard->savedScoreboard->giveResults()){
              wpm[index] = QString::number(result.giveWpm());
              dates[index] = QString::fromStdString(result.giveDate());
              accuracy[index] = QString::fromStdString(result.giveAccuracy());
              index++;
    }


    Scoreboard->populateData(places, dates, wpm, accuracy);

    ui->tableView->setModel(Scoreboard);

    ui->tableView->horizontalHeader()->setVisible(true);
}

Scoreboard::~Scoreboard()
{
    delete ui;
}

Model::Model(QObject *parent) : QAbstractTableModel(parent)
{
}

void Model::populateData(const QVector<QString> &place, const QVector<QString> &date, const QVector<QString> &wpm, const QVector<QString> &acc)
{
_place.clear();
_place = place.toList();
_date.clear();
_date = date.toList();
_wpm.clear();
_wpm = wpm.toList();
_acc.clear();
_acc = acc.toList();

return;
}

auto Model::rowCount(const QModelIndex &parent) const -> int
{
Q_UNUSED(parent);
  return _place.length();
}

auto Model::columnCount(const QModelIndex &parent) const -> int
{
Q_UNUSED(parent);
return 4;
}

auto Model::data(const QModelIndex &index, int role) const -> QVariant
{
if (!index.isValid() || role != Qt::DisplayRole) {
    return QVariant();
}
if (index.column() == 0) {
    return _place[index.row()];
} else if (index.column() == 1) {
    return _date[index.row()];
} else if (index.column() == 2) {
    return _wpm[index.row()];
} else if (index.column() == 3) {
    return _acc[index.row()];
}

return QVariant();
}

auto Model::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
    if (section == 0) {
        return QString(QString::fromStdString("Place"));
    } else if (section == 1) {
        return QString(QString::fromStdString("Date"));
    } else if (section == 2) {
        return QString(QString::fromStdString("WPM"));
    } else if (section == 3) {
        return QString(QString::fromStdString("Accuracy"));
    }

}
return QVariant();
}

