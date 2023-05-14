#include "cub_temp.h"
#include <Qpainter>

QRectF cub_temp::boundingRect() const {
    return QRectF(0, 0, pixmap().width(), pixmap().height());
}


void cub_temp::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap());
}

cub_temp::cub_temp(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/destru.png"));
}

void cub_temp::posicion()
{
    setPos(x,y);
}

void cub_temp::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}


int cub_temp::getX() const
{
    return x;
}

void cub_temp::setX(int value)
{
    x = value;
}

int cub_temp::getY() const
{
    return y;
}

void cub_temp::setY(int value)
{
    y = value;
}


void cub_temp::setScale(qreal scale) {
    QGraphicsPixmapItem::setScale(scale);
}

