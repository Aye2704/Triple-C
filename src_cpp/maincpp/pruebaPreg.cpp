#include "preg.hpp"
#include "uireal.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <clocale> // Necesario para setlocale

int main() {
    // 1. Inicializar la semilla para los números aleatorios
    srand(time(NULL));

    setlocale(LC_ALL, "es_ES.UTF-8"); // Activa el soporte para español
    // 2. Definir la ruta de tu archivo .txt existente
    // REEMPLAZA "preguntas.txt" por el nombre exacto de tu archivo si es diferente
    std::string rutaArchivo = "archivopregs.txt"; 

    // 3. Instanciar el Backend (Motor Lógico) usando memoria dinámica
    MotorTrivia* backend = new MotorTrivia();

    // Cargar las preguntas desde tu archivo
    if (!backend->cargar_Preguntas(rutaArchivo)) {
        std::cout << "Error critico: No se pudo abrir o leer el archivo '" << rutaArchivo << "'.\n";
        std::cout << "Asegurate de que el archivo este en la misma carpeta que el ejecutable.\n";
        delete backend; // Liberar memoria antes de salir por error
        return 1;
    }

    // 4. Instanciar el Frontend (Interfaz), inyectando el puntero del backend
    uireal frontend(backend);

    bool ejecutando = true;

    // 5. Bucle principal de la aplicación
    while (ejecutando) {
        int opcion = frontend.menu_principal();

        if (opcion == 1) { // Seleccionó Jugar
            bool jugandoNivel = true;
            backend->barajar_Preguntas(); // Mezclar las preguntas antes de empezar

            while (jugandoNivel) {
                // El frontend maneja la pantalla y la entrada, devolviendo el resultado de la jugada
                int resultado = frontend.jugar_una_pregunta();

                if (resultado == 2) { 
                    // El usuario decidió salir voluntariamente presionando 'Q'
                    jugandoNivel = false;
                } 
                else if (resultado == 1 || resultado == 0) { 
                    // El usuario respondió (1 = Correcto, 0 = Incorrecto)
                    Jugador* jugadorActual = backend->getJugador();
                    
                    // Evaluar el estado de la partida basándose en las reglas del backend
                    if (jugadorActual->getVidas() <= 0) {
                        frontend.pantalla_transicion(2); // Game Over
                        jugandoNivel = false;
                    } 
                    else if (jugadorActual->getPuntajeNivel() >= PREGUNTAS_SUBIR) {
                        frontend.pantalla_transicion(1); // Nivel superado
                        jugadorActual->avanzarNivel();
                        
                        // Validar si quedan preguntas disponibles para el nuevo nivel del jugador
                        if (backend->seleccionar_pregunta_aleatoria(jugadorActual->getNivel()) == -1) {
                            frontend.pantalla_transicion(3); // Fin definitivo del juego
                            jugandoNivel = false;
                        }
                    }
                }
                // Si el resultado es -1 significa que pidió una pista. El bucle continúa
                // sin alterar las vidas ni el progreso, reimprimiendo la pregunta con la pista.
            }
        } 
        else if (opcion == 2) { // Seleccionó Salir del programa
            std::cout << "¡Gracias por jugar!\n";
            ejecutando = false;
        } 
        else { // Entrada inválida en el menú
            std::cout << "Opcion no valida.\n";
            frontend.presionar_enter();
        }
    }

    // 6. Liberar la memoria solicitada dinámicamente al inicio
    delete backend;

    return 0;
}