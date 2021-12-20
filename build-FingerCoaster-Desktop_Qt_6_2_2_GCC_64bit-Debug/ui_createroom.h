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

QT_BEGIN_NAMESPACE

class Ui_createroom
{
public:

    void setupUi(QDialog *createroom)
    {
        if (createroom->objectName().isEmpty())
            createroom->setObjectName(QString::fromUtf8("createroom"));
        createroom->resize(300, 200);

        retranslateUi(createroom);

        QMetaObject::connectSlotsByName(createroom);
    } // setupUi

    void retranslateUi(QDialog *createroom)
    {
        createroom->setWindowTitle(QCoreApplication::translate("createroom", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createroom: public Ui_createroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEROOM_H
