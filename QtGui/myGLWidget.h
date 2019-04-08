#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <Gl/GL.h>
#include <Gl/GLU.h>
#include <Gl/glut.h>
#include <glm.hpp>

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QVector>
#include <QtWidgets/qopenglwidget.h>
#include <QtWidgets/qwidget.h>
#include <STVector3.h>
#include <Sphere.h>
#include <Triangle.h>
#include <qopenglshaderprogram.h>
#include <qopenglvertexarrayobject.h>
#include <qopenglwidget.h>
#include <qvector.h>

class myGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    myGLWidget(QWidget* parent = 0);
    ~myGLWidget();

    void initLists(std::vector<Sphere>* sphereList, std::vector<Triangle>* triangleList);
    void addNewTriangle();
    void addNewSphere();

public:
    std::vector<Sphere>* sphereList;
    std::vector<Triangle>* triangleList;

    QOpenGLContext* context;
    QOpenGLShaderProgram* shaderProgram;

    QVector<QOpenGLVertexArrayObject*> triangleVAOs;
    QVector<QOpenGLBuffer*> triangleVBOs;

    QVector<QOpenGLVertexArrayObject*> sphereVAOs;
    QVector<QOpenGLBuffer*> sphereVBOs;

private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void initVertices();
};