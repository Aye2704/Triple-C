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

    printf("Hola y bienvenido a en juego de preguntas para aprender C\n"); // estos textos se van a ir para la fusion con el apartadodo de mov
    printf("Presina ENTER para continuar... ");
    getchar();
    do {
        if(opcion_menu==0) opcion_menu = menu_principal(opcion_menu);
        switch (opcion_menu) {
            case 1:
                // Usar la nueva función modular para manejar la sesión de preguntas
                while (opcion_menu!=0) {
                    int resultado = jugar_sesion_preguntas(&j, b, maxPreg);
                    if (resultado == 0) {  // Nivel completado o juego terminado
                        if (j.nivelActual > MAX_NIVELES) {
                            opcion_menu = 2;  // Fin del juego
                            break;
                        }
                    } else if (resultado == 1) {  // Perdido
                        opcion_menu = 0;  // Volver al menú
                    } else if (resultado == 2) {  // Salir voluntario
                        opcion_menu = 0;  // Volver al menú
                    }
                    // Si resultado == 3, continuar con más preguntas
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
