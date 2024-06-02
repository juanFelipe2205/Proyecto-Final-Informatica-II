#include "Enemigo.h"
#include <QtMath>
#include <QGraphicsScene>

Enemigo::Enemigo(Jugador *jugador, int vida) 
    : jugador(jugador), velocidad(2), vida(vida) {
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

void Enemigo::reducirVida(int cantidad) {
    vida -= cantidad;
    if (vida <= 0) {
        scene()->removeItem(this);
        delete this;
    }
}

int Enemigo::getVida() const {
    return vida;
}
