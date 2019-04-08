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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Create_Sphere
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxX;
    QDoubleSpinBox *doubleSpinBoxY;
    QDoubleSpinBox *doubleSpinBoxZ;
    QDoubleSpinBox *doubleSpinBoxRadius;
    QLabel *label_7;
    QPushButton *btnOK;

    void setupUi(QDialog *Create_Sphere)
    {
        if (Create_Sphere->objectName().isEmpty())
            Create_Sphere->setObjectName(QString::fromUtf8("Create_Sphere"));
        Create_Sphere->resize(300, 115);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Create_Sphere->sizePolicy().hasHeightForWidth());
        Create_Sphere->setSizePolicy(sizePolicy);
        Create_Sphere->setMinimumSize(QSize(300, 115));
        gridLayout = new QGridLayout(Create_Sphere);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Create_Sphere);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(Create_Sphere);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(Create_Sphere);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(Create_Sphere);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBoxX = new QDoubleSpinBox(Create_Sphere);
        doubleSpinBoxX->setObjectName(QString::fromUtf8("doubleSpinBoxX"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(doubleSpinBoxX->sizePolicy().hasHeightForWidth());
        doubleSpinBoxX->setSizePolicy(sizePolicy3);
        doubleSpinBoxX->setMinimum(-1000.000000000000000);
        doubleSpinBoxX->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxX, 1, 1, 1, 1);

        doubleSpinBoxY = new QDoubleSpinBox(Create_Sphere);
        doubleSpinBoxY->setObjectName(QString::fromUtf8("doubleSpinBoxY"));
        sizePolicy3.setHeightForWidth(doubleSpinBoxY->sizePolicy().hasHeightForWidth());
        doubleSpinBoxY->setSizePolicy(sizePolicy3);
        doubleSpinBoxY->setMinimum(-1000.000000000000000);
        doubleSpinBoxY->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxY, 1, 2, 1, 1);

        doubleSpinBoxZ = new QDoubleSpinBox(Create_Sphere);
        doubleSpinBoxZ->setObjectName(QString::fromUtf8("doubleSpinBoxZ"));
        sizePolicy3.setHeightForWidth(doubleSpinBoxZ->sizePolicy().hasHeightForWidth());
        doubleSpinBoxZ->setSizePolicy(sizePolicy3);
        doubleSpinBoxZ->setMinimum(-1000.000000000000000);
        doubleSpinBoxZ->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxZ, 1, 3, 1, 1);

        doubleSpinBoxRadius = new QDoubleSpinBox(Create_Sphere);
        doubleSpinBoxRadius->setObjectName(QString::fromUtf8("doubleSpinBoxRadius"));
        sizePolicy3.setHeightForWidth(doubleSpinBoxRadius->sizePolicy().hasHeightForWidth());
        doubleSpinBoxRadius->setSizePolicy(sizePolicy3);
        doubleSpinBoxRadius->setMinimum(-1000.000000000000000);
        doubleSpinBoxRadius->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxRadius, 3, 1, 1, 1);

        label_7 = new QLabel(Create_Sphere);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        btnOK = new QPushButton(Create_Sphere);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        sizePolicy3.setHeightForWidth(btnOK->sizePolicy().hasHeightForWidth());
        btnOK->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(btnOK, 3, 3, 1, 1);


        retranslateUi(Create_Sphere);

        QMetaObject::connectSlotsByName(Create_Sphere);
    } // setupUi

    void retranslateUi(QDialog *Create_Sphere)
    {
        Create_Sphere->setWindowTitle(QApplication::translate("Create_Sphere", "Create_Sphere", nullptr));
        label->setText(QApplication::translate("Create_Sphere", "x", nullptr));
        label_2->setText(QApplication::translate("Create_Sphere", "y", nullptr));
        label_3->setText(QApplication::translate("Create_Sphere", "z", nullptr));
        label_4->setText(QApplication::translate("Create_Sphere", "Center", nullptr));
        label_7->setText(QApplication::translate("Create_Sphere", "Radius", nullptr));
        btnOK->setText(QApplication::translate("Create_Sphere", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Sphere: public Ui_Create_Sphere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_SPHERE_H
