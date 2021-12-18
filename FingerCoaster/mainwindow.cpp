#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QString> places;
    QList<int> wpm;

    for (int i=1; i<11; i++){
        places.append(QString::number(i) + ".");
        //Stoji samo zbog izgleda i bice vrv i string
        wpm.append(0);
    }
    // Uraditi dohvatanje iz fajla
    ui->label_ime->setText("Ovo se menja");

    Model *Scoreboard = new Model(this);

    Scoreboard->populateData(places,wpm);

    ui->tableView->setModel(Scoreboard);

    ui->tableView->horizontalHeader()->setVisible(true);
    //qDebug()<<ui->tableView->geometry();
//    ui->tableView->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}

Model::Model(QObject *parent) : QAbstractTableModel(parent)
{
}

void Model::populateData(const QList<QString> &place,const QList<int> &wpm)
{
    tm_place.clear();
    tm_place = place;
    tm_wpm.clear();
    tm_wpm = wpm;
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
    return 2;
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
