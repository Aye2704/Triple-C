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
    printf("\n------------------------------------------------------------\n");
    if (esCorrecto) {
        printf("        ¡CORRECTO!\n");
    } else {
        printf("        ¡INCORRECTO!\n");
        printf("    La respuesta correcta era la opcion: %c\n", respuesta_real);
    }
    printf("------------------------------------------------------------\n");

    // Pausa dramática para que el usuario pueda leer el resultado
    printf("\n  Cargando siguiente paso...");
    fflush(stdout); // Asegura que el texto se imprima antes de dormir el programa
    
    // Pausa de 1.5 a 2 segundos
    Sleep(3000); // Windows usa milisegundos
}
void pantalla_transmicion (int tipo , int nivelActual){
    system("cls");
    printf("\n\n");
    switch (tipo) {
        case 1:
            printf("¡OBJETIVO LOGRADO!\n ");
            printf("Has completado con exito el Nivel %d\n", nivelActual);
            printf("Tus vidas y pistas han sido restauradas.\n");
            break;
        case 2:
            printf("¡GAME OVER!");
            printf("Te has quedado sin vidas en el Nivel %d.\n", nivelActual);
            prnitf("Regresaras al menu principal");
            break;
        case 3:
            printf("¡FELICIDADES, SE TERMINO EL JUEGO! \n");
            break;
    }
    printf("\n\n  Presiona [ENTER] para continuar...");
    // Limpieza de buffer y espera de entrada
    fflush(stdout);
    while (getchar() != '\n'); // Consume el Enter residual si existe
    getchar();                 // Espera el nuevo Enter del usuario
}