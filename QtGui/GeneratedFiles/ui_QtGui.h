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
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QComboBox *comboBoxShapeType;
    QPushButton *btnAddShape;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label_5;
    QDoubleSpinBox *camPosZ;
    QDoubleSpinBox *camPosY;
    QLabel *label_3;
    QDoubleSpinBox *camLookX;
    QDoubleSpinBox *camUpZ;
    QDoubleSpinBox *camPosX;
    QDoubleSpinBox *camUpX;
    QDoubleSpinBox *camUpY;
    QDoubleSpinBox *camLookY;
    QDoubleSpinBox *camLookZ;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *btnRender;
    myGLWidget *openGLWidget;
    QListWidget *shapesList;

    void setupUi(QMainWindow *QtGuiClass)
    {
        if (QtGuiClass->objectName().isEmpty())
            QtGuiClass->setObjectName(QString::fromUtf8("QtGuiClass"));
        QtGuiClass->setWindowModality(Qt::NonModal);
        QtGuiClass->resize(900, 690);
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
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(0, 100));
        widget->setBaseSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBoxShapeType = new QComboBox(widget);
        comboBoxShapeType->addItem(QString());
        comboBoxShapeType->addItem(QString());
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
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_5, 6, 0, 1, 1);

        camPosZ = new QDoubleSpinBox(widget);
        camPosZ->setObjectName(QString::fromUtf8("camPosZ"));
        camPosZ->setMinimum(-1000.000000000000000);
        camPosZ->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(camPosZ, 2, 3, 1, 1);

        camPosY = new QDoubleSpinBox(widget);
        camPosY->setObjectName(QString::fromUtf8("camPosY"));
        camPosY->setMinimum(-1000.000000000000000);
        camPosY->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(camPosY, 2, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_3, 5, 0, 1, 1);

        camLookX = new QDoubleSpinBox(widget);
        camLookX->setObjectName(QString::fromUtf8("camLookX"));
        camLookX->setMinimum(-1000.000000000000000);
        camLookX->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(camLookX, 5, 1, 1, 1);

        camUpZ = new QDoubleSpinBox(widget);
        camUpZ->setObjectName(QString::fromUtf8("camUpZ"));
        camUpZ->setMinimum(-1000.000000000000000);
        camUpZ->setMaximum(1000.000000000000000);
        camUpZ->setValue(0.000000000000000);

        gridLayout_3->addWidget(camUpZ, 6, 3, 1, 1);

        camPosX = new QDoubleSpinBox(widget);
        camPosX->setObjectName(QString::fromUtf8("camPosX"));
        camPosX->setMinimum(-1000.000000000000000);
        camPosX->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(camPosX, 2, 1, 1, 1);

        camUpX = new QDoubleSpinBox(widget);
        camUpX->setObjectName(QString::fromUtf8("camUpX"));
        camUpX->setMinimum(-1000.000000000000000);
        camUpX->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(camUpX, 6, 1, 1, 1);

        camUpY = new QDoubleSpinBox(widget);
        camUpY->setObjectName(QString::fromUtf8("camUpY"));
        camUpY->setMinimum(-1000.000000000000000);
        camUpY->setMaximum(1000.000000000000000);
        camUpY->setValue(1.000000000000000);

        gridLayout_3->addWidget(camUpY, 6, 2, 1, 1);

        camLookY = new QDoubleSpinBox(widget);
        camLookY->setObjectName(QString::fromUtf8("camLookY"));
        camLookY->setMinimum(-1000.000000000000000);
        camLookY->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(camLookY, 5, 2, 1, 1);

        camLookZ = new QDoubleSpinBox(widget);
        camLookZ->setObjectName(QString::fromUtf8("camLookZ"));
        camLookZ->setMinimum(-1000.000000000000000);
        camLookZ->setMaximum(1000.000000000000000);
        camLookZ->setValue(-1.000000000000000);

        gridLayout_3->addWidget(camLookZ, 5, 3, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_4, 1, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_6, 1, 2, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_7, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 2);

        btnRender = new QPushButton(widget);
        btnRender->setObjectName(QString::fromUtf8("btnRender"));

        gridLayout_2->addWidget(btnRender, 2, 0, 1, 1);


        gridLayout->addWidget(widget, 4, 0, 1, 1);

        openGLWidget = new myGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(openGLWidget, 1, 1, 4, 2);

        shapesList = new QListWidget(centralWidget);
        shapesList->setObjectName(QString::fromUtf8("shapesList"));
        sizePolicy4.setHeightForWidth(shapesList->sizePolicy().hasHeightForWidth());
        shapesList->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(shapesList, 1, 0, 1, 1);

        QtGuiClass->setCentralWidget(centralWidget);

        retranslateUi(QtGuiClass);
        QObject::connect(camLookX, SIGNAL(valueChanged(QString)), QtGuiClass, SLOT(update()));

        QMetaObject::connectSlotsByName(QtGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiClass)
    {
        QtGuiClass->setWindowTitle(QApplication::translate("QtGuiClass", "QtGui", nullptr));
        comboBoxShapeType->setItemText(0, QApplication::translate("QtGuiClass", "Light", nullptr));
        comboBoxShapeType->setItemText(1, QApplication::translate("QtGuiClass", "Sphere", nullptr));
        comboBoxShapeType->setItemText(2, QApplication::translate("QtGuiClass", "Triangle", nullptr));
        comboBoxShapeType->setItemText(3, QApplication::translate("QtGuiClass", "Cylinder", nullptr));

        btnAddShape->setText(QApplication::translate("QtGuiClass", "Add", nullptr));
        label_2->setText(QApplication::translate("QtGuiClass", "Position", nullptr));
        label_5->setText(QApplication::translate("QtGuiClass", "Up (V)", nullptr));
        label_3->setText(QApplication::translate("QtGuiClass", "Look at (W)", nullptr));
        label->setText(QApplication::translate("QtGuiClass", "Camera", nullptr));
        label_4->setText(QApplication::translate("QtGuiClass", "x", nullptr));
        label_6->setText(QApplication::translate("QtGuiClass", "y", nullptr));
        label_7->setText(QApplication::translate("QtGuiClass", "z", nullptr));
        btnRender->setText(QApplication::translate("QtGuiClass", "Render", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiClass: public Ui_QtGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_H
