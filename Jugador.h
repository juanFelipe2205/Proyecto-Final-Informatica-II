#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

class Jugador : public QGraphicsPixmapItem {
public:
    Jugador();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mover();

private slots:
    void actualizarSalto();

private:
    bool izquierda;
    bool derecha;
    bool saltando;
    qreal velocidadX;
    qreal velocidadY;
    qreal gravedad;
    QTimer *timerSalto;
};

#endif 
