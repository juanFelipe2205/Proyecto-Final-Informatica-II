#ifndef NIVEL1_H
#define NIVEL1_H

#include "Nivel.h"

class Nivel1 : public Nivel {
public:
    Nivel1(Jugador *jugador);
    void cargar() override;
    void actualizar() override;
};

#endif 
