#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Jugador.h"

class Obstaculo : public QGraphicsPixmapItem {
public:
    Obstaculo(Jugador *jugador);
    void mover();

private slots:
    void actualizarCaida();

private:
    qreal velocidadY;
    qreal gravedad;
    Jugador *jugador;
    QTimer *timerCaida;
};

#endif 
