#include "Obstaculo.h"

Obstaculo::Obstaculo() 
    : velocidadY(0), gravedad(0.5) {
    setPixmap(QPixmap(":/images/obstaculo.png"));
    timerCaida = new QTimer(this);
    connect(timerCaida, &QTimer::timeout, this, &Obstaculo::actualizarCaida);
    timerCaida->start(16);
}

void Obstaculo::actualizarCaida() {
    setPos(x(), y() + velocidadY);
    velocidadY += gravedad;
    if (y() >= 500) { 
        setPos(x(), 500);
        timerCaida->stop();
    }
}

void Obstaculo::mover() {
    // Por implementar
}
