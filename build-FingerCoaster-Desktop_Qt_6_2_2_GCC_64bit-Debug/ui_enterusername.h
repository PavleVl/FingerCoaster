/********************************************************************************
** Form generated from reading UI file 'enterusername.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERUSERNAME_H
#define UI_ENTERUSERNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_enterUsername
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *enterUsername)
    {
        if (enterUsername->objectName().isEmpty())
            enterUsername->setObjectName(QString::fromUtf8("enterUsername"));
        enterUsername->resize(300, 200);
        label = new QLabel(enterUsername);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 120, 25));
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(enterUsername);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 50, 120, 25));
        pushButton = new QPushButton(enterUsername);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 160, 120, 25));

        retranslateUi(enterUsername);

        QMetaObject::connectSlotsByName(enterUsername);
    } // setupUi

    void retranslateUi(QDialog *enterUsername)
    {
        enterUsername->setWindowTitle(QCoreApplication::translate("enterUsername", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("enterUsername", "Enter Username", nullptr));
        pushButton->setText(QCoreApplication::translate("enterUsername", "Save Username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enterUsername: public Ui_enterUsername {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERUSERNAME_H
