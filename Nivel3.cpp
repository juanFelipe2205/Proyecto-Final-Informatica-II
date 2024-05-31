#include "Nivel3.h"

Nivel3::Nivel3(Jugador *jugador) : Nivel(jugador), contadorHordas(0), jefeFinalGenerado(false) {}

void Nivel3::cargar() {
    jugador->setPos(400, 500); 
    generarHorda();
}

void Nivel3::actualizar() {
    for (Enemigo *enemigo : enemigos) {
        enemigo->atacar();
    }
    jugador->mover();
    if (enemigos.isEmpty() && !jefeFinalGenerado) {
        if (contadorHordas < 5) {
            generarHorda();
        } else {
            Enemigo *jefeFinal = new Enemigo();  
            jefeFinal->setPos(400, 400);
            enemigos.append(jefeFinal);
            jugador->scene()->addItem(jefeFinal);
            jefeFinalGenerado = true;
        }
    }
}

void Nivel3::generarHorda() {
    for (int i = 0; i < 5; ++i) {
        Enemigo *enemigo = new Enemigo();
        enemigo->setPos(100 * i, 500);
        enemigos.append(enemigo);
        jugador->scene()->addItem(enemigo);
    }
    contadorHordas++;
}
