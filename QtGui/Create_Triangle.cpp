#include "Create_Triangle.h"

Create_Triangle::Create_Triangle(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Create_Triangle::~Create_Triangle()
{
}

void Create_Triangle::setReferences(STVector3& a, STVector3& b, STVector3& c, QColor& color)
{
	aPtr = &a;
	bPtr = &b;
	cPtr = &c;
    colorPtr = &color;
}

void Create_Triangle::on_btnOK_clicked() {
	float v1x = ui.doubleSpinBoxV1X->value();
	float v1y = ui.doubleSpinBoxV1Y->value();
	float v1z = ui.doubleSpinBoxV1Z->value();

	float v2x = ui.doubleSpinBoxV2X->value();
	float v2y = ui.doubleSpinBoxV2Y->value();
	float v2z = ui.doubleSpinBoxV2Z->value();

	float v3x = ui.doubleSpinBoxV3X->value();
	float v3y = ui.doubleSpinBoxV3Y->value();
	float v3z = ui.doubleSpinBoxV3Z->value();

	*aPtr = STVector3(v1x, v1y, v1z);
	*bPtr = STVector3(v2x, v2y, v2z);
	*cPtr = STVector3(v3x, v3y, v3z);

    *colorPtr = QColorDialog::getColor(Qt::white, this, "Choose Color");

	this->close();
}
