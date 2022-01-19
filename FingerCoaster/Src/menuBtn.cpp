#include "Headers/menuBtn.h"
#include <QFont>
#include <QPixmap>
menuBtn::menuBtn(QString text) {
  this->setText(text);
  this->resize(200, 100);
  this->setObjectName(QStringLiteral("exit"));
  QFont font;
  font.setBold(true);
  font.setPixelSize(50);
  this->setFont(font);
  this->setStyleSheet(QString::fromStdString(
      "background-color:green;border-style: outset;border-width: "
      "2px;border-radius: 10px;border-color: beige;font: bold 30px;padding: "
      "6px;"));
}
