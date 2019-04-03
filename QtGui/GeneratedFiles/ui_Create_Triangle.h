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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Create_Triangle
{
public:
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxV3Z;
    QDoubleSpinBox *doubleSpinBoxV1X;
    QDoubleSpinBox *doubleSpinBoxV1Z;
    QDoubleSpinBox *doubleSpinBoxV2Z;
    QDoubleSpinBox *doubleSpinBoxV3Y;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxV1Y;
    QDoubleSpinBox *doubleSpinBoxV2Y;
    QDoubleSpinBox *doubleSpinBoxV3X;
    QDoubleSpinBox *doubleSpinBoxV2X;
    QLabel *label_4;
    QPushButton *btnOK;

    void setupUi(QDialog *Create_Triangle)
    {
        if (Create_Triangle->objectName().isEmpty())
            Create_Triangle->setObjectName(QString::fromUtf8("Create_Triangle"));
        Create_Triangle->resize(400, 300);
        label = new QLabel(Create_Triangle);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(58, 10, 98, 33));
        doubleSpinBoxV3Z = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV3Z->setObjectName(QString::fromUtf8("doubleSpinBoxV3Z"));
        doubleSpinBoxV3Z->setGeometry(QRect(268, 142, 98, 39));
        doubleSpinBoxV1X = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV1X->setObjectName(QString::fromUtf8("doubleSpinBoxV1X"));
        doubleSpinBoxV1X->setGeometry(QRect(58, 50, 98, 39));
        doubleSpinBoxV1Z = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV1Z->setObjectName(QString::fromUtf8("doubleSpinBoxV1Z"));
        doubleSpinBoxV1Z->setGeometry(QRect(268, 50, 98, 39));
        doubleSpinBoxV2Z = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV2Z->setObjectName(QString::fromUtf8("doubleSpinBoxV2Z"));
        doubleSpinBoxV2Z->setGeometry(QRect(268, 96, 98, 39));
        doubleSpinBoxV3Y = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV3Y->setObjectName(QString::fromUtf8("doubleSpinBoxV3Y"));
        doubleSpinBoxV3Y->setGeometry(QRect(163, 142, 98, 39));
        label_6 = new QLabel(Create_Triangle);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 142, 31, 39));
        label_2 = new QLabel(Create_Triangle);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(163, 10, 98, 33));
        label_3 = new QLabel(Create_Triangle);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(268, 10, 98, 33));
        label_5 = new QLabel(Create_Triangle);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 96, 31, 39));
        doubleSpinBoxV1Y = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV1Y->setObjectName(QString::fromUtf8("doubleSpinBoxV1Y"));
        doubleSpinBoxV1Y->setGeometry(QRect(163, 50, 98, 39));
        doubleSpinBoxV2Y = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV2Y->setObjectName(QString::fromUtf8("doubleSpinBoxV2Y"));
        doubleSpinBoxV2Y->setGeometry(QRect(163, 96, 98, 39));
        doubleSpinBoxV3X = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV3X->setObjectName(QString::fromUtf8("doubleSpinBoxV3X"));
        doubleSpinBoxV3X->setGeometry(QRect(58, 142, 98, 39));
        doubleSpinBoxV2X = new QDoubleSpinBox(Create_Triangle);
        doubleSpinBoxV2X->setObjectName(QString::fromUtf8("doubleSpinBoxV2X"));
        doubleSpinBoxV2X->setGeometry(QRect(58, 96, 98, 39));
        label_4 = new QLabel(Create_Triangle);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 50, 31, 39));
        btnOK = new QPushButton(Create_Triangle);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(220, 230, 145, 42));

        retranslateUi(Create_Triangle);

        QMetaObject::connectSlotsByName(Create_Triangle);
    } // setupUi

    void retranslateUi(QDialog *Create_Triangle)
    {
        Create_Triangle->setWindowTitle(QApplication::translate("Create_Triangle", "Create_Triangle", nullptr));
        label->setText(QApplication::translate("Create_Triangle", "x", nullptr));
        label_6->setText(QApplication::translate("Create_Triangle", "V3", nullptr));
        label_2->setText(QApplication::translate("Create_Triangle", "y", nullptr));
        label_3->setText(QApplication::translate("Create_Triangle", "z", nullptr));
        label_5->setText(QApplication::translate("Create_Triangle", "V2", nullptr));
        label_4->setText(QApplication::translate("Create_Triangle", "V1", nullptr));
        btnOK->setText(QApplication::translate("Create_Triangle", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create_Triangle: public Ui_Create_Triangle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_TRIANGLE_H
