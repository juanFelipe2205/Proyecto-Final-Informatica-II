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
    void reducirVida(int cantidad);
    int getVida() const;
    void atacar();

private slots:
    void actualizarSalto();

private:
    bool izquierda;
    bool derecha;
    bool saltando;
    bool atacando;
    qreal velocidadX;
    qreal velocidadY;
    qreal gravedad;
    int vida;
    QTimer *timerSalto;
    QTimer *timerAtaque;
};

#endif 
