#include <QApplication>
#include "Juego.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Juego *juego = new Juego();
    juego->show();
    return a.exec();
}
