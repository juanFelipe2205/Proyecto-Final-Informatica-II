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
    void habilitarMovimiento(bool habilitado);
    void guardarProgreso();
    void cargarProgreso();
    void borrarProgreso();

private:
    bool izquierda;
    bool derecha;
    bool saltando;
    bool atacando;
    bool movimientoHabilitado;
    qreal velocidadX;
    qreal velocidadY;
    qreal gravedad;
    int vida;
    int nivelActual;
    QTimer *timerSalto;
    QTimer *timerAtaque;

private slots:
    void actualizarSalto();
};

#endif
