#include "Enemigo.h"

Enemigo::Enemigo(int vidaInicial)
    : vida(vidaInicial) {
    setPixmap(QPixmap(":/images/enemigo.png"));
}

void Enemigo::mover() {
    QGraphicsItem *jugador = scene()->focusItem();
    if (jugador) {
        int dx = jugador->x() - x();
        int dy = jugador->y() - y();
        if (dx > 0) setPos(x() + 1, y());
        else if (dx < 0) setPos(x() - 1, y());
        if (dy > 0) setPos(x(), y() + 1);
        else if (dy < 0) setPos(x(), y() - 1);
    }
}

void Enemigo::reducirVida(int cantidad) {
    vida -= cantidad;
}

int Enemigo::getVida() const {
    return vida;
}
