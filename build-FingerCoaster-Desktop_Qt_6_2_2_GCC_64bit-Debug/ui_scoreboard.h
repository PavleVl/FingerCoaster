/********************************************************************************
** Form generated from reading UI file 'scoreboard.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREBOARD_H
#define UI_SCOREBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Scoreboard
{
public:
    QTableView *tableView;
    QLabel *usr;
    QLabel *vr_user;

    void setupUi(QDialog *Scoreboard)
    {
        if (Scoreboard->objectName().isEmpty())
            Scoreboard->setObjectName(QString::fromUtf8("Scoreboard"));
        Scoreboard->resize(410, 353);
        tableView = new QTableView(Scoreboard);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 410, 353));
        usr = new QLabel(Scoreboard);
        usr->setObjectName(QString::fromUtf8("usr"));
        usr->setGeometry(QRect(5, 330, 71, 17));
        vr_user = new QLabel(Scoreboard);
        vr_user->setObjectName(QString::fromUtf8("vr_user"));
        vr_user->setGeometry(QRect(85, 330, 110, 17));

        retranslateUi(Scoreboard);

        QMetaObject::connectSlotsByName(Scoreboard);
    } // setupUi

    void retranslateUi(QDialog *Scoreboard)
    {
        Scoreboard->setWindowTitle(QCoreApplication::translate("Scoreboard", "Dialog", nullptr));
        usr->setText(QCoreApplication::translate("Scoreboard", "Username:", nullptr));
        vr_user->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Scoreboard: public Ui_Scoreboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREBOARD_H
