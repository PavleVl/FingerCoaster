#include "Headers/menuBtn.h"
#include <QFont>
#include <QPixmap>
menuBtn::menuBtn(QString text){
    this->setText(text);
    this->resize(300,100);
    QFont font;
    font.setBold(true);
    font.setPixelSize(50);
    setFont(font);
//    QPixmap pixmap(":/images/prefix1/exit.png");
//    QIcon ButtonIcon(pixmap);
//    this->setIcon(QIcon(ButtonIcon));
//    this->setIconSize(this->size());
}
