#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include "Nivel.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Jugador.h"

class Juego : public QGraphicsView {
    Q_OBJECT

public:
    Juego(QWidget *parent = nullptr);
    void iniciar(int nivelSeleccionado);

private slots:
    void actualizar();

private:
    Nivel *nivel;
    Jugador *jugador;
};

#endif
