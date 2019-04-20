#pragma once

#include "ui_Create_Cylinder.h"
#include <QColorDialog>
#include <QDialog>
#include <STVector3.h>

class Create_Cylinder : public QDialog {
    Q_OBJECT

public:
    Create_Cylinder(QWidget* parent = Q_NULLPTR);
    ~Create_Cylinder();

    void setReferences(STVector3& top, STVector3& bottom, float& radius, QColor& color);

private slots:
    void on_btnOK_clicked();

private:
    Ui::Create_Cylinder ui;

    QColor* colorPtr;
    STVector3* topPtr;
    STVector3* bottomPtr;
    float* radiusPtr;
};
