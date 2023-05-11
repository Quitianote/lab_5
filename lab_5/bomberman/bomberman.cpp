#include "bomberman.h"
#include <Qpainter>

QRectF bomberman::boundingRect() const {
    return QRectF(0, 0, pixmap().width(), pixmap().height());
}

void bomberman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap());
}


bomberman::bomberman(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/character.png"));
}


void bomberman::posicion()
{
    setPos(x,y);
}

void bomberman::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

int bomberman::getX() const
{
    return x;
}

void bomberman::setX(int value)
{
    x = value;
}

int bomberman::getY() const
{
    return y;
}

void bomberman::setY(int value)
{
    y = value;
}

void bomberman::setScale(qreal scale) {
    QGraphicsPixmapItem::setScale(scale); // Usa la implementación del método en la clase base
}

