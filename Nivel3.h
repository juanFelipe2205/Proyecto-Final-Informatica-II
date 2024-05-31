#ifndef NIVEL3_H
#define NIVEL3_H

#include "Nivel.h"

class Nivel3 : public Nivel {
public:
    Nivel3(Jugador *jugador);
    void cargar() override;
    void actualizar() override;

private:
    void generarHorda();
    int contadorHordas;
    bool jefeFinalGenerado;
};

#endif 
