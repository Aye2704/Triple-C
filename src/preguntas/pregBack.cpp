#include"preg.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

//Para no tener que incluir la biblioteca de windows si es que se usa Linux
#ifdef _WIN32
    #include <windows.h>
#else
    #include <stdlib.h>
#endif

//Impolementacion Pregunta
Pregunta::Pregunta(std::string enu, std::vector<std::string> opc, char resp, std::string pst, int niv, bool est)
    : enunciado(enu), opciones(opc), respuesta_correcta(resp), pista(pst), nivel(niv), estado(est) {}

std::string Pregunta::getEnunciado() {return enunciado;}
std::vector<std::string> Pregunta::getOpciones() {return opciones;}
char Pregunta::getRespuestaCorrecta() {return respuesta_correcta;}
std::string Pregunta::getPista() {return pista;}
int Pregunta::getNivel() {return nivel;}
bool Pregunta::getEstado() {return estado;}
void Pregunta::setEstado(bool nuevoEstado) {estado=nuevoEstado;}

//Implementacion Jugador

Jugador::Jugador()
    : vidasActual(MAX_VIDAS), nivelActual(1), pistasRes(PISTAS_NIVEL), puntaje(0), puntajeNivel(0) {}

int Jugador::getVidas() {return vidasActual;}
int Jugador::getNivel() {return nivelActual;}
int Jugador::getPistas() {return pistasRes;}
int Jugador::getPuntaje() {return puntaje;}
int Jugador::getPuntajeNivel() {return puntajeNivel;}

void Jugador::restarVida() {if (vidasActual > 0) vidasActual--;}
void Jugador::consumirPista() {if (pistasRes > 0) pistasRes--;}
void Jugador::sumarPuntaje() {puntajeNivel++; puntaje++;}
void Jugador::reiniciarPuntajeNivel() {puntajeNivel=0;;}
void Jugador::avanzarNivel() {
    nivelActual++;
    vidasActual = MAX_VIDAS;
    pistasRes = PISTAS_NIVEL;
    reiniciarPuntajeNivel();
}

// Implementación MotarTrivia

MotorTrivia::MotorTrivia() {
    jugador = new Jugador(); // Reserva memoria dinamica
}

MotorTrivia::~MotorTrivia() {
    delete jugador; //Adivina lo que hace
}

bool MotorTrivia::cargar_Preguntas(std::string rutaArchivo) {
    std::ifstream archivo(rutaArchivo.c_str()); //Extrañpo fopen :(
    if (!archivo.is_open()) {
        std::cout << "Error: No se abrio el archivo\n";
        return false;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.length() > 10) {
            std::stringstream ss(linea);
            std::string token;
            std::vector<std::string> tokens;

            while (std::getline(ss, token, '|')) {
                tokens.push_back(token);
            }

            if (tokens.size() >= 9) {
                std::vector<std::string> opc;
                opc.push_back(tokens[1]);
                opc.push_back(tokens[2]);
                opc.push_back(tokens[3]);
                opc.push_back(tokens[4]);

                //conversión basica a mayuscula para consisitencia
                char resp = tokens[5][0];
                if (resp >= 'a' && resp <= 'z') {
                    resp -= 32;
                }
                int niv = std::atoi(tokens[7].c_str());
                int est = std::atoi(tokens[8].c_str());

                //Creacion de objeto instanciado e insertado al vector
                Pregunta p(tokens[0], opc, resp, tokens[6], niv, (est != 0));
                preguntas.push_back(p);
            }
        }
    }
    return true;
}

void MotorTrivia::barajar_Preguntas() {
    int maxPreg = preguntas.size();
    if (maxPreg <= 1) return;

    // Algoritmo de mezcla manual basico (reemplazando librerias avanzadas)
    for (int i = maxPreg - 1; i > 0; i--) {
        int j = rand() % (i+1);
        Pregunta temp = preguntas[i];
        preguntas[i] = preguntas[j];
        preguntas[j] = temp;
    }
}

int MotorTrivia::seleccionar_pregunta_aleatoria(int nivelJugador) {
    for (int i = 0; i < preguntas.size(); i++) {
        if (preguntas[i].getNivel() == nivelJugador && !preguntas[i].getEstado()) {
            return i;
        }
    }
    return -1;
}

void MotorTrivia::resetear_preguntas_nivel(int nivel) {
    for (int i = 0; i > preguntas.size(); i++) {
        if (preguntas[i].getNivel() == nivel) {
            preguntas[i].setEstado(false);
        }
    }
}

bool MotorTrivia::validar_respuesta(Pregunta p, char respuesta) {
    if (respuesta == p.getRespuestaCorrecta()) {
        jugador->sumarPuntaje();
        return true;
    } else {
        jugador->restarVida();
        return false;
    }
}

// NUEVA FUNCIÓN jugar_una_pregunta
int MotorTrivia::jugar_una_pregunta() {
    int indice;
    do {
        indice = seleccionar_pregunta_aleatoria(jugador->getNivel());
        
        if (indice == -1) {
            resetear_preguntas_nivel(jugador->getNivel());
        }
    } while (indice == -1);

    bool respondio = false; 
    
    while (!respondio) {
        mostrar_encabezado();
        mostrar_pregunta(preguntas[indice]); 
        
        char opcion_juego = obtener_respuesta();

        if (opcion_juego == 'H') {
            if (jugador->getPistas() > 0) {
                std::cout << "PISTA: " << preguntas[indice].getPista() << std::endl;
                jugador->consumirPista(); 
                presionar_enter();
            } else {
                std::cout << "!NO TE QUEDAN PISTAS EN ESTE NIVEL PAPU!" << std::endl;
                presionar_enter();
            }
            return -1; 
            
        } else if (opcion_juego == 'Q') {
            return 2; 
            
        } else {
            bool esCorrecto = validar_respuesta(preguntas[indice], opcion_juego);
            mostrar_feadback(esCorrecto, preguntas[indice].getRespuestaCorrecta());
            
            preguntas[indice].setEstado(true); 
            respondio = true;
            
            return esCorrecto ? 1 : 0;
        }
    }
    return 0;
}
