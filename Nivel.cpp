#include "Nivel.h"

Nivel::Nivel(Jugador *jugador) : jugador(jugador) {}

void Nivel::cargar() {
    jugador->setPos(100, 500);  
    Obstaculo *obstaculo1 = new Obstaculo();
    obstaculo1->setPos(300, 500);
    obstaculos.append(obstaculo1);

    Obstaculo *obstaculo2 = new Obstaculo();
    obstaculo2->setPos(500, 500);
    obstaculos.append(obstaculo2);
    Enemigo *enemigo1 = new Enemigo();
    enemigo1->setPos(700, 500);
    enemigos.append(enemigo1);
    for (Obstaculo *obstaculo : obstaculos) {
        jugador->scene()->addItem(obstaculo);
    }

    for (Enemigo *enemigo : enemigos) {
        jugador->scene()->addItem(enemigo);
    }
}

void Nivel::actualizar() {
    for (Obstaculo *obstaculo : obstaculos) {
        obstaculo->mover();
    }

    for (Enemigo *enemigo : enemigos) {
        enemigo->atacar();
    }

    jugador->mover();
}
