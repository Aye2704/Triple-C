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

#LOGICA DE PREGUNTAS
1. Herramientas y Modelos Utilizados
•	Modelo Core: Gemini 3 Flash.
•	Interfaz: Chat interactivo (Web/App).
•	Capacidades empleadas: Generación de código fuente en C, diseño de arquitectura de software, documentación técnica y asesoría de despliegue multiplataforma.


3. Metodología de Prompts (Ingeniería de Instrucciones)
El desarrollo se basó en una estrategia de prompts incrementales y modulares, donde se solicitó:
•	Definición de Interfaz: Creación de archivos de cabecera (.h) para establecer un contrato de funciones entre dos desarrolladores (Persona A y Persona B).
•	Implementación Específica: Solicitudes individuales para cada función definida (mostrar_pregunta, cargar_base_datos, etc.), asegurando que cada bloque de código fuera funcional y coherente con el anterior.
•	Refinamiento Técnico: Ajustes sobre el formato de lectura de archivos (cambio de separadores ; a |) y manejo de errores (prevención de Segmentation Faults).
•	Asesoría de Entorno: Consultas sobre rutas de archivos, gestión del Directorio de Trabajo Actual (CWD) y requisitos de compilación.


4. Observaciones y Limitaciones
Durante el desarrollo, se identificaron y mitigaron las siguientes limitaciones propias de la IA generativa:
-	Contexto de Archivos: La IA no puede ver tu carpeta local o dónde está el .exe.
-	Rrigidez de Formato: Modelos como fscanf son sensibles a errores en el .txt.
-	Dependencia de OS: Funciones como system("cls") o sleep varían por sistema.
-	Gestión de Memoria: La IA puede sugerir código que olvida liberar memoria.


4. Contribución de la IA vs. Usuario
•	IA: Proporcionó la sintaxis correcta de funciones estándar de C, lógica de algoritmos (recorrido circular, scansets de fscanf) y estructura modular del proyecto.
•	Usuario (Estudiante): Definió los requisitos del juego, la lógica de niveles, el formato de la base de datos de preguntas y realizó la integración/pruebas en el entorno local de compilación.


# Fusion de codigos
1. Herramientas de IA Generativa Utilizadas (Copilot)
- Google Gemini: Utilizado como modelo principal de IA generativa para asistencia en el desarrollo del código.

- 
2. Prompts Principales
- "entender como funciona la matriz para plantear el mapa" - Para comprender la estructura de datos de la matriz
- "ahi esta mi codigo estructurado dame un main sencillo para solo probar que tal se ve y ver que me falta" - Para generar un archivo de prueba
- Solicitudes de ayuda para entender la formación del struct del mapa
- Solicitudes de ayuda para corrección de errores en general
- 

3. Observaciones y Limitaciones
- Gemini proporcionó una implementación funcional del struct `map` y el código de prueba en `newprueba.c`
- La herramienta fue útil para explicar conceptos de estructuras de datos (matrices)
- Como cualquier modelo de IA generativa, el código generado requiere revisión y pruebas por parte del desarrollador
- Las sugerencias de código pueden necesitar ajustes según los requisitos específicos del proyecto



