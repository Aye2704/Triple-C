# Triple-C
Hito 1:
Problematica: Al adentrarse al mundo de la programación, el primer lenguaje en el cual uno piensa siempre es "Python". Esté destaca por: su facilidad, su implementación en proyectos de IA, Ciencia de datos, etc. En un principio esto suena totalmente genial, el problema viene que para saltar de un lenguaje a otro hay cierto problema, ya que, Python al ser un lenguaje de alto nivel los comandos son bastantes amistosos y entendibles, en cambio C es todo lo contrario, un lenguaje de bajo nivel, un compilador quisquilloso(ojo aquí), pero con un rendimiento y velocidad muy eficientes, junto con un uso de memoria bastante bueno, si lo vemos de esta forma Python estaría opacando a C, teniendo una gran perdida en lo que es su aprendizaje en nivel general, esto respaldado por el PYPL y el TIOBE, los cuales dejan ver que la tendencia de aprender Python vs C es ABISMAL. En base a esta problemática Nace Triple-C, un juego que busca reducir el freno que tiene el aprendizaje en C para los principiantes.

Objetivo General: Fomentar a la programación en C y su popularidad, otorgándole un enfoque distinto al habitual, para que sea más atractivo para los que recién entran en el mundo de la programación.

Objetivos Especificos:
1. Crear un Juego, con entrada de texto en el que el usuario debe escribir condigo en C para jugar y avanzar en el juego.
2. Diseñar el Juego de manera divertida y simple, mediante el uso de librerías externas para tener una interfaz atractiva, con la intención de cambiar la percepción de que c es un lenguaje complejo y aburrido.
3. Implementar un sistema de gestión de memoria eficiente en C para el manejo de Sprites y entidades, demostrando las ventajas del control manual de recursos.

Roles:  
- Scrum master: Valentina Vilches.
- Product Owner: Joaquin López. 
- Equipo: Ezequiel Ñuñez y Alexander Maluenda.

Funcionalidades Clave:
- Movimiento del jugador, utilizando un sistema de coordenadas con vectores
- función para agregar preguntas desde un archivo .txt(Base de datos)
- menú principal interactivo.
- generación de niveles dinámico y progresión de dificultas a medida que se avanza en los niveles.


Avance logrado y próximos pasos para el hito 2:
Se logro implementar el sistema de movimiento en 2d ocupando coordenadas cartesianas, la lógica de preguntas, el menú principal y el trabajo de lógica y movimiento se logró juntar para dar un primer prototipo de lo que queremos que sea el juego.
Los próximos pasos para el hito 2 serían:
-	Explorar en su mayoría las capacidades de C++ para mejorar el código (Clases, objetos, etc.).
-	Investigar y comprender el cómo se ocupará “raylib” para el proyecto y facilitar este en algún punto.
-	Refinar el uso de punteros y memoria dinámica para que se soporte una mayor carga de elementos gráficos sin que esto afecte el rendimiento del sistema (mayor accesibilidad).

Documentación funciones;
//Aquí se explica el funcionamiento de las funciones del movimiento y mapeado.
Para la parte de movimiento se inicializaron 3 structs, 1 para el uso de los vectores (ahora mismo se hizo con enteros, para que se entendiera el movimiento en la terminal, a futuro queremos ocupar esto como floats para un movimiento más continuo), otro para el movimiento del jugador, incluyendo el primer  struct junto con una variable que podría ser entera o flotante, para indicar que tanto se moverá el personaje y otro struct para iniciar el mapa, el cual contiene la matriz que guardara caracteres en tal posición.


void iniciarmapa(map *p2,int nivel);

La función iniciar mapa recibe un puntero y el nivel actual en el que se encuentra el jugador. Se parte restando la dimensión al mapa, dependiendo del nivel en el que este y luego se realiza un ciclo “for”, para moverse por el eje Y (filas) y acto seguido sobre el ciclo se hace otro más para moverse por el eje X (columnas). Se realizan las verificaciones con un “if”, para ver si es que toca los bordes, en caso de ser así, el carácter que se guardara en el espacio será un # (un muro), en caso no estar tocando los bordes (con el “else”) se guardara en esa posición un espacio.

void dibujarmapa(movjug *p1,movjug*PE,int nivel,map *p2);

Dibujar mapa busca que todo lo que registro iniciar mapa se muestre en la terminal, aunque la peculiaridad de este es que es un ciclo “for”, pero en vez de ir aumentando el eje Y (filas), las está restando, debido a que en la función iniciar mapa, mi primera fila (0) esta en el techo(así es como lo registra la terminal) ,y al momento de moverse el personaje, se quiere que vaya hacia arriba sumando al eje Y, se debe invertir el cómo está el eje y actual, por ese el ciclo “for” restando , en el eje x no ocurre ningún cambio, la función lo recorre y busca si en tal posición está el jugador, el enemigo o si están en el mismo punto para imprimir un símbolo característico, para cada caso. En caso de que no se cumpla nada de lo anterior imprimirá su correspondiente en pantalla (espacio o #).

void procesomov(movjug *p1,char comandou,map *p2);

 “procesomov” recibe un puntero para la dirección de memoria del movimiento del jugador, una tecla que apretara el usuario y otro puntero para indicar la dirección de memoria del mapa, luego dentro de esta crea unas variables temporales para realizar las verificaciones de los límites del mapa y en caso de que el movimiento correspondiente este dentro del mapa se realiza el cambio a la dirección de memoria para efectuar el cambio correctamente.

void procesomovE(movjug *PE,map*p2);

“procesomovE” es un código totalmente analogo a “procesomov”, la única diferencia es que este cuenta con un “int” que sale de rand para un movimiento aleatorio del enemigo, este tiene 4 posibilidades “wasd” y si este movimiento cumple las verificaciones se realiza su cambio a la dirección de memoria.

//Aquí se explica el funcionamiento de las funciones del Backend de las preguntas.
·	Pregunta* cargar_preguntas(const char archivo, int maxPreg);
En esta función sirve para leer el archivo.txt y extraerle la información para guardarla dentro de la estructura de datos “Pregunta” con la intención de utilizarla a futuro en el código principal. Una vez terminada la lectura, y el traspaso a la estructura de datos se determina cuantas preguntas hay y se devuelve al stack mediante el uso de punteros para uso futuro.

•	int seleccionar_pregunta_aleatoria(Pregunta* b, int maxPreg, int nivelActual):
Función con la intención de cambiar el orden en el cual va a ser seleccionada las preguntas para que no tengan el mismo orden que tienen en el archivo y que al momento de jugar no se tenga una sensación de repetitividad, el banco de las preguntas (Pregunta* b), el número de preguntas (obtenidas en la función anterior) y el nivel actual en el momento en el cual es llamada la función (de esta forma se asegura de la progresión por nivel). La función retorna un indicador para saber si esta pregunta ya fue usada para no repetir dos preguntas seguidas.

•	int validar_respuesta(Jugador* j, Pregunta* p, char respuesta):
función simple en la cual se recibe los datos del jugado, los datos de la pregunta respondida por el usuario y la respuesta elegida por el usuario. Esta función se encarga de comparar la respuesta elegida por el usuario con la respuesta correcta y cambiar los datos del usuario en función a esta comparación (quita vidas si fallas y te da puntos del nivel y general si acertaste). La función retorna un indicador si la respuesta fue correcta o no.

•	void resetear_preguntas_nivel(Pregunta* b, int maxPreg, int nivel):
Función complementaria de “seleccionar_pregunta_aleatria”, su función es resetear las banderas de cada pregunta que identificaban si ya fue usada, la intención de esta función es ser usada cuando todas las preguntas de un nivel ya han sido usadas y el juego no se trabe, recibe el banco de las preguntas, el numero de preguntas y el nivel en el cual fueron usadas todas sus preguntas.

•	void barajar_preguntas(Pregunta* b, int maxPreg):
Función extra aparte de “seleccionar_pregunta_aleatoria” con la intención corregir un error el cual consistía que a pesar de que las preguntas se seleccionaban de manera aleatoria dentro de su nivel seguían siendo leídas en el mismo orden que el archivo .txt pero desde la primera pregunta aleatoria seleccionada. La función recibe el banco de preguntas y el total de preguntas.

•	int jugar_una_pregunta(Jugador* j, Pregunta* b, int maxPreg):
Esta función tiene el objetivo comenzar el juego de las preguntas llamar a todas las otras funciones relacionadas el juego de las preguntas, al momento de ser llamado, la intención de esta función es modularizar el código principal para mantenerlo lo mas compacto posible y mejor control de errores al momento de someter el código a pruebas. Recibe los datos del jugados, el banco de las preguntas y el número de preguntas, además este devuelve un numero entero para avisar si la respuesta elegida por el usuario fue correcta o incorrecta (1,0), si salió con ‘Q’ (2) o pidió una pista (-1).

//Aquí se explicará el funcionamiento de las funciones del Frontend del código:
•	void limpiar_patalla():
Función simple para limpiar la pantalla de la terminal cada vez que es usada, la intención es poder limpiar la terminal tanto de Windows (system(“cls”)) como de MAC y Linux (system(“clear”)) para que el código sea lo más accesible posible (uno de nuestros objetivos específicos).

•	void mostrar_encabezado (Jugador* j):
Función para mostrar en terminal las estadísticas del jugador y su estado (vidas y pistas), recibe los datos del jugador.

•	void mostrar_pregunta (Pregunta* p):
Función para mostrar en terminal los enunciados y las alternativas de la estructura de datos de la pregunta recibida.  

•	char obtener_respuesta ():
Función básica en la cual captura y filtra el carácter ingresado por el usuario y una vez filtrado para evitar errores se devuelve este mismo carácter.

•	void mostrar_feadback (int esCorrecto, char respuesta_real):
Función para mostrar una reacción visual a la respuesta del usuario después de verificar si es correcta o no, y si el usuario se equivoca muestra la respuesta real de la pregunta.

•	void pantalla_transicion (int tipo , int nivelactual); //Pantalla de si pasaste al siguiente nivel o perdiste
Función que muestra una pantalla en función de si el jugador paso un nivel, perdió o completo el juego, la función recibe un identificador para saber cual de estrás tres pantallas quieren mostrarse y el nivel en el cual se actual en el cual es llamada esta función.

•	int menu_principal(int opcion_menu);
Función para modularizar en el cual se muestra la pantalla del menú que debe de ser accesible en cualquier momento del juego para funcionar como una pausa. Se recibe y se devuelve el entero de la opción de este menú para saber si se sale del juego o se comienza/continua jugando.

•	void presionar_enter():
Función simple, en la cual funciona como pantalla de transición mientras el usuario lee un mensaje y luego presionar [ENTER] sin necesidad de un temporizador.


//Funcionamiento de las pruebas:
Para comprobar el funcionamiento del minijuego de las preguntas antes de fusionar  con el código de movimiento, se decido trabajar en distintas ramas en la cual la idea original era tener en ramas distintas también el Frontend y el Backend de las preguntas, pero luego por conveniencia al final se mantuvieron ambas en la misma rama. 

Dentro de la rama frontPreg y como se puede ver en la rama main existe un archivo llamado pruebasPreg.c en el cual se utilizo para comprobar el funcionamiento del minijuego como si fuera un juego por separado para hacer pruebas sin necesidad de depender de las funciones del movimiento. pruebasPreg.c comienza preparando la terminal para leer los caracteres del español, luego declarar las variables utilizadas y prepara las estructuras del banco de preguntas con punteros y los datos del jugados, después empieza el bucle principal del código en el cual dependiendo de la opción elegida en el menú principal este se acabara o continuara, dentro del bucle se crea un switch case para las opciones del menú para poder empezar el juego de las preguntas.
Se ejecuta la función jugar_una_pregunta para comenzar el minijuego y dependiendo de las respuestas elegidas en el minijuego se verifica la reacción de del programa en función a su elección. Una vez terminado un nivel ya sea por perder todas las vidas o completar todas las preguntas para subir de nivel se verifica y se cambian los datos del jugador en función a ello. Una vez terminado el juego se libera la memoria del heap al cual el puntero del banco guardaba sus preguntas y luego se limpia este puntero para evitar memory leak y dangling pointer. 


El newprueba.c se encargara de ejecutar el codigo de movi.c para ver si todo lo que es lógica de movimiento está funcionando correctamente
-comienza inicializando las variables correspondientes el movimiento del enemigo y el jugador , el mapa la tecla que irá poniendo el usuario y el nivel actual en el cual nos encontramos, luego se llama a la función iniciar mapa para que luego dibujar mapa sepa que poner en cada espacio, luego hacemos un ciclo while mientras la tecla que el usuario presione sea distinta de q luego se muestra un mini menú en la parte superior de la terminal y abajo se realizara la función dibujar mapa de la cual aparecerá el mapa en el cual se moverá tanto el enemigo como el personaje  luego se agrega unos printf para señalar ciertas acciones y se procesa el movimiento con las funciones procesomov y procesomovE y finalmente cuando el ciclo while termina se imprimirá “juego finalizado”.


Compilación del código:
Comando de compilación en el directorio Triple-C: gcc -I headers src/main/main.c src/preguntas/enginePreg.c src/mov/mov.c/movi.c -o build/triplec
Comando de compilación en el directorio Triple-C/build: gcc -I../headers ../src/main/main.c ../src/preguntas/enginePreg.c ../src/mov/mov.c/movi.c -o triplec
//Atención: el ejecutable debe de ser compilado en el directorio build, ya que el ejecutable debe de estar en el mismo directorio que archivopregs.txt (no se dio la dirección de este archivo al código por lo cual buscara en el mismo directorio en el cual el ejecutable este).

Requerimientos:
Descarga el repositorio presionando code<> y luego Download ZIP.
Descomprime el archivo zip e identifica el directorio del archivo descomprimido.
A continuación se explicara paso a paso como compilar el código para todos los Sistemas operativos.

Linux:
Instalar GCC: Abrir terminal y escribir: (sudo apt install build-essential).
Navegar y compilar: entra en la carpeta y ejecuta los comandos de compilación dependiendo en que directorio lo compiles.
Ejecutar: en el directorio build escribe ./triplec y presiona ENTER.

MAC:
Instalar Terminal tolos: Abrir la aplicación "Terminal" y escribir: xcode-select --install. para luego dale a "instalar".
Navegar: en la terminal escribe cd seguido de un espacio y arrastrar la carpeta del repositorio descomprimido dentro de la terminal y luego presiona ENTER.
Compilar: escribir los comandos de compilación dependiendo de el directorio en el que compiles.
Ejecutar: en el directorio build escribe ./triplec y presiona ENTER.

Windows:
Instalar el Compilador: Descargar e instalar VS Code. y una vez echo esto instala la extencion dentro de VS Code C/C++, esto instala el programa para escribir código y el GCC al mismo tiempo.
Abrir la carpeta descomprimida del repositorio: En VS Code busca la carpeta instalada File > Open Folder > Triple-C
Compilar y correr: Abres una nueva terminal con Terminal > New Terminal y compilas el código con el comando dado dependiendo en que directorio estes.
Ejecutar: en el directorio build escribe ./triplec y presiona ENTER.


Cambios:
Cambiamos los objetivos clave del proyecto al encontrarnos con varias dificultades con los tiempos y nuestras capacidades. por lo cual fueron cambiadas a unas mas básicas y simples para implementar.
Problemática fue cambiada, no cambiando el problema planteado pero si añadiéndole contexto y profundidad para una mayor compresión.
Se cambio la forma en la cual esta escrita el objetivo general para darle mas formalidad.
Se cambio la idea de escribir el código en juego por un juego de preguntas por complicaciones en la implantación de esta función.
La idea de un plataformero ah sido parcialmente descartada, ya que hasta el hito 1 solo se ah logrado un juego de movimiento en cuatro direcciones sin los aspectos plataformero que es posible que si pueda ser implementado en un futuro.



HITO 2:

//Documentacion de los cambios estructurales, las clases y sus metodos

Cambios estructurales para la logica de movimiento y mapa: Los cambios estructurales realizados consistieron principalmente en la adopción de la estructura de clases, dividiendo el proyecto en tres componentes esenciales: entidad(para el movimiento), mapa (para gestionar el entorno) y juego (para encapsular la lógica principal y simplificar el código del archivo main). Además, a diferencia de la versión en C donde estructurábamos el mapa manualmente usando punteros y memoria dinámica, en esta iteración de C++ implementamos contenedores como std::vector, lo que facilita y hace más segura la creación del espacio.

Clase Mapa: Se encarga de generar el espacio donde interactúan los personajes. Sus atributos incluyen un valor entero que define la dimensión del área (la cual se reduce progresivamente al avanzar de nivel) y una matriz basada en un vector de vectores.  sus métodos son  obtenerDimension, que devuelve el tamaño actual del mapa, y obtenerCasilla(x, y), el cual retorna el valor de una coordenada específica, siendo clave para validar el movimiento.

Clase Entidad: Funciona como la clase base para otorgar estructura a Jugador y Enemigo. Sus atributos protegidos almacenan las coordenadas de posición (x, y) y la cantidad de casillas de avance. Implementa un método virtual puro (mov) para obligar a las clases derivadas a definir su propio comportamiento de desplazamiento , el jugador utiliza  las teclas de control (WASD), mientras que el enemigo opera mediante un sistema de movimiento aleatorio. Adicionalmente, sus métodos son bastantes pequeños (obtenerX y obtenerY) para compartir su ubicación con la clase juego sin romper el encapsulamiento

Clase Juego: Actúa como el motor principal, encargándose de dibujar el mapa en la terminal y que se muestre el movimiento de las entidades. Posee instancias directas de las clases mencionadas anteriormente y un atributo booleano (flagjuego) que dictara cuando debe terminar la partida, la cual solo terminara si se presiona la tecla 'q'. Su método central, iniciar(), ejecuta el bucle de juego: limpia la pantalla, dibuja el estado actual mediante ciclos for y procesa las actualizaciones de movimiento.

Dificultades de la Migración La principal dificultad enfrentada durante esta entrega fue el proceso de traducción mental desde lo que era la estructura de C hacia la Programación Orientada a Objetos. Por lo que hubo un montón de errores de sintaxis iniciales y, más importante aún, se tuvo que reestructurar la arquitectura del código para darle la forma a la estructura de C++ ademas fue necesario diseñar nuevos métodos para la comunicación entre clases para lograr interacciones que antes resolvíamos directamente manipulando punteros

Las pruebas de las mecánicas de movimiento se encuentran en el archivo pruebita.cpp. Al delegar la lógica pesada a la clase Juego, este ejecutable resulta bastante corto. Su compilación y ejecución permiten verificar en consola que el control por teclado (WASD) responde correctamente, que las posiciones de ambos personajes se actualizan en tiempo real y que el sistema de colisión previene  que las entidades atraviesen los límites del mapa

Con respecto al tercer hito, y ahora que contamos con un dominio mucho más claro de C++ y de la visión final de Triple-C, hemos tomado la decisión  de no utilizar la biblioteca gráfica Raylib. Si bien Raylib resultaba intuitiva para el manejo de interfaces, hemos optado por utilizar el framework de Qt Creator. Consideramos que las herramientas que provee este framework son más completas y nos permitirán alcanzar un estándar estético más profesional, logrando así la distinción visual y didáctica que buscamos para el proyecto.


//ANEXOS

https://pypl.github.io/PYPL.html

https://www.tiobe.com/tiobe-index/
TIOBE

- Referencias
Alzahrani, N., Vahid, F., et al. (2018). Python Versus C++: An Analysis of Student Struggle on Small Coding Exercises in Introductory Programming Courses. SIGCSE '18. DOI: 10.1145/3159450.3160586.
-link respectivo:https://dl.acm.org/doi/10.1145/3159450.3160586

