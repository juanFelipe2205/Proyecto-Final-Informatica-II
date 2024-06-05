#ifndef NIVEL2_H
#define NIVEL2_H

#include "Nivel.h"
#include "Enemigo.h"

class Nivel2 : public Nivel {
    Q_OBJECT

public:
    Nivel2(Jugador *jugador);
    void cargar() override;
    void actualizar() override;

private:
    QVector<Enemigo *> enemigos;
    QTimer *timerGeneracion;

private slots:
    void generarEnemigo();
};

#endif
