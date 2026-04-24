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

Funcionalidades claves del codigo:
- Nucleo para ejecutar codigo C en vivo (Escribir codigo en el juego y afecte en tiempo real).
- Uso de vectores para un juego dinámico de movimiento.


DOCUMENTACIÓN FUNCIONES;


PARA LA PARTE DE MOVIMIENTO SE INICIALIZAN 3 STRUCTS 1 PARA EL USO DE LOS VECTORES(AHORA MISMO SE HIZO CON ENTEROS
PARA QUE SE ENTENDIERA EL MOVIMIENTO EN LA TERMINAL A FUTURO QUEREMOS OCUPAR ESTO COMO FLOATS PARA UN MOVIMIENTO MAS CONTINUO), OTRO PARA EL MOVIMIENTO DEL JUGADOR INCLUYENDO EL PRIMER  STRUCT JUNTO CON UNA VARIABLE QUE PODRÍA SER ENTERA O FLOTANTE PARA INDICAR QUE TANTO SE MOVERÁ EL PJ Y OTRO STRUCT PARA INICIAR EL MAPA
EL CUAL CONTIENE LA MATRIZ QUE GUARDARA CARACTERES EN TAL POSICIÓN


void iniciarmapa(map *p2,int nivel);


MI FUNCIÓN INICIAR MAPA RECIBE UN PUNTERO Y EL NIVEL ACTUAL EN EL QUE SE ENCUENTRA EL JUGADOR 
SE PARTE RESTANDO LA DIMENSIÓN A MI MAPA DEPENDIENDO DEL NIVEL EN EL QUE ESTE Y LUEGO SE REALIZA UN CICLO FOR PARA MOVERSE POR EL EJE Y (FILAS) Y ACTO SEGUIDO SOBRE ESTE FOR SE HACE OTRO FOR PARA IR MOVIÉNDOSE POR EL EJE X(COLUMNAS)
SE REALIZAN LAS VERIFICACIONES CON UN IF PARA VER SI ES QUE TOCA LOS BORDES EN CASO DE SER ASI EL CARACTER QUE SE GUARDARA EN EL ESPACIO SERÁ UN # (UN MURO) EN CASO NO ESTAR TOCANDO LOS BORDES(CON EL ELSE) SE GUARDARÁ EN ESA POSICION UN ESPACIO

void dibujarmapa(movjug *p1,movjug*PE,int nivel,map *p2);

DIBUJAR MAPA BUSCA QUE TODO LO QUE REGISTRÓ INICIAR MAPA SE MUESTRE EN LA TERMINAL PERO LA PECULIARIDAD DE ESTE ES QUE ES UN CICLO FOR PERO EN VEZ DE IR AUMENTANDO EL EJE Y OSEA LAS FILAS LAS VA RESTANDO, ESTO PQ CON INICIAR MAPA MÍ PRIMERA FILA OSEA MI FILA 0 ESTA EN EL TECHO YA QUE ASÍ ES COMO LO REGISTRA LA TERMINAL ,Y COMO AL MOMENTO DE MOVERSE EL PERSONAJE QUIERO QUE VAYA PARA ARRIBA SUMANDO AL EJE Y DEBO INVERTIR EL COMO ESTA MI EJE Y ACTUAL POR ESE EL CICLO FOR RESTANDO , EN EL EJE X NO OCURRE NINGÚN CAMBIO LO RECORRE Y BUSCA SI EN TAL POSICIÓN ESTÁ EL JUGADOR , EL ENEMIGO O SI ESTÁN EN EL MISMO PUNTO PARA IMPRIMIR UN SIMBOLO CARACTERISTICO PARA CADA CASO Y EN CASO DE QUE NO SE CUMPLA NADA DE LO ANTERIOR IMPRIMIRÁ SU CORRESPONDIENTE EN PANTALLA( ESPACIO O #)

void procesomov(movjug *p1,char comandou,map *p2);



 PROCESOMOV RECIBE UN PUNTERO PARA LA DIRECCIÓN DE MEMORIA DEL MOVIMIENTO DEL JUGADOR, UNA TECLA QUE APRETARA EL USUARIO Y OTRO PUNTERO PARA INDICAR LA DIRECCIÓN DE MEMORIA DEL MAPA
LUEGO DENTRO DE ESTA CREA UNAS VARIABLES TEMPORALES PARA REALIZAR LAS VERIFICACIONES DE LOS LÍMITES DEL MAPA Y EN CASO DE QUE EL MOVIMIENTO CORRESPONDIENTE ESTÉ DENTRO DEL MAPA SE REALIZA EL CAMBIO A LA DIRECCIÓN DE MEMORIA PARA EFECTUAR EL CAMBIO CORRECTAMENTE

void procesomovE(movjug *PE,map*p2);

PROCESOMOVE ES UN CODIGO TOTALMENTE ANÁLOGO A PROCESOMOV LA ÚNICA DIFERENCIA ES QUE ESTE CUENTA CON UN INT QUE SALE DE RAND PARA UN MOVIMIENTO ALEATORIO DE EL ENEMIGO ESTE TIENE 4 POSIBILIDADES WASD Y SI ESTE MOVIMIENTO CUMPLE LAS VERIFICACIONES SE REALIZA SU CAMBIO A LA DIRECCIÓN DE MEMORIA

