#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
class bomberman : public QGraphicsPixmapItem {

public:

    void setScale(qreal scale);

    bomberman(QGraphicsItem *carr = nullptr);
    void posicion();
    void posicion(int newX, int newY);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    int x,y;
};


#endif // BOMBERMAN_H
