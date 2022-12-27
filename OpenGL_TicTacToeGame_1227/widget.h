#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
#include <GL/glut.h>
#include <QTimer>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void initializeGL( );
    void paintGL( );
    void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    void init_game( );
    int check_move( );
    int blocking_win( );
    int check_corner( );
    int check_row( );
    int computer_move( );

    void Sprint(int x, int y, QString st);
    void Draw_O(int x, int y, int z, int a);
    void Draw_X(int x, int y, int z, int a);

    void play_x( );
    void play_y( );
    QTimer timer;

    // mouse variables: Win = windows size, mouse = mouse position
    int mouse_x, mouse_y, win_x, win_y, object_select;

    // state variables for Orho/Perspective view, lighting on/off
    int view_state, light_state;

    // Use to spin X's and O's
    int spin, spinboxes;

    // Win = 1 player wins, -1 computer wins, 2 tie.
    // player or computer; 1 = X, -1 = O
    // start_game indicates that game is in play.
    int player, computer, win, start_game;

    // quadric pointer for build our X
    GLUquadricObj *Cylinder;

    // Storage for our game board
    // 1 = X's, -1 = O's, 0 = open space
    int box_map[9];

private slots:
    void updateTimer( );
};
#endif // WIDGET_H
