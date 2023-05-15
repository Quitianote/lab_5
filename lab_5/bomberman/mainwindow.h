#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QDebug>
#include "bomberman.h"
#include "cubos.h"
#include "bomb.h"
#include "cub_temp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool col_est();

    bool col_temp1(QGraphicsLineItem *line_temp);

    bool col_temp2(QGraphicsLineItem *line_temp);

    bool col_temp3(QGraphicsLineItem *line_temp);

    void crear_orilla();

    void keyPressEvent(QKeyEvent *event);

    void crear_est();

    void crear_temp();

    void crear_linea();

private slots:
    void explosion();
    void dest_linea();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    cub_temp *alfa;
    cubos *cubo;
    bomberman *jugador;
    bomb *bomba;
    QGraphicsLineItem *line_right;
    QGraphicsLineItem *line_up;
    QGraphicsLineItem *line_left;
    QGraphicsLineItem *line_down;
    int vel;
    int vel_auto;

    QTimer *timer_explo;
    QTimer *timer_linea;
    QList<QGraphicsLineItem*> lines;
    QList<cubos*> cubo_orilla;
    QList<cubos*> cubo_est;
    QList<cub_temp*> cubos_temp;
};

#endif // MAINWINDOW_H
