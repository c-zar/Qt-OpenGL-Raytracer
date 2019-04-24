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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Create_Light
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxX;
    QLabel *label_2;
    QPushButton *btnOK;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxY;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxZ;
    QLabel *label_5;

    void setupUi(QDialog *Create_Light)
    {
        if (Create_Light->objectName().isEmpty())
            Create_Light->setObjectName(QString::fromUtf8("Create_Light"));
        Create_Light->resize(300, 115);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Create_Light->sizePolicy().hasHeightForWidth());
        Create_Light->setSizePolicy(sizePolicy);
        Create_Light->setMinimumSize(QSize(300, 115));
        gridLayout = new QGridLayout(Create_Light);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Create_Light);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        doubleSpinBoxX = new QDoubleSpinBox(Create_Light);
        doubleSpinBoxX->setObjectName(QString::fromUtf8("doubleSpinBoxX"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(doubleSpinBoxX->sizePolicy().hasHeightForWidth());
        doubleSpinBoxX->setSizePolicy(sizePolicy2);
        doubleSpinBoxX->setMinimum(-1000.000000000000000);
        doubleSpinBoxX->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxX, 1, 1, 1, 1);

        label_2 = new QLabel(Create_Light);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        btnOK = new QPushButton(Create_Light);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        sizePolicy2.setHeightForWidth(btnOK->sizePolicy().hasHeightForWidth());
        btnOK->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(btnOK, 3, 3, 1, 1);

        label_4 = new QLabel(Create_Light);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBoxY = new QDoubleSpinBox(Create_Light);
        doubleSpinBoxY->setObjectName(QString::fromUtf8("doubleSpinBoxY"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxY->sizePolicy().hasHeightForWidth());
        doubleSpinBoxY->setSizePolicy(sizePolicy2);
        doubleSpinBoxY->setMinimum(-1000.000000000000000);
        doubleSpinBoxY->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxY, 1, 2, 1, 1);

        label_3 = new QLabel(Create_Light);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        doubleSpinBoxZ = new QDoubleSpinBox(Create_Light);
        doubleSpinBoxZ->setObjectName(QString::fromUtf8("doubleSpinBoxZ"));
        sizePolicy2.setHeightForWidth(doubleSpinBoxZ->sizePolicy().hasHeightForWidth());
        doubleSpinBoxZ->setSizePolicy(sizePolicy2);
        doubleSpinBoxZ->setMinimum(-1000.000000000000000);
        doubleSpinBoxZ->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxZ, 1, 3, 1, 1);

        label_5 = new QLabel(Create_Light);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy5);
        label_5->setWordWrap(true);

        gridLayout->addWidget(label_5, 3, 0, 1, 3);


        retranslateUi(Create_Light);

        QMetaObject::connectSlotsByName(Create_Light);
    } // setupUi

    void retranslateUi(QDialog *Create_Light)
    {
        Create_Light->setWindowTitle(QApplication::translate("Create_Light", "Create_Light", nullptr));
        label->setText(QApplication::translate("Create_Light", "x", nullptr));
        label_2->setText(QApplication::translate("Create_Light", "y", nullptr));
        btnOK->setText(QApplication::translate("Create_Light", "OK", nullptr));
        label_4->setText(QApplication::translate("Create_Light", "Origin", nullptr));
        label_3->setText(QApplication::translate("Create_Light", "z", nullptr));
        label_5->setText(QApplication::translate("Create_Light", "The strength of the light is determined by the alpha channel (Strength/Distance^2)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Light: public Ui_Create_Light {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_LIGHT_H
