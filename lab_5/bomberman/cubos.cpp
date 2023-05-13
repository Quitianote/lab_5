#include "cubos.h"
#include <Qpainter>

QRectF cubos::boundingRect() const {
    return QRectF(0, 0, pixmap().width(), pixmap().height());
}


void cubos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap());
}




cubos::cubos(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/cube32.png"));
}

void cubos::posicion()
{
    setPos(x,y);
}

void cubos::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}


int cubos::getX() const
{
    return x;
}

void cubos::setX(int value)
{
    x = value;
}

int cubos::getY() const
{
    return y;
}

void cubos::setY(int value)
{
    y = value;
}


void cubos::setScale(qreal scale) {
    QGraphicsPixmapItem::setScale(scale);
}

