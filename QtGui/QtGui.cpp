#include "QtGui.h"
#include "Light.h"
#include "RayTracer.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "defs.h"
//#include "stglew.h"
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

    sphereList.push_back(Sphere(0, .1, 15, RGBR_f(0, 0, 255, 1), 2, true));
    STVector3 a(10, -2, 0);
    STVector3 b(-10, -2, 0);
    STVector3 c(0, -2, 100);
    triangleList.push_back(Triangle(a, b, c, RGBR_f(255, 0, 0, 1), true));

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

void QtGui::openCreateSpherePage(STVector3& center, float& radius, QColor& color)
{
    //open page
    Create_Sphere* page = new Create_Sphere();
    page->setReferences(center, radius, color);
    page->exec();

    //add sphere obj to vector
    sphereList.push_back(Sphere(center.x, center.y, center.z, RGBR_f(color.red(), color.green(), color.blue(), 1), radius));

    //add sphere info to vector - REPLACE ONCE WE WRITE GETTER IN SPHERE
    QString sphereInfo = QString::fromStdString("SPHERE AT (" + std::to_string(center.x) + ", " + std::to_string(center.y) + ", " + std::to_string(center.z) + "WITH RADIUS OF " + std::to_string(radius));
    sphereInfoList.push_back(sphereInfo);

    updateShapesList();
}

void QtGui::openCreateTrianglePage(STVector3& a, STVector3& b, STVector3& c, QColor& color)
{
    //open page
    Create_Triangle* page = new Create_Triangle();
    page->setReferences(a, b, c, color);
    page->exec();

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

void QtGui::renderRayTracing()
{
    pScene->m_surfaceList.clear();
    pScene->SetBackgroundColor(RGBR_f(0, 0, 0, 1.0f));

    //Lights -------------------------------------------------------------------------------------------------------
    Light scenelight = Light(STVector3(0, 50, 10), RGBR_f(255, 255, 255, 20), "Light1");
    pScene->AddLight(scenelight);
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

    //run ray tracing

    //Render* renderPage = new Render();
    //renderPage->exec();

    RenderMode mode = MIRROR;
    ProjectionType m_projectionType = PERSPECTIVE;

    pRayTracer->Run(pScene, "test.png", mode, m_projectionType, width, height);
}