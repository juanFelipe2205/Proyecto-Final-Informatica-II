#include "Juego.h"
#include <QGraphicsScene>
#include <QTimer>

Juego::Juego(QWidget *parent) : QGraphicsView(parent), jugador(new Jugador()) {
    setFixedSize(800, 600);
    setScene(new QGraphicsScene(this));
    scene()->setSceneRect(0, 0, 800, 600);
}

void Juego::iniciar() {
    nivel = new Nivel(jugador);
    scene()->addItem(jugador);
    nivel->cargar();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Juego::update);
    timer->start(16);

    show();
}
