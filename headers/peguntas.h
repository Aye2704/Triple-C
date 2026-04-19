#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Pregunta {
    char preguntas[256];
    char opciones[256];
    char respuesta[256];
    int niveles = 5;
    bool estado=false;
};

struct Jugador {
    int vidasAcual;
    int vidasMax=3;
    int nivelActual;
    int pistasRes;
    int puntaje;
};
