/********************************************************************************
** Form generated from reading UI file 'Triangle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLE_H
#define UI_TRIANGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Triangle
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Triangle)
    {
        if (Triangle->objectName().isEmpty())
            Triangle->setObjectName(QString::fromUtf8("Triangle"));
        Triangle->resize(288, 167);
        gridLayout = new QGridLayout(Triangle);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Triangle);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(Triangle);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(Triangle);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(Triangle);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(Triangle);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout->addWidget(doubleSpinBox, 1, 1, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(Triangle);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout->addWidget(doubleSpinBox_2, 1, 2, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(Triangle);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        gridLayout->addWidget(doubleSpinBox_3, 1, 3, 1, 1);

        label_5 = new QLabel(Triangle);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(Triangle);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));

        gridLayout->addWidget(doubleSpinBox_6, 2, 1, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(Triangle);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        gridLayout->addWidget(doubleSpinBox_5, 2, 2, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(Triangle);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));

        gridLayout->addWidget(doubleSpinBox_4, 2, 3, 1, 1);

        label_6 = new QLabel(Triangle);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(Triangle);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));

        gridLayout->addWidget(doubleSpinBox_7, 3, 1, 1, 1);

        doubleSpinBox_8 = new QDoubleSpinBox(Triangle);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));

        gridLayout->addWidget(doubleSpinBox_8, 3, 2, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(Triangle);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));

        gridLayout->addWidget(doubleSpinBox_9, 3, 3, 1, 1);

        buttonBox = new QDialogButtonBox(Triangle);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 4, 1, 1);


        retranslateUi(Triangle);

        QMetaObject::connectSlotsByName(Triangle);
    } // setupUi

    void retranslateUi(QDialog *Triangle)
    {
        Triangle->setWindowTitle(QApplication::translate("Triangle", "Dialog", nullptr));
        label->setText(QApplication::translate("Triangle", "x", nullptr));
        label_2->setText(QApplication::translate("Triangle", "y", nullptr));
        label_3->setText(QApplication::translate("Triangle", "z", nullptr));
        label_4->setText(QApplication::translate("Triangle", "V1", nullptr));
        label_5->setText(QApplication::translate("Triangle", "V2", nullptr));
        label_6->setText(QApplication::translate("Triangle", "V3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Triangle: public Ui_Triangle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLE_H
