#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , juego(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (juego != nullptr) {
        delete juego;
    }
}

void MainWindow::on_btnStartGame_clicked()
{
    if (juego == nullptr) {
        juego = new Juego(this);
        setCentralWidget(juego);
        juego->iniciarJuego();
    }
}

void MainWindow::on_btnQuit_clicked()
{
    QApplication::quit();
}
