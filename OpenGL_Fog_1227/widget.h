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

private:
    void keyPressEvent(QKeyEvent *event) override;

    void initializeGL( ) override;
    void paintGL( ) override;
    void resizeGL(int w, int h) override;

    int m_angle = 0, m_dist = 0;
    bool m_isFogOn;
};
#endif // WIDGET_H
