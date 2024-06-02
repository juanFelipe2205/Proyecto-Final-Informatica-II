#include "Jugador.h"
#include "Enemigo.h"
#include <QGraphicsScene>
#include <QList>

Jugador::Jugador() 
    : izquierda(false), derecha(false), saltando(false), atacando(false),
      velocidadX(0), velocidadY(0), gravedad(0.5), vida(10) {
    setPixmap(QPixmap(":/images/jugador.png"));
    timerSalto = new QTimer(this);
    connect(timerSalto, &QTimer::timeout, this, &Jugador::actualizarSalto);
    timerAtaque = new QTimer(this);
    connect(timerAtaque, &QTimer::timeout, [this] { atacando = false; timerAtaque->stop(); });
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
    } else if (event->key() == Qt::Key_A && !atacando) {
        atacando = true;
        atacar();
        timerAtaque->start(500);  
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

void Jugador::atacar() {
    QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items) {
        Enemigo *enemigo = dynamic_cast<Enemigo *>(item);
        if (enemigo) {
            qreal dx = enemigo->x() - x();
            qreal dy = enemigo->y() - y();
            qreal distancia = qSqrt(dx*dx + dy*dy);
            if (distancia < 20) {  
                enemigo->reducirVida(1);
            }
        }
    }
}
