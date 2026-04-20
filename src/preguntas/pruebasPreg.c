//Esta funcion solo es para pruebas. luego sera borrado
#include "preguntas.h"

int main (){ 
    int opcion_menu;
    char opcion_juego;
    int maxPreg;

    Pregunta* b=cargar_preguntas("archivopregs.txt", maxPreg);
    if (b==NULL){
        printf("Error: no se pudo cargar el archivo");
        return 1;
    }

    Jugador j= {MAX_VIDAS, 0, PISTAS_NIVEL, 0, 0};

    printf("Hola y bienvenido a en juego de preguntas para aprender C\n"); // estos textos se van a ir para la fusion con el apartadodo de mov
    do {
        printf("============================================================\n");
        printf("                    MENU PRINCIPA\n");
        printf("                      1. Jugar\n");
        printf("                      2. Salir\n");
        printf("============================================================\n");
        scanf("%d", &opcion_menu);
        limpiar_patalla();
        switch (opcion_menu) {
            case 1:
                printf("Pues que comience el juego!\n");
                int indice;
                do {
                    indice = seleccionar_pregunta_aleatoria(b, maxPreg, j.nivelActual);
                    if (indice==-1){
                       resetear_preguntas_nivel(b, maxPreg, j.nivelActual);
                    }
                } while(indice==-1);
                mostrar_encabezado(&j);
                mostrar_pregunta(&b[indice]);
                opcion_juego=obtener_respuesta();
                if (opcion_juego=='H'){
                    if (j.pistasRes > 0){
                        printf("PISTA: %s\n", b[indice].pista);
                        j.pistasRes--;
                        printf("\n\n  Presiona [ENTER] para continuar...");
                        fflush(stdout); // Limpieza de buffer y espera de entrada
                        while (getchar() != '\n'); // Consume el Enter residual si existe
                        getchar();    
                    } else {
                        printf("\n!NO TE QUEDAN PISTAS EN ESTE NIVEL PAPU!\n");
                        printf("\n\n  Presiona [ENTER] para continuar...");
                        fflush(stdout); // Limpieza de buffer y espera de entrada
                        while (getchar() != '\n'); // Consume el Enter residual si existe
                        getchar();  
                    }
                } else {
                    int esCorrecto = validar_respuesta(&j, &b[indice], opcion_juego);
                    mostrar_feadback(esCorrecto, &b[indice].respuesta_correcta);
                    b[indice].estado=1;
                }

                //Pasar de nivel
                if(j.puntajeNivel>=PREGUNTAS_PARA_SUBIR){
                    pantalla_transicion(1, j.nivelActual);
                    j.nivelActual++;
                    j.vidasActual = MAX_VIDAS;
                    j.pistasRes = PISTAS_NIVEL;
                    j.puntajeNivel = 0;
                }

                //Preder
                if(j.vidasActual<=0){
                    pantalla_transicion(2, j.nivelActual);
                    j.nivelActual=1;
                    j.vidasActual = MAX_VIDAS;
                    j.pistasRes = PISTAS_NIVEL;
                    j.puntajeNivel = 0;
                    j.puntaje=0;
                }
                break;
            case 2:
                printf("fin del programa\n");
                break;
            default:
                printf("opcion invalida\n");
        }
    } while (opcion_menu != 2);
    free(b);
    b=NULL;
    return 0;
}
