#include "../Headers/lobby.h"
#include <qlistview.h>
#include <QMovie>
#include <iostream>
#include <sstream>
#include "ui_lobby.h"

Lobby::Lobby(QWidget* parent)
    : QDialog(parent), ui(new Ui::Lobby), checkCloseFlag(false) {
  isClient = false;
  i = 0;
  ui->setupUi(this);
  this->setWindowTitle(QString::fromStdString("Lobby"));
  this->setObjectName(QString::fromStdString("PopUp"));
  this->setStyleSheet(
      QString::fromUtf8("#PopUp {border-image: url(:/images/prefix1/popup.jpg) "
                        "0 0 0 0 stretch stretch;}"));
  ui->label->setStyleSheet(QString::fromStdString("font-weight: bold"));
}

Lobby::~Lobby() {
  delete ui;
}

void Lobby::addPlayer(QString username) {
  players << username;
  i++;
  QString s = QString(QString::fromStdString("%1. %2")).arg(i).arg(username);
  ui->playerList->addItem(s);
}

void Lobby::onBtStartGameClicked() {
  checkCloseFlag = true;
  this->close();

  emit closeServerConnections();
  emit startGameForClients();
  emit setGameScene();
}

void Lobby::rewriteUsernames(QVector<QString>* usernames) {
  ui->playerList->clear();
  i = usernames->size();
  usernames->size();
  QString buff = QString::fromStdString("");
  for (int j = 0; j < usernames->size(); j++) {
    buff += QString::number(j + 1) + QString::fromStdString(". ") +
            usernames->at(j);
    ui->playerList->addItem(buff);
    buff = QString::fromStdString("");
  }
}

void Lobby::closeEvent(QCloseEvent* event) {
  if (checkCloseFlag)
    return;

  if (!isClient)
    emit popUpForcedClose();
  else
    emit joinPopupForcedClose();
}

void Lobby::setIsClient() {
  isClient = true;
  ui->btStartGame->hide();

  ui->label = new QLabel(this);
  auto* movie =
      new QMovie(QString::fromStdString(":/images/prefix1/loading.gif"));

  auto* gif_label = new QLabel(this);
  gif_label->setGeometry(155, 140, 40, 40);
  gif_label->setMovie(movie);
  movie->start();
}

void Lobby::dontShowLobby() {
  checkCloseFlag = true;
  this->close();
}

void Lobby::closeLobbyStartGame() {
  checkCloseFlag = true;
  this->close();
  emit startClientGame();
}
