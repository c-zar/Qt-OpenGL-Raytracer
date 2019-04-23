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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Show_Image
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *Show_Image)
    {
        if (Show_Image->objectName().isEmpty())
            Show_Image->setObjectName(QString::fromUtf8("Show_Image"));
        Show_Image->resize(619, 573);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Show_Image->sizePolicy().hasHeightForWidth());
        Show_Image->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Show_Image);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Show_Image);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);


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
