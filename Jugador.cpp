#include "Jugador.h"
#include "Nivel.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QFont>
#include <QList>
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include <QApplication>

Jugador::Jugador()
    : izquierda(false), derecha(false), saltando(false), atacando(false),
    movimientoHabilitado(true), saltoEsquiveHabilitado(false),
    velocidadX(0), velocidadY(0), gravedad(0.5), vida(10), nivelActual(1), nivel(nullptr) {
    setPixmap(QPixmap(":/images/jugador.png"));
    timerSalto = new QTimer(this);
    connect(timerSalto, &QTimer::timeout, this, &Jugador::actualizarSalto);
    timerAtaque = new QTimer(this);
    connect(timerAtaque, &QTimer::timeout, [this] { atacando = false; timerAtaque->stop(); });
    timerSaltoEsquive = new QTimer(this);
}

void Jugador::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space && !saltando) {
        if (!saltoEsquiveHabilitado || (saltoEsquiveHabilitado && !timerSaltoEsquive->isActive())) {
            saltando = true;
            velocidadY = -10;
            timerSalto->start(16);
            if (saltoEsquiveHabilitado) {
                timerSaltoEsquive->start(3000);
            }
        }
    } else if (event->key() == Qt::Key_H && !atacando) {
        atacando = true;
        atacar();
        timerAtaque->start(500);
    }

    if (movimientoHabilitado) {
        if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
            izquierda = true;
            velocidadX = -5;
        } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
            derecha = true;
            velocidadX = 5;
        }
    }

    if (event->key() == Qt::Key_K) {
        guardarProgreso();
    } else if (event->key() == Qt::Key_L) {
        cargarProgreso();
    } else if (event->key() == Qt::Key_J) {
        borrarProgreso();
    }
}

void Jugador::keyReleaseEvent(QKeyEvent *event) {
    if (movimientoHabilitado) {
        if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
            izquierda = false;
            if (!derecha) velocidadX = 0;
        } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
            derecha = false;
            if (!izquierda) velocidadX = 0;
        }
    }
}

void Jugador::mover() {
    if (movimientoHabilitado) {
        setPos(x() + velocidadX, y());
    }
}

void Jugador::actualizarSalto() {
    if (saltando) {
        setPos(x(), y() + velocidadY);
        velocidadY += gravedad;
        if (y() >= 500) {
            setPos(x(), 500);
            saltando = false;
            timerSalto->stop();
        }
    }
}

void Jugador::reducirVida(int cantidad) {
    vida -= cantidad;
    if (vida <= 0) {
        QGraphicsTextItem *gameOverText = new QGraphicsTextItem("Game Over");
        QFont font("Arial", 48);
        gameOverText->setFont(font);
        gameOverText->setDefaultTextColor(Qt::red);
        gameOverText->setPos(200, 150);
        scene()->addItem(gameOverText);
        QPushButton *reintentarButton = new QPushButton("Reintentar");
        QPushButton *salirButton = new QPushButton("Salir");
        reintentarButton->setGeometry(300, 300, 200, 50);
        salirButton->setGeometry(300, 400, 200, 50);

        scene()->addWidget(reintentarButton);
        scene()->addWidget(salirButton);

        connect(reintentarButton, &QPushButton::clicked, this, &Jugador::reiniciarNivel);
        connect(salirButton, &QPushButton::clicked, []() { QApplication::quit(); });
        movimientoHabilitado = false;
        if (nivel) {
            nivel->detener();
        }
    }
}

int Jugador::getVida() const {
    return vida;
}

void Jugador::atacar() {
    QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items) {
        Enemigo *enemigo = dynamic_cast<Enemigo *>(item);
        if (enemigo) {
            qreal dx = enemigo->x() - x();
            qreal dy = enemigo->y() - y();
            qreal distancia = qSqrt(dx * dx + dy * dy);
            if (distancia < 40) {
                enemigo->reducirVida(1);
            }
        }
    }
}

void Jugador::habilitarMovimiento(bool habilitado) {
    movimientoHabilitado = habilitado;
}

void Jugador::habilitarSaltoEsquive(bool habilitado) {
    saltoEsquiveHabilitado = habilitado;
}

void Jugador::guardarProgreso() {
    QFile file("progreso.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << nivelActual << "\n";
        out << vida << "\n";
        out << x() << "\n";
        out << y() << "\n";
        file.close();
    }
}

void Jugador::cargarProgreso() {
    QFile file("progreso.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in >> nivelActual;
        in >> vida;
        qreal posX, posY;
        in >> posX;
        in >> posY;
        setPos(posX, posY);
        file.close();
    }
}

void Jugador::borrarProgreso() {
    QFile file("progreso.txt");
    if (file.exists()) {
        file.remove();
    }
}

void Jugador::reiniciarNivel() {
    vida = 10;
    setPos(400, 500);
    for (QGraphicsItem *item : scene()->items()) {
        if (QGraphicsTextItem *textItem = dynamic_cast<QGraphicsTextItem *>(item)) {
            if (textItem->toPlainText() == "Game Over") {
                scene()->removeItem(item);
                delete item;
            }
        } else if (QGraphicsWidget *widget = dynamic_cast<QGraphicsWidget *>(item)) {
            if (QPushButton *button = dynamic_cast<QPushButton *>(widget->widget())) {
                if (button->text() == "Reintentar" || button->text() == "Salir") {
                    scene()->removeItem(item);
                    delete item;
                }
            }
        }
    }
    if (nivel) {
        nivel->inicializar();
    }
    movimientoHabilitado = true;
}
