/********************************************************************************
** Form generated from reading UI file 'Create_Light.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_LIGHT_H
#define UI_CREATE_LIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Create_Light
{
public:

    void setupUi(QDialog *Create_Light)
    {
        if (Create_Light->objectName().isEmpty())
            Create_Light->setObjectName(QString::fromUtf8("Create_Light"));
        Create_Light->resize(400, 300);

        retranslateUi(Create_Light);

        QMetaObject::connectSlotsByName(Create_Light);
    } // setupUi

    void retranslateUi(QDialog *Create_Light)
    {
        Create_Light->setWindowTitle(QApplication::translate("Create_Light", "Create_Light", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Light: public Ui_Create_Light {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_LIGHT_H
