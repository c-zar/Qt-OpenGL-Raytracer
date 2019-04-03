#include "myGLWidget.h"
#include "GLFW/glfw3.h"
#include <Gl/GL.h>
#include <Gl/GLU.h>
#include <Gl/glut.h>

myGLWidget::myGLWidget(QWidget* parent, std::vector<Sphere>* sphereList,
    std::vector<Triangle>* triangleList)
    : QOpenGLWidget(parent)
{
    this->sphereList = sphereList;
    this->triangleList = triangleList;

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    setFormat(format);
}

myGLWidget::~myGLWidget()
{
}

void myGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void myGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    //glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, 0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.5, 0);
    //glPopMatrix();
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    GLUquadric* quad = gluNewQuadric();
    glPushMatrix();
    gluSphere(quad, .5, 50, 20);
    glTranslatef(.3, .3, 0);
    glPopMatrix();
    glEnd();
}

void myGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45, (float)w / h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

//void myGLWidget::initVertices()
//{
//    for (auto it = triangleList->begin(); it != triangleList->end(); ++it) {
//        glGenVertexArrays
//    }
//}