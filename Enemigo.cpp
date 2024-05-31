#include "Enemigo.h"

Enemigo::Enemigo() 
    : amplitud(50), frecuencia(0.05), fase(0) {
    setPixmap(QPixmap(":/images/enemigo.png"));
    timerMovimiento = new QTimer(this);
    connect(timerMovimiento, &QTimer::timeout, this, &Enemigo::actualizarMovimiento);
    timerMovimiento->start(16);
}

void Enemigo::atacar() {
    // Por implementar
}

void Enemigo::actualizarMovimiento() {
    setPos(x() + amplitud * qSin(fase), y());
    fase += frecuencia;
    if (fase >= 2 * M_PI) {
        fase = 0;
    }
}

void Enemigo::mover() {
    // Por implementar
}
