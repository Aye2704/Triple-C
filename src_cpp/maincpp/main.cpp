#include <iostream>
#include <ctime>
#include <cstdlib>

#include "juego.hpp"
#include "uireal.hpp"
#include "preg.hpp"

int main() {
    //Semilla para asegurar aleatoriedad en el enemigo y barajado de preguntas
    srand(static_cast<unsigned>(time(NULL)));

    
    //1. Inicializacion del motor de Trivia (Backend y Frontend)
    MotorTrivia motor;
    //Cargar de archivo de preguntas
    if (!motor.cargar_Preguntas("archivopregs.txt")) {
        std::cout << "No se pudo cargar 'archivopregs.txt'." << std::endl;
    }
    motor.barajar_Preguntas();
    uireal ui(&motor);

    //2. Menu Principal
    int opcion = ui.menu_principal();
    if (opcion != 1) {
        return 0;
    }

    //3. Inicializacion del juego de Movimiento
    juego motorMovimiento;
    bool juego_activo = true;
    Jugador* datosJugador = motor.getJugador();

    // 4. Bucle Maestro
    while(juego_activo) {
        //Ejecuta un turno de movimiento
        juego_activo = motorMovimiento.actualizar();

        //Verifica si hubo encuentro
        if (juego_activo && motorMovimiento.hay_colision()) {
            ui.limpiar_pantalla();
            std::cout << std::endl <<"===============================================" << std::endl
                      <<"Enemigo detectado! Preparate para las preguntas."
                      << std::endl <<"===============================================" << std::endl;
            ui.presionar_enter();
            
            bool en_combate = true;

            //Bucle de Trivia / Combate
            while (en_combate) {
                int resultado = ui.jugar_una_pregunta();

                if (resultado == 2) { //2 indica salir o sin preguntas
                    juego_activo = false;
                    break;
                }

                //Evaluar el progreso del jugador
                if (datosJugador->getPuntajeNivel() >= PREGUNTAS_SUBIR) {
                    datosJugador->avanzarNivel();
                    ui.pantalla_transicion(1); // Nivel Superado
                    en_combate = false;

                    //Alejar al enemigo para que no choque inmediatamente
                    motorMovimiento.reset_enemigo();
                } else if (datosJugador->getVidas() <= 0) {
                    ui.pantalla_transicion(2); // Game Over
                    juego_activo = false; // Finaliza el Porgrama
                    en_combate = false;
                }
            }
        }
    }

    ui.limpiar_pantalla();
    std::cout << "Gracias por jugar" << std::endl;
    return 0;
}