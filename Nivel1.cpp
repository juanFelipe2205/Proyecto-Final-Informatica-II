#include "Nivel1.h"
#include "Obstaculo.h"

Nivel1::Nivel1(Jugador *jugador, QObject *parent)
    : Nivel(jugador, parent) {
}

void Nivel1::cargar() {
    jugador->habilitarMovimiento(false); 
    crearObstaculos();
}

void Nivel1::actualizar() {
    for (QGraphicsItem *item : scene->items()) {
        Obstaculo *obstaculo = dynamic_cast<Obstaculo *>(item);
        if (obstaculo) {
            obstaculo->mover();
            if (jugador->collidesWithItem(obstaculo)) {
                jugador->reducirVida(1);
                scene->removeItem(obstaculo);
                delete obstaculo;
            }
        }
    }
}

void Nivel1::crearObstaculos() {
    for (int i = 0; i < 5; ++i) {
        Obstaculo *obstaculo = new Obstaculo();
        obstaculo->setPos(800 + i * 200, 500);  
        scene->addItem(obstaculo);
    }
}
