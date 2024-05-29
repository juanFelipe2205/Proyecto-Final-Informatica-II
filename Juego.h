#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include "Nivel.h"
#include "Jugador.h"

class Juego : public QGraphicsView {
    Q_OBJECT

public:
    Juego(QWidget *parent = nullptr);
    void iniciar();

private:
    Nivel *nivel;
    Jugador *jugador;
};

#endif 
