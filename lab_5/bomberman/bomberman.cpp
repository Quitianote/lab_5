#include "bomberman.h"

bomberman::bomberman()
{

}
bomberman::bomberman(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/character.png"));
}


void soldado::posicion()
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
