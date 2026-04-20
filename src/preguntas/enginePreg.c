#include "preguntas.h"

void mostrar_encabezado (Jugador* j){
    printf("============================================================\n");
    printf("        Nivel: %d  |   PUNTAJE: %d   |   PROGRESO: %d/%d\n",
        j->nivelActual, j->puntaje, j->puntajeNivel, PREGUNTAS_PARA_SUBIR);
    printf("------------------------------------------------------------\n");
    printf("            VIDAS: ");
    for (int i = 0; i<j->vidasActual; i++) {
        printf("<3");
    }
    printf("    |   PISTAS: %d\n", j->pistasRes);
    printf("============================================================\n\n");
}

void mostrar_pregunta (Pregunta* p){
    printf("%s\n\n", p->enunciado);
    for (int i = 0; i < MAX_OPCIONES; i++) {
        printf("    [%c] %s\n", (char)('A'+i), p->opciones[i]);
    }
}
char obtener_respuesta (){
    char respuesta;
    int validar=0;
    printf("\n------------------------------------------------------------\n");
    printf(" Escribe A, B, C, D para responder o'H' para pedir una PISTA\n");
    do{
        printf("    >> Tu eleccion: ");
        scanf("%c", &respuesta);
        if ((respuesta>= 'A' && respuesta <= 'D') || respuesta =='H'){
            validar=1;
        } else{
            printf("Caracter incorrecto\n presiona Enter para intentar de nuevo\n");
        }
    } while (!validar);
    return respuesta;
}
void mostrar_feadback (int esCorrecto, char respuesta_real){
    //TODO: Reaccion visual a la respuesta
}
void pantalla_transmicion (int tipo , int nivelactual){
    //TODO: Pantalla de si pasaste al siguiente nivel o perdiste
}