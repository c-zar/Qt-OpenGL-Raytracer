#include "QtGui.h"

QtGui::QtGui(QWidget *parent)
    : QMainWindow(parent),
	  ui(new Ui::QtGuiClass)
{
    ui->setupUi(this);
}

void QtGui::on_btnAddShape_clicked() {
	QString selected = ui->comboBoxShapeType->itemText(ui->comboBoxShapeType->currentIndex());

	if (selected == "Sphere") {
		STVector3 center;
		float     radius;
		openCreateSpherePage(center, radius);
	}

	if (selected == "Triangle") {
		STVector3 a;
		STVector3 b;
		STVector3 c;
		openCreateTrianglePage(a, b, c);
	}
}

void QtGui::openCreateSpherePage(STVector3 &center, float &radius) {
	//open page
	Create_Sphere *page = new Create_Sphere();
	page->setReferences(center, radius);
	page->exec();

	//add sphere obj to vector
	sphereList.push_back(Sphere(center.x, center.y, center.z, RGBR_f(255.0, 0, 0, 1), radius));
	
	//add sphere info to vector - REPLACE ONCE WE WRITE GETTER IN SPHERE
	QString sphereInfo = QString::fromStdString("SPHERE AT (" + std::to_string(center.x) + ", " + std::to_string(center.y) + ", " + std::to_string(center.z) + "WITH RADIUS OF " + std::to_string(radius));
	sphereInfoList.push_back(sphereInfo);

	updateShapesList();
}

void QtGui::openCreateTrianglePage(STVector3 &a, STVector3 &b, STVector3 &c) {
	//open page
	Create_Triangle *page = new Create_Triangle();
	page->setReferences(a, b, c);
	page->exec();

	//add triangle obj to vector
	triangleList.push_back(Triangle(a, b, c, RGBR_f(255.0, 0, 0, 1)));

	//add triangle info to vector - REPLACE ONCE WE WRITE GETTER IN TRIANGLE
	QString triangleInfo = QString::fromStdString("TRIANGLE AT (" + std::to_string(a.x) + "," + std::to_string(a.y) + "," + std::to_string(a.z) + "),(" + std::to_string(b.x) + "," + std::to_string(b.y) + "," + std::to_string(b.z) + "),(" + std::to_string(c.x) + "," + std::to_string(c.y) + "," + std::to_string(c.z) + ")");
	triangleInfoList.push_back(triangleInfo);

	updateShapesList();
}

void QtGui::updateShapesList() {
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