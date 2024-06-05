#include "Juego.h"

Juego::Juego(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    jugador = new Jugador();
    scene->addItem(jugador);
    iniciarJuego();
}

void Juego::iniciarJuego() {
    cambiarNivel(1);
}

void Juego::cambiarNivel(int nivel) {
    if (nivelActual != nullptr) {
        scene->removeItem(nivelActual);
        delete nivelActual;
    }

    switch (nivel) {
    case 1:
        nivelActual = new Nivel1(jugador);
        break;
    case 2:
        nivelActual = new Nivel2(jugador);
        break;
    case 3:
        nivelActual = new Nivel3(jugador);
        break;
    default:
        nivelActual = nullptr;
        break;
    }

    if (nivelActual != nullptr) {
        nivelActual->cargar();
        scene->addItem(nivelActual);
        connect(&nivelActual->timer, &QTimer::timeout, this, &Juego::actualizar);
        nivelActual->timer.start(16);
    }
}

void Juego::actualizar() {
    if (nivelActual != nullptr) {
        nivelActual->actualizar();
    }
}
