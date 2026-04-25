#LOGICA MOVIMIENTO

Se utilizo gemini para:

-entender como funciona la matriz para plantear el mapa
-hacer el ultimo main de prueba para probar las funcionalidades
"ahi esta mi codigo estructurado dame un main sencillo para solo probar que tal se ve y ver que me falta"
y devolvio el archivo newprueba.c

[text](src/mov/mov.c/newprueba.c)

-tambien se pedio ayuda para poder entender como formar el struct del mapa
typedef struct{
    char mapa[MAX][MAX];
    int dimension;
}map;

-ayuda para la correccion de errores en general
-se le solicito ayuda para ver si el codigo hecho por la parte logica de mov y de preguntas seria compatible
--"t acabo de enviar los archivos con las preguntas todo lo que son las prubeas de la logica preguntas las definiciones y funciones y tmb mis definiciones mis funciones y mis pruebas , segun yo lo veo bastante unible solo faltaria agregarle al main de prueba de logica preguntas un intermedio para que entrara el movimiento no¿"-
devolvio:
#include "movi.h"
#include "preguntas.h" // Importante incluir ambos

int main() {
    srand(time(NULL));
    
    // 1. Inicialización de Preguntas
    int maxPreg = 0;
    Pregunta* banco = cargar_preguntas("archivopregs.txt", &maxPreg);
    Jugador jugador_preg = {MAX_VIDAS, 1, PISTAS_NIVEL, 0, 0};
    barajar_preguntas(banco, maxPreg);

    // 2. Inicialización de Movimiento
    map m1;
    movjug p1 = {{1, 1}, 1}; 
    movjug PE = {{7, 9}, 1};
    char tecla = ' ';
    int nivel_juego = 1;

    iniciarmapa(&m1, nivel_juego);

    // 3. Bucle Principal
    while (tecla != 'q' && jugador_preg.vidasActual > 0) {
        // ... (Limpiar pantalla y dibujar mapa) ...
        dibujarmapa(&p1, &PE, nivel_juego, &m1);

        printf("\nSiguiente movimiento: ");
        scanf(" %c", &tecla);

        // Procesar Movimiento
        procesomov(&p1, tecla, &m1);
        procesomovE(&PE, &m1);

        // --- EL INTERMEDIO: DETECCIÓN DE COLISIÓN ---
        if (p1.posicion.x == PE.posicion.x && p1.posicion.y == PE.posicion.y) {
            limpiar_patalla();
            printf("¡TE HA ATRAPADO EL ENEMIGO! Responde correctamente para sobrevivir...\n");
            presionar_enter();

            // Llamamos a la lógica de Joako
            int resultado = jugar_sesion_preguntas(&jugador_preg, banco, maxPreg);

            if (resultado == 1) { // Perdió todas las vidas en las preguntas
                printf("GAME OVER definitivo.\n");
                break; 
            }
            
            // Si sobrevivió, reseteamos posiciones para que no sigan colisionando
            p1.posicion.x = 1; p1.posicion.y = 1;
            PE.posicion.x = 7; PE.posicion.y = 9;
        }
    }

    free(banco); // No olvides liberar la memoria de malloc
    return 0;
}
este archivo de prueba para hacer una aproximacion a lo que seria el main.c final

- se tuvo un problema con lo que era el como se dibujaba el mapa por lo que se le solicito ayuda a gemini para entender pq el eje y se invertia
- "Necesito hacer un mapa en C usando una matriz para mover un personaje con WASD. ¿Cómo manejo las coordenadas? Porque me confunde que en la matriz las filas van hacia abajo pero en un plano el eje Y va hacia arriba."
 y luego devolvio:
#define FILAS 10
#define COLS 10

// Te dije: "Para que el (0,0) sea abajo a la izquierda..."
for (int i = FILAS - 1; i >= 0; i--) {    // Empezamos desde la última fila hacia arriba
    for (int j = 0; j < COLS; j++) {     // De izquierda a derecha
        if (i == pos_y && j == pos_x) {
            printf("P "); // Personaje
        } else {
            printf(". "); // Suelo
        }
    }
    printf("\n");
}

explicando el pq se invertia el eje y y un codigo sugerente 



