# Triple-C
Bienvenido a **Triple-C**, un juego educativo diseñado para hacer el aprendizaje de programación C sea interactivo, visual y menos intimidante para los principiantes

---

## Problematica
Al adentrarse al mundo de la programación, el primer lenguaje en el cual uno piensa siempre es **Python**. Esté destaca por: su facilidad, su implementación en proyectos de IA y Ciencia de datos. En un principio esto suena totalmente genial, el problema viene que para saltar de un lenguaje a otro hay cierto problema, ya que, Python al ser un lenguaje de alto nivel los comandos son bastantes amistosos y entendibles, en cambio C es todo lo contrario, un lenguaje de bajo nivel, un compilador quisquilloso(ojo aquí), pero con un rendimiento y velocidad muy eficientes, junto con un uso de memoria bastante bueno, si lo vemos de esta forma Python estaría opacando a C, teniendo una gran perdida en lo que es su aprendizaje en nivel general, esto respaldado por el PYPL y el TIOBE, los cuales dejan ver que la tendencia de aprender Python vs C es ABISMAL. En base a esta problemática Nace Triple-C, un juego que busca reducir el freno que tiene el aprendizaje en C para los principiantes.

---

## Objetivo General
Fomentar a la programación en C y su popularidad, otorgándole un enfoque distinto al habitual, para que sea más atractivo para los que recién entran en el mundo de la programación.

## Objetivos Especificos 
//Previamente se tenían objetivos específicos distintos pero durante el desarrollo del programa hubieron cambios y se decidió que estos son los mejores objetivos específicos que representa nuestro proyecto
1. **Implementar un sistema de preguntas tipo Trivia** de opcion multiple basado en preguntas reales de C.
2. **Cerar un mapa interactivo de exploracion** donde el usuario deba evadir y alcanzar metas para progresar
3. **Diseñar una interfaz Grafca de usuario atractiva** e intuitiva, cambiando la percepcion de que aprender C/C++ es aburrido y complejo.

## Roles  
* **Scrum master:** Valentina Vilches.
* **Product Owner:** Joaquin López. 
* **Equipo de Desarrollo:** Ezequiel Ñuñez y Alexander Maluenda.

## Funcionalidades Clave:
* **Navegacion 2D** Movimiento del jugador, utilizando un sistema de coordenadas con vectores
* **Motor de Trivia** para agregar preguntas desde un archivo .txt(Base de datos)
* **Menú principal interactivo.**
* **Progresión Dinamíca** generación de niveles dinámico y progresión de dificultas a medida que se avanza en los niveles.

### Pruebas Realizadas
| Prueba | Acción | Resultado Esperado & Logrado |
| :--- | :--- | :--- |
| **Parsing de BD** | Carga de archivo con líneas vacías o incompletas. | El sistema ignora errores y carga solo objetos `Pregunta` válidos sin colapsar. |
| **Límites de Vidas** | Fallar intencionalmente 3 respuestas. | El juego detecta `vidas <= 0`, notifica la derrota y retorna al menú. |
| **Colisión y Bloqueo** | Jugador camina contra muros perimetrales. | El algoritmo deniega la actualización de coordenadas; el sprite no traspasa la pared. |
| **Eventos Qt** | Presionar múltiples teclas rápidamente en el mapa. | El widget procesa el evento asíncrono sin congelar el hilo principal de la UI. |

---

## Evolucion del Proyecto (Hito 1 al 3)

1. **Hito 1 (C Basico - Terminal):** Nacimiento del motor base. se usaron punteros basicos, memoria manuel ('malloc' y 'free') y matrices de caracteres para simular un mapa en la consola. La logica era puramente secuencial.
2. **Hito 2 (C++ POO -Terminal):** Migracion completa a la orientacion a objetos. Se crearon clases encapsuladas ('Entidad', 'Mapa', 'MotorTrivia'). Se usó la biblióteca estandar ('std::vector' y 'std::string') para mayor seguridad.
3. **Hito 3(C++ Qt - GUI):** El salto definitivo. Reemplao del bucl infinito clasico de consola ('while(true)`) por una **Arquitectura dirigida por eventos (Signals y Slots)**. Creacion de componentes visuales, botones y renderizado 2D mediante 'QPainter'.

---

## Clases Principales, Responsabilidades y Relaciones

### Motor de Exploración
* **'mapa':** Genera y administra la matriz especial del laberinto
* **'entidad':** Abstraccion generica con coordenadas
  * **'player':** Sobrescribe el metodo 'mov()' escuchando inputs (WASD).
  * **'enemigo':** Sobrescribe 'mov()' con logica de movimiento de persecucion. 
* **'juego':** Contiene mapa, jugador y enemigo. Verifica condiciones de victoria y colisiones.

### Motor de de Trivia
* **'Pregunta':** Entidad pura de datos (Enunciado, opciones, respuestas, estado).
* **'Jugador':** Gestiona el estado de la sesión (vidas, nivel, puntaje).
* **'MotorTrivia':** Administra los datos. Lee el '.txt', instancia los objetos 'Pregunta' en un 'std::vector' y valida las respuestas usando el objeto 'Jugador'.

### Frontend
* **'maponW':** componente visual (hereda de 'QWidget') encargado exclusivamente de pintar cuadrados ussando 'QPainter' y emitir señales de teclado
* **'MainWindow':** La ventana maestra que coordina la aplicacion entera

---

## Interfaz Desarrollada y Flujo de Uso

**Objetivo UI:** dar una experiencia de escritorio inmersiva, eliminando la terminal y ofreciendo ventanas y dialogos nativos.

* **Widgets Principales:** 'QStackedWidget' : Usado como adminstrador central para apilar las pantallas y alternar entre ellas sin abrir ventanas nuevas.
  * 'QRadioButton' / 'QStackedWidget' : Para la seleccion de respuestas únicas en la trivia
  * 'QMessegeBox' : Para el feedback inmediato (victorias y Derrotas)
* **Parametrizacion:** El juego parametriza su estado en base al 'nivel' alcanzado. A mayor nivel, la dimencion del mapa se reduce, obligando a jugar en espacios más reducidos.
* **Flujo de Uso:**
  1. Pantalla de Menú (inicio)
  2. Trasición al 'mapoW'
  3. al chocar, señal inmediata a 'MainWindow' -> Muestra Pantalla Trivia.
  4. Bloque de 5 preguntas -> al terminar, el enemigo desaparece y se vuelve al mapa.
  5. Al alcanzar la meta, se sube de nivel y se reinicia el ciclo.

---

## Separación entre Lógica e Interfaz
El proyecto respeta firmemente el patrón de arquitectura separada.
* **La lógica es ciega:** Clases como 'MotorTrivia' o juego **no incluyen nada** relacionado a '<QWidget>' o '<QPushButton>'. Solo manejan enteros, booleanos y strings, retornando resultados en crudo.
* **La interfaz es reactiva:** 'MainWindow' contiene instancias (punteros) hacia 'MotorTrivia' y 'juego'. Cuando el usuario hace clic en un botón, la interfaz extrae el valor del formulario, se lo envía a la lógica y, basándose en la respuesta, decide si pintar un mensaje de éxito o restar una vida

---

## Compilación y Ejecución (Qt)

Debido al Hito 3, **ya no se usa GCC mediante línea de comandos pura**, sino el sistema de construcción de **CMake integrado con Qt**.

1. **Requisitos Previos:** Tener instalado **Qt Creator** y **Qt 6** (o superior) junto con un compilador de C++17 (MinGW o MSVC).
2. **Abrir el Proyecto:** * Abre Qt Creator y selecciona 'File -> Open File or Project...'
   * Navega hasta la carpeta del proyecto y selecciona el archivo 'CMakeLists.txt'.
   * En caso de no tener descargado el repositorio aquí tienes una pequeña guia:
     * Descarga el repositorio en '<> Code' y luego 'Dowload ZIP'.
     * Descomprimelo en donde quieras e identifica su direccion para seleccionar 'CMakeLists.txt'.
3. **Configurar el Kit:** Selecciona el Kit correspondiente (ej. *Desktop Qt 6.x.x MinGW 64-bit*) y establece la carpeta 'build' como directorio de compilación (Este paso es opcional, ya que normalmente este kit esta por defaul).
4. **Construir y Ejecutar:**
   * Haz clic en el boton de **"Run"** (icono verde de "Play") en la esquina inferior izquierda o presiona 'Ctrl + R'.
   * CMake compilará los meta-objetos ('MOC'), enlazara las bibliotecas y lanzará la ventana gráfica automáticamente.
   * *Nota:* El archivo 'archivopregs.txt' se copia automáticamente al directorio 'build' gracias a una regla incorporada en nuestro 'CMakeLists.txt'.

---

## Principales Dificultades (Qt)

1. **El paradigma asíncrono:** Pasar de un 'cin >> opcion' que detenía el código mágicamente a un entorno de interfaz gráfica fue el mayor reto. Entender que no se puede pausar un método esperando a que el usuario haga clic obligo a aprender el uso de Signals y Slots.
2. **QPainter y el PaintEvent:** Acostumbrarnos a que la interfaz solo se dibuja cuando el sistema operativo lo ordena, y aprender a forzar este redibujado utilizando la función 'update()' del widget.
3. **Manejo del Foco del Teclado:** Asegurarnos de que el widget del mapa mantuviese el foco ('Qt::StrongFocus') para que las teclas WASD no fuesen capturadas por error por otros componentes de la ventana.

---

## Principales Dificultades (Qt)

1. **El paradigma asíncrono:** Pasar de un 'cin >> opcion' que detenía el código mágicamente a un entorno de interfaz gráfica fue el mayor reto. Entender que no se puede pausar un método esperando a que el usuario haga clic obligo a aprender el uso de Signals y Slots.
2. **QPainter y el PaintEvent:** Acostumbrarnos a que la interfaz solo se dibuja cuando el sistema operativo lo ordena, y aprender a forzar este redibujado utilizando la función 'update()' del widget.
3. **Manejo del Foco del Teclado:** Asegurarnos de que el widget del mapa mantuviese el foco ('Qt::StrongFocus') para que las teclas WASD no fuesen capturadas por error por otros componentes de la ventana.

---

## Justificación de Cambios

A medida que el proyecto escaló, el equipo acordó estratégicamente redefinir ciertos aspectos de las bases originales:
1. **Trivia vs. Escritura de Código:** Se modificó la regla inicial de "escribir código C en la terminal" por un sistema de seleccion múltiple. *Justificación:* Procesar codigo escrito libremente por el usuario requería desarrollar un analizador léxico/sintáctico incrustado, escapando monumentalmente del alcance de tiempo de la asignatura. Las opciones multiples permiten centrarse en la lógica del juego (resumen: fantasmeada historica).
2. **Abandono de Raylib por Qt:** En el hito 1 y 2 se menciono la intención de usar Raylib. *Justificación:* Qt framework demostró proveer herramientas más holísticas (widgets de formulario) idóneas para construir encuestas, a diferencia de Raylib, orientado 100% a canvas bruto que hubiese obligado a programar botones desde cero.
3. **Plataformero a Top-Down Explorativo:** *Justificación:* Aplicar físicas vectoriales de gravedad requería cálculos intermedios de colision que entorpecían el núcleo educativo del programa (resumen: ni el Momo vendio tanto humo).

---

## Conclusion y posibles mejoras

Como equipo, tras finalizar este proyecto, llegamos a una conclusión clara: aunque el desarrollo presentó sus roces sobre todo al lidiar con los tiempos y la organización interna, logramos obtener el aprendizaje que de verdad importa. Consolidamos la lógica necesaria para estructurar proyectos robustos tanto en C como en C++, dominando herramientas fundamentales como punteros, structs y clases. Precisamente, contar con esta base técnica sólida fue lo que nos dio la confianza para dar el salto y abarcar el framework de Qt. Esto nos permitió optimizar la arquitectura del proyecto de manera eficaz y materializar el resultado funcional que se puede probar hoy.

Haciendo un poco de autocrítica, el reloj nos limitó en algunos detalles. Con más tiempo, nos habría encantado profundizar en las funciones que ofrece QtWidgets para darle a Triple-C una estética más pulida, inmersiva y menos "cuadrada". Asimismo, nos quedó en el tintero la opción de agregar más enemigos y diseñar mecánicas de movimiento más dinámicas. Somos conscientes de que estos ejes habrían escalado la complejidad y el tiempo de desarrollo, pero representan el siguiente paso lógico para seguir haciendo crecer el juego.


---

## Documentos Adicionales, Anexos y referencias

* **Anexo PYPL:** https://pypl.github.io/PYPL.html

* **Anexo TIOBE:** https://www.tiobe.com/tiobe-index/

### Referencias
* Alzahrani, N., Vahid, F., et al. (2018). Python Versus C++: An Analysis of Student Struggle on Small Coding Exercises in Introductory Programming Courses. SIGCSE '18. DOI: 10.1145/3159450.3160586.
	* link respectivo:https://dl.acm.org/doi/10.1145/3159450.3160586

