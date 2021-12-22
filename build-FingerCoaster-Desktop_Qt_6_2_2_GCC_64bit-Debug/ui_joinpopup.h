/********************************************************************************
** Form generated from reading UI file 'joinpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOINPOPUP_H
#define UI_JOINPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_JoinPopUp
{
public:
    QLabel *key;
    QLabel *vr_key;
    QPushButton *joinButton;

    void setupUi(QDialog *JoinPopUp)
    {
        if (JoinPopUp->objectName().isEmpty())
            JoinPopUp->setObjectName(QString::fromUtf8("JoinPopUp"));
        JoinPopUp->resize(300, 200);
        key = new QLabel(JoinPopUp);
        key->setObjectName(QString::fromUtf8("key"));
        key->setGeometry(QRect(10, 50, 31, 17));
        vr_key = new QLabel(JoinPopUp);
        vr_key->setObjectName(QString::fromUtf8("vr_key"));
        vr_key->setGeometry(QRect(50, 50, 175, 17));
        joinButton = new QPushButton(JoinPopUp);
        joinButton->setObjectName(QString::fromUtf8("joinButton"));
        joinButton->setGeometry(QRect(200, 165, 89, 25));

        retranslateUi(JoinPopUp);

        QMetaObject::connectSlotsByName(JoinPopUp);
    } // setupUi

    void retranslateUi(QDialog *JoinPopUp)
    {
        JoinPopUp->setWindowTitle(QCoreApplication::translate("JoinPopUp", "Dialog", nullptr));
        key->setText(QCoreApplication::translate("JoinPopUp", "Key :", nullptr));
        vr_key->setText(QString());
        joinButton->setText(QCoreApplication::translate("JoinPopUp", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JoinPopUp: public Ui_JoinPopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINPOPUP_H
