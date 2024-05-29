#ifndef NIVEL_H
#define NIVEL_H

#include "Jugador.h"

class Nivel {
public:
    Nivel(Jugador *jugador);
    void cargar();
    void actualizar();

private:
    Jugador *jugador;
};

#endif /
