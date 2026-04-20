#include "preguntas.h"

//Funciones para el Backend
Pregunta* cargar_preguntas(const char* archivo, int* maxPreg) {
    FILE *f = fopen(archivo, "r");
    if (f==NULL){
        printf("Error (no abrió archivo)\n");
        return NULL;
    }
    char linea[1024];
    int c=0; 
    //primera pasada: contar cuantas preguntas tiene el archivo
    while (fgets(linea, sizeof(linea), f)){
        if (strlen(linea) > 10) c++;
    }
    if (c==0) {
        fclose(f);
        return NULL;
    }

    //pedimos memoria dinamica para el array de estructuras
    Pregunta* b= (Pregunta*)malloc(sizeof(Pregunta)*c);
    if (b==0){
        fclose(f);
        return NULL;
    }
    //Volver al inicio y leer los datos
    rewind(f);
    for (int i = 0; i<c; i++){
        int leidos = fscanf(f,
            " %255[^|]|%255[^|]|%255[^|]|%255[^|]|%255[^|]| %c |%255[^|]|%d|%d ",
            b[i].enunciado,
            b[i].opciones[0],
            b[i].opciones[1],
            b[i].opciones[2],
            b[i].opciones[3],
            &b[i].respuesta_correcta,
            b[i].pista,
            &b[i].nivel,
            &b[i].estado);
        if (leidos < 9){
            printf("Error en el formato en la linea%d\n", i+1);
        }
    }
    fclose(f);
    *maxPreg = c;
    return b;  
}

int seleccionar_pregunta_aleatoria(Pregunta* b, int maxPreg, int nivel_jugador){
    int inicio = rand() % maxPreg; // punto de inicio dentro del array
    for (int i = 0; i<maxPreg; i++){
        int indiceAct = (inicio +i) % maxPreg;

        if (b[indiceAct].nivel == nivel_jugador && 
            b[indiceAct].estado == 0) { // verificar si la pregunta cumple los requisitos
            return indiceAct;
            }
    }
    return -1;
}
int validar_respuesta(Jugador* j, Pregunta* p, char respuesta){
    if (toupper(respuesta) == toupper(p->respuesta_correcta)) {
        j->puntajeNivel +=1;
        j->puntaje += 1;
        return 1;
    } else {
        j->vidasActual -=1;
        return 0;
    }
}
void resetear_preguntas_nivel(Pregunta* b, int maxPreg, int nivel){
    for (int i = 0; i<maxPreg; i++) {
        if (b[i].nivel == nivel) {
            b[i].estado = 0;
        }
    }
}


//Funciones para el Frontend
void limpiar_patalla(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

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

    printf("\n\n  Presiona [ENTER] para continuar...");
    fflush(stdout); // Limpieza de buffer y espera de entrada
    while (getchar() != '\n'); // Consume el Enter residual si existe
    getchar();                 // Espera el nuevo Enter del usuario
}
void pantalla_transicion (int tipo , int nivelActual){
    limpiar_patalla();
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
            printf("Regresaras al menu principal");
            break;
        case 3:
            printf("¡FELICIDADES, SE TERMINO EL JUEGO! \n");
            break; 
    }
    printf("\n\n  Presiona [ENTER] para continuar...");
    fflush(stdout); // Limpieza de buffer y espera de entrada
    while (getchar() != '\n'); // Consume el Enter residual si existe
    getchar();                 // Espera el nuevo Enter del usuario
}
