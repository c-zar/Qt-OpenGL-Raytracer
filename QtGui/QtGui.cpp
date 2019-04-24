#include "QtGui.h"
#include "Light.h"
#include "RayTracer.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "defs.h"
#include "Show_Image.h"
#include <map>
#include <stdio.h>
#include <string.h>

QtGui::QtGui(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::QtGuiClass)
{
    timer = new QTimer(this);
    ui->setupUi(this);
    //ui->openGLWidget->initLists(&sphereList, &triangleList);
    pScene = new Scene();
    sceneCam = pScene->GetCamera();

    //sphereList.push_back(Sphere(0, .1, 20, RGBR_f(0, 0, 255, 1), 2, false));

    //STVector3 a(50, -2, 0);
    //STVector3 b(-50, -2, 0);
    //STVector3 c(0, -2, 100);
    //triangleList.push_back(Triangle(a, b, c, RGBR_f(255, 0, 0, 1), false));

    //STVector3 a2(10, -2, 20);
    //STVector3 b2(-10, -2, 0);
    //STVector3 c2(-10, 20, 0);
    //triangleList.push_back(Triangle(a2, c2, b2, RGBR_f(0, 255, 0, 1), true));

    ui->openGLWidget->setReferences(sphereList, triangleList, cylinderList, lightList, sceneCam, width, height);
}

void QtGui::on_btnAddShape_clicked()
{
    QString selected = ui->comboBoxShapeType->itemText(ui->comboBoxShapeType->currentIndex());

    if (selected == "Sphere") {
        STVector3 center;
        float radius;
        QColor color;
        openCreateSpherePage(center, radius, color);
    }

    if (selected == "Triangle") {
        STVector3 a;
        STVector3 b;
        STVector3 c;
        QColor color;
        openCreateTrianglePage(a, b, c, color);
    }

    if (selected == "Light") {
        STVector3 origin;
        QColor color;
        openCreateLightPage(origin, color);
    }

    if (selected == "Cylinder") {
        STVector3 top;
        STVector3 bottom;
        float radius;
        QColor color;
        openCreateCylinderPage(top, bottom, radius, color);
    }
}

void QtGui::on_btnRender_clicked()
{
    renderRayTracing();
}

void QtGui::on_camPosX_valueChanged(double newVal)
{
    STVector3 old = sceneCam->Position();
    sceneCam->SetPostion(STVector3(newVal, old.y, old.z));
}

void QtGui::on_camPosY_valueChanged(double newVal)
{
    STVector3 old = sceneCam->Position();
    sceneCam->SetPostion(STVector3(old.x, newVal, old.z));
}

void QtGui::on_camPosZ_valueChanged(double newVal)
{
    STVector3 old = sceneCam->Position();
    sceneCam->SetPostion(STVector3(old.x, old.y, newVal));
}

void QtGui::on_camLookX_valueChanged(double newVal)
{
    STVector3 old = sceneCam->LookAt();
    STVector3 newL(newVal, old.y, old.z);
    newL.Normalize();
    STVector3 up = sceneCam->Up();
    sceneCam->SetLookAt(newL, up);
}

void QtGui::on_camLookY_valueChanged(double newVal)
{
    STVector3 old = sceneCam->LookAt();
    STVector3 newL(old.x, newVal, old.z);
    newL.Normalize();
    STVector3 up = sceneCam->Up();
    sceneCam->SetLookAt(newL, up);
}

void QtGui::on_camLookZ_valueChanged(double newVal)
{
    STVector3 old = sceneCam->LookAt();
    STVector3 newL(old.x, old.y, newVal);
    newL.Normalize();
    STVector3 up = sceneCam->Up();
    sceneCam->SetLookAt(newL, up);
}

void QtGui::on_camUpX_valueChanged(double newVal)
{
    STVector3 old = sceneCam->Up();
    STVector3 newU(newVal, old.y, old.z);
    STVector3 lookat = sceneCam->LookAt();
    sceneCam->SetLookAt(lookat, newU);
}

void QtGui::on_camUpY_valueChanged(double newVal)
{
    STVector3 old = sceneCam->Up();
    STVector3 newU(old.x, newVal, old.z);
    STVector3 lookat = sceneCam->LookAt();
    sceneCam->SetLookAt(lookat, newU);
}

void QtGui::on_camUpZ_valueChanged(double newVal)
{
    STVector3 old = sceneCam->Up();
    STVector3 newU(old.x, old.y, newVal);
    STVector3 lookat = sceneCam->LookAt();
    sceneCam->SetLookAt(lookat, newU);
}

void QtGui::openCreateSpherePage(STVector3& center, float& radius, QColor& color)
{
	bool submitted = false;

    //open page
    Create_Sphere* page = new Create_Sphere();
    page->setReferences(submitted, center, radius, color);
    page->exec();

	if (!submitted) {
		return;
	}

    //add sphere obj to vector
    sphereList.push_back(Sphere(center.x, center.y, center.z, RGBR_f(color.red(), color.green(), color.blue(), 1), radius));

    //add sphere info to vector - REPLACE ONCE WE WRITE GETTER IN SPHERE
    QString sphereInfo = QString::fromStdString("SPHERE AT (" + std::to_string(center.x) + ", " + std::to_string(center.y) + ", " + std::to_string(center.z) + "WITH RADIUS OF " + std::to_string(radius));
    sphereInfoList.push_back(sphereInfo);

    updateShapesList();
}

void QtGui::openCreateTrianglePage(STVector3& a, STVector3& b, STVector3& c, QColor& color)
{
	bool submitted = false;

    //open page
    Create_Triangle* page = new Create_Triangle();
    page->setReferences(submitted, a, b, c, color);
    page->exec();

	if (!submitted) {
		return;
	}

    //add triangle obj to vector
    triangleList.push_back(Triangle(a, b, c, RGBR_f(color.red(), color.green(), color.blue(), 1)));

    //add triangle info to vector - REPLACE ONCE WE WRITE GETTER IN TRIANGLE
    QString triangleInfo = QString::fromStdString("TRIANGLE AT (" + std::to_string(a.x) + "," + std::to_string(a.y) + "," + std::to_string(a.z) + "),(" + std::to_string(b.x) + "," + std::to_string(b.y) + "," + std::to_string(b.z) + "),(" + std::to_string(c.x) + "," + std::to_string(c.y) + "," + std::to_string(c.z) + ")");
    triangleInfoList.push_back(triangleInfo);

    updateShapesList();
}

void QtGui::openCreateLightPage(STVector3& origin, QColor& color)
{
    //open page
    Create_Light* page = new Create_Light();
    page->setReferences(origin, color);
    page->exec();

    //add triangle obj to vector
    //triangleList.push_back(Triangle(a, b, c, RGBR_f(255.0, 0, 0, 1)));

    //add triangle info to vector - REPLACE ONCE WE WRITE GETTER IN TRIANGLE
    //QString triangleInfo = QString::fromStdString("TRIANGLE AT (" + std::to_string(a.x) + "," + std::to_string(a.y) + "," + std::to_string(a.z) + "),(" + std::to_string(b.x) + "," + std::to_string(b.y) + "," + std::to_string(b.z) + "),(" + std::to_string(c.x) + "," + std::to_string(c.y) + "," + std::to_string(c.z) + ")");
    //triangleInfoList.push_back(triangleInfo);

    //updateShapesList();
}

void QtGui::openCreateCylinderPage(STVector3& top, STVector3& bottom, float& radius, QColor& color)
{
    //open page
    Create_Cylinder* page = new Create_Cylinder();
    page->setReferences(top, bottom, radius, color);
    page->exec();

    //add triangle obj to vector
    cylinderList.push_back(Cylinder(top.x, top.y, top.z, bottom.x, bottom.y, bottom.z, RGBR_f(color.red(), color.green(), color.blue(), 1), radius));
    //ui->openGLWidget->addNewTriangle();

    //add triangle info to vector - REPLACE ONCE WE WRITE GETTER IN TRIANGLE
    //QString triangleInfo = QString::fromStdString("TRIANGLE AT (" + std::to_string(a.x) + "," + std::to_string(a.y) + "," + std::to_string(a.z) + "),(" + std::to_string(b.x) + "," + std::to_string(b.y) + "," + std::to_string(b.z) + "),(" + std::to_string(c.x) + "," + std::to_string(c.y) + "," + std::to_string(c.z) + ")");
    //triangleInfoList.push_back(triangleInfo);

    //updateShapesList();
}

void QtGui::updateShapesList()
{
    ui->shapesList->clear();

    //display sphere infos
    for (int i = 0; i < sphereInfoList.size(); i++) {
        ui->shapesList->addItem(sphereInfoList.at(i));
    }

    //display triangle infos
    for (int i = 0; i < triangleInfoList.size(); i++) {
        ui->shapesList->addItem(triangleInfoList.at(i));
    }
}

/* DELETES ITEM ON DOUBLE CLICK */
void QtGui::on_shapesList_itemDoubleClicked(QListWidgetItem* listWidgetItem) {
	int index = ui->shapesList->currentIndex().row();

	QString text = listWidgetItem->text();

	if (text.at(0) == 'S') {
		sphereList.erase(sphereList.begin() + index);
		sphereInfoList.erase(sphereInfoList.begin() + index);
	} 

	if (text.at(0) == 'T') {
		index = index - sphereList.size();
		triangleList.erase(triangleList.begin() + index);
		triangleInfoList.erase(triangleInfoList.begin() + index);
	}

	ui->shapesList->removeItemWidget(listWidgetItem);
	updateShapesList();
}

void QtGui::renderRayTracing()
{
    pScene->m_surfaceList.clear();
    pScene->SetBackgroundColor(RGBR_f(0, 0, 0, 1.0f));

    //Lights -------------------------------------------------------------------------------------------------------
    Light scenelight = Light(STVector3(0, 50, 10), RGBR_f(255, 255, 255, 20), "Light1");
    Light scenelight2 = Light(STVector3(0, 0, 0), RGBR_f(255, 255, 255, 1), "Light2");
    
    pScene->AddLight(scenelight);
    pScene->AddLight(scenelight2);
    //Lights -------------------------------------------------------------------------------------------------------

    //Surfaces -------------------------------------------------------------------------------------------------------
    //pScene->AddSurface(new Triangle(STVector3(-200, -200, 0), STVector3(-200, -200, 900), STVector3(200, -200, 0), RGBR_f(255, 255, 255, 1), true));
    //pScene->AddSurface(new Triangle(STVector3(-200, -200, 900), STVector3(200, -200, 900), STVector3(200, -200, 0), RGBR_f(255, 255, 255, 1), true));
    //pScene->AddSurface(new Sphere(-50, -150, 150, RGBR_f(255.0f, 0.0f, 0.0f, 1.0f), 50));
    //pScene->AddSurface(new Sphere(50, -175, 100, RGBR_f(0, 0, 255, 1), 25, 0.5f));
    //pScene->AddSurface(new Sphere(50, -125, 200, RGBR_f(0.0f, 255.0f, 0.0f, 1.0f), 75));

    for (int i = 0; i < sphereList.size(); i++) {
        pScene->AddSurface(&sphereList.at(i));
    }

    for (int i = 0; i < triangleList.size(); i++) {
        pScene->AddSurface(&triangleList.at(i));
    }

    //Surfaces -------------------------------------------------------------------------------------------------------

    // init a ray tracer object
    RayTracer* pRayTracer = new RayTracer();

    int int_mode = -1;
    int int_proj = -1;
    bool submitted = false;

    Render* renderPage = new Render();
    renderPage->setReferences(int_mode, int_proj, submitted);
    renderPage->exec();

    if (!submitted) {
        return;
    }

    RenderMode mode;
    switch (int_mode) {
    case 0:
        mode = REFRACT;
        break;
    case 1:
        mode = PHONG;
        break;
    case 2:
        mode = SHADOWS;
        break;
    case 3:
        mode = TRANSPARENCY;
        break;
    case 4:
        mode = MIRROR;
        break;
    default:
        mode = LAMBERTIAN;
        break;
    }

    ProjectionType m_projectionType;
    switch (int_proj) {
    case 0:
        m_projectionType = PERSPECTIVE;
        break;
    case 1:
        m_projectionType = PARALLEL;
        break;
    default:
        m_projectionType = PERSPECTIVE;
        break;
    }

    //run ray tracing
    pRayTracer->Run(pScene, "test.png", mode, m_projectionType, width, height);

    //open image after
    Show_Image* page = new Show_Image();
    page->exec();
}