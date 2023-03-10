#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Animation");
    resize(600, 600);
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
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    /*glBegin(GL_TRIANGLES);
    GLfloat x = -0.8;
    GLfloat y = 0.4;
    for(int i = 0; i < 6; i++) {
        glVertex2f(x, y);
        x += 0.3;
        y *= -1;
    }*/

    /*glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLE_STRIP);
    GLfloat x = -0.8;
    GLfloat y = 0.4;

    for(int i = 0; i < 6; i++) {
        if(i % 2 == 0) {
            glColor3f(1.0, 0.0, 0.0);
        }
        else {
            glColor3f(0.0, 1.0, 0.0);
        }
        glVertex2f(x, y);
        x += 0.3;
        y *= -1;
    }*/

    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.35, 0.35);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.5, 0.0);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.35, -0.35);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, -0.5);

    glEnd();
    glFlush();
}
