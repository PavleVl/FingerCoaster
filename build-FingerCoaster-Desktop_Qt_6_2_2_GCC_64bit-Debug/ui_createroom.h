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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_createroom
{
public:
    QLabel *vr_key;
    QPushButton *create_key_button;
    QPushButton *create_lobby_button;

    void setupUi(QDialog *createroom)
    {
        if (createroom->objectName().isEmpty())
            createroom->setObjectName(QString::fromUtf8("createroom"));
        createroom->resize(300, 200);
        vr_key = new QLabel(createroom);
        vr_key->setObjectName(QString::fromUtf8("vr_key"));
        vr_key->setGeometry(QRect(110, 55, 80, 17));
        vr_key->setAlignment(Qt::AlignCenter);
        create_key_button = new QPushButton(createroom);
        create_key_button->setObjectName(QString::fromUtf8("create_key_button"));
        create_key_button->setGeometry(QRect(105, 20, 90, 25));
        create_lobby_button = new QPushButton(createroom);
        create_lobby_button->setObjectName(QString::fromUtf8("create_lobby_button"));
        create_lobby_button->setGeometry(QRect(200, 160, 89, 25));

        retranslateUi(createroom);

        QMetaObject::connectSlotsByName(createroom);
    } // setupUi

    void retranslateUi(QDialog *createroom)
    {
        createroom->setWindowTitle(QCoreApplication::translate("createroom", "Dialog", nullptr));
        vr_key->setText(QString());
        create_key_button->setText(QCoreApplication::translate("createroom", "Create Key", nullptr));
        create_lobby_button->setText(QCoreApplication::translate("createroom", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createroom: public Ui_createroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEROOM_H
