#include "Nivel3.h"

Nivel3::Nivel3(Jugador *jugador) : Nivel(jugador), contadorHordas(0), jefeFinalGenerado(false) {
    timerGeneracion = new QTimer(this);
    connect(timerGeneracion, &QTimer::timeout, this, &Nivel3::generarEnemigos);
    timerGeneracion->start(3000); 
}

void Nivel3::cargar() {
    jugador->setPos(400, 500);  
    generarEnemigos();
}

void Nivel3::actualizar() {
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

    if (enemigos.isEmpty() && !jefeFinalGenerado && contadorHordas >= 5) {
        Enemigo *jefeFinal = new Enemigo(jugador);  
        jefeFinal->setPos(400, 400);
        enemigos.append(jefeFinal);
        jugador->scene()->addItem(jefeFinal);
        jefeFinalGenerado = true;
    }
}

void Nivel3::generarEnemigos() {
    if (enemigos.size() < 10 && contadorHordas < 5) {
        for (int i = 0; i < 5; ++i) {
            Enemigo *enemigo = new Enemigo(jugador);
            enemigo->setPos(qrand() % 800, 0);  
            enemigos.append(enemigo);
            jugador->scene()->addItem(enemigo);
        }
        contadorHordas++;
    }
}
