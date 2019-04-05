/********************************************************************************
** Form generated from reading UI file 'Create_Triangle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_TRIANGLE_H
#define UI_CREATE_TRIANGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Create_Triangle
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxV1X;
    QDoubleSpinBox *doubleSpinBoxV1Y;
    QDoubleSpinBox *doubleSpinBoxV1Z;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxV2X;
    QDoubleSpinBox *doubleSpinBoxV2Y;
    QDoubleSpinBox *doubleSpinBoxV2Z;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxV3X;
    QDoubleSpinBox *doubleSpinBoxV3Y;
    QDoubleSpinBox *doubleSpinBoxV3Z;
    QPushButton *btnOK;

    void setupUi(QDialog *Create_Triangle)
    {
        if (Create_Triangle->objectName().isEmpty())
            Create_Triangle->setObjectName(QString::fromUtf8("Create_Triangle"));
        Create_Triangle->resize(255, 135);
        gridLayout = new QGridLayout(Create_Triangle);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Create_Triangle);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(Create_Triangle);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(Create_Triangle);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(Create_Triangle);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBoxV1X = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV1X->setObjectName(QString::fromUtf8("doubleSpinBoxV1X"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBoxV1X->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV1X->setSizePolicy(sizePolicy1);
        doubleSpinBoxV1X->setMinimum(-1000.000000000000000);
        doubleSpinBoxV1X->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV1X, 1, 1, 1, 1);

        doubleSpinBoxV1Y = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV1Y->setObjectName(QString::fromUtf8("doubleSpinBoxV1Y"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxV1Y->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV1Y->setSizePolicy(sizePolicy1);
        doubleSpinBoxV1Y->setMinimum(-1000.000000000000000);
        doubleSpinBoxV1Y->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV1Y, 1, 2, 1, 1);

        doubleSpinBoxV1Z = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV1Z->setObjectName(QString::fromUtf8("doubleSpinBoxV1Z"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxV1Z->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV1Z->setSizePolicy(sizePolicy1);
        doubleSpinBoxV1Z->setMinimum(-1000.000000000000000);
        doubleSpinBoxV1Z->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV1Z, 1, 3, 1, 1);

        label_5 = new QLabel(Create_Triangle);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        doubleSpinBoxV2X = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV2X->setObjectName(QString::fromUtf8("doubleSpinBoxV2X"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxV2X->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV2X->setSizePolicy(sizePolicy1);
        doubleSpinBoxV2X->setMinimum(-1000.000000000000000);
        doubleSpinBoxV2X->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV2X, 2, 1, 1, 1);

        doubleSpinBoxV2Y = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV2Y->setObjectName(QString::fromUtf8("doubleSpinBoxV2Y"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxV2Y->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV2Y->setSizePolicy(sizePolicy1);
        doubleSpinBoxV2Y->setMinimum(-1000.000000000000000);
        doubleSpinBoxV2Y->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV2Y, 2, 2, 1, 1);

        doubleSpinBoxV2Z = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV2Z->setObjectName(QString::fromUtf8("doubleSpinBoxV2Z"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxV2Z->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV2Z->setSizePolicy(sizePolicy1);
        doubleSpinBoxV2Z->setMinimum(-1000.000000000000000);
        doubleSpinBoxV2Z->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV2Z, 2, 3, 1, 1);

        label_6 = new QLabel(Create_Triangle);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        doubleSpinBoxV3X = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV3X->setObjectName(QString::fromUtf8("doubleSpinBoxV3X"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxV3X->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV3X->setSizePolicy(sizePolicy1);
        doubleSpinBoxV3X->setMinimum(-1000.000000000000000);
        doubleSpinBoxV3X->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV3X, 3, 1, 1, 1);

        doubleSpinBoxV3Y = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV3Y->setObjectName(QString::fromUtf8("doubleSpinBoxV3Y"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxV3Y->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV3Y->setSizePolicy(sizePolicy1);
        doubleSpinBoxV3Y->setMinimum(-1000.000000000000000);
        doubleSpinBoxV3Y->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV3Y, 3, 2, 1, 1);

        doubleSpinBoxV3Z = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV3Z->setObjectName(QString::fromUtf8("doubleSpinBoxV3Z"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxV3Z->sizePolicy().hasHeightForWidth());
        doubleSpinBoxV3Z->setSizePolicy(sizePolicy1);
        doubleSpinBoxV3Z->setMinimum(-1000.000000000000000);
        doubleSpinBoxV3Z->setMaximum(1000.000000000000000);

        gridLayout->addWidget(doubleSpinBoxV3Z, 3, 3, 1, 1);

        btnOK = new QPushButton(Create_Triangle);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        sizePolicy1.setHeightForWidth(btnOK->sizePolicy().hasHeightForWidth());
        btnOK->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(btnOK, 4, 2, 1, 2);


        retranslateUi(Create_Triangle);

        QMetaObject::connectSlotsByName(Create_Triangle);
    } // setupUi

    void retranslateUi(QDialog *Create_Triangle)
    {
        Create_Triangle->setWindowTitle(QApplication::translate("Create_Triangle", "Create_Triangle", nullptr));
        label->setText(QApplication::translate("Create_Triangle", "x", nullptr));
        label_2->setText(QApplication::translate("Create_Triangle", "y", nullptr));
        label_3->setText(QApplication::translate("Create_Triangle", "z", nullptr));
        label_4->setText(QApplication::translate("Create_Triangle", "V1", nullptr));
        label_5->setText(QApplication::translate("Create_Triangle", "V2", nullptr));
        label_6->setText(QApplication::translate("Create_Triangle", "V3", nullptr));
        btnOK->setText(QApplication::translate("Create_Triangle", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Triangle: public Ui_Create_Triangle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_TRIANGLE_H
