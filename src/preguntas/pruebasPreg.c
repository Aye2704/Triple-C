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
    char opcion_juego;
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
                        presionar_enter();
                    } else {
                        printf("!NO TE QUEDAN PISTAS EN ESTE NIVEL PAPU!\n");
                        presionar_enter();  
                    }
                } else if (opcion_juego=='Q') {
                    opcion_menu = menu_principal(opcion_menu);
                } else {
                    int esCorrecto = validar_respuesta(&j, &b[indice], opcion_juego);
                    mostrar_feadback(esCorrecto, b[indice].respuesta_correcta);
                    b[indice].estado=1;
                }

                //Pasar de nivel
                if(j.puntajeNivel>=PREGUNTAS_PARA_SUBIR){
                    if (j.nivelActual>=MAX_NIVELES){
                        pantalla_transicion(3, j.nivelActual);
                        opcion_menu=2;
                    } else{
                        pantalla_transicion(1, j.nivelActual);
                        j.nivelActual++;
                        j.vidasActual = MAX_VIDAS;
                        j.pistasRes = PISTAS_NIVEL;
                        j.puntajeNivel = 0;                        
                    }
                }

                //Preder
                if(j.vidasActual<=0){
                    pantalla_transicion(2, j.nivelActual);
                    j.nivelActual=1;
                    j.vidasActual = MAX_VIDAS;
                    j.pistasRes = PISTAS_NIVEL;
                    j.puntajeNivel = 0;
                    j.puntaje=0;
                    opcion_menu=0;
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
