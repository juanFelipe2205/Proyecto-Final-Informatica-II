#ifndef NIVEL1_H
#define NIVEL1_H

#include "Nivel.h"
#include <QTimer>

class Nivel1 : public Nivel {
    Q_OBJECT
public:
    explicit Nivel1(Jugador *jugador, QObject *parent = nullptr);
    void cargar() override;
    void actualizar() override;
private:
    void crearObstaculos();
};

#endif
