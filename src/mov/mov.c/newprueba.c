#include <stdio.h>
#include <stdlib.h>
#include "movi.h"

/*FALTA AGREGARLE LA LOGICA DE IR AUMENTADO EL NIVEL Y LA DE LA GENERACION DE ENEMIGOS
CON MOV RANDOM*/
/*Este main es de prueba le pedi a gemini que me lo tirara y solo lo puse ojito*/
int main() {
    // 1. Inicializamos las estructuras
    map m1;
    // Empezamos al jugador en la posición 1,1 para que no aparezca sobre un muro
    movjug p1 = {{1, 1}, 1}; 
    char tecla = ' ';
    int nivel_actual = 1;

    // 2. Preparamos el terreno inicial
    iniciarmapa(&m1, nivel_actual);

    // 3. Bucle de juego
    while (tecla != 'q') {
        // Limpiamos pantalla según el sistema
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif


        printf("NIVEL: %d | WASD para mover | 'q' para salir\n", nivel_actual);
                if(tecla=='p'){
            printf("Su posiciones:x=%d,y=%d\n",p1.posicion.x,p1.posicion.y-1);
        }
        
        // Dibujamos el estado actual
        dibujarmapa(&p1, nivel_actual, &m1);

        // Leemos la entrada del usuario
        // El espacio antes de %c es vital para ignorar el 'Enter' anterior
        printf("\nSiguiente movimiento: ");
        scanf(" %c", &tecla);

        // Procesamos el movimiento
        procesomov(&p1, tecla, &m1);
    }

    printf("Juego finalizado.\n");
    return 0;
}