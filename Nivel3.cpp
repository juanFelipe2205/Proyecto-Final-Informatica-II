#include "Nivel3.h"
#include "Obstaculo.h"

NivelTres::Nivel3(Jugador *jugador, QObject *parent)
    : Nivel(jugador, parent), jefeFinal(nullptr), contadorEnemigos(0) {
}

void Nivel3::cargar() {
    jugador->habilitarMovimiento(true);  
    jugador->habilitarSaltoEsquive(true); 
    crearEnemigos();
    crearObstaculos();
}

void Nivel3::actualizar() {
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
    for (Enemigo* enemigo : enemigos) {
        enemigo->mover();
        if (jugador->collidesWithItem(enemigo)) {
            jugador->reducirVida(1);
        }
        if (enemigo->getVida() <= 0) {
            scene->removeItem(enemigo);
            enemigos.removeOne(enemigo);
            delete enemigo;
            contadorEnemigos--;
        }
    }
    if (jefeFinal) {
        jefeFinal->mover();
        if (jugador->collidesWithItem(jefeFinal)) {
            jugador->reducirVida(1);
        }
        if (jefeFinal->getVida() <= 0) {
            scene->removeItem(jefeFinal);
            delete jefeFinal;
            jefeFinal = nullptr;
        }
    }
    if (contadorEnemigos <= 0 && !jefeFinal) {
        crearJefeFinal();
    }
}

void Nivel3::crearObstaculos() {
    for (int i = 0; i < 5; ++i) {
        Obstaculo *obstaculo = new Obstaculo(Obstaculo::CaidaLibre);
        obstaculo->setPos(qrand() % 800, 0);  
        scene->addItem(obstaculo);
    }
}

void Nivel3::crearEnemigos() {
    for (int i = 0; i < 10; ++i) {
        Enemigo *enemigo = new Enemigo(2);
        enemigo->setPos(qrand() % 800, 500);  
        enemigos.append(enemigo);
        scene->addItem(enemigo);
        contadorEnemigos++;
    }
}

void Nivel3::crearJefeFinal() {
    jefeFinal = new Enemigo(10);  
    jefeFinal->setPos(400, 500);
    scene->addItem(jefeFinal);
}
