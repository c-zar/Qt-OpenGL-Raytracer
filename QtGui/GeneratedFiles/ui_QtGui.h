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
#include <QtWidgets/QGridLayout>
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
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QComboBox *comboBoxShapeType;
    QPushButton *btnAddShape;
    QListWidget *shapesList;

    void setupUi(QMainWindow *QtGuiClass)
    {
        if (QtGuiClass->objectName().isEmpty())
            QtGuiClass->setObjectName(QString::fromUtf8("QtGuiClass"));
        QtGuiClass->setWindowModality(Qt::NonModal);
        QtGuiClass->resize(900, 600);
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
        comboBoxShapeType->setObjectName(QString::fromUtf8("comboBoxShapeType"));

        gridLayout_2->addWidget(comboBoxShapeType, 0, 0, 1, 1);

        btnAddShape = new QPushButton(widget);
        btnAddShape->setObjectName(QString::fromUtf8("btnAddShape"));

        gridLayout_2->addWidget(btnAddShape, 0, 1, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        shapesList = new QListWidget(centralWidget);
        shapesList->setObjectName(QString::fromUtf8("shapesList"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(shapesList->sizePolicy().hasHeightForWidth());
        shapesList->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(shapesList, 0, 0, 1, 1);

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
    } // retranslateUi

};

namespace Ui {
    class QtGuiClass: public Ui_QtGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_H
