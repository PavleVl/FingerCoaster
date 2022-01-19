#include "Headers/enterusername.h"
#include "ui_enterusername.h"

enterUsername::enterUsername(QWidget* parent)
    : QDialog(parent), ui(new Ui::enterUsername) {
  ui->setupUi(this);

  this->setWindowTitle(QString::fromStdString("Welcome"));
  this->setObjectName(QString::fromStdString("PopUp"));
  this->setStyleSheet(
      QString::fromUtf8("#PopUp {border-image: url(:/images/prefix1/popup.jpg) "
                        "0 0 0 0 stretch stretch;}"));
  ui->label->setStyleSheet(QString::fromStdString("font-weight: bold"));
}

enterUsername::~enterUsername() {
  delete ui;
}

void enterUsername::on_pushButton_clicked() {
  QString username = ui->lineEdit->text();
  if (username.size() == 0) {
    ui->err_label->setText(QString::fromStdString("Username is required"));
    ui->err_label->setStyleSheet(QString::fromStdString(
        "QLabel {background-color: rgba(128,195,66,0.5); color: red;}"));
    return;
  }

  auto* scoreboardWrite = new ScoreboardBackend();
  std::string name = username.toStdString();
  scoreboardWrite->writeUsername(name);

  this->close();
}
