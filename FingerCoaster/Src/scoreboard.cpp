#include "Headers/scoreboard.h"
#include "ui_scoreboard.h"

Scoreboard::Scoreboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scoreboard)
{
    ui->setupUi(this);

    this->setWindowTitle("Scoreboard");


    Model *Scoreboard = new Model(this);
    Scoreboard->savedScoreboard = new ScoreboardBackend();

    QVector<QString> places;
    QVector<int> wpm;
    wpm.fill(0,10);

    //Prvi put username
    if(Scoreboard->savedScoreboard->isFirstTimeCheck()){
        //TODO
        //SIGNAL
        //SIgnal that asks you to input the username
    }

    //Unosi se username u tabelu
    ui->vr_user->setText(QString::fromStdString(Scoreboard->savedScoreboard->giveUsername()));

    //Popunjavamo redna mesta
    for (int i=1; i<11; i++)
        places.append(QString::number(i) + ".");

   int index = 0;
   for(Result result : Scoreboard->savedScoreboard->giveResults()){
              wpm[index] = result.giveWpm();
              index++;
    }

    Scoreboard->populateData(places,wpm);

    ui->tableView->setModel(Scoreboard);

    ui->tableView->horizontalHeader()->setVisible(true);
    //    ui->tableView->show();


}
    /*
    Ui::MainWindow* MainWindow::getU(){
    return ui;
    }*/



Scoreboard::~Scoreboard()
{
    delete ui;
}

Model::Model(QObject *parent) : QAbstractTableModel(parent)
{
}

void Model::populateData(const QVector<QString> &place,const QVector<int> &wpm)
{
tm_place.clear();
tm_place = place.toList();
tm_wpm.clear();
tm_wpm = wpm.toList();
return;
}

int Model::rowCount(const QModelIndex &parent) const
{
Q_UNUSED(parent);
return tm_place.length();
}

int Model::columnCount(const QModelIndex &parent) const
{
Q_UNUSED(parent);
return 4;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
if (!index.isValid() || role != Qt::DisplayRole) {
    return QVariant();
}
if (index.column() == 0) {
    return tm_place[index.row()];
} else if (index.column() == 1) {
    return tm_wpm[index.row()];
}
return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
    if (section == 0) {
        return QString("Place");
    } else if (section == 1) {
        return QString("WPM");
    }
}
return QVariant();
}
