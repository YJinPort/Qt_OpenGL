#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
#include <GL/glut.h>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    GLfloat xAngle, yAngle, zAngle;
    GLfloat red, green, blue;
    GLboolean bColorTrack;

private:
     void initializeGL( ) override;
     void paintGL( ) override;
     void resizeGL(int w, int h) override;

protected:
     void keyPressEvent(QKeyEvent* event);
};
#endif // WIDGET_H
