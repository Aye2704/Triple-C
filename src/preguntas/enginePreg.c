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

    //TODO: Muestra la pregunta (BRUH)
}
char obtener_respuesta (){
    //TODO: Captura y filtra el teclado
    char nig = 'n';
    return nig;
}
void mostrar_feadback (int esCorrecto, char respuesta_real){
    //TODO: Reaccion visual a la respuesta
}
void pantalla_transmicion (int tipo , int nivelactual){
    //TODO: Pantalla de si pasaste al siguiente nivel o perdiste
}