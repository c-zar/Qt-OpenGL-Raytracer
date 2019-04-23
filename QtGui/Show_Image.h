#pragma once
#include "ui_Show_Image.h"
#include <QDialog>


class Show_Image : public QDialog
{
	Q_OBJECT

public:
	Show_Image(QWidget *parent = Q_NULLPTR);
	~Show_Image();

private:
	Ui::Show_Image ui;
};
