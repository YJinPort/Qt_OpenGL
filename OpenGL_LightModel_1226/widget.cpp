#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = yAngle = zAngle = 0;
    red = green = blue = 0.2;

    setWindowTitle("OpenGL LightModel");
    resize(300, 300);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    GLfloat arLight[] = {red, green, blue, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, arLight);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glutSolidTeapot(0.5);

    glPopMatrix();

    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_1:
        yAngle += 2;
        break;

    case Qt::Key_2:
        yAngle -= 2;
        break;

    case Qt::Key_3:
        xAngle += 2;
        break;

    case Qt::Key_4:
        xAngle -= 2;
        break;

    case Qt::Key_5:
        zAngle += 2;
        break;

    case Qt::Key_6:
        zAngle -= 2;
        break;

    case Qt::Key_0:
        xAngle = yAngle = zAngle = 0.0;
        break;

    case Qt::Key_A:
        red += 0.1;
        break;

    case Qt::Key_S:
        red -= 0.1;
        break;

    case Qt::Key_D:
        green += 0.1;
        break;

    case Qt::Key_F:
        green -= 0.1;
        break;

    case Qt::Key_G:
        blue += 0.1;
        break;

    case Qt::Key_H:
        blue -= 0.1;
        break;

    case Qt::Key_J:
        red = green = blue = 0.5;
        break;
    }

    QString str = QString("x: %1, y: %1 z: %1, red: %1, green: %1, blue: %1").arg(xAngle).arg(yAngle).arg(zAngle).arg(red).arg(green).arg(blue);
    setWindowTitle(str);

    update();
}
