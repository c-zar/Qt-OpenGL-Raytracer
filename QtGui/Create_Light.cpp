#include "Create_Light.h"

Create_Light::Create_Light(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Create_Light::~Create_Light()
{
}

void Create_Light::setReferences(STVector3& origin, QColor& color)
{
    originPtr = &origin;
    colorPtr = &color;
}

void Create_Light::on_btnOK_clicked()
{
    float x = ui.doubleSpinBoxX->value();
    float y = ui.doubleSpinBoxY->value();
    float z = ui.doubleSpinBoxZ->value();

    *originPtr = STVector3(x, y, z);
    *colorPtr = QColorDialog::getColor(Qt::white, this, "Choose Color");

    this->close();
}
