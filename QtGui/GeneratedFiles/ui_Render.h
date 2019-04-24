/********************************************************************************
** Form generated from reading UI file 'Render.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDER_H
#define UI_RENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Render
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBoxProjectionType;
    QComboBox *comboBoxRenderMode;
    QSpinBox *spinBoxHeight;
    QLabel *label_3;
    QLabel *label_2;
    QSpinBox *spinBoxWidth;
    QPushButton *btnOK;

    void setupUi(QDialog *Render)
    {
        if (Render->objectName().isEmpty())
            Render->setObjectName(QString::fromUtf8("Render"));
        Render->resize(239, 93);
        gridLayout = new QGridLayout(Render);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBoxProjectionType = new QComboBox(Render);
        comboBoxProjectionType->addItem(QString());
        comboBoxProjectionType->addItem(QString());
        comboBoxProjectionType->setObjectName(QString::fromUtf8("comboBoxProjectionType"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxProjectionType->sizePolicy().hasHeightForWidth());
        comboBoxProjectionType->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxProjectionType, 3, 0, 1, 1);

        comboBoxRenderMode = new QComboBox(Render);
        comboBoxRenderMode->addItem(QString());
        comboBoxRenderMode->addItem(QString());
        comboBoxRenderMode->addItem(QString());
        comboBoxRenderMode->addItem(QString());
        comboBoxRenderMode->addItem(QString());
        comboBoxRenderMode->addItem(QString());
        comboBoxRenderMode->setObjectName(QString::fromUtf8("comboBoxRenderMode"));

        gridLayout->addWidget(comboBoxRenderMode, 1, 0, 1, 1);

        spinBoxHeight = new QSpinBox(Render);
        spinBoxHeight->setObjectName(QString::fromUtf8("spinBoxHeight"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxHeight->sizePolicy().hasHeightForWidth());
        spinBoxHeight->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(spinBoxHeight, 1, 4, 1, 1);

        label_3 = new QLabel(Render);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_2 = new QLabel(Render);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        spinBoxWidth = new QSpinBox(Render);
        spinBoxWidth->setObjectName(QString::fromUtf8("spinBoxWidth"));

        gridLayout->addWidget(spinBoxWidth, 3, 4, 1, 1);

        btnOK = new QPushButton(Render);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnOK->sizePolicy().hasHeightForWidth());
        btnOK->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(btnOK, 4, 0, 1, 1);


        retranslateUi(Render);

        QMetaObject::connectSlotsByName(Render);
    } // setupUi

    void retranslateUi(QDialog *Render)
    {
        Render->setWindowTitle(QApplication::translate("Render", "Render", nullptr));
        comboBoxProjectionType->setItemText(0, QApplication::translate("Render", "Perspective", nullptr));
        comboBoxProjectionType->setItemText(1, QApplication::translate("Render", "Parallel", nullptr));

        comboBoxRenderMode->setItemText(0, QApplication::translate("Render", "Lambertian", nullptr));
        comboBoxRenderMode->setItemText(1, QApplication::translate("Render", "Phong", nullptr));
        comboBoxRenderMode->setItemText(2, QApplication::translate("Render", "Shadows", nullptr));
        comboBoxRenderMode->setItemText(3, QApplication::translate("Render", "Transparency", nullptr));
        comboBoxRenderMode->setItemText(4, QApplication::translate("Render", "Mirror", nullptr));
        comboBoxRenderMode->setItemText(5, QApplication::translate("Render", "Refraction", nullptr));

        label_3->setText(QApplication::translate("Render", "Width", nullptr));
        label_2->setText(QApplication::translate("Render", "Height", nullptr));
        btnOK->setText(QApplication::translate("Render", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Render: public Ui_Render {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDER_H
