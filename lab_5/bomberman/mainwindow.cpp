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
    QGraphicsLineItem *linea = new QGraphicsLineItem(0, 105, 700, 106);
    scene->addItem(linea);



    jugador = new bomberman(nullptr);
    jugador->setScale(1.5);

    crear_orilla();

    jugador->posicion(0,270);
    scene->addItem(jugador);

    crear_est();//cubos estaticos crear

    vel=5;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()== Qt::Key_F4) close();

    if(event->key()== Qt::Key_A && jugador->getX()>4){
        jugador->setX(jugador->getX()-vel);
        if (col_est()) {
            jugador->setX(jugador->getX()+(vel*3));
        }
    }

    if(event->key()== Qt::Key_S && jugador->getY()<scene->height()-50){
        jugador->setY(jugador->getY()+vel);
        if (col_est()) {
            jugador->setY(jugador->getY()-(vel*3));
        }
    }

    if(event->key()== Qt::Key_D && jugador->getX()<scene->width()-34){
        jugador->setX(jugador->getX()+vel);
        if (col_est()) {
            jugador->setX(jugador->getX()-(vel*3));
        }
    }

    if(event->key()== Qt::Key_W && jugador->getY()>109){
        jugador->setY(jugador->getY()-vel);
        if (col_est()) {
            jugador->setY(jugador->getY()+(vel*3));
        }
    }

    jugador->posicion();
}


bool MainWindow::col_est(){
    QList<cubos*>::iterator
            it (cubo_est.begin()),
            end (cubo_est.end());
    for(; it != end; it ++){
        if(jugador->collidesWithItem((*it))) return true;
    }
    return false;
}

void MainWindow::crear_orilla(){
    int x = 0;
    int y = 400;

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


}

void MainWindow::crear_est(){
    int x = 49;
    int y = 106;

    for(int i = 0; i < 7; i ++){
        cubo_est.append(new cubos(nullptr));//arriba
        cubo_est.last()->setScale(7.0);
        cubo_est.last()->posicion(x,y);
        scene->addItem(cubo_est.last());
        x += cubo_est.last()->pixmap().width()*14;//14 porque se multiplica por 7 por la escala que le aumente y luego le multiplico 2 porque son cada dos bloques, y pos 2*7 es 14
    }
        x = 49;
        y = 204;

    for(int i = 0; i < 7; i ++){
        cubo_est.append(new cubos(nullptr));//abajo
        cubo_est.last()->setScale(7.0);
        cubo_est.last()->posicion(x,y);
        scene->addItem(cubo_est.last());
        x += cubo_est.last()->pixmap().width()*14;
    }

        x = 49;
        y = 302;

    for(int i = 0; i < 7; i ++){
        cubo_est.append(new cubos(nullptr));//abajo
        cubo_est.last()->setScale(7.0);
        cubo_est.last()->posicion(x,y);
        scene->addItem(cubo_est.last());
        x += cubo_est.last()->pixmap().width()*14;
    }
}
//primero: agrega la bomba, que despues de unos segundos desaparezca
//segundo: colocar los bloques que se van a destruir
//tercero: colocar funcion para que se destruyan los bloques
//cuarto: metelo efectos, tiempo
//quinto: enemigos y vidas
