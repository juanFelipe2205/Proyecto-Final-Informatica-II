#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class Obstaculo : public QGraphicsPixmapItem {
public:
    Obstaculo();
    void mover();

private slots:
    void actualizarCaida();

private:
    qreal velocidadY;
    qreal gravedad;
    QTimer *timerCaida;
};

#endif 
