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

public:
    MotorTrivia();
    ~MotorTrivia(); //Destructor para liberar memoria dinamica (BRUH)

    // Backend
    bool cargar_Preguntas(std::string rutaArchivo);
    void barajar_Preguntas();
    int seleccionar_pregunta_aleatoria(int nivelJugador);
    void resetear_preguntas_nivel(int nivel);
    
    bool validar_respuesta(int indice, char respuesta);
    void marcar_pregunta_usada(int indice); //funcion nueva para facilitar cosas (No me ejecuten :( )

    // Getters para que el frot end pueda acceder a los datos
    Jugador* getJugador();
    Pregunta getPregunta(int indice);
    int getCantidadPreguntas();
};
#endif