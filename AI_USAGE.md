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

# Logica de Preguntas Hito 2

### 1. Herramientas y Modelos de IA Utilizados

* **Herramienta / Plataforma:** Gemini (Google AI).
* **Modelo:** Gemini Large Language Model.
* **Archivos de contexto provistos:** `05_IntroCPP_POO.pdf` (Documento guía con los fundamentos académicos de C++ y Programación Orientada a Objetos para la sincronización de estándares sintácticos).

---

### 2. Registro de Prompts (Indicaciones de Entrada)

El desarrollo del código se realizó de manera iterativa a través de las siguientes instrucciones secuenciales:

1. *Adaptación inicial a lineamientos académicos:* > "Necesito que modifiques de ser necesario el código con las mismas indicaciones, pero teniendo en cuenta los contenidos presentados en el archivo adjunto, por lo cual si se debe de cambiar los métodos de no ser presentados en el archivo adjunto."
2. *Refactorización Arquitectónica:*
> "Separa el código en dos archivos (uno para el frontend y otro para el Backend)."


3. *Generación del Entorno de Pruebas:*
> "Haz un código para hacer pruebas con el juego de las preguntas de los códigos anteriormente pedidos considerando las indicaciones previamente dadas."


4. *Ajuste a Datos Existentes:*
> "Ya tengo un archivo .txt para hacer las pruebas, por lo cual modifica el código teniendo eso en cuenta."



---

### 3. Observaciones sobre el Desarrollo y Contribución de la IA

* **Alineación Pedagógica Estricta:** La IA filtró y omitió deliberadamente características avanzadas o modernas de C++ (como `auto`, bucles *range-based* o la librería `<random>`) que, aunque óptimas en la industria, no correspondían al material académico del archivo adjunto proporcionado.
* **Modularización y Modularidad (POO):** El modelo reestructuró de forma efectiva un diseño monolítico hacia una arquitectura basada en el principio de separación de responsabilidades, aislando la lógica de negocio (`backend`) de la interfaz de usuario por consola (`frontend`) mediante el patrón de inyección de dependencias (pasando el puntero del motor lógico al constructor de la interfaz).
* **Gestión de Memoria Obligatoria:** Se forzó el uso manual de memoria dinámica mediante los operadores `new` y `delete` para cumplir con los objetivos evaluativos de la materia sobre la administración de punteros y ciclos de vida de los objetos en el *Heap*.

---

### 4. Limitaciones Identificadas de la IA y del Código Generado

* **Dependencia Estricta del Formato de Entrada:** El método de parseo implementado por la IA en el Backend asume un orden y una estructura rígida en el archivo `.txt` (delimitado estrictamente por caracteres `|`). Si el archivo posee líneas vacías, saltos de línea inesperados o columnas faltantes, el sistema podría ignorar registros o fallar en tiempo de ejecución debido a la falta de validaciones robustas de expresiones regulares.
* **Prácticas de C++ Tradicional vs. Moderno:** Para cumplir con el programa de estudios del PDF, la IA utilizó arreglos dinámicos tradicionales controlados por punteros crudos (`raw pointers`). En un entorno de producción moderno, esto constituye una limitación de seguridad contra fugas de memoria (*memory leaks*), donde se preferiría el uso de punteros inteligentes (`std::unique_ptr` o `std::shared_ptr`).
* **Algoritmo de Mezcla Básico:** El método `barajarPreguntas()` utiliza `rand() % (i + 1)`. Los modelos de IA advierten implícitamente que la función estándar `rand()` de `<cstdlib>` posee limitaciones en su distribución de entropía y aleatoriedad matemática en comparación con los motores de generación modernos incluidos en `<random>`.
* **Lógica de Reinicio Limitada:** El código de prueba en `main.cpp` maneja el flujo de juego continuo, pero ante un escenario de *Game Over*, requiere de una intervención manual del programador para restablecer los estados internos de las variables del jugador (como las vidas y el puntaje acumulado) si se desea iniciar una partida completamente nueva sin reiniciar el ejecutable.



# Fusion de codigos para la creacion del main

#### 1. Herramientas de IA Generativa Utilizadas

* **Modelo:** Google Gemini.
* **Uso principal:** Generación de código (`main.cpp`), refactorización de código C a estándares de C++ (POO), y diseño de la arquitectura del bucle principal del juego.

#### 2. Prompts Principales Utilizados

Durante el desarrollo de la integración, se utilizó el siguiente prompt principal (o variaciones del mismo) para guiar a la IA:

> *"Haz el código de un archivo main.c en el cual se fusionan los conceptos de un juego de alternativas y otro de movimiento, creando un juego en el cual cada vez que se choca con el enemigo aparezca el juego de las preguntas y una vez terminado el nivel en el juego de alternativas se pueda progresar en el juego con movimiento. Haz este código o modificaciones de los códigos presentados considerando los siguientes criterios: compilación en C++, definición de clases coherentes con responsabilidades claras y encapsulamiento, estructura ordenada, uso adecuado de la biblioteca estándar de C++ (evitando patrones innecesarios de C), código claro y consistente."*

#### 3. Observaciones sobre la IA

* **Estructuración Arquitectónica:** La IA fue eficaz para identificar que el bucle `while` original dentro de la clase `juego` impedía la integración con el motor de preguntas. Propuso correctamente transformar el método `iniciar()` en un método `actualizar()` que procesa el juego "fotograma a fotograma", permitiendo al `main.cpp` actuar como controlador maestro.
* **Transición de C a C++:** La herramienta identificó exitosamente sintaxis heredada de C (como el uso de `printf` y falta de encapsulamiento estricto) y la adaptó a flujos de C++ (`std::cout`, constructores delegados, etc.).
* **Resolución de Lógica de Juego:** La IA anticipó un error lógico común en este tipo de integraciones (el bucle infinito de colisiones instantáneas tras salir del modo trivia) y propuso proactivamente el método `reset_enemigo()` para reubicar la entidad.

#### 4. Limitaciones Encontradas

* **Dependencia del Entorno del Sistema Operativo:** La IA no puede probar el código en el entorno real de ejecución (la consola de comandos). Esto limitó la capacidad de asegurar que los comandos de limpieza de pantalla (`system("cls")` para Windows vs `system("clear")` para Linux) funcionaran perfectamente sin causar parpadeos (flickering) en la terminal. El desarrollador humano tuvo que verificar esto empíricamente.
* **Falta de Contexto del Archivo Externo:** Para que el código generado (como el `MotorTrivia`) funcionara, la IA asumió la existencia y estructura de un archivo externo (`preguntas.txt`) delimitado por caracteres `|`. La validación de que el archivo real coincidiera con la lógica de *parsing* sugerida recayó completamente en el desarrollador.
* **Manejo de la Aleatoriedad:** Aunque la IA sugirió el uso de `srand(time(NULL))` para la semilla del generador, la distribución real de las preguntas y el movimiento enemigo requiere pruebas manuales para asegurar que la experiencia de juego sea balanceada, algo que el modelo no puede simular por sí mismo.


USO IA HITO 3:

Modelo: Gemini Pro3.1
Se utilizo gemini para entender la diferencia entre cmake y qmake para ver cual sera el mejor para
el proyecto
Prompt:
EN QUE CAMBIAN Qmake y cmake
Respuesta:Ambos son "sistemas de construcción" (build systems). Su trabajo principal es leer la configuración de tu proyecto, encontrar dónde están tus archivos .cpp y .hpp, y darle las instrucciones exactas al compilador (como GCC o MinGW) para armar todo y generar tu archivo ejecutable final.

La diferencia principal radica en su alcance y en el estándar de la industria.

Diferencias Clave
qmake: Es la herramienta clásica creada exclusivamente por y para el ecosistema Qt. Utiliza archivos .pro que son muy limpios, amigables y fáciles de leer. Si solo vas a hacer aplicaciones en Qt, es el camino más rápido y con la curva de aprendizaje más baja. Sin embargo, Qt Company anunció que a partir de Qt 6, este sistema pasará a segundo plano.

CMake: Es el estándar universal de la industria para proyectos en C++, sin importar si usan Qt, otra librería gráfica, o pura consola. Utiliza archivos CMakeLists.txt. Es muchísimo más potente, flexible y te permite integrar librerías externas complejas con facilidad, pero su sintaxis es más enredada y difícil de aprender al principio.
Obs:La respuesta nos ayudo a tener mas claro cual usaremos para el desarrollo del proyecto





Se utilizo gemini para aprender sobre Keypressevent y Qpaint
Prompt:
explicame el keypressevent y el paint event y que funciones me son utiles para dibujar el mapa de mi proyecto
Respuesta:
Comprender estos dos eventos es el gran salto de nivel que estás dando al pasar de la consola a una interfaz gráfica real. En Qt, tú no "mandas" a dibujar o a leer el teclado directamente en un bucle infinito (como un while(true)), sino que Qt te avisa cuándo ocurren estas cosas a través de Eventos.

Aquí tienes la explicación directa y las funciones exactas que necesitas usar para que tu mapa se dibuje impecable.

1. keyPressEvent (El Sistema Nervioso)
Este método es un "interruptor" que Qt enciende automáticamente cada vez que el usuario presiona físicamente una tecla.

¿Cómo funciona?
Tú no llamas a esta función; Qt la llama por ti y le pasa un "paquete" de información llamado QKeyEvent. Ese paquete contiene qué tecla exacta se presionó.

Funciones y elementos vitales:

evento->key(): Extrae el código de la tecla presionada.

Las constantes de Qt: Usas esto para comparar. Por ejemplo: Qt::Key_W, Qt::Key_A, Qt::Key_S, Qt::Key_D, o las flechas Qt::Key_Up, Qt::Key_Down, etc.

update() (¡La función más importante!): Al final de tu keyPressEvent, después de cambiar las coordenadas (X, Y) de tu jugador, debes llamar a update(). Esto le grita a Qt: "¡Oye, las coordenadas cambiaron, borra la pantalla y vuelve a dibujar todo!". Si olvidas el update(), tu jugador se moverá en la lógica, pero la pantalla se quedará congelada.

2. paintEvent (El Lienzo y el Pincel)
Este es el único lugar donde tienes permitido dibujar en Qt. Se ejecuta automáticamente al abrir la ventana, al maximizarla, o cuando tú lo pides a la fuerza llamando a update().

¿Cómo funciona?
Adentro de este método, siempre debes crear un objeto QPainter. Imagina que el QPainter es tu pincel mágico y la ventana (this) es tu lienzo.

Funciones súper útiles para dibujar tu mapa:

painter.drawPixmap(x, y, ancho, alto, imagen): Esta es la joya de la corona. Te sirve para dibujar tus imágenes (wekeche.png y nicki.png). Le dices exactamente en qué píxel ponerla y de qué tamaño.

painter.fillRect(x, y, ancho, alto, QColor(r, g, b)): Ideal para dibujar los muros de tu mapa (#) si no tienes una imagen para ellos. Te pinta un cuadrado sólido del color que elijas.

painter.drawRect(x, y, ancho, alto): Esto dibuja solo el borde (el contorno) de un rectángulo. Es perfecto si quieres dibujar las líneas de la cuadrícula de tu mapa para que se vea como un tablero.

painter.drawText(x, y, "Texto"): Útil si quieres dibujar sobre el mapa textos rápidos como "Nivel 1" o el contador de vidas de tu personaje.