#ifndef NIVEL_H
#define NIVEL_H

#include <QList>
#include "Jugador.h"
#include "Obstaculo.h"
#include "Enemigo.h"

class Nivel {
public:
    Nivel(Jugador *jugador);
    void cargar();
    void actualizar();

private:
    Jugador *jugador;
    QList<Obstaculo*> obstaculos;
    QList<Enemigo*> enemigos;
};

#endif 

