#ifndef NIVEL_H
#define NIVEL_H

#include <QObject>
#include <QGraphicsScene>
#include "Jugador.h"
#include <QTimer>

class Nivel : public QObject {
    Q_OBJECT
public:
    explicit Nivel(Jugador *jugador, QObject *parent = nullptr);
    virtual void cargar() = 0;
    virtual void actualizar() = 0;
    virtual void inicializar();
    void detener();
protected:
    Jugador *jugador;
    QGraphicsScene *scene;
    QTimer *timer;
};

#endif
