#include "Nivel2.h"

Nivel2::Nivel2(Jugador *jugador) : Nivel(jugador) {
    timerGeneracion = new QTimer(this);
    connect(timerGeneracion, &QTimer::timeout, this, &Nivel2::generarEnemigo);
    timerGeneracion->start(2000); 
}

void Nivel2::cargar() {
    jugador->setPos(0, 500);  
}

void Nivel2::actualizar() {
    for (Enemigo *enemigo : enemigos) {
        enemigo->mover();
        enemigo->atacar();
    }
    jugador->mover();
    for (int i = 0; i < enemigos.size(); ++i) {
        if (enemigos[i]->x() < -50 || enemigos[i]->x() > 850) {
            delete enemigos[i];
            enemigos.removeAt(i);
        }
    }
}

void Nivel2::generarEnemigo() {
    if (enemigos.size() < 5) {
        Enemigo *enemigo = new Enemigo(jugador);
        enemigo->setPos(800, qrand() % 600); 
        enemigos.append(enemigo);
        jugador->scene()->addItem(enemigo);
    }
}
