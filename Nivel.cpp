#include "Nivel.h"

Nivel::Nivel(Jugador *jugador, QObject *parent)
    : QObject(parent), jugador(jugador) {
    scene = new QGraphicsScene(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Nivel::actualizar);
}

void Nivel::inicializar() {
    scene->clear();  
    scene->addItem(jugador);
    jugador->setPos(400, 500);  
    jugador->habilitarMovimiento(true);
    jugador->habilitarSaltoEsquive(false);
    jugador->setVida(10);  
    cargar();
    timer->start(16); 
}

void Nivel::detener() {
    timer->stop();  
    for (QGraphicsItem *item : scene->items()) {
        if (item != jugador) {
            scene->removeItem(item);
            delete item;
        }
    }
}
