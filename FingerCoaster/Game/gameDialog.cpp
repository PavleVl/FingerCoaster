#include "Game/gameDialog.h"
#include "ui_gamedialog.h"


#define MAX_CHARS (100)

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog),
    isClient(false),
    currentProgress(0),
    currentPosition(0),
    currentWpm(0),
    totalCharacters(0),
    totalTypedChars(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Let's play the game");
    this->setObjectName("GameWindow");
    this->setStyleSheet(QString::fromUtf8("#GameWindow {border-image: url(:/images/prefix1/board.jpeg) 0 0 0 0 stretch stretch;}"));

    ui->pb1->setObjectName("QProgressBar1");
    ui->pb2->setObjectName("QProgressBar2");
    ui->pb3->setObjectName("QProgressBar3");
    ui->pb4->setObjectName("QProgressBar4");

    ui->pb1->setStyleSheet(QString::fromUtf8("#QProgressBar1 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->pb2->setStyleSheet(QString::fromUtf8("#QProgressBar2 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->pb3->setStyleSheet(QString::fromUtf8("#QProgressBar3 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));
    ui->pb4->setStyleSheet(QString::fromUtf8("#QProgressBar4 {border: 2px solid grey;border-radius: 5px;background-color: #00FF00;}"));

    ui->lineEdit->setObjectName("lEdit");
    ui->lineEdit->setStyleSheet(QString::fromUtf8("#lEdit {border: 2px solid grey;border-radius: 5px}"));
    ui->lwText->setStyleSheet(QString::fromUtf8("#lwText {border: 2px solid grey;border-radius: 5px}"));
    ui->lwText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->lwText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->lineEdit->installEventFilter(this);
    //Grouping groupBoxes
    groupBoxes[0] = ui->gb1;
    groupBoxes[1] = ui->gb2;
    groupBoxes[2] = ui->gb3;
    groupBoxes[3] = ui->gb4;

    //Grouping
    progressBars[0] = ui->pb1;
    progressBars[1] = ui->pb2;
    progressBars[2] = ui->pb3;
    progressBars[3] = ui->pb4;

    ui->lwText->setAttribute(Qt::WA_StyledBackground, true);
    ui->lwText->setStyleSheet("QListView::item:selected { background: palette(Highlight) }");

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()),Qt::DirectConnection);
    timer->start(1000);


    time(&startTime);
}

void GameDialog::setWordsOnScreen(std::vector<std::string> text){
    words = text;
    for(auto& word:text){
        ui->lwText->addItem(QString::fromStdString(word));
    }
}

GameDialog::~GameDialog()
{
    delete ui;
}

void GameDialog::cmpWords(){
    QString currentTypedWord = ui->lineEdit->text();
    QString currentCmpWord = ui->lwText->item(currentPosition)->text();

    totalTypedChars+=ui->lwText->item(currentPosition)->text().size();

    QBrush brush;
    if(currentTypedWord.compare(currentCmpWord) == 0){
        brush.setColor(Qt::green);
        ui->lwText->item(currentPosition)->setHidden(true);
        ui->lineEdit->clear();

        totalCharacters += words[currentPosition].size();
        currentPosition++;

        if(currentPosition > words.size())
            saveResult();

        currentProgress =(((float)currentPosition) / words.size()) * 100;
    }


    calculateWpm();
}


bool GameDialog::eventFilter(QObject* obj,QEvent* event){
    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Space){
            cmpWords();
            return true;
        }
        else{
            return false;
            }
    }

    return QObject::eventFilter(obj,event);
}

void GameDialog::closeEvent(QCloseEvent *){
    emit gameDialogClosing();

    if(!isClient){
       emit shutdownServer();
    }
}

void GameDialog::populateGame(QVector<QString>* usernames){

    int i = 0;
    for(;i<usernames->size();i++)
        groupBoxes[i]->setTitle(usernames->at(i));

    while(i <= 3){
        groupBoxes[i]->hide();
        progressBars[i]->hide();
        i++;
    }
}

void GameDialog::timeoutSlot(){
    ui->pb1->setValue(currentProgress);
    emit updateProgress(currentProgress);
}

void GameDialog::updateCurGameProgress(QVector<unsigned>* progresess){

    for(int i=0;i<progresess->size();i++){
        progressBars[i]->setValue(progresess->at(i));
    }
}

void GameDialog::calculateWpm(){

    time_t endTime;
    time(&endTime);

    unsigned seconds = (endTime - startTime);

    currentWpm = (totalCharacters/5.0)/(seconds/60.0);
    //You update on label here
    ui->label->setText("Current WPM: " + QString::number(currentWpm));
}

void GameDialog::saveResult(){

    ScoreboardBackend sc;

    time_t rawTime;
    struct tm *info;
    time(&rawTime);
    info = localtime(&rawTime);

    std::string date = "";
    date.append(std::to_string(info->tm_mday));
    date.append(":");
    date.append(std::to_string(info->tm_mon));
    date.append(":");
    date.append(std::to_string(info->tm_year));

    Result rs(date,currentWpm,totalCharacters,totalTypedChars,"");

    sc.updateScoreboard(rs);
}
