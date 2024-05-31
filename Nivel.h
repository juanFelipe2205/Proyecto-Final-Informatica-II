#ifndef NIVEL_H
#define NIVEL_H

#include <QList>
#include "Jugador.h"
#include "Obstaculo.h"
#include "Enemigo.h"

class Nivel {
public:
    Nivel(Jugador *jugador);
    virtual ~Nivel() = default;
    virtual void cargar() = 0;
    virtual void actualizar() = 0;

protected:
    Jugador *jugador;
    QList<Obstaculo*> obstaculos;
    QList<Enemigo*> enemigos;
};

#endif 
