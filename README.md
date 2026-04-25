# Triple-C

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
