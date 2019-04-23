/********************************************************************************
** Form generated from reading UI file 'Show_Image.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_IMAGE_H
#define UI_SHOW_IMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Show_Image
{
public:
    QLabel *label;

    void setupUi(QDialog *Show_Image)
    {
        if (Show_Image->objectName().isEmpty())
            Show_Image->setObjectName(QString::fromUtf8("Show_Image"));
        Show_Image->resize(619, 573);
        label = new QLabel(Show_Image);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 100, 491, 421));

        retranslateUi(Show_Image);

        QMetaObject::connectSlotsByName(Show_Image);
    } // setupUi

    void retranslateUi(QDialog *Show_Image)
    {
        Show_Image->setWindowTitle(QApplication::translate("Show_Image", "Show_Image", nullptr));
        label->setText(QApplication::translate("Show_Image", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Show_Image: public Ui_Show_Image {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_IMAGE_H
