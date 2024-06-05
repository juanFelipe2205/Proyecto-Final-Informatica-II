#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Jugador.h"
#include "Nivel.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"

class Juego : public QGraphicsView {
    Q_OBJECT

public:
    Juego(QWidget *parent = nullptr);
    void iniciarJuego();
    void cambiarNivel(int nivel);

private:
    QGraphicsScene *scene;
    Jugador *jugador;
    Nivel *nivelActual;

private slots:
    void actualizar();
};

#endif
