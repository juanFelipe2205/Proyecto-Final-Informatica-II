#ifndef NIVEL3_H
#define NIVEL3_H

#include "Nivel.h"
#include "Enemigo.h"
#include <QTimer>

class Nivel3 : public Nivel {
    Q_OBJECT
public:
    explicit NivelTres(Jugador *jugador, QObject *parent = nullptr);
    void cargar() override;
    void actualizar() override;
private:
    void crearObstaculos();
    void crearEnemigos();
    void crearJefeFinal();
    QList<Enemigo*> enemigos;
    Enemigo* jefeFinal;
    int contadorEnemigos;
};

#endif
