//Esta funcion solo es para pruebas. luego sera borrado
#include "preguntas.h"

int main (){ 
    Pregunta* p=(Pregunta*) malloc(sizeof(Pregunta));
    p->enunciado;
    p->estado;
    p->nivel;
    p->opciones;
    p->pista;
    p->respuesta_correcta;

    Jugador* j=(Jugador*) malloc(sizeof(Jugador));
    j->vidasActual=MAX_VIDAS;
    j->puntaje=0;
    j->puntajeNivel=0;
    j->nivelActual=0;
    j ->pistasRes= PISTAS_NIVEL;

    int opcion_menu;

    printf("Hola y bienvenido a en juego de preguntas para aprender C\n");
    do {
        printf("============================================================\n");
        printf("                    MENU PRINCIPA\n");
        printf("                      1. Jugar\n");
        printf("                      2. Salir\n");
        printf("============================================================\n");
        scanf("%d", &opcion_menu);
        system("cls");
        switch (opcion_menu) {
            case 1:
                printf("Pues que comience el juego!\n");
                mostrar_encabezado(j);
                break;
            case 2:
                printf("fin del programa\n");
                break;
            default:
                printf("opcion invalida\n");
        }
    } while (opcion_menu != 2);
    free(p);
    p=NULL;
    free(j);
    j=NULL;
    return 0;
}
