#include "Nivel1.h"

Nivel1::Nivel1(Jugador *jugador) : Nivel(jugador) {
    timerGeneracion = new QTimer(this);
    connect(timerGeneracion, &QTimer::timeout, this, &Nivel1::generarObstaculo);
    timerGeneracion->start(2000);  
}

void Nivel1::cargar() {
    jugador->setPos(0, 500);
}

void Nivel1::actualizar() {
    for (Obstaculo *obstaculo : obstaculos) {
        obstaculo->mover();
    }
    jugador->mover();
    for (int i = 0; i < obstaculos.size(); ++i) {
        if (obstaculos[i]->x() < -50) {
            delete obstaculos[i];
            obstaculos.removeAt(i);
        }
    }
}

void Nivel1::generarObstaculo() {
    if (obstaculos.size() < 5) {
        Obstaculo *obstaculo = new Obstaculo(jugador);
        obstaculo->setPos(800, jugador->y());  
        obstaculos.append(obstaculo);
        jugador->scene()->addItem(obstaculo);
    }
}
