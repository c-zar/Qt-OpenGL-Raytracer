#pragma once

#include <QDialog>
#include "ui_Create_Light.h"

class Create_Light : public QDialog
{
	Q_OBJECT

public:
	Create_Light(QWidget *parent = Q_NULLPTR);
	~Create_Light();

private:
	Ui::Create_Light ui;
};
