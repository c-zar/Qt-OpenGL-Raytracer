/********************************************************************************
** Form generated from reading UI file 'Sphere.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPHERE_H
#define UI_SPHERE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Sphere
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_10;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_3;

    void setupUi(QDialog *Sphere)
    {
        if (Sphere->objectName().isEmpty())
            Sphere->setObjectName(QString::fromUtf8("Sphere"));
        Sphere->resize(446, 160);
        gridLayout = new QGridLayout(Sphere);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(Sphere);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 9, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(Sphere);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(doubleSpinBox_2, 9, 2, 1, 1);

        buttonBox = new QDialogButtonBox(Sphere);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy2);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 16, 4, 1, 1);

        label = new QLabel(Sphere);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label, 8, 1, 1, 1);

        label_7 = new QLabel(Sphere);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_7, 10, 1, 1, 2);

        doubleSpinBox_10 = new QDoubleSpinBox(Sphere);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_10->sizePolicy().hasHeightForWidth());
        doubleSpinBox_10->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(doubleSpinBox_10, 11, 1, 1, 1);

        label_2 = new QLabel(Sphere);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_2, 8, 2, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(Sphere);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        sizePolicy1.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(doubleSpinBox, 9, 1, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(Sphere);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(doubleSpinBox_3, 9, 3, 1, 1);

        label_3 = new QLabel(Sphere);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_3, 8, 3, 1, 1);


        retranslateUi(Sphere);
        QObject::connect(buttonBox, SIGNAL(accepted()), Sphere, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Sphere, SLOT(reject()));

        QMetaObject::connectSlotsByName(Sphere);
    } // setupUi

    void retranslateUi(QDialog *Sphere)
    {
        Sphere->setWindowTitle(QApplication::translate("Sphere", "Dialog", nullptr));
        label_4->setText(QApplication::translate("Sphere", "Center", nullptr));
        label->setText(QApplication::translate("Sphere", "x", nullptr));
        label_7->setText(QApplication::translate("Sphere", "Radius", nullptr));
        label_2->setText(QApplication::translate("Sphere", "y", nullptr));
        label_3->setText(QApplication::translate("Sphere", "z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sphere: public Ui_Sphere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHERE_H
