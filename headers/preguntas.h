#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//Constantes
#define MAX_VIDAS 3
#define MAX_NIVELES 5
#define MAX_OPCIONES 4
#define MAX_TEXTO 256
#define PISTAS_NIVEL 2
#define PREGUNTAS_PARA_SUBIR 5

typedef struct {
    char enunciado[MAX_TEXTO]; //Texto que se mostrara en cada pregunta
    char opciones[MAX_OPCIONES][MAX_TEXTO]; //numero de opciones posibles
    char respuesta_correcta; //Texto de la respuesta correcta
    char pista[MAX_TEXTO];
    int nivel; //nivel al que pertenece la pregunta
    int estado; //para saber si esta pregunta fue usada (1) o no (0)
} Pregunta;

typedef struct {
    int vidasActual;
    int nivelActual;
    int pistasRes; //numero de pistas que puedes pedir
    int puntaje; //Cuantas respuestas correctas hay en un nivel
    int puntajeNivel;
}Jugador;

//Prototipos para la presentacion

void limpiar_patalla();

void mostrar_encabezado (Jugador* j); //Muestra stats (vidas y pistas)

void mostrar_pregunta (Pregunta* p); //Muestra la pregunta (BRUH)

char obtener_respuesta (); //Captura y filtra el teclado

void mostrar_feadback (int esCorrecto, char respuesta_real); //Reaccion visual a la respuesta

void pantalla_transicion (int tipo , int nivelactual); //Pantalla de si pasaste al siguiente nivel o perdiste

int menu_principal(int opcion_menu);

//Prototipos para el Backend

Pregunta* cargar_preguntas(const char *archivo, int* maxPreg); // Funcion para cargar las preguntas dentro de una estructura de datos

int seleccionar_pregunta_aleatoria(Pregunta* b, int maxPreg, int nivelActual); //Funcion nueva con la intencion de elegir pregunta random

int validar_respuesta(Jugador* j, Pregunta* p, char respuesta); // Funcion nueva que ve si la respuesta es correcta y actualiza el estado

void resetear_preguntas_nivel(Pregunta* b, int maxPreg, int nivel); // Funcion nueva para reiniciar los flags de estado

#endif 
