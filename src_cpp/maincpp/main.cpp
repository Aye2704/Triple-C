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
            std::cout <<"Enemigo detectado" << std::endl;
            ui.presionar_enter();
            //TODO: me falta crear el bucle de la trivia y combate
        }
    }


}