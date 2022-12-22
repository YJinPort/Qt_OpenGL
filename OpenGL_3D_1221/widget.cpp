#include "widget.h"
#include <GL/glut.h>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    //Pyramid3D
    /*bDepthTest = GL_TRUE;
    bCullFace = GL_FALSE;*/

    //Culling3D
    /*bCullFace = GL_FALSE;
    bCcwFront = GL_TRUE;*/

    //PolygonMode3D
    /*polygonMode = GL_FILL;
    shadeMode = GL_FLAT;*/

    //GLUT3D
    setWindowTitle("OpenGL GLUT3D");

    //setWindowTitle("OpenGL PolygonMode3D");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Widget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    //Pyramid3D
    /*glShadeModel(GL_FLAT);

    if(bDepthTest) glEnable(GL_DEPTH_TEST);
    else glDisable(GL_DEPTH_TEST);

    if(bCullFace) glEnable(GL_CULL_FACE);
    else glDisable(GL_CULL_FACE);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 1);
    glVertex3f(0.0, 0.0, -0.8);
    glColor3f(1, 0, 0);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);

    glColor3f(1, 1, 0);
    glVertex2f(-0.5, -0.5);

    glColor3f(0, 1, 0);
    glVertex2f(0.5, -0.5);

    glColor3f(0, 0, 1);
    glVertex2f(0.5, 0.5);
    glEnd();

    glPopMatrix();*/

    //Culling3D
    /*if(bCullFace) glEnable(GL_CULL_FACE);
    else glDisable(GL_CULL_FACE);

    glFrontFace(bCcwFront ? GL_CCW : GL_CW);

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.1, -0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.9, -0.5);
    glVertex2f(0.1, -0.5);
    glEnd();*/

    //PolygonMode3D
    /*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    glShadeModel(shadeMode);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 1);
    glVertex3f(0.0, 0.0, -0.8);
    glColor3f(1, 0, 0);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);

    glColor3f(1, 1, 0);
    glVertex2f(-0.5, -0.5);

    glColor3f(0, 1, 0);
    glVertex2f(0.5, -0.5);

    glColor3f(0, 0, 1);
    glVertex2f(0.5, 0.5);
    glEnd();

    glPopMatrix();*/

    //GLUT3D
    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glutWireTeapot(0.3);

    glPushMatrix();
    glTranslatef(-0.6, 0.6, 0.0);
    glutWireCube(0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6, -0.6, 0.0);
    glutWireSphere(0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.6, 0.0);
    glutWireCone(0.3, 0.6, 20, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, -0.6, 0.0);
    glutWireTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    glPopMatrix();

    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event) {
    //Pyramid3D
    /*switch(event->key()) {
    case Qt::Key_Up:
        bDepthTest = GL_TRUE;
        break;

    case Qt::Key_Down:
        bDepthTest = GL_FALSE;
        break;

    case Qt::Key_Left:
        bCullFace = GL_TRUE;
        break;

    case Qt::Key_Right:
        bCullFace = GL_FALSE;
        break;

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
    }

    QString str = QString("Pyramid3D -> x: %1, y: %2, z: %3").arg(xAngle).arg(yAngle).arg(zAngle);

    setWindowTitle(str);*/

    //Culling3D
    /*switch(event->key()) {
    case Qt::Key_Up:
        bCullFace = GL_TRUE;
        break;

    case Qt::Key_Down:
        bCullFace = GL_FALSE;
        break;

    case Qt::Key_Left:
        bCcwFront = GL_TRUE;
        break;

    case Qt::Key_Right:
        bCcwFront = GL_FALSE;
        break;
    }

    QString str = QString("Cull: %s, Front: %s").arg(bCullFace ? "ON" : "OFF").arg(bCcwFront ? "CCW" : "CW");

    setWindowTitle(str);*/

    //PolygonMode3D
    /*switch(event->key()) {
    case Qt::Key_Up:
        yAngle += 2;
        break;

    case Qt::Key_Down:
        yAngle -= 2;
        break;

    case Qt::Key_Left:
        xAngle += 2;
        break;

    case Qt::Key_Right:
        xAngle -=  2;
        break;
    case Qt::Key_1:
        polygonMode = GL_POINT;
        break;

    case Qt::Key_2:
        polygonMode = GL_LINE;
        break;

    case Qt::Key_3:
        polygonMode = GL_FILL;
        break;

    case Qt::Key_4:
        shadeMode = GL_SMOOTH;
        break;

    case Qt::Key_5:
        shadeMode = GL_FLAT;
        break;
    }*/

    //GLUT3D

    update();
}
