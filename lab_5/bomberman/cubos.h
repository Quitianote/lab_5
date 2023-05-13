#ifndef CUBOS_H
#define CUBOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
class cubos : public QGraphicsPixmapItem {

public:

    void setScale(qreal scale);

    cubos(QGraphicsItem *carr = nullptr);
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


#endif // CUBOS_H

