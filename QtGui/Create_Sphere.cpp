#include "Create_Sphere.h"

Create_Sphere::Create_Sphere(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

Create_Sphere::~Create_Sphere()
{
}

void Create_Sphere::setReferences(STVector3& center, float& radius, QColor& color)
{
    centerPtr = &center;
    radiusPtr = &radius;
    colorPtr = &color;
}

void Create_Sphere::on_btnOK_clicked()
{
    float x = ui.doubleSpinBoxX->value();
    float y = ui.doubleSpinBoxY->value();
    float z = ui.doubleSpinBoxZ->value();
    float radius = ui.doubleSpinBoxRadius->value();

    *centerPtr = STVector3(x, y, z);
    *radiusPtr = radius;
    *colorPtr = QColorDialog::getColor(Qt::white, this, "Choose Color");


    this->close();
}
