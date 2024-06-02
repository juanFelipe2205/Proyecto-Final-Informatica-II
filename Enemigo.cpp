#include "Enemigo.h"
#include <QtMath>
#include <QGraphicsScene>

Enemigo::Enemigo(Jugador *jugador) 
    : jugador(jugador), velocidad(2) {
    setPixmap(QPixmap(":/images/enemigo.png"));
    timerMovimiento = new QTimer(this);
    connect(timerMovimiento, &QTimer::timeout, this, &Enemigo::mover);
    timerMovimiento->start(16);
}

void Enemigo::atacar() {
    qreal dx = jugador->x() - x();
    qreal dy = jugador->y() - y();
    qreal distancia = qSqrt(dx*dx + dy*dy);
    
    if (distancia < 10) {  
        jugador->reducirVida(1);
    }
}

void Enemigo::mover() {
    qreal dx = jugador->x() - x();
    qreal dy = jugador->y() - y();
    qreal distancia = qSqrt(dx*dx + dy*dy);
    
    if (distancia > 0) {
        setPos(x() + velocidad * (dx / distancia), y() + velocidad * (dy / distancia));
    }
    
    atacar();
}
