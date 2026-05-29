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



Uso de IA Hito 2:

Modelo: Gemini Pro3.1
se utilizo gemini para lograr tener mas clara la idea de como crear la clase para dibujar el mapa , los metodos que esta tendra y como conectarlo para que todo se uniera con esta clase

PROMPT
anterioemente en mi .c yo tenia dibujar mapa pero ahora con todas las clases que estoy creando debere en mi main crear el mapa inicializando el objeto y dibujandolo con los  std::cout en mi juego no¿ , lo otro me gustaria hacer el mov por mi cuenta por lo que me gustaria que me dieras pistas o señalizaciones de por donde deberia llevar la creacion de este

"Me encanta esa actitud! Querer armar la lógica por tu cuenta es la mejor forma de aprender. Te voy a dar las herramientas y pistas necesarias sin escribirte el código final para que tú mismo armes el rompecabezas.1. Sobre dibujar el mapa: ¿Todo al main? 🎨Poder, puedes. Pero si pones todos los std::cout y los ciclos for directamente dentro del main(), estarías rompiendo la regla de oro del Hito 2 que exige "responsabilidades claras" y un diseño orientado a objetos.  Como cuando armas la estructura central de un plataformero 2D, lo ideal en cualquier juego es separar la lógica interna (las matemáticas) de lo que el jugador ve en la pantalla (el renderizado). Tu main() debería quedar casi vacío, pareciéndose a un simple interruptor de encendido.La pista para el dibujo:
Lo ideal es crear una clase "Controladora" (podrías llamarla Juego o Motor). Esta clase sería la dueña de todo: tendría como atributos tu objeto Mapa, tu Jugador y tu Enemigo.
Dentro de esa clase Juego, tendrías un método dibujarFrame() que se encargue de hacer exactamente lo que hacía tu antiguo dibujarmapa de C . Así, tu main solo diría algo como miJuego.iniciar().  2. Pistas para crear tu lógica de Movimiento 🏃♂️💨En tu versión de C, tenías la función procesomov  y procesomovE que recibían los punteros a los structs para moverlos. Ahora, los objetos se moverán a sí mismos. Aquí tienes los "faros" para guiarte en tu diseño de la clase Entidad y sus hijas:  Pista 1: El nivel de protección adecuado 🛡️En tu clase padre Entidad, las coordenadas x e y no pueden ser private. Si son privadas, el Jugador (que es su hijo) no podrá modificarlas directamente al moverse. Debes declararlas como protected. Esto permite que estén ocultas para el exterior, pero totalmente accesibles para sus clases derivadas.Pista 2: El parámetro vital para no atravesar paredes 🧱Si haces un método que sea solo virtual void procesarMovimiento() = 0;, te encontrarás con un problema gigante: ¿cómo sabe el jugador si en la siguiente coordenada hay un #?Para que la entidad pueda verificar colisiones, tu método necesita "ver" el entorno. Tu firma del método debería obligatoriamente recibir una referencia al mapa: virtual void procesarMovimiento(Mapa& mapaActual) = 0;.Pista 3: Reutilizando tu lógica de C ♻️Para el Jugador::procesarMovimiento(Mapa& mapaActual): Aquí adentro pondrás el std::cin >> tecla (o la captura de teclado que prefieras) y tu antigua lógica de sumar/restar a X e Y dependiendo de si es 'w', 'a', 's', 'd'.Para el Enemigo::procesarMovimiento(Mapa& mapaActual): Aquí no pides teclas. Aquí meterás directamente tu lógica de generar un número con rand() % 4 para decidir hacia dónde intenta moverse en ese turno.Pista 4: El orden de las acciones 🚦Dentro de cada procesarMovimiento, la estructura lógica siempre debe ser la misma que tenías antes:Guardar una copia temporal de tu posición actual (nx, ny).Aplicar el intento de movimiento a nx o ny.Preguntarle al mapa: mapaActual.obtenerCasilla(nx, ny).Si la casilla es un espacio en blanco (' '), actualizas tu posición real (x = nx; y = ny;). Si no, te quedas donde estás.

Obs: La respuesta fue bastante completa y permitio ver claramente como armar la clase 
se utilizo gemini para entender como funcionaba srand y decidir implementar esta herramienta en el proyecto

PROMPT:
explicame que es srand y como me sirve esta herramienta para mi proyecto

gemini respondio:
¡Claro que sí! Para entender qué es srand y por qué es tan vital para tu juego, primero tenemos que revelar un gran secreto de la informática: las computadoras son pésimas improvisando. No saben hacer absolutamente nada al azar.

Son máquinas deterministas; si les das la misma instrucción, te darán exactamente el mismo resultado un millón de veces.

Vamos a desglosar qué es esta herramienta y cómo impacta directamente en tu código.

1. El problema de usar solo rand() 📖
Piensa en la función rand() que usaste en tu método enemigo::mov como si la computadora tuviera un libro gigante y secreto lleno de números desordenados.

Si en tu código solo escribes rand() % 4, la computadora abre ese "libro de números" y empieza a leer desde la Página 1.
Te va a dar números que parecen aleatorios (ej. 2, 0, 3, 1...). Sin embargo, si cierras tu juego y lo vuelves a abrir, la computadora volverá a abrir el libro en la Página 1.

¿Cómo afecta esto a tu proyecto?
Si no usaras nada más, tu enemigo haría exactamente la misma ruta de movimientos en cada partida (por ejemplo: siempre se movería Arriba, Derecha, Derecha, Abajo). El jugador se aprendería el patrón de memoria en el primer intento y el juego perdería toda la gracia.

2. La solución: srand() (Seed Random) 🌱
La "s" significa seed (semilla). Esta función sirve para decirle a la computadora: "Oye, no empieces a leer desde la página 1. Empieza a leer desde la página X".

Si tú escribes srand(5);, la computadora empezará a leer desde la página 5. Pero seguimos con el mismo problema: si siempre le pasas un 5 fijo, el juego seguirá siendo igual cada vez que lo abras. Necesitamos un número que cambie constantemente sin que nosotros hagamos nada.

3. El combo perfecto: srand(time(NULL)) ⏱️
Aquí es donde entra la genialidad de usar el reloj de tu computadora.

La función time(NULL) revisa el reloj de tu PC y devuelve la cantidad exacta de segundos que han pasado desde el 1 de enero de 1970 (esto se conoce como Tiempo Unix). Es un número gigantesco (como 1716937500) que cambia cada segundo.

Cuando pones srand(time(NULL)); en tu main.cpp, ocurre esta magia:

El programa lee la hora y saca un número enorme.

srand() usa ese número como semilla, abriendo el "libro de números aleatorios" en una página completamente aleatoria.

A partir de ahí, cuando tu enemigo llama a rand() % 4, saca direcciones que nunca se repetirán entre una partida y otra.

Obs: Esta respuesta permitio entender como funcionaba srand y time null para su implementación en el main y asi generar que cada ejecución fuera unica
