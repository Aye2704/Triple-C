#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    motorJuego = nullptr;
    motorTrivia = new MotorTrivia();
    motorTrivia->cargar_Preguntas("archivopregs.txt") //Se asume que esta en build
    motorTrivia->barajar_Preguntas();

    setupUI();
    setcentralWidget(stackedWidget);
    resize(600, 500);
}

void MainWindow::setupUI {
    stackedWidget = new QStackedWidget(this);

    //Pantalla del menu
    menuScreen = new QWidget();
    QVBoxLayout *menuLayout = new QVBoxLayout(menuScreen);
    QLabel *titulo = new QLabel("TRIPLE-C\n", this);
    titulo->setAligment(Qt::AliingnCenter);
    QPushButton *btnJugar = new QPushButton("Jugar", this);
    QPushButton *btnSalir = new QPushButton("Salir", this);

    connect(btnJugar, QPushButton::clicked, this, &MainWindow::iniciarJuego);
    connect(btnSalir, QPushButton::clicked, this, &MainWindow::salirJuego);

    menuLayout->addWidget(titulo);
    menuLayout->addWidget(btnJugar);
    menuLayout->addWidget(btnSalir);

    //Pantalla Juego
    gameScreen = new QWidget();
    QVBoxLayout *gameLayout = new QVBoxLayout(gameScreen);
    statsLabel = new QLabel("Vidas: 3 | Nivel: 1", this);
    mapLabel = new Qlabel(this);
    mapLabel->setFont(QFont("Courier", 14)); // Fuente
    gameLayout->addWidget(statsLabel);
    gameLayout->addWidget(mapLabel);

    //Agregar al Stack
    stackedWidget->addWidget(menuScreen); //Index 0
    stackedWidget->addWidget(gameScreen); //Index 1
}

void MainWindow::iniciarJuego() {
    if(motorJuego) delete motorJuego;
    motorJuego = new juego();
    actualizarPantallaJuego();
    stackedWidget->setCurrentIndex(1); // mover al mapa
}

//Aqui conectamos el teclado de QT con la logica de C++
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (stackedWidget->currentIndex() != 1) return; // Solo actuar si estamos en el mapa

    char tecla = ' ';
    if (event->key() == Qt::key_W) tecla = 'w';
    else if (event->key() == Qt::key_S) tecla = 's';
    else if (event->key() == Qt::key_A) tecla = 'a';
    else if (event->key() == Qt::key_D) tecla = 'd';

    if (tecla != ' ') {
        motorJuego->actualizar(tecla);
        actualizarPantallaJuego();

        int estado = motorJuego->verificar_colisiones();
        if (estado == 1) { //Choco con enemigo
            inicarCombate();
        } else if (estado == 2) { LLegó a la meta
            motorTrivia->getJugador()->avanzarNivel();
            iniciarJuego();
        }
    }
}