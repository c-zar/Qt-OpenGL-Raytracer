/********************************************************************************
** Form generated from reading UI file 'Create_Cylinder.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_CYLINDER_H
#define UI_CREATE_CYLINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Create_Cylinder
{
public:

    void setupUi(QDialog *Create_Cylinder)
    {
        if (Create_Cylinder->objectName().isEmpty())
            Create_Cylinder->setObjectName(QString::fromUtf8("Create_Cylinder"));
        Create_Cylinder->resize(400, 300);

        retranslateUi(Create_Cylinder);

        QMetaObject::connectSlotsByName(Create_Cylinder);
    } // setupUi

    void retranslateUi(QDialog *Create_Cylinder)
    {
        Create_Cylinder->setWindowTitle(QApplication::translate("Create_Cylinder", "Create_Cylinder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Cylinder: public Ui_Create_Cylinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_CYLINDER_H
