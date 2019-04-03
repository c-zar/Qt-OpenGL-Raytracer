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
	
	//add sphere info to vector
	QString sphereInfo = QString::fromStdString("X: " + std::to_string(center.x) + " Y: " + std::to_string(center.y) + " Z: " + std::to_string(center.x) + " RADIUS: " + std::to_string(radius));
	sphereInfoList.push_back(sphereInfo);

	updateShapesList();
}

void QtGui::openCreateTrianglePage(STVector3 &a, STVector3 &b, STVector3 &c) {

}

void QtGui::updateShapesList() {
	ui->shapesList->clear();

	for (int i = 0; i < sphereInfoList.size(); i++) {
		ui->shapesList->addItem(sphereInfoList.at(i));
	}
}