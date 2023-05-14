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

    void crear_orilla();

    void keyPressEvent(QKeyEvent *event);

    void crear_est();



private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    cubos *cubo;
    bomberman *jugador;
    int vel;
    int vel_auto;

    QList<cubos*> cubo_orilla;
    QList<cubos*> cubo_est;
};

#endif // MAINWINDOW_H
