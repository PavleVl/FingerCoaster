/********************************************************************************
** Form generated from reading UI file 'createroom.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEROOM_H
#define UI_CREATEROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_createroom
{
public:
    QPushButton *create_lobby_button;
    QRadioButton *rb_easy;
    QRadioButton *rb_medium;
    QRadioButton *rb_hard;
    QLabel *diff_label;
    QComboBox *num_players_cb;
    QLabel *num_players_label;
    QLabel *err_label;

    void setupUi(QDialog *createroom)
    {
        if (createroom->objectName().isEmpty())
            createroom->setObjectName(QString::fromUtf8("createroom"));
        createroom->resize(300, 200);
        create_lobby_button = new QPushButton(createroom);
        create_lobby_button->setObjectName(QString::fromUtf8("create_lobby_button"));
        create_lobby_button->setGeometry(QRect(100, 160, 100, 25));
        rb_easy = new QRadioButton(createroom);
        rb_easy->setObjectName(QString::fromUtf8("rb_easy"));
        rb_easy->setGeometry(QRect(20, 30, 90, 17));
        rb_medium = new QRadioButton(createroom);
        rb_medium->setObjectName(QString::fromUtf8("rb_medium"));
        rb_medium->setGeometry(QRect(20, 55, 90, 17));
        rb_hard = new QRadioButton(createroom);
        rb_hard->setObjectName(QString::fromUtf8("rb_hard"));
        rb_hard->setGeometry(QRect(20, 80, 90, 17));
        diff_label = new QLabel(createroom);
        diff_label->setObjectName(QString::fromUtf8("diff_label"));
        diff_label->setGeometry(QRect(10, 10, 120, 17));
        num_players_cb = new QComboBox(createroom);
        num_players_cb->addItem(QString());
        num_players_cb->addItem(QString());
        num_players_cb->addItem(QString());
        num_players_cb->setObjectName(QString::fromUtf8("num_players_cb"));
        num_players_cb->setGeometry(QRect(175, 30, 90, 25));
        num_players_label = new QLabel(createroom);
        num_players_label->setObjectName(QString::fromUtf8("num_players_label"));
        num_players_label->setGeometry(QRect(150, 10, 140, 17));
        err_label = new QLabel(createroom);
        err_label->setObjectName(QString::fromUtf8("err_label"));
        err_label->setGeometry(QRect(25, 135, 250, 17));
        err_label->setAlignment(Qt::AlignCenter);

        retranslateUi(createroom);

        QMetaObject::connectSlotsByName(createroom);
    } // setupUi

    void retranslateUi(QDialog *createroom)
    {
        createroom->setWindowTitle(QCoreApplication::translate("createroom", "Dialog", nullptr));
        create_lobby_button->setText(QCoreApplication::translate("createroom", "Enter Lobby", nullptr));
        rb_easy->setText(QCoreApplication::translate("createroom", "Easy", nullptr));
        rb_medium->setText(QCoreApplication::translate("createroom", "Medium", nullptr));
        rb_hard->setText(QCoreApplication::translate("createroom", "Hard", nullptr));
        diff_label->setText(QCoreApplication::translate("createroom", "Select Difficulty:", nullptr));
        num_players_cb->setItemText(0, QCoreApplication::translate("createroom", "1 player", nullptr));
        num_players_cb->setItemText(1, QCoreApplication::translate("createroom", "2 players", nullptr));
        num_players_cb->setItemText(2, QCoreApplication::translate("createroom", "3 players", nullptr));

        num_players_label->setText(QCoreApplication::translate("createroom", "Number of players:", nullptr));
        err_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class createroom: public Ui_createroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEROOM_H
