#include "Show_Image.h"

Show_Image::Show_Image(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QPixmap pic("test.png");
	ui.label->setPixmap(pic);
}

Show_Image::~Show_Image()
{
}
