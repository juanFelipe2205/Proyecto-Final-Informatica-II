#include "Juego.h"
#include <QGraphicsScene>
#include <QTimer>

Juego::Juego(QWidget *parent) : QGraphicsView(parent), jugador(new Jugador()) {
    setFixedSize(800, 600);
    setScene(new QGraphicsScene(this));
    scene()->setSceneRect(0, 0, 800, 600);
}

void Juego::iniciar(int nivelSeleccionado) {
    switch (nivelSeleccionado) {
        case 1:
            nivel = new Nivel1(jugador);
            break;
        case 2:
            nivel = new Nivel2(jugador);
            break;
        case 3:
            nivel = new Nivel3(jugador);
            break;
        default:
            nivel = new Nivel1(jugador);
            break;
    }

    scene()->addItem(jugador);
    nivel->cargar();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Juego::actualizar);
    timer->start(16);  

    show();
}

void Juego::actualizar() {
    nivel->actualizar();
    scene()->update();
}
