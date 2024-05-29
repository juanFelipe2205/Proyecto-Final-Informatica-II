#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>

class Enemigo : public QGraphicsPixmapItem {
public:
    Enemigo();
    void atacar();

private:
    int vida;
    QPointF posicion;
};

#endif 
