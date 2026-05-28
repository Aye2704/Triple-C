#include "uireal.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cctype> 

int uireal::menu_principal(int opcion_menu){
    limpiar_pantalla();

    std::cout << "============================================================\n";
    std::cout << "                     TRIPLE C - MENU PRINCIPAL              \n";
    std::cout << "                            1. Jugar                      \n";
    std::cout << "                            2. Salir                     \n";
    std::cout << "============================================================\n";

    //validación de la entrada
    if(!(std::cin >> opcion_menu)){
        while(std::cin.get() != '\n'); // Limpia el buffer de entrada
        opcion_menu = 0; // Asigna un valor no válido para que el menú se muestre de nuevo
    }
    limpiar_pantalla();
    return opcion_menu;

}

char uireal::obtener_respuesta(){
    char respuesta; // Guardar letra ingresada
    bool valida = false; // Controla si la opcion es valida

    std::cout << "\n------------------------------------------------------------\n";
    std::cout << " Escribe A, B, C, D para responder,'H' para pedir una PISTA\n";
    std::cout << "Salir del juego con 'Q'\n";
    //repetir hasta que la opcion sea valida
    do{
        std::cout << "Tu respuesta:";
        std::cin >> respuesta;
        respuesta = toupper(respuesta); // Convertir a mayúscula para facilitar la comparación
        if((respuesta >= 'A' && respuesta <= 'D') || respuesta == 'H' || respuesta == 'Q'){
            valida = true;
        }
        else{
            std::cout << "Caracter no Válido. Por favor, ingresa A, B, C, D, H o Q.\n";
        }
    } while(!valida);
    return respuesta;

}

void uireal::presionar_enter(){
    std::cout << "Presiona [ENTER] para continuar...";
    while (std::cin.get() != '\n'); // Limpia el buffer de entrada
    std::cin.get(); // Espera a que el usuario presione Enter
    limpiar_pantalla();
}
