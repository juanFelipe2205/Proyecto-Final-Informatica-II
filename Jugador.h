#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Jugador : public QGraphicsPixmapItem {
public:
    Jugador();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mover();

private:
    bool izquierda;
    bool derecha;
};

#endif 
