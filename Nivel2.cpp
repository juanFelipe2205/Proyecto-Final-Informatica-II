#include "Nivel2.h"

Nivel2::Nivel2(Jugador *jugador) : Nivel(jugador) {}

void Nivel2::cargar() {
    jugador->setPos(0, 500);  
    Enemigo *enemigo1 = new Enemigo();
    enemigo1->setPos(400, 500);
    enemigos.append(enemigo1);

    Enemigo *enemigo2 = new Enemigo();
    enemigo2->setPos(800, 500);
    enemigos.append(enemigo2);

    for (Enemigo *enemigo : enemigos) {
        jugador->scene()->addItem(enemigo);
    }
}

void Nivel2::actualizar() {
    for (Enemigo *enemigo : enemigos) {
        enemigo->mover();
        enemigo->atacar();
    }
    jugador->mover();
    // Por implementar
}
