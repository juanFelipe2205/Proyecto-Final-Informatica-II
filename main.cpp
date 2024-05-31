#include <QApplication>
#include "Juego.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Juego juego;
    int nivelSeleccionado = 1;  
    juego.iniciar(nivelSeleccionado);

    return app.exec();
}
