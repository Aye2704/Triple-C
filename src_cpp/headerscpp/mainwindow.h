#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include "juego.hpp"
#include "preg.hpp"
#include "mapitawidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;

    // Componentes del Motor Lógico
    juego *motorJuego;
    MotorTrivia *motorTrivia;

    // Pantallas de la Interfaz
    QWidget *pantallaMenu;
    maponW *mapaVisual;
    QWidget *pantallaTrivia;

    // Elementos Gráficos para el Sistema de Trivia Reactivo
    QLabel *labelPregunta;
    QRadioButton *radioOpciones[4];
    QButtonGroup *grupoOpciones;
    QLabel *labelEstadoTrivia;
    int indicePreguntaActual;
    int preguntasRespondidasEnCombate;

    void setupUI();
    void mostrarPreguntaEnPantalla();
    void finalizarPartida(bool victoria);

private slots:
    void iniciarJuego();
    void procesarColision();
    void procesarMeta();
    void verificarRespuestaTrivia();
    void regresarAlMenu();
};

#endif