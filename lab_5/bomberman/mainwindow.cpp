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

    timer_explo =  new QTimer;
    connect(timer_explo,SIGNAL(timeout()),this, SLOT(explosion()));

    timer_linea =  new QTimer;
    connect(timer_linea,SIGNAL(timeout()),this, SLOT(dest_linea()));

    crear_temp();//cubos que se pueden destruir





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

    if(event->key()== Qt::Key_S && jugador->getY()<scene->height()-40){
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

    if(event->key()== Qt::Key_Space){
        if(!timer_explo->isActive()){
            bomba = new bomb(nullptr);
            bomba->posicion((jugador->getX() - 5),jugador->getY());
            bomba->setScale(0.1);
            scene->addItem(bomba);
            timer_explo->start(2000);
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

bool MainWindow::col_temp1(QGraphicsLineItem *line_temp){//verifica que no sea solido
    QList<cubos*>::iterator
            it (cubo_est.begin()),
            end (cubo_est.end());
    for(; it != end; it ++){
        if(line_temp->collidesWithItem((*it))) return true;
    }
    return false;
}

bool MainWindow::col_temp2(QGraphicsLineItem *line_temp){//ahora mira si es temp
    if(cubos_temp.isEmpty()) return false;
    else{
        QList<cub_temp*>::iterator
            it (cubos_temp.begin()),
            end (cubos_temp.end());

        for(; it != end; it ++){
            if(line_temp->collidesWithItem((*it))){
                cubos_temp.removeAt(cubos_temp.indexOf((*it)));
                delete (*it);
                return true;
            }
        }
        return false;
    }
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
        x += cubo_orilla.last()->pixmap().height()*7;
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

void MainWindow::explosion(){
    delete bomba;

    crear_linea();
    QList<QGraphicsLineItem*>::iterator
            it (lines.begin()),
            end(lines.end());

    for(; it != end; it ++){
        if(col_temp1((*it)));
        else if(col_temp2((*it)));
        else int a;
    }


    timer_linea->start(1500);

    timer_explo->stop();
}

void MainWindow::crear_temp(){
    int x = 49;
    int y = 350;
    cubos_temp.append(new cub_temp(nullptr));
    cubos_temp.last()->setScale(2.47);

    cubos_temp.last()->posicion(49,253);
    scene->addItem(cubos_temp.last());

    cubos_temp.append(new cub_temp(nullptr));
    cubos_temp.last()->setScale(2.47);

    cubos_temp.last()->posicion(49,155);
    scene->addItem(cubos_temp.last());

    for(int i = 0; i < 4; i ++){
        cubos_temp.append(new cub_temp(nullptr));
        cubos_temp.last()->setScale(2.47);

        cubos_temp.last()->posicion(x,y);
        scene->addItem(cubos_temp.last());
        x += cubos_temp.last()->pixmap().width()*2.47;
        x ++;
    }

    /*x += cubos_temp.last()->pixmap().width()*2.47;
    for(int i = 0; i < 6; i ++){
        cubos_temp.append(new cub_temp(nullptr));
        cubos_temp.last()->setScale(2.47);

        cubos_temp.last()->posicion(x,y);
        scene->addItem(cubos_temp.last());
        x += cubos_temp.last()->pixmap().width()*2.47;
    }*/
}

void MainWindow::crear_linea(){
    //if(!lines.isEmpty()) lines.clear();
    line_right = new QGraphicsLineItem(bomba->getX() + 25, bomba->getY() + 17, bomba->getX() + 60, bomba->getY() + 17);
    QPen pen_right(Qt::red); // Color rojo
    pen_right.setWidth(1); // Grosor de 5
    line_right->setPen(pen_right);
    line_right->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(line_right);

    line_up = new QGraphicsLineItem(bomba->getX() + 17, bomba->getY() + 21, bomba->getX() + 17, bomba->getY() - 20);
    QPen pen_up(Qt::red); // Color rojo
    pen_up.setWidth(1); // Grosor de 5
    line_up->setPen(pen_up);
    line_up->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(line_up);

    line_left = new QGraphicsLineItem(bomba->getX() + 25, bomba->getY() + 17, bomba->getX() - 25, bomba->getY() + 17);
    QPen pen_left(Qt::red); // Color rojo
    pen_left.setWidth(1); // Grosor de 5
    line_left->setPen(pen_left);
    line_left->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(line_left);

    line_down = new QGraphicsLineItem(bomba->getX() + 17, bomba->getY() + 21, bomba->getX() + 17, bomba->getY() + 50);
    QPen pen_down(Qt::red); // Color rojo
    pen_down.setWidth(1); // Grosor de 5
    line_down->setPen(pen_down);
    line_down->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(line_down);

    lines.append(line_right);
    lines.append(line_up);
    lines.append(line_left);
    lines.append(line_down);
}

void MainWindow::dest_linea(){
    lines.clear();
    delete line_up;
    delete line_down;
    delete line_left;
    delete line_right;

    timer_linea->stop();
}

//segundo: colocar los bloques que se van a destruir
//tercero: colocar funcion para que se destruyan los bloques
//cuarto: metele efectos, tiempo
//quinto: enemigos y vidas
