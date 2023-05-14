#include "bomb.h"
#include <Qpainter>

QRectF bomb::boundingRect() const {
    return QRectF(0, 0, pixmap().width(), pixmap().height());
}

void bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap());
}


bomb::bomb(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/bomba.png"));
}


void bomb::posicion()
{
    setPos(x,y);
}

void bomb::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

int bomb::getX() const
{
    return x;
}

void bomb::setX(int value)
{
    x = value;
}

int bomb::getY() const
{
    return y;
}

void bomb::setY(int value)
{
    y = value;
}

void bomb::setScale(qreal scale) {
    QGraphicsPixmapItem::setScale(scale);
}

