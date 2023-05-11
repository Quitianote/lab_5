#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene();
    scene->setSceneRect(0,0,420,420);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

    jugador = new bomberman(nullptr);
    jugador->setScale(2.5);


    jugador->posicion(270,270);
    scene->addItem(jugador);
    vel=5;
    vel_auto=1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hmov()
{
    if(jugador->getX()<scene->width()-36) jugador->posicion(jugador->getX()+vel_auto,jugador->getY());
    else {
        vel_auto *= -1;
        jugador->posicion(scene->width()-36+vel_auto,jugador->getY());
    }

    if(jugador->getX()>0) jugador->posicion(jugador->getX()+vel_auto,jugador->getY());
    else {
        vel_auto *= -1;
        jugador->posicion(0+vel_auto,jugador->getY());
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()== Qt::Key_F4) close();

    if(event->key()== Qt::Key_A && jugador->getX()>0){
        jugador->setX(jugador->getX()-vel);

    }

    if(event->key()== Qt::Key_S && jugador->getY()<scene->height()-55){
        jugador->setY(jugador->getY()+vel);

    }

    if(event->key()== Qt::Key_D && jugador->getX()<scene->width()-36){
        jugador->setX(jugador->getX()+vel);

    }

    if(event->key()== Qt::Key_W && jugador->getY()>0){
        jugador->setY(jugador->getY()-vel);


    }

    jugador->posicion();
}

