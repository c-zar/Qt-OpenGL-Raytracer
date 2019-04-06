#include "myGLWidget.h"

static float testVerts[] = { 0, -0.5, 0,
    0.5, -0.5, 0,
    0, 0.5, 0 };

myGLWidget::myGLWidget(QWidget* parent)
    : QOpenGLWidget(parent)
{
    //QSurfaceFormat format;
    //format.setDepthBufferSize(24);
    //setFormat(format);
}

myGLWidget::~myGLWidget()
{
}

void myGLWidget::initLists(std::vector<Sphere>* sphereList = nullptr,
    std::vector<Triangle>* triangleList = nullptr)
{
    this->sphereList = sphereList;
    this->triangleList = triangleList;
}

void myGLWidget::test()
{
    makeCurrent();
    shaderProgram->bind();
    QOpenGLVertexArrayObject* VAO = new QOpenGLVertexArrayObject();
    QOpenGLBuffer* VBO = new QOpenGLBuffer();

    VAO->create();
    VAO->bind();

    VBO->create();
    VBO->bind();
    VBO->allocate(testVerts, 9 * sizeof(float));

    //VBO.bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    //VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);

    VAO->release();
    VBO->release();

    VAOs.push_back(VAO);
    VBOs.push_back(VBO);
    shaderProgram->release();
    this->update();
}

void myGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);

    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHTING);
    //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_COLOR_MATERIAL);

    shaderProgram = new QOpenGLShaderProgram();
    shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, "./Shaders/simple.vert");
    shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, "./Shaders/simple.frag");
    shaderProgram->link();
    shaderProgram->bind();

    //QOpenGLVertexArrayObject* VAO = new QOpenGLVertexArrayObject();
    //QOpenGLBuffer* VBO = new QOpenGLBuffer();

    //VAO->create();
    //VAO->bind();

    //VBO->create();
    //VBO->bind();
    //VBO->allocate(testVerts, 9 * sizeof(float));

    ////VBO.bind();
    //glEnableVertexAttribArray(0);
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    ////VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);

    //VAO->release();
    //VBO->release();

    //VAOs.push_back(VAO);
    //VBOs.push_back(VBO);

    shaderProgram->release();
}

void myGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shaderProgram->bind();

    //VAO->bind();

    for (auto it = VAOs.begin(); it != VAOs.end(); it++) {
        (*it)->bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        (*it)->release();
    }

    //VAO->release();

    /*if (!triangleList->empty()) {
        float* vertices_ = triangleList->at(0).vertexBuffer
    }*/

    //glBegin(GL_TRIANGLES);
    ////glPushMatrix();
    //glColor3f(0.0, 1.0, 0.0);
    //glVertex3f(0.5, -0.5, 0);
    //glColor3f(1.0, 0.0, 0.0);
    //glVertex3f(-0.5, -0.5, 0);
    //glColor3f(0.0, 0.0, 1.0);
    //glVertex3f(0.0, 0.5, 0);
    ////glPopMatrix();
    //glEnd();

    /*  glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    GLUquadric* quad = gluNewQuadric();
    glPushMatrix();
    gluSphere(quad, .5, 50, 20);
    glTranslatef(.3, .3, 0);
    glPopMatrix();
    glEnd();*/

    shaderProgram->release();
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