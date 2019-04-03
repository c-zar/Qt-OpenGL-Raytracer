#pragma once

#include <QtWidgets/qopenglwidget.h>
#include <QtWidgets/qwidget.h>

class myGLWidget : public QOpenGLWidget {
    Q_OBJECT
public:
    myGLWidget(QWidget* parent = 0);
    ~myGLWidget();

private:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};