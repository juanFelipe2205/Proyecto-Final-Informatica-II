#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Jugador.h"

class Enemigo : public QGraphicsPixmapItem {
public:
    Enemigo(Jugador *jugador, int vida = 2);
    void atacar();
    void mover();
    void reducirVida(int cantidad);
    int getVida() const;

private:
    Jugador *jugador;
    qreal velocidad;
    int vida;
    QTimer *timerMovimiento;
};

#endif 
