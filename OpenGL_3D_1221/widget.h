#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //Pyramid3D
    /*GLfloat xAngle, yAngle, zAngle;
    GLfloat bDepthTest;
    GLfloat bCullFace;*/

    //Culling3D
    /*GLboolean bCullFace;
    GLboolean bCcwFront;*/

    //PolygonMode3D
    /*GLfloat xAngle, yAngle, zAngle;
    GLenum polygonMode;
    GLenum shadeMode;*/

    //GLUT3D
    GLfloat xAngle, yAngle, zAngle;

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

protected:
    void keyPressEvent(QKeyEvent* event);
};
#endif // WIDGET_H
