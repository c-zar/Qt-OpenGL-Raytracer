#pragma once

#include "GL/glew.h"
#include <QtWidgets/qopenglwidget.h>
#include <QtWidgets/qwidget.h>
#include <QOpenGLFunctions>
#include <STVector3.h>
#include <vector>
#include <Sphere.h>
#include <Triangle.h>

class myGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    myGLWidget(QWidget* parent = 0, std::vector<Sphere>* sphereList = nullptr,
        std::vector<Triangle>* triangleList = nullptr);
    ~myGLWidget();

public:
    std::vector<uint32_t> VAOs;
    std::vector<Sphere>* sphereList;
    std::vector<Triangle>* triangleList;
    QOpenGLContext* m_context;

private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void initVertices();
};