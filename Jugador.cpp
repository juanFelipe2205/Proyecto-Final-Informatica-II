#include "Jugador.h"

Jugador::Jugador() : izquierda(false), derecha(false) {
    setPixmap(QPixmap(":/images/jugador.png"));
}

void Jugador::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        izquierda = true;
    } else if (event->key() == Qt::Key_Right) {
        derecha = true;
    }
}

void Jugador::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        izquierda = false;
    } else if (event->key() == Qt::Key_Right) {
        derecha = false;
    }
}

void Jugador::mover() {
    if (izquierda) {
        setPos(x() - 5, y());
    }
    if (derecha) {
        setPos(x() + 5, y());
    }
}
