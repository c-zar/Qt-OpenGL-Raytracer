#pragma once

#include "Create_Cylinder.h"
#include "Create_Light.h"
#include "Create_Sphere.h"
#include "Create_Triangle.h"
#include "Light.h"
#include "RayTracer.h"
#include "Render.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "myGLWidget.h"
#include "ui_QtGui.h"
#include <QStringListModel>
#include <QTimer>
#include <QtWidgets/QMainWindow>

class QtGui : public QMainWindow {
    Q_OBJECT

public:
    QtGui(QWidget* parent = Q_NULLPTR);

private slots:
    void on_btnAddShape_clicked();
    void on_btnRender_clicked();

	void on_shapesList_itemDoubleClicked(QListWidgetItem* listWidgetItem);

    void on_camPosX_valueChanged(double newVal);
    void on_camPosY_valueChanged(double newVal);
    void on_camPosZ_valueChanged(double newVal);

    void on_camLookX_valueChanged(double newVal);
    void on_camLookY_valueChanged(double newVal);
    void on_camLookZ_valueChanged(double newVal);

    void on_camUpX_valueChanged(double newVal);
    void on_camUpY_valueChanged(double newVal);
    void on_camUpZ_valueChanged(double newVal);

private:
    Ui::QtGuiClass* ui;
    QTimer* timer;
    Scene* pScene;
    Camera* sceneCam;

    int width;
    int height;

    std::vector<Sphere> sphereList;
    std::vector<QString> sphereInfoList;

    std::vector<Triangle> triangleList;
    std::vector<QString> triangleInfoList;

    std::vector<Cylinder> cylinderList;
    std::vector<QString> cylinderInfoList;

    std::vector<Light> lightList;
    std::vector<QString> lightInfoList;

    //functions
    void openCreateSpherePage(STVector3& center, float& radius, QColor& color);
    void openCreateTrianglePage(STVector3& a, STVector3& b, STVector3& c, QColor& color, bool & ref);
    void openCreateLightPage(STVector3& origin, QColor& color);
    void openCreateCylinderPage(STVector3& top, STVector3& bottom, float& radius, QColor& color);
    void updateShapesList();
    void renderRayTracing();
};
