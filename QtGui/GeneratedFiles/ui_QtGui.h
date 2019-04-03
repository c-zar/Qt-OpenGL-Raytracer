/********************************************************************************
** Form generated from reading UI file 'QtGui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUI_H
#define UI_QTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "myGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QtGuiClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    myGLWidget *openGLWidget;
    QListWidget *shapesList;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QComboBox *comboBoxShapeType;
    QPushButton *btnAddShape;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_9;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_5;
    QLabel *label_4;

    void setupUi(QMainWindow *QtGuiClass)
    {
        if (QtGuiClass->objectName().isEmpty())
            QtGuiClass->setObjectName(QString::fromUtf8("QtGuiClass"));
        QtGuiClass->setWindowModality(Qt::NonModal);
        QtGuiClass->resize(966, 690);
        centralWidget = new QWidget(QtGuiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(900, 600));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new myGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 1, 2, 1);

        shapesList = new QListWidget(centralWidget);
        shapesList->setObjectName(QString::fromUtf8("shapesList"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(shapesList->sizePolicy().hasHeightForWidth());
        shapesList->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(shapesList, 0, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 100));
        widget->setBaseSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBoxShapeType = new QComboBox(widget);
        comboBoxShapeType->addItem(QString());
        comboBoxShapeType->addItem(QString());
        comboBoxShapeType->setObjectName(QString::fromUtf8("comboBoxShapeType"));

        gridLayout_2->addWidget(comboBoxShapeType, 1, 0, 1, 1);

        btnAddShape = new QPushButton(widget);
        btnAddShape->setObjectName(QString::fromUtf8("btnAddShape"));

        gridLayout_2->addWidget(btnAddShape, 1, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        doubleSpinBox_2 = new QDoubleSpinBox(widget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout_3->addWidget(doubleSpinBox_2, 1, 2, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(widget);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));

        gridLayout_3->addWidget(doubleSpinBox_7, 4, 2, 1, 1);

        doubleSpinBox_12 = new QDoubleSpinBox(widget);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));

        gridLayout_3->addWidget(doubleSpinBox_12, 5, 3, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(widget);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));

        gridLayout_3->addWidget(doubleSpinBox_6, 3, 1, 1, 1);

        doubleSpinBox_11 = new QDoubleSpinBox(widget);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));

        gridLayout_3->addWidget(doubleSpinBox_11, 5, 2, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(widget);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));

        gridLayout_3->addWidget(doubleSpinBox_9, 5, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_3, 5, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 2, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(widget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        gridLayout_3->addWidget(doubleSpinBox_3, 1, 3, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(widget);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));

        gridLayout_3->addWidget(doubleSpinBox_4, 3, 3, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(widget);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        gridLayout_3->addWidget(doubleSpinBox_5, 3, 2, 1, 1);

        doubleSpinBox_10 = new QDoubleSpinBox(widget);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));

        gridLayout_3->addWidget(doubleSpinBox_10, 4, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(widget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout_3->addWidget(doubleSpinBox, 1, 1, 1, 1);

        doubleSpinBox_8 = new QDoubleSpinBox(widget);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));

        gridLayout_3->addWidget(doubleSpinBox_8, 4, 3, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_5, 4, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_4, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 2);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        QtGuiClass->setCentralWidget(centralWidget);

        retranslateUi(QtGuiClass);

        QMetaObject::connectSlotsByName(QtGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiClass)
    {
        QtGuiClass->setWindowTitle(QApplication::translate("QtGuiClass", "QtGui", nullptr));
        comboBoxShapeType->setItemText(0, QApplication::translate("QtGuiClass", "Sphere", nullptr));
        comboBoxShapeType->setItemText(1, QApplication::translate("QtGuiClass", "Triangle", nullptr));

        btnAddShape->setText(QApplication::translate("QtGuiClass", "Add Shape", nullptr));
        label_3->setText(QApplication::translate("QtGuiClass", "Look at (W)", nullptr));
        label_2->setText(QApplication::translate("QtGuiClass", "Position", nullptr));
        label->setText(QApplication::translate("QtGuiClass", "Camera", nullptr));
        label_5->setText(QApplication::translate("QtGuiClass", "Up (V)", nullptr));
        label_4->setText(QApplication::translate("QtGuiClass", "Right (U)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiClass: public Ui_QtGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_H
