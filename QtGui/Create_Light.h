#pragma once

#include "ui_Create_Light.h"
#include <QColorDialog>
#include <QDialog>
#include <STVector3.h>

class Create_Light : public QDialog {
    Q_OBJECT

public:
    Create_Light(QWidget* parent = Q_NULLPTR);
    ~Create_Light();
    void setReferences(bool &submitted, STVector3& origin, QColor& color);

private slots:
    void on_btnOK_clicked();

private:
    Ui::Create_Light ui;

	bool *submittedPtr;
    QColor* colorPtr;
    STVector3* originPtr;
};
