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

void myGLWidget::setReferences(std::vector<Sphere>& sphereList, std::vector<Triangle>& triangleList, std::vector<Cylinder>& cylinderList, std::vector<Light>& lightList, Camera* camera, int& width, int& height)
{
    this->sphereList = &sphereList;
    this->triangleList = &triangleList;
    this->cylinderList = &cylinderList;
    this->lightList = &lightList;
    this->sceneCamera = camera;
    this->width = &width;
    this->height = &height;
}

void myGLWidget::addNewTriangle()
{
    //Triangle* newTriangle = &triangleList->back();

    //makeCurrent();
    //shaderProgram->bind();
    //QOpenGLVertexArrayObject* VAO = new QOpenGLVertexArrayObject();
    //QOpenGLBuffer* VBO = new QOpenGLBuffer();

    //VAO->create();
    //VAO->bind();

    //VBO->create();
    //VBO->bind();
    //VBO->allocate(&newTriangle->vertexArray[0], 9 * sizeof(float));

    ////VBO.bind();
    //glEnableVertexAttribArray(0);
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    ////VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);

    //VAO->release();
    //VBO->release();

    //triangleVAOs.push_back(VAO);
    //triangleVBOs.push_back(VBO);
    //shaderProgram->release();
}

void myGLWidget::addNewSphere()
{
    //Sphere* newSphere = &sphereList->back();

    //makeCurrent();
    //shaderProgram->bind();
    //QOpenGLVertexArrayObject* VAO = new QOpenGLVertexArrayObject();
    //QOpenGLBuffer* VBO = new QOpenGLBuffer();

    //VAO->create();
    //VAO->bind();

    //VBO->create();
    //VBO->bind();
    //VBO->allocate(&newSphere->vertexArray[0], 9 * sizeof(float));

    ////VBO.bind();
    //glEnableVertexAttribArray(0);
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    ////VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);

    //VAO->release();
    //VBO->release();

    //triangleVAOs.push_back(VAO);
    //triangleVBOs.push_back(VBO);
    //shaderProgram->release();
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

    //VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);

    //VAO->release();
    //VBO->release();

    //triangleVAOs.push_back(VAO);
    //triangleVBOs.push_back(VBO);

    shaderProgram->release();
}

void myGLWidget::test()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //shaderProgram->bind();

    for (auto it = triangleList->begin(); it != triangleList->end(); it++) {
        //glMatrixMode(GL_MODELVIEW);
        //glPushMatrix();
        RGBR_f color = (*it).GetColor();
        glColor3f(color.r / 255.f, color.g / 255.f, color.b / 255.f);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, &(*it).vertexArray[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glPopMatrix();
    }

    //for (auto it = cylinderList->begin(); it != cylinderList->end(); it++) {
    //    //glMatrixMode(GL_MODELVIEW);
    //    //glPushMatrix();
    //    //glColor3f(1, 1, 0);
    //    ////glEnableClientState(GL_VERTEX_ARRAY);
    //    ////glVertexPointer(3, GL_FLOAT, 0, &(*it).vertexArray[0]);
    //    ////glDrawArrays(GL_TRIANGLES, 0, 3);
    //    //glPopMatrix();
    //}

    for (auto it = sphereList->begin(); it != sphereList->end(); it++) {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        RGBR_f color = (*it).GetColor();
        glColor3f(color.r / 255.f, color.g / 255.f, color.b / 255.f);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);

        glVertexPointer(3, GL_FLOAT, 0, &(*it).vertices[0]);
        glNormalPointer(GL_FLOAT, 0, &(*it).normals[0]);

        STVector3 spherePos = (*it).getPos();
        glTranslatef(spherePos.x, spherePos.y, spherePos.z);

        glDrawElements(GL_TRIANGLES, (*it).indices.size(), GL_UNSIGNED_INT, &(*it).indices[0]);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);

        glPopMatrix();
    }

    //shaderProgram->release();
}

void myGLWidget::paintGL()
{
    test();
}

void myGLWidget::resizeGL(int w, int h)
{
    *width = w;
    *height = h;
    STVector3 camPos = sceneCamera->Position();
    STVector3 camLookAt = sceneCamera->LookAt();
    STVector3 camUp = sceneCamera->Up();
    int halfW = w / 2;
    int halfh = h / 2;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / (float)h, 0.001, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(camPos.x, camPos.y, camPos.z);
    gluLookAt(camLookAt.x, camLookAt.y, camLookAt.z, 0, 0, 0, camUp.x, camUp.y, camUp.z);
}