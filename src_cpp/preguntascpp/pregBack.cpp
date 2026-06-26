#include"preg.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

//Impolementacion Pregunta
Pregunta::Pregunta(std::string enu, std::vector<std::string> opc, char resp, std::string pst, int niv, bool est)
    : enunciado(enu), opciones(opc), respuesta_correcta(resp), pista(pst), nivel(niv), estado(est) {}

std::string Pregunta::getEnunciado() const {return enunciado;}
std::vector<std::string> Pregunta::getOpciones() const {return opciones;}
char Pregunta::getRespuestaCorrecta() const {return respuesta_correcta;}
std::string Pregunta::getPista() const {return pista;}
int Pregunta::getNivel() const {return nivel;}
bool Pregunta::getEstado() const {return estado;}
void Pregunta::setEstado(bool nuevoEstado) {estado=nuevoEstado;}

//Implementacion Jugador

Jugador::Jugador()
    : vidasActual(MAX_VIDAS), nivelActual(1), pistasRes(PISTAS_NIVEL), puntaje(0), puntajeNivel(0) {}

int Jugador::getVidas() const {return vidasActual;}
int Jugador::getNivel() const {return nivelActual;}
int Jugador::getPistas() const {return pistasRes;}
int Jugador::getPuntaje() const {return puntaje;}
//int Jugador::getPuntajeNivel() {return puntajeNivel;}

void Jugador::restarVida() {if (vidasActual > 0) vidasActual--;}
void Jugador::consumirPista() {if (pistasRes > 0) pistasRes--;}
void Jugador::sumarPuntaje() {puntajeNivel++; puntaje++;}
//void Jugador::reiniciarPuntajeNivel() {puntajeNivel=0;;}
void Jugador::reiniciarPartida() {
    vidasActual = MAX_VIDAS;
    nivelActual = 1;
    pistasRes = PISTAS_NIVEL;
    puntaje = 0;
    puntajeNivel = 0;
}
void Jugador::avanzarNivel() {
    nivelActual++;
    vidasActual = MAX_VIDAS;
    pistasRes = PISTAS_NIVEL;
    puntajeNivel=0;
}

// Implementación MotarTrivia

MotorTrivia::MotorTrivia() {
    jugador = new Jugador(); // Reserva memoria dinamica
}

MotorTrivia::~MotorTrivia() {
    delete jugador; //Adivina lo que hace
}

bool MotorTrivia::cargar_Preguntas(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo); //Extrañpo fopen :(
    if (!archivo.is_open()) {return false;}

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        //nueva forma ya que no me gusto el metodo de tokens
        std::string enu, op1, op2, op3, op4, respStr, pst, nivStr, estStr;

        if (std::getline(ss, enu, '|') && std::getline(ss, op1, '|') &&
            std::getline(ss, op2, '|') && std::getline(ss, op3, '|') &&
            std::getline(ss, op4, '|') && std::getline(ss, respStr, '|') &&
            std::getline(ss, pst, '|') && std::getline(ss, nivStr, '|') &&
            std::getline(ss, estStr, '|')) {

            std::vector<std::string> opciones = {op1, op2, op3, op4};
            char resp = respStr.empty() ? 'A' : respStr[0];
            int niv = std::stoi(nivStr);
            bool est = (estStr == "1");

            preguntas.push_back(Pregunta(enu, opciones, resp, pst, niv, est));
        }
    }
    archivo.close();
    return true;
}

void MotorTrivia::barajar_Preguntas() {
    int maxPreg = preguntas.size();
    if (maxPreg <= 1) return;

    // Algoritmo de mezcla manual basico (reemplazando librerias avanzadas)
    for (int i = maxPreg - 1; i > 0; i--) {
        int j = rand() % (i+1);
        std::swap(preguntas[i], preguntas[j]); // Trucazo
        /*
        Pregunta temp = preguntas[i];
        preguntas[i] = preguntas[j];
        preguntas[j] = temp;*/
    }
}

int MotorTrivia::seleccionar_pregunta_aleatoria(int nivelJugador) {
    for (size_t i = 0; i < preguntas.size(); ++i) {
        if (preguntas[i].getNivel() == nivelJugador && !preguntas[i].getEstado()) {
            return static_cast<int>(i);
        }
    }
    //si se agotaron, resetear estado del nivel
    for (size_t i = 0; i < preguntas.size(); ++i) {
        if (preguntas[i].getNivel() == nivelJugador) preguntas[i].setEstado(false);
    }
    //Da weba hacer un bulce para esto
    for (size_t i = 0; i < preguntas.size(); ++i) {
        if (preguntas[i].getNivel() == nivelJugador && !preguntas[i].getEstado()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}
/*
void MotorTrivia::resetear_preguntas_nivel(int nivel) {
    for (std::vector<Pregunta>::size_type i = 0; i < preguntas.size(); ++i) {
        if (preguntas[i].getNivel() == nivel) {
            preguntas[i].setEstado(false);
        }
    }
}
*/
bool MotorTrivia::validar_respuesta(int indice, char respuesta) {
    if (indice < 0 || indice >= static_cast<int>(preguntas.size())) return false;
    preguntas[indice].setEstado(true);
    if (respuesta == preguntas[indice].getRespuestaCorrecta()){
        jugador->sumarPuntaje();
        return true;
    } else {
        jugador->restarVida();
        return false;
    }
}
/*
void MotorTrivia::marcar_pregunta_usada(int indice) {
    preguntas[indice].setEstado(true);
}*/

//Jugador* MotorTrivia::getJugador() {return jugador;}?
Pregunta MotorTrivia::getPregunta(int indice) const {return preguntas[indice];}
//int MotorTrivia::getCantidadPreguntas() {return preguntas.size();}
