#pragma once

#include "ui_Render.h"
#include <QDialog>

class Render : public QDialog
{
    Q_OBJECT

public:
    Render(QWidget *parent = Q_NULLPTR);
    ~Render();

	void setReferences(int &renderMode, int &m_projectionType, bool &submitted);

private slots:
	void on_btnOK_clicked();

private:
    Ui::Render ui;

	int *renderModePtr;
	int *m_projectionTypePtr;
	bool *submittedPtr;
};
