#pragma once
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
    std::string getEnunciado() const;
    std::vector<std::string> getOpciones() const;
    char getRespuestaCorrecta() const;
    std::string getPista() const;
    int getNivel() const;
    bool getEstado() const;
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

    int getVidas() const;
    int getNivel() const;
    int getPistas() const;
    int getPuntaje() const;
    //int getPuntajeNivel();

    void restarVida();
    void consumirPista();
    void sumarPuntaje();
    //void reiniciarPuntajeNivel();
    void reiniciarPartida();
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
    bool cargar_Preguntas(const std::string& rutaArchivo);
    void barajar_Preguntas();
    int seleccionar_pregunta_aleatoria(int nivelJugador);
    //void resetear_preguntas_nivel(int nivel);
    
    bool validar_respuesta(int indice, char respuesta);
    //void marcar_pregunta_usada(int indice);

    // Getters para que el frot end pueda acceder a los datos
    Jugador* getJugador() {return jugador;}
    Pregunta getPregunta(int indice) const;
    //int getCantidadPreguntas();
};
