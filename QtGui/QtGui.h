#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGui.h"
#include <STVector3.h>
#include <vector>
#include <Sphere.h>
#include <Triangle.h>
#include "Create_Sphere.h"
#include "Create_Triangle.h"
#include <QStringListModel>

class QtGui : public QMainWindow
{
    Q_OBJECT

public:
    QtGui(QWidget *parent = Q_NULLPTR);

private slots:
	void on_btnAddShape_clicked();

private:
	Ui::QtGuiClass *ui;

	std::vector<Sphere>  sphereList;
	std::vector<QString> sphereInfoList;

	std::vector<Triangle> triangleList;
	std::vector<QString>  triangleInfoList;

	//functions
	void openCreateSpherePage(STVector3 &center, float &radius);
	void openCreateTrianglePage(STVector3 &a, STVector3 &b, STVector3 &c);

	void updateShapesList();


};
