#ifndef CUB_TEMP_H
#define CUB_TEMP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class cub_temp :  public QGraphicsPixmapItem {

public:

    void setScale(qreal scale);

    cub_temp(QGraphicsItem *carr = nullptr);
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

#endif // CUB_TEMP_H
