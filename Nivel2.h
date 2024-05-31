#ifndef NIVEL2_H
#define NIVEL2_H

#include "Nivel.h"

class Nivel2 : public Nivel {
public:
    Nivel2(Jugador *jugador);
    void cargar() override;
    void actualizar() override;
};

#endif 
