#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class Enemigo : public QGraphicsPixmapItem {
public:
    Enemigo();
    void atacar();
    void mover();

private slots:
    void actualizarMovimiento();

private:
    qreal amplitud;
    qreal frecuencia;
    qreal fase;
    QTimer *timerMovimiento;
};

#endif 
