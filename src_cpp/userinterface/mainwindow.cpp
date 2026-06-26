#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), motorJuego(nullptr), indicePreguntaActual(-1), preguntasRespondidasEnCombate(0) 
{
    ui->setupUi(this);

    motorTrivia = new MotorTrivia();
    // Cargar base de datos desde el directorio de compilación local
    if (!motorTrivia->cargar_Preguntas("archivopregs.txt")) {
        QMessageBox::critical(this, "Error de Datos", "No se encontró el archivo de preguntas 'archivopregs.txt'.");
    }

    setupUI();
}

MainWindow::~MainWindow() {
    delete ui;
    if (motorJuego) delete motorJuego;
    delete motorTrivia;
}

void MainWindow::setupUI() {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // ==========================================
    // CONFIGURACIÓN: PANTALLA PRINCIPAL (MENÚ)
    // ==========================================
    pantallaMenu = new QWidget();
    QVBoxLayout *layoutMenu = new QVBoxLayout(pantallaMenu);
    layoutMenu->setAlignment(Qt::AlignCenter);

    QLabel *titulo = new QLabel("TRIPLE-C: Aprende C Jugando", pantallaMenu);
    titulo->setStyleSheet("font-size: 26px; font-weight: bold; color: #2c3e50; margin-bottom: 20px;");
    layoutMenu->addWidget(titulo);

    QPushButton *btnIniciar = new QPushButton("Iniciar Nueva Partida", pantallaMenu);
    btnIniciar->setStyleSheet("font-size: 16px; padding: 10px 20px; background-color: #3498db; color: white; border-radius: 5px;");
    connect(btnIniciar, &QPushButton::clicked, this, &MainWindow::iniciarJuego);
    layoutMenu->addWidget(btnIniciar);

    QPushButton *btnSalir = new QPushButton("Salir", pantallaMenu);
    btnSalir->setStyleSheet("font-size: 16px; padding: 10px 20px; background-color: #95a5a6; color: white; border-radius: 5px; margin-top: 10px;");
    connect(btnSalir, &QPushButton::clicked, this, &QWidget::close);
    layoutMenu->addWidget(btnSalir);

    stackedWidget->addWidget(pantallaMenu);

    // ==========================================
    // CONFIGURACIÓN: PANTALLA DEL MAPA DE JUEGO
    // ==========================================
    motorJuego = new juego(1);
    mapaVisual = new maponW(motorJuego, this);
    
    connect(mapaVisual, &maponW::colisionEnemigoDetectada, this, &MainWindow::procesarColision);
    connect(mapaVisual, &maponW::metaAlcanzada, this, &MainWindow::procesarMeta);
    connect(mapaVisual, &maponW::salirMenu, this, &MainWindow::regresarAlMenu);
    
    stackedWidget->addWidget(mapaVisual);

    // ==========================================
    // CONFIGURACIÓN: PANTALLA DE TRIVIA COMBATE
    // ==========================================
    pantallaTrivia = new QWidget();
    QVBoxLayout *layoutTrivia = new QVBoxLayout(pantallaTrivia);
    layoutTrivia->setContentsMargins(40, 40, 40, 40);

    labelEstadoTrivia = new QLabel(pantallaTrivia);
    labelEstadoTrivia->setStyleSheet("font-size: 14px; font-weight: bold; color: #7f8c8d;");
    layoutTrivia->addWidget(labelEstadoTrivia);

    labelPregunta = new QLabel(pantallaTrivia);
    labelPregunta->setWordWrap(true);
    labelPregunta->setStyleSheet("font-size: 18px; font-weight: bold; margin-bottom: 20px; color: #2c3e50;");
    layoutTrivia->addWidget(labelPregunta);

    grupoOpciones = new QButtonGroup(pantallaTrivia);
    for (int i = 0; i < 4; i++) {
        radioOpciones[i] = new QRadioButton(pantallaTrivia);
        radioOpciones[i]->setStyleSheet("font-size: 15px; padding: 5px;");
        grupoOpciones->addButton(radioOpciones[i], i);
        layoutTrivia->addWidget(radioOpciones[i]);
    }

    QPushButton *btnResponder = new QPushButton("Enviar Respuesta", pantallaTrivia);
    btnResponder->setStyleSheet("font-size: 16px; padding: 12px; background-color: #e67e22; color: white; font-weight: bold; border-radius: 4px; margin-top: 20px;");
    connect(btnResponder, &QPushButton::clicked, this, &MainWindow::verificarRespuestaTrivia);
    layoutTrivia->addWidget(btnResponder);

    stackedWidget->addWidget(pantallaTrivia);
    
    // Iniciar mostrando el menú principal
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::iniciarJuego() {
    motorTrivia->getJugador()->reiniciarPartida();
    motorTrivia->barajar_Preguntas();
    
    if (motorJuego) delete motorJuego;
    motorJuego = new juego(1);
    
    mapaVisual->setMotorJuego(motorJuego);
    stackedWidget->setCurrentIndex(1); // Cambiar a pantalla de mapa
    mapaVisual->setFocus();
}

void MainWindow::procesarColision() {
    preguntasRespondidasEnCombate = 0;
    QMessageBox::information(this, "¡Combate!", "¡Has chocado con el enemigo! Responde correctamente para derrotarlo.");
    
    indicePreguntaActual = motorTrivia->seleccionar_pregunta_aleatoria(motorTrivia->getJugador()->getNivel());
    if (indicePreguntaActual == -1) {
        // Fallback si no hay preguntas del nivel actual
        indicePreguntaActual = motorTrivia->seleccionar_pregunta_aleatoria(1);
    }
    
    mostrarPreguntaEnPantalla();
    stackedWidget->setCurrentIndex(2); // Cambiar de forma reactiva a pantalla Trivia
}

void MainWindow::mostrarPreguntaEnPantalla() {
    if (indicePreguntaActual == -1) {
        regresarAlMenu();
        return;
    }

    Pregunta p = motorTrivia->getPregunta(indicePreguntaActual);
    labelEstadoTrivia->setText(QString("Nivel: %1 | Vidas: %2 | Pregunta del Combate: %3/5")
                               .arg(motorTrivia->getJugador()->getNivel())
                               .arg(motorTrivia->getJugador()->getVidas())
                               .arg(preguntasRespondidasEnCombate + 1));
    
    labelPregunta->setText(QString::fromStdString(p.getEnunciado()));
    std::vector<std::string> ops = p.getOpciones();
    
    for (int i = 0; i < 4; i++) {
        radioOpciones[i]->setText(QString::fromStdString(ops[i]));
    }
    
    // Limpiar selección previa de botones radiales de forma segura
    QAbstractButton* checked = grupoOpciones->checkedButton();
    if (checked) {
        grupoOpciones->setExclusive(false);
        checked->setChecked(false);
        grupoOpciones->setExclusive(true);
    }
}

void MainWindow::verificarRespuestaTrivia() {
    int idSeleccionado = grupoOpciones->checkedId();
    if (idSeleccionado == -1) {
        QMessageBox::warning(this, "Validación", "Por favor, seleccione una opción antes de continuar.");
        return;
    }

    char respuestasLetras[4] = {'A', 'B', 'C', 'D'};
    char respuestaUsuario = respuestasLetras[idSeleccionado];

    bool correcto = motorTrivia->validar_respuesta(indicePreguntaActual, respuestaUsuario);
    preguntasRespondidasEnCombate++;

    if (correcto) {
        QMessageBox::information(this, "Resultado", "¡Respuesta Correcta!");
    } else {
        Pregunta p = motorTrivia->getPregunta(indicePreguntaActual);
        QMessageBox::critical(this, "Resultado", QString("Incorrecto. %1").arg(QString::fromStdString(p.getPista())));
    }

    // Verificar condición crítica de término (Muerte del usuario)
    if (motorTrivia->getJugador()->getVidas() <= 0) {
        finalizarPartida(false);
        return;
    }

    // El combate requiere responder exitosamente un bloque cerrado de 5 preguntas
    if (preguntasRespondidasEnCombate >= 5) {
        QMessageBox::information(this, "Combate Ganado", "¡Felicidades! Has derrotado al enemigo. Ahora puedes avanzar con seguridad hacia la meta.");
        motorJuego->setEnemigoDerrotado(true);
        stackedWidget->setCurrentIndex(1); // Regresar al mapa de exploración sin mutar posiciones
        mapaVisual->setFocus();
    } else {
        // Cargar siguiente pregunta reactiva dentro del mismo bucle de combate
        indicePreguntaActual = motorTrivia->seleccionar_pregunta_aleatoria(motorTrivia->getJugador()->getNivel());
        mostrarPreguntaEnPantalla();
    }
}

void MainWindow::procesarMeta() {
    QMessageBox::information(this, "¡Nivel Completado!", "Has alcanzado la meta a salvo.");
    motorTrivia->getJugador()->avanzarNivel();
    int sgteNivel = motorTrivia->getJugador()->getNivel();

    if (sgteNivel > 4) { // Condición de victoria definitiva del juego completo
        finalizarPartida(true);
    } else {
        QMessageBox::information(this, "Siguiente Nivel", QString("Avanzando al Nivel %1. El laberinto se reduce y el enemigo se vuelve más ágil.").arg(sgteNivel));
        
        delete motorJuego;
        motorJuego = new juego(sgteNivel);
        mapaVisual->setMotorJuego(motorJuego);
        
        stackedWidget->setCurrentIndex(1);
        mapaVisual->setFocus();
    }
}

void MainWindow::finalizarPartida(bool victoria) {
    if (victoria) {
        QMessageBox::information(this, "¡Victoria Magna!", QString("¡Enhorabuena! Completaste todos los niveles de Triple-C.\nTu puntuación final es: %1 puntos.").arg(motorTrivia->getJugador()->getPuntaje()));
    } else {
        QMessageBox::critical(this, "Fin de la Partida", "Te has quedado sin vidas. ¡Sigue estudiando C e inténtalo de nuevo!");
    }
    regresarAlMenu();
}

void MainWindow::regresarAlMenu() {
    stackedWidget->setCurrentIndex(0);
}