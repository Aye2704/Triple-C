//Esta funcion solo es para pruebas. luego sera borrado
#include "preguntas.h"

int main (){ 
    srand(time(NULL));

    // Configurar la consola de Windows para que entienda UTF-8
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8); // Opcional, pero util si el usuario debe ingresar tildes
    #endif

    int opcion_menu=0;
    int maxPreg=0;

    Pregunta* b=cargar_preguntas("archivopregs.txt", &maxPreg);
    if (b==NULL){
        printf("Error: no se pudo cargar el archivo");
        return 1;
    }
    barajar_preguntas(b, maxPreg);

    Jugador j= {MAX_VIDAS, 1, PISTAS_NIVEL, 0, 0};
    
    do {
        if(opcion_menu==0) opcion_menu = menu_principal(opcion_menu);
        switch (opcion_menu) {
            case 1:
                // Usar la nueva función jugar_una_pregunta (una pregunta a la vez)
                while (opcion_menu!=0 && j.vidasActual > 0 && j.puntajeNivel < PREGUNTAS_PARA_SUBIR) {
                    int resultado = jugar_una_pregunta(&j, b, maxPreg);

                    if (resultado == 2) {  // Salir voluntario
                        opcion_menu = 0;
                        break;
                    } else if (resultado == 1) {
                        // Correcta - el puntaje ya se maneja en jugar_una_pregunta
                    } else if (resultado == 0) {
                        // Incorrecta - el decremento de vidas ya se maneja en jugar_una_pregunta
                    }
                    // Si resultado == -1 (pista), continuar sin contar

                    // Verificar si completó el nivel
                    if (j.puntajeNivel >= PREGUNTAS_PARA_SUBIR) {
                        if (j.nivelActual >= MAX_NIVELES) {
                            pantalla_transicion(3, j.nivelActual);
                            opcion_menu = 2;
                        } else {
                            pantalla_transicion(1, j.nivelActual);
                            j.nivelActual++;
                            j.vidasActual = MAX_VIDAS;
                            j.pistasRes = PISTAS_NIVEL;
                            j.puntajeNivel = 0;
                            resetear_preguntas_nivel(b, maxPreg, j.nivelActual);
                        }
                    }

                    // Verificar si perdió
                    if (j.vidasActual <= 0) {
                        pantalla_transicion(2, j.nivelActual);
                        j.nivelActual = 1;
                        j.vidasActual = MAX_VIDAS;
                        j.pistasRes = PISTAS_NIVEL;
                        j.puntajeNivel = 0;
                        j.puntaje = 0;
                        opcion_menu = 0;
                    }
                }
                break;
            case 2: //fin del programa
                break;
            default:
                printf("opcion invalida\n");
                getchar();
                opcion_menu=0;
        }
    } while (opcion_menu != 2);
    printf("fin del programa\n");
    free(b);
    b=NULL;
    return 0;
}
