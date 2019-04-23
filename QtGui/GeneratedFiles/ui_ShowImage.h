/********************************************************************************
** Form generated from reading UI file 'ShowImage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWIMAGE_H
#define UI_SHOWIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowImage
{
public:
    QLabel *label;

    void setupUi(QWidget *ShowImage)
    {
        if (ShowImage->objectName().isEmpty())
            ShowImage->setObjectName(QString::fromUtf8("ShowImage"));
        ShowImage->resize(591, 512);
        label = new QLabel(ShowImage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 50, 431, 421));

        retranslateUi(ShowImage);

        QMetaObject::connectSlotsByName(ShowImage);
    } // setupUi

    void retranslateUi(QWidget *ShowImage)
    {
        ShowImage->setWindowTitle(QApplication::translate("ShowImage", "ShowImage", nullptr));
        label->setText(QApplication::translate("ShowImage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowImage: public Ui_ShowImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWIMAGE_H
