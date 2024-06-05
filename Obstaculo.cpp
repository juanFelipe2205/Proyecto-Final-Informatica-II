#include "Obstaculo.h"
#include <QGraphicsScene>

Obstaculo::Obstaculo(Jugador *jugador, bool movimientoHorizontal)
    : jugador(jugador), velocidad(5), movimientoHorizontal(movimientoHorizontal) {
    setPixmap(QPixmap(":/images/obstaculo.png"));
    timerMovimiento = new QTimer(this);
    if (movimientoHorizontal) {
        connect(timerMovimiento, &QTimer::timeout, this, &Obstaculo::mover);
    } else {
        connect(timerMovimiento, &QTimer::timeout, this, &Obstaculo::moverCaidaLibre);
    }
    timerMovimiento->start(16);
}

void Obstaculo::mover() {
    setPos(x() - velocidad, y());

    if (x() < -50) {
        scene()->removeItem(this);
        delete this;
    }
}

void Obstaculo::moverCaidaLibre() {
    setPos(x(), y() + velocidad);

    if (y() > 600) {
        scene()->removeItem(this);
        delete this;
    }
}
