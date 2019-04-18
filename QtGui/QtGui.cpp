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
    ui->openGLWidget->initLists(&sphereList, &triangleList);
}

void QtGui::on_btnAddShape_clicked()
{
    QString selected = ui->comboBoxShapeType->itemText(ui->comboBoxShapeType->currentIndex());

    if (selected == "Sphere") {
        STVector3 center;
        float radius;
        openCreateSpherePage(center, radius);
    }

    if (selected == "Triangle") {
        STVector3 a;
        STVector3 b;
        STVector3 c;
        openCreateTrianglePage(a, b, c);
    }
}

void QtGui::on_btnRender_clicked() {
	renderRayTracing();
}

void QtGui::openCreateSpherePage(STVector3& center, float& radius)
{
    //open page
    Create_Sphere* page = new Create_Sphere();
    page->setReferences(center, radius);
    page->exec();

    //add sphere obj to vector
    sphereList.push_back(Sphere(center.x, center.y, center.z, RGBR_f(255.0, 0, 0, 1), radius));

    //add sphere info to vector - REPLACE ONCE WE WRITE GETTER IN SPHERE
    QString sphereInfo = QString::fromStdString("SPHERE AT (" + std::to_string(center.x) + ", " + std::to_string(center.y) + ", " + std::to_string(center.z) + "WITH RADIUS OF " + std::to_string(radius));
    sphereInfoList.push_back(sphereInfo);

    updateShapesList();
}

void QtGui::openCreateTrianglePage(STVector3& a, STVector3& b, STVector3& c)
{
    //open page
    Create_Triangle* page = new Create_Triangle();
    page->setReferences(a, b, c);
    page->exec();

    //add triangle obj to vector
    triangleList.push_back(Triangle(a, b, c, RGBR_f(255.0, 0, 0, 1)));
    ui->openGLWidget->addNewTriangle();
    

    //add triangle info to vector - REPLACE ONCE WE WRITE GETTER IN TRIANGLE
    QString triangleInfo = QString::fromStdString("TRIANGLE AT (" + std::to_string(a.x) + "," + std::to_string(a.y) + "," + std::to_string(a.z) + "),(" + std::to_string(b.x) + "," + std::to_string(b.y) + "," + std::to_string(b.z) + "),(" + std::to_string(c.x) + "," + std::to_string(c.y) + "," + std::to_string(c.z) + ")");
    triangleInfoList.push_back(triangleInfo);

    updateShapesList();
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

void QtGui::renderRayTracing() {
	//setup
	Scene *pScene = new Scene();

	pScene->SetBackgroundColor(RGBR_f(200, 200, 200, 1.0f));

	//Lights -------------------------------------------------------------------------------------------------------
	Light scenelight = Light(STVector3(-100, 0, 0), RGBR_f(255, 255, 255, 1.0f), "Light1");
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
	RayTracer *pRayTracer = new RayTracer();

	//run ray tracing
	RenderMode mode = PHONG;
	ProjectionType m_projectionType = PERSPECTIVE;
	pRayTracer->Run(pScene, "test.png", mode, m_projectionType);
}