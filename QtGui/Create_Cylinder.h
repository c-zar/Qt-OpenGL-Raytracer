#pragma once

#include <QDialog>
#include "ui_Create_Cylinder.h"

class Create_Cylinder : public QDialog
{
	Q_OBJECT

public:
	Create_Cylinder(QWidget *parent = Q_NULLPTR);
	~Create_Cylinder();

private:
	Ui::Create_Cylinder ui;
};
