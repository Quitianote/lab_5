#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene();
    scene->setSceneRect(0,7,686,400);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    QGraphicsLineItem *linea = new QGraphicsLineItem(0, 100, 700, 100);
    scene->addItem(linea);



    jugador = new bomberman(nullptr);
    jugador->setScale(2.0);

    crear_orilla();

    jugador->posicion(270,270);
    scene->addItem(jugador);


    for(int pos_cubo = 0; pos_cubo < 7; pos_cubo ++){

    }

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

    if(event->key()== Qt::Key_A && jugador->getX()>4){
        jugador->setX(jugador->getX()-vel);

    }

    if(event->key()== Qt::Key_S && jugador->getY()<scene->height()-50){
        jugador->setY(jugador->getY()+vel);

    }

    if(event->key()== Qt::Key_D && jugador->getX()<scene->width()-34){
        jugador->setX(jugador->getX()+vel);

    }

    if(event->key()== Qt::Key_W && jugador->getY()>11){
        jugador->setY(jugador->getY()-vel);


    }

    jugador->posicion();
}

void MainWindow::crear_orilla(){
    int x = 0;
    int y = 400;
    cubo = new cubos(nullptr);
    cubo->setScale(7.0);
    cubo->posicion(170,351);
    scene->addItem(cubo);

    for(int i = 0; i < 14; i ++){//abajo
        cubo_orilla.append(new cubos(nullptr));
        cubo_orilla.last()->setScale(7.0);
        cubo_orilla.last()->posicion(x,y);
        scene->addItem(cubo_orilla.last());
        x += cubo_orilla.last()->pixmap().width() * 7;//obteniendo anchura escalada del cubo
    }
    x = 686;
    y = 8;
    for(int i = 0; i < 9; i ++){//lados
        cubo_orilla.append(new cubos(nullptr));//izquierda cubo
        cubo_orilla.last()->setScale(7.0);
        cubo_orilla.last()->posicion(-cubo_orilla.last()->pixmap().width() * 7,y);
        scene->addItem(cubo_orilla.last());

        cubo_orilla.append(new cubos(nullptr));//derecha cubo
        cubo_orilla.last()->setScale(7.0);
        cubo_orilla.last()->posicion(x,y);
        scene->addItem(cubo_orilla.last());
        y += cubo_orilla.last()->pixmap().height() * 7;//obteniendo anchura escalada del cubo

    }
    x = 0;
    for(int i = 0; i < 16; i ++){//arriba
        cubo_orilla.append(new cubos(nullptr));
        cubo_orilla.last()->setScale(7.0);
        cubo_orilla.last()->posicion(-cubo_orilla.last()->pixmap().height() * 7 + x,(-cubo_orilla.last()->pixmap().width() * 7) + 7);
        scene->addItem(cubo_orilla.last());
        x += cubo_orilla.last()->pixmap().height() * 7;
    }

    // cubo_orilla.last()->pixmap().width();

    /*
    cubo_orilla.append(new cubos(nullptr));
    cubo_orilla.last()->setScale(7.0);
    cubo_orilla.last()->posicion(-cubo_orilla.last()->pixmap().height() * 7,(-cubo_orilla.last()->pixmap().width() * 7) + 7);
    scene->addItem(cubo_orilla.last());;*/


}

bool MainWindow::col_soli(){
    QList::iterator
            it (cubo_orilla.begin()),
            end (cubo_orilla.end());

    for(; it != end; it ++){


    }
}
