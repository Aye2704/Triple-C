#include "preguntas.h"
#include "movi.h"
#include <time.h>

int main(){
    srand(time(NULL));

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int opcion_menu = 0;
    int maxPreg = 0;

    // Cargar preguntas desde el archivo
    Pregunta* b = cargar_preguntas("archivopregs.txt", &maxPreg);
    if (b == NULL) {
        printf("Error: no se pudo cargar el archivo de preguntas\n");
        return 1;
    }
    barajar_preguntas(b, maxPreg);

    // Estructuras del juego
    Jugador j = {MAX_VIDAS, 1, PISTAS_NIVEL, 0, 0};
    map m1;
    movjug p1 = {{1, 1}, 1};  // Jugador
    movjug PE = {{7, 9}, 1};  // Enemigo
    char tecla = ' ';

    printf("Hola y bienvenido a Triple-C: El juego de preguntas para aprender C\n");
    printf("Presiona ENTER para continuar...");
    getchar();

    do {
        if (opcion_menu == 0) {
            opcion_menu = menu_principal(opcion_menu);
        }

        switch (opcion_menu) {
            case 1:
                // Reiniciar estado del juego al comenzar
                j.nivelActual = 1;
                j.vidasActual = MAX_VIDAS;
                j.pistasRes = PISTAS_NIVEL;
                j.puntaje = 0;
                j.puntajeNivel = 0;

                // Reiniciar preguntas del nivel 1
                resetear_preguntas_nivel(b, maxPreg, 1);

                // Loop principal del juego
                while (opcion_menu == 1) {
                    // Inicializar mapa según el nivel actual
                    iniciarmapa(&m1, j.nivelActual);

                    // Reiniciar posiciones del jugador y enemigo
                    p1.posicion.x = 1;
                    p1.posicion.y = 1;
                    PE.posicion.x = m1.dimension - 2;
                    PE.posicion.y = m1.dimension - 2;

                    // Loop del mapa (mover hasta chocar con enemigo o salir)
                    while (tecla != 'q' && tecla != 'm') {
                        limpiar_patalla();

                        printf("NIVEL: %d | Preguntas correctas: %d/%d | Vidas: %d\n",
                               j.nivelActual, j.puntajeNivel, PREGUNTAS_PARA_SUBIR, j.vidasActual);
                        printf("WASD para mover | 'm' para menu | 'q' para salir\n");

                        // Dibujar el mapa
                        dibujarmapa(&p1, &PE, j.nivelActual, &m1);

                        // Leer movimiento
                        printf("\nSiguiente movimiento: ");
                        scanf(" %c", &tecla);

                        // Procesar movimiento del jugador
                        procesomov(&p1, tecla, &m1);
                        // Procesar movimiento del enemigo
                        procesomovE(&PE, &m1);

                        // Verificar colisión con el enemigo
                        if (p1.posicion.x == PE.posicion.x && p1.posicion.y == PE.posicion.y) {
                            // ¡Colisión! Limpiar pantalla y iniciar minijuego de preguntas
                            limpiar_patalla();
                            printf("\n¡CHOCASTE CON EL ENEMIGO! Es hora de responder preguntas...\n");
                            printf("Presiona ENTER para continuar...");
                            getchar();
                            getchar();

                            // Jugar las 5 preguntas del nivel seguidas
                            // Ahora cada pregunta es independiente - main.c controla el loop
                            // NOTA: validar_respuesta (llamada por jugar_una_pregunta) ya modifica
                            // puntajeNivel, puntaje y vidasActual - NO duplicar aquí
                            while (j.puntajeNivel < PREGUNTAS_PARA_SUBIR && j.vidasActual > 0) {
                                limpiar_patalla();
                                // Llamar a jugar_una_pregunta que solo maneja UNA pregunta
                                // Esta función llama a validar_respuesta que ya actualiza el estado
                                int resultado = jugar_una_pregunta(&j, b, maxPreg);

                                if (resultado == 2) {
                                    // Salir del minijuego
                                    break;
                                } else if (resultado == -1) {
                                    // Pista pedida - continuar con la siguiente pregunta sin contar
                                    continue;
                                }
                                // Si resultado == 1 (correcta) o 0 (incorrecta), 
                                // validar_respuesta ya actualizó el estado - no hacer nada aquí

                                // Verificar si perdió por vidas
                                if (j.vidasActual <= 0) {
                                    break;
                                }
                            }

                            // Después de terminar las preguntas, verificar el estado
                            if (j.vidasActual <= 0) {
                                // Game over
                                pantalla_transicion(2, j.nivelActual);
                                opcion_menu = 0;  // Volver al menú
                                break;
                            }

                            if (j.puntajeNivel >= PREGUNTAS_PARA_SUBIR) {
                                // Nivel completado
                                j.puntajeNivel = 0;
                                j.nivelActual++;

                                if (j.nivelActual > MAX_NIVELES) {
                                    pantalla_transicion(3, j.nivelActual - 1);
                                    opcion_menu = 2;
                                } else {
                                    pantalla_transicion(1, j.nivelActual - 1);
                                    resetear_preguntas_nivel(b, maxPreg, j.nivelActual);
                                }
                            }
                            break;  // Salir del loop del mapa
                        }
                    }

                    // Si salió con 'm' o 'q', manejar la salida
                    if (tecla == 'm') {
                        opcion_menu = 0;  // Volver al menú
                        tecla = ' ';  // Resetear para la próxima vez
                    } else if (tecla == 'q') {
                        opcion_menu = 2;  // Salir del juego
                    }
                }
                break;

            case 2:
                // Salir del programa
                break;

            default:
                printf("Opcion invalida\n");
                getchar();
                opcion_menu = 0;
        }
    } while (opcion_menu != 2);

    printf("Fin del programa. ¡Gracias por jugar!\n");

    // Liberar memoria
    free(b);
    b = NULL;

    return 0;
}