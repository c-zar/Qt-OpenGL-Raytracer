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
    /*makeCurrent();

    QOpenGLVertexArrayObject VAO, VBO;
    float* vertices_ = triangleList->at(0).vertexBuffer;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), &vertices_, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);
    glBindVertexArray(0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);*/

    //VAO.release();
    //VBO.release();
    //update();
}

void myGLWidget::initializeGL()
{
    //context = new QOpenGLContext(this);
    //context->create();

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
    shaderProgram->bindAttributeLocation("vertex", 0);
    shaderProgram->link();
    shaderProgram->bind();

    VAO.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&VAO);
    //shaderProgram->setAttributeBuffer(0, GL_FLOAT, 0, 3);

    VBO.create();
    VBO.bind();
    VBO.allocate(testVerts, 9 * sizeof(float));

    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();

    //VBO.bind();
    f->glEnableVertexAttribArray(0);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    //VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);

    //VAO.release();
    VBO.release();

    shaderProgram->release();
}

void myGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shaderProgram->bind();

    VAO.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    VAO.release();

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