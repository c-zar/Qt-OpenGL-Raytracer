#pragma once

#include <QDialog>
#include "ui_Create_Sphere.h"
#include <STVector3.h>

class Create_Sphere : public QDialog
{
	Q_OBJECT

public:
	Create_Sphere(QWidget *parent = Q_NULLPTR);
	~Create_Sphere();

	void setReferences(STVector3 &center, float &radius);

private slots:
	void on_btnOK_clicked();

private:
	Ui::Create_Sphere ui;

	STVector3 *centerPtr;
	float     *radiusPtr;
};
