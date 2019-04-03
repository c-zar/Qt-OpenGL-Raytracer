/********************************************************************************
** Form generated from reading UI file 'Create_Sphere.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_SPHERE_H
#define UI_CREATE_SPHERE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Create_Sphere
{
public:
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxY;
    QLabel *label_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxX;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxZ;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBoxRadius;
    QPushButton *btnOK;

    void setupUi(QDialog *Create_Sphere)
    {
        if (Create_Sphere->objectName().isEmpty())
            Create_Sphere->setObjectName(QString::fromUtf8("Create_Sphere"));
        Create_Sphere->resize(400, 142);
        label_3 = new QLabel(Create_Sphere);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(275, 15, 108, 11));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        doubleSpinBoxY = new QDoubleSpinBox(Create_Sphere);
        doubleSpinBoxY->setObjectName(QString::fromUtf8("doubleSpinBoxY"));
        doubleSpinBoxY->setGeometry(QRect(163, 35, 107, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBoxY->sizePolicy().hasHeightForWidth());
        doubleSpinBoxY->setSizePolicy(sizePolicy1);
        label_2 = new QLabel(Create_Sphere);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(163, 15, 107, 11));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_4 = new QLabel(Create_Sphere);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(18, 35, 27, 16));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        doubleSpinBoxX = new QDoubleSpinBox(Create_Sphere);
        doubleSpinBoxX->setObjectName(QString::fromUtf8("doubleSpinBoxX"));
        doubleSpinBoxX->setGeometry(QRect(50, 35, 108, 16));
        sizePolicy1.setHeightForWidth(doubleSpinBoxX->sizePolicy().hasHeightForWidth());
        doubleSpinBoxX->setSizePolicy(sizePolicy1);
        label = new QLabel(Create_Sphere);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 15, 5, 11));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        doubleSpinBoxZ = new QDoubleSpinBox(Create_Sphere);
        doubleSpinBoxZ->setObjectName(QString::fromUtf8("doubleSpinBoxZ"));
        doubleSpinBoxZ->setGeometry(QRect(275, 35, 108, 16));
        sizePolicy1.setHeightForWidth(doubleSpinBoxZ->sizePolicy().hasHeightForWidth());
        doubleSpinBoxZ->setSizePolicy(sizePolicy1);
        label_7 = new QLabel(Create_Sphere);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 60, 27, 11));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        doubleSpinBoxRadius = new QDoubleSpinBox(Create_Sphere);
        doubleSpinBoxRadius->setObjectName(QString::fromUtf8("doubleSpinBoxRadius"));
        doubleSpinBoxRadius->setGeometry(QRect(50, 80, 108, 16));
        sizePolicy1.setHeightForWidth(doubleSpinBoxRadius->sizePolicy().hasHeightForWidth());
        doubleSpinBoxRadius->setSizePolicy(sizePolicy1);
        btnOK = new QPushButton(Create_Sphere);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(300, 110, 91, 19));

        retranslateUi(Create_Sphere);

        QMetaObject::connectSlotsByName(Create_Sphere);
    } // setupUi

    void retranslateUi(QDialog *Create_Sphere)
    {
        Create_Sphere->setWindowTitle(QApplication::translate("Create_Sphere", "Create_Sphere", nullptr));
        label_3->setText(QApplication::translate("Create_Sphere", "z", nullptr));
        label_2->setText(QApplication::translate("Create_Sphere", "y", nullptr));
        label_4->setText(QApplication::translate("Create_Sphere", "Center", nullptr));
        label->setText(QApplication::translate("Create_Sphere", "x", nullptr));
        label_7->setText(QApplication::translate("Create_Sphere", "Radius", nullptr));
        btnOK->setText(QApplication::translate("Create_Sphere", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Sphere: public Ui_Create_Sphere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_SPHERE_H
