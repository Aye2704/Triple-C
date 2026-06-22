#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QKeyEvent>
#include "juego.hpp"
#include "preg.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    //Captura eventos del teclado de forma global en la ventana
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void iniciarJuego();
    void salirJuego();
    void responderTrivia(char respuesta);

private:
    QStakedWidget *stackedWidget;
    // Pantallas
    QWidget *menuScreen;
    QWidget *gameScreen;
    QWidget *triviaScreen;

    //Elementos de UI
    QLabel *mapLabel;
    QLabel *statsLabel;
    QLabel *preguntaLabel;

    //Logica (Punteros)
    juego *motorJuego;
    MotorTrivia *motorTrivia;
    int preguntaActualIndice;

    //Metodos internos de UI
    void setupUI();
    void actualizarPantallaJuego();
    void iniciarCombate();
};
#endif