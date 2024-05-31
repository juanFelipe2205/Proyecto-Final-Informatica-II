#include "Nivel1.h"

Nivel1::Nivel1(Jugador *jugador) : Nivel(jugador) {}

void Nivel1::cargar() {
    jugador->setPos(0, 500);  
    Obstaculo *obstaculo1 = new Obstaculo();
    obstaculo1->setPos(300, 500);
    obstaculos.append(obstaculo1);

    Obstaculo *obstaculo2 = new Obstaculo();
    obstaculo2->setPos(600, 500);
    obstaculos.append(obstaculo2);

    for (Obstaculo *obstaculo : obstaculos) {
        jugador->scene()->addItem(obstaculo);
    }
}

void Nivel1::actualizar() {
    for (Obstaculo *obstaculo : obstaculos) {
        obstaculo->mover();
    }
    jugador->mover();
}
