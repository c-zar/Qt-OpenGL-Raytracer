#pragma once

#include <QDialog>
#include "ui_Create_Triangle.h"
#include <STVector3.h>

class Create_Triangle : public QDialog
{
	Q_OBJECT

public:
	Create_Triangle(QWidget *parent = Q_NULLPTR);
	~Create_Triangle();

	void setReferences(STVector3 &a, STVector3 &b, STVector3 &c);

private slots:
	void on_btnOK_clicked();

private:
	Ui::Create_Triangle ui;

	STVector3 *aPtr;
	STVector3 *bPtr;
	STVector3 *cPtr;

};
