#pragma once

#include "ui_Render.h"
#include <QDialog>

class Render : public QDialog
{
    Q_OBJECT

public:
    Render(QWidget *parent = Q_NULLPTR);
    ~Render();

private:
    Ui::Render ui;

    bool* lambertian;
    bool* phong;
    bool* shadowns;
    bool* transparency;
    bool* reflection;
};
