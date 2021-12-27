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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_JoinPopUp
{
public:
    QLabel *key;
    QPushButton *joinButton;
    QLineEdit *labelInsertKey;
    QLabel *lMessage;

    void setupUi(QDialog *JoinPopUp)
    {
        if (JoinPopUp->objectName().isEmpty())
            JoinPopUp->setObjectName(QString::fromUtf8("JoinPopUp"));
        JoinPopUp->resize(320, 130);
        key = new QLabel(JoinPopUp);
        key->setObjectName(QString::fromUtf8("key"));
        key->setGeometry(QRect(10, 20, 31, 25));
        joinButton = new QPushButton(JoinPopUp);
        joinButton->setObjectName(QString::fromUtf8("joinButton"));
        joinButton->setGeometry(QRect(220, 90, 90, 25));
        labelInsertKey = new QLineEdit(JoinPopUp);
        labelInsertKey->setObjectName(QString::fromUtf8("labelInsertKey"));
        labelInsertKey->setGeometry(QRect(60, 20, 171, 25));
        lMessage = new QLabel(JoinPopUp);
        lMessage->setObjectName(QString::fromUtf8("lMessage"));
        lMessage->setGeometry(QRect(10, 90, 200, 25));

        retranslateUi(JoinPopUp);

        QMetaObject::connectSlotsByName(JoinPopUp);
    } // setupUi

    void retranslateUi(QDialog *JoinPopUp)
    {
        JoinPopUp->setWindowTitle(QCoreApplication::translate("JoinPopUp", "Dialog", nullptr));
        key->setText(QCoreApplication::translate("JoinPopUp", "Key :", nullptr));
        joinButton->setText(QCoreApplication::translate("JoinPopUp", "Join", nullptr));
        labelInsertKey->setText(QString());
        lMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JoinPopUp: public Ui_JoinPopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOINPOPUP_H
