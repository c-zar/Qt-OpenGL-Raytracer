#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGui.h"
#include "Create_Sphere.h"
#include "Create_Triangle.h"
#include <QStringListModel>
#include "myGLWidget.h"
#include <QTimer>

class QtGui : public QMainWindow
{
    Q_OBJECT

public:
    QtGui(QWidget *parent = Q_NULLPTR);

private slots:
	void on_btnAddShape_clicked();
	void on_btnRender_clicked();

private:
	Ui::QtGuiClass *ui;
    QTimer* timer;

	std::vector<Sphere>  sphereList;
	std::vector<QString> sphereInfoList;

	std::vector<Triangle> triangleList;
	std::vector<QString>  triangleInfoList;

	STVector3 cameraPosition;
	STVector3 cameraLookAt;
	STVector3 cameraUp;

	//functions
	void openCreateSpherePage(STVector3 &center, float &radius);
	void openCreateTrianglePage(STVector3 &a, STVector3 &b, STVector3 &c);
	void updateShapesList();
	void renderRayTracing();


};
