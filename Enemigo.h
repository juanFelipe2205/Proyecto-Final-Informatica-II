#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Jugador.h"

class Enemigo : public QGraphicsPixmapItem {
public:
    Enemigo(Jugador *jugador);
    void atacar();
    void mover();

private:
    Jugador *jugador;
    qreal velocidad;
    QTimer *timerMovimiento;
};

#endif 


