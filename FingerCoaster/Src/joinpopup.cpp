#include "Headers/joinpopup.h"
#include <arpa/inet.h>
#include "Headers/configuration.h"
#include "ui_joinpopup.h"

JoinPopUp::JoinPopUp(QWidget* parent) : QDialog(parent), ui(new Ui::JoinPopUp) {
  ui->setupUi(this);

  this->setWindowTitle(QString::fromStdString("Join room"));
  this->setObjectName(QString::fromStdString("PopUp"));
  this->setStyleSheet(
      QString::fromUtf8("#PopUp {border-image: url(:/images/prefix1/popup.jpg) "
                        "0 0 0 0 stretch stretch;}"));
  ui->key->setStyleSheet(QString::fromStdString("font-weight: bold"));

  if (ui->joinButton->isChecked())
    onJoinButtonClicked();
}

JoinPopUp::~JoinPopUp() {
  delete ui;
}

auto JoinPopUp::isValidIp4Address(const std::string& str) -> bool {
  struct sockaddr_in sa;
  int result = inet_pton(AF_INET, str.c_str(), &(sa.sin_addr));
  return result != 0;
}

auto JoinPopUp::isValidPort(int port) -> bool {
  if (port >= 0 && port <= 65535)
    return true;
  return false;
}

void JoinPopUp::onJoinButtonClicked() {
  QString key = ui->labelInsertKey->text();
  QStringList list = key.split(QString::fromStdString(":"));
  if (list.size() < 2) {
    ui->lMessage->setText(
        QString::fromStdString("IP address and port is needed"));
    ui->lMessage->setStyleSheet(QString::fromStdString(
        "QLabel {background-color: rgba(128,195,66,0.5); color: red;}"));
    return;
  }
  bool isIpAddr = isValidIp4Address(list[0].toStdString());
  int isPort = list[1].toInt();
  bool isVPort = isValidPort(isPort);
  if (!isIpAddr) {
    ui->lMessage->setText(QString::fromStdString("IPv4 address is not valid"));
    ui->lMessage->setStyleSheet(QString::fromStdString(
        "QLabel {background-color: rgba(128,195,66,0.5); color: red;}"));
  } else if (!isVPort) {
    ui->lMessage->setText(QString::fromStdString("Port not valid"));
    ui->lMessage->setStyleSheet(QString::fromStdString(
        "QLabel {background-color: rgba(128,195,66,0.5); color: red;}"));
  } else {
    ui->lMessage->setText(QString::fromStdString("Client is connected."));
    this->close();
    emit startClient(key);
    emit openLobby();
  }
}
