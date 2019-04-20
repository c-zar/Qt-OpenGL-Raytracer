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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Create_Cylinder
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBoxZ;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxX;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxY;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxX_2;
    QDoubleSpinBox *doubleSpinBoxY_2;
    QDoubleSpinBox *doubleSpinBoxZ_2;
    QDoubleSpinBox *doubleSpinBoxRadius;
    QLabel *label_7;
    QPushButton *btnOK;

    void setupUi(QDialog *Create_Cylinder)
    {
        if (Create_Cylinder->objectName().isEmpty())
            Create_Cylinder->setObjectName(QString::fromUtf8("Create_Cylinder"));
        Create_Cylinder->resize(300, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Create_Cylinder->sizePolicy().hasHeightForWidth());
        Create_Cylinder->setSizePolicy(sizePolicy);
        Create_Cylinder->setMinimumSize(QSize(300, 150));
        gridLayout = new QGridLayout(Create_Cylinder);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Create_Cylinder);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(Create_Cylinder);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        doubleSpinBoxZ = new QDoubleSpinBox(Create_Cylinder);
        doubleSpinBoxZ->setObjectName(QString::fromUtf8("doubleSpinBoxZ"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(doubleSpinBoxZ->sizePolicy().hasHeightForWidth());
        doubleSpinBoxZ->setSizePolicy(sizePolicy2);
        doubleSpinBoxZ->setMinimum(-1000.000000000000000);
        doubleSpinBoxZ->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxZ, 1, 3, 1, 1);

        label_4 = new QLabel(Create_Cylinder);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBoxX = new QDoubleSpinBox(Create_Cylinder);
        doubleSpinBoxX->setObjectName(QString::fromUtf8("doubleSpinBoxX"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxX->sizePolicy().hasHeightForWidth());
        doubleSpinBoxX->setSizePolicy(sizePolicy2);
        doubleSpinBoxX->setMinimum(-1000.000000000000000);
        doubleSpinBoxX->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxX, 1, 1, 1, 1);

        label_3 = new QLabel(Create_Cylinder);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        doubleSpinBoxY = new QDoubleSpinBox(Create_Cylinder);
        doubleSpinBoxY->setObjectName(QString::fromUtf8("doubleSpinBoxY"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxY->sizePolicy().hasHeightForWidth());
        doubleSpinBoxY->setSizePolicy(sizePolicy2);
        doubleSpinBoxY->setMinimum(-1000.000000000000000);
        doubleSpinBoxY->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxY, 1, 2, 1, 1);

        label_5 = new QLabel(Create_Cylinder);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        doubleSpinBoxX_2 = new QDoubleSpinBox(Create_Cylinder);
        doubleSpinBoxX_2->setObjectName(QString::fromUtf8("doubleSpinBoxX_2"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxX_2->sizePolicy().hasHeightForWidth());
        doubleSpinBoxX_2->setSizePolicy(sizePolicy2);
        doubleSpinBoxX_2->setMinimum(-1000.000000000000000);
        doubleSpinBoxX_2->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxX_2, 2, 1, 1, 1);

        doubleSpinBoxY_2 = new QDoubleSpinBox(Create_Cylinder);
        doubleSpinBoxY_2->setObjectName(QString::fromUtf8("doubleSpinBoxY_2"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxY_2->sizePolicy().hasHeightForWidth());
        doubleSpinBoxY_2->setSizePolicy(sizePolicy2);
        doubleSpinBoxY_2->setMinimum(-1000.000000000000000);
        doubleSpinBoxY_2->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxY_2, 2, 2, 1, 1);

        doubleSpinBoxZ_2 = new QDoubleSpinBox(Create_Cylinder);
        doubleSpinBoxZ_2->setObjectName(QString::fromUtf8("doubleSpinBoxZ_2"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxZ_2->sizePolicy().hasHeightForWidth());
        doubleSpinBoxZ_2->setSizePolicy(sizePolicy2);
        doubleSpinBoxZ_2->setMinimum(-1000.000000000000000);
        doubleSpinBoxZ_2->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxZ_2, 2, 3, 1, 1);

        doubleSpinBoxRadius = new QDoubleSpinBox(Create_Cylinder);
        doubleSpinBoxRadius->setObjectName(QString::fromUtf8("doubleSpinBoxRadius"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxRadius->sizePolicy().hasHeightForWidth());
        doubleSpinBoxRadius->setSizePolicy(sizePolicy2);
        doubleSpinBoxRadius->setMinimum(-1000.000000000000000);
        doubleSpinBoxRadius->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxRadius, 4, 1, 1, 1);

        label_7 = new QLabel(Create_Cylinder);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        btnOK = new QPushButton(Create_Cylinder);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        sizePolicy2.setHeightForWidth(btnOK->sizePolicy().hasHeightForWidth());
        btnOK->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(btnOK, 4, 3, 1, 1);


        retranslateUi(Create_Cylinder);

        QMetaObject::connectSlotsByName(Create_Cylinder);
    } // setupUi

    void retranslateUi(QDialog *Create_Cylinder)
    {
        Create_Cylinder->setWindowTitle(QApplication::translate("Create_Cylinder", "Create_Cylinder", nullptr));
        label->setText(QApplication::translate("Create_Cylinder", "x", nullptr));
        label_2->setText(QApplication::translate("Create_Cylinder", "y", nullptr));
        label_4->setText(QApplication::translate("Create_Cylinder", "Top", nullptr));
        label_3->setText(QApplication::translate("Create_Cylinder", "z", nullptr));
        label_5->setText(QApplication::translate("Create_Cylinder", "Bottom", nullptr));
        label_7->setText(QApplication::translate("Create_Cylinder", "Radius", nullptr));
        btnOK->setText(QApplication::translate("Create_Cylinder", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Cylinder: public Ui_Create_Cylinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_CYLINDER_H
