#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsPixmapItem>

class Obstaculo : public QGraphicsPixmapItem {
public:
    Obstaculo();
    void mover();

private:
    QPointF posicion;
};

#endif
