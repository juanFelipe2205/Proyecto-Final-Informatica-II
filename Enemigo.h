#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemigo : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemigo(int vida);
    void mover();
    void reducirVida(int cantidad);
    int getVida() const;
private:
    int vida;
};

#endif
