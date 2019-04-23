#include "Render.h"

Render::Render(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

void Render::setReferences(int &renderMode, int &m_projectionType, bool &submitted) {
	renderModePtr = &renderMode;
	m_projectionTypePtr = &m_projectionType;
	submittedPtr = &submitted;
}

void Render::on_btnOK_clicked() {
	*renderModePtr = ui.comboBoxRenderMode->currentIndex();
	*m_projectionTypePtr = ui.comboBoxProjectionType->currentIndex();
	*submittedPtr = true;

	this->close();
}

Render::~Render()
{
}
