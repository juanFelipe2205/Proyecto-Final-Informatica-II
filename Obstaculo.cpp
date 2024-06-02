#include "Obstaculo.h"
#include <QGraphicsScene>

Obstaculo::Obstaculo(Jugador *jugador) 
    : velocidadY(0), gravedad(0.5), jugador(jugador) {
    setPixmap(QPixmap(":/images/obstaculo.png"));
    timerCaida = new QTimer(this);
    connect(timerCaida, &QTimer::timeout, this, &Obstaculo::actualizarCaida);
    timerCaida->start(16);
}

void Obstaculo::actualizarCaida() {
    setPos(x(), y() + velocidadY);
    velocidadY += gravedad;

    // Detectar colisión con el jugador
    if (collidesWithItem(jugador)) {
        jugador->reducirVida(1);
        scene()->removeItem(this);
        delete this;
        return;
    if (y() >= 500) {  
        setPos(x(), 500);
        timerCaida->stop();
    }
}

void Obstaculo::mover() {
    //Nada que implementar de momento
}
