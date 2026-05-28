#ifndef PREG_HPP
#define PREG_HPP
#include <iostream>
#include <vector>
#include <string>

//Constantes Globales 
const int MAX_VIDAS = 3;
const int PREGUNTAS_SUBIR = 5;
const int PISTAS_NIVEL = 2;

class Pregunta {
private:
    std::string enunciado;
    std::vector<std::string> opciones;
    char respuesta_correcta;
    std::string pista;
    int nivel;
    bool estado; //ahora si se puede usar booleanos :)
public:
    //construcor
    Pregunta(std::string enu, std::vector<std::string> opc, char resp, std::string pst, int niv, bool est);
    
    //Metodos
    std::string getEnunciado();
    std::vector<std::string> getOpciones();
    char getRespuestaCorrecta();
    std::string getPista();
    int getNivel();
    bool getEstado();
    void setEstado(bool nuevoEstado);
};

class Jugador {
private:
    int vidasActual;
    int nivelActual;
    int pistasRes;
    int puntaje;
    int puntajeNivel;

public:
    Jugador();

    int getVidas();
    int getNivel();
    int getPistas();
    int getPuntaje();
    int getPuntajeNivel();

    void restarVida();
    void consumirPista();
    void sumarPuntaje();
    void reiniciarPuntajeNivel();
    void avanzarNivel();
};

//Controlador Principal

class MotorTrivia {
private:
    Jugador* jugador; //puntero para uso de memoria dinamica
    std::vector<Pregunta> preguntas; //Contenedor STL

    bool validarREspuesta(Pregunta p, char respuesta);

public:
    MotorTrivia();
    ~MotorTrivia(); //Destructor para liberar memoria dinamica (BRUH)

    // Backend
    bool cargarPreguntas(std::string rutaArchivo);
    void barajarPreguntas();
    int obtenerIndicePregunta(int nivelJugador);
    void resetearPreguntasNivel(int nivel);
    
    //Funcion para el juego
    int jugarUnaPregunta();

    //Frontend
    void limpiarPantalla();
    void presionarEnter();
    void mostrarEncabezado();
    void mostrarPregunta(Pregunta p);
    char obtenerRespuesta();
    void mostrarFeedback(bool esCorrecto, char respuestaReal);
    void pantallaTransicion(int tipo);
    int menuPrincipal();
};
#endif