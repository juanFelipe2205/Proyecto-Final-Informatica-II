#include "Jugador.h"
#include <QGraphicsScene>

Jugador::Jugador() 
    : izquierda(false), derecha(false), saltando(false), 
      velocidadX(0), velocidadY(0), gravedad(0.5), vida(10) {
    setPixmap(QPixmap(":/images/jugador.png"));
    timerSalto = new QTimer(this);
    connect(timerSalto, &QTimer::timeout, this, &Jugador::actualizarSalto);
}

void Jugador::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        izquierda = true;
    } else if (event->key() == Qt::Key_Right) {
        derecha = true;
    } else if (event->key() == Qt::Key_Space && !saltando) {
        saltando = true;
        velocidadY = -10; 
        timerSalto->start(16);
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

void Jugador::actualizarSalto() {
    if (saltando) {
        setPos(x(), y() + velocidadY);
        velocidadY += gravedad;
        if (y() >= 500) {  
            setPos(x(), 500);
            saltando = false;
            timerSalto->stop();
        }
    }
}

void Jugador::reducirVida(int cantidad) {
    vida -= cantidad;
    if (vida <= 0) {
        scene()->removeItem(this);
        delete this;
    }
}

int Jugador::getVida() const {
    return vida;
}
