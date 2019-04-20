#include "Create_Cylinder.h"

Create_Cylinder::Create_Cylinder(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

Create_Cylinder::~Create_Cylinder()
{
}

void Create_Cylinder::setReferences(STVector3& top, STVector3& bottom, float& radius, QColor& color)
{
    topPtr = &top;
    bottomPtr = &bottom;
    radiusPtr = &radius;
    colorPtr = &color;
}

void Create_Cylinder::on_btnOK_clicked()
{
    float x1 = ui.doubleSpinBoxX->value();
    float y1 = ui.doubleSpinBoxY->value();
    float z1 = ui.doubleSpinBoxZ->value();

    float x2 = ui.doubleSpinBoxX->value();
    float y2 = ui.doubleSpinBoxY->value();
    float z2 = ui.doubleSpinBoxZ->value();

    float radius = ui.doubleSpinBoxRadius->value();

    *topPtr = STVector3(x1, y1, z1);
    *bottomPtr = STVector3(x2, y2, z2);
    *radiusPtr = radius;
    *colorPtr = QColorDialog::getColor(Qt::white, this, "Choose Color");

    this->close();
}
