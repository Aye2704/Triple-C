#include <iostream>
#include <cstdlib>
#include "uireal.hpp"

void uireal::limpiar_pantalla(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

void uireal::mostrar_encabezado(Jugador*j){
    std::cout << "============================================================\n";
        std::cout << " Nivel: " << j->nivelActual
              << " | PUNTAJE: " << j->puntaje
              << " | PROGRESO: "
              << j->puntajeNivel
              << "/5\n";

    std::cout << "------------------------------------------------------------\n";
    std::cout << " VIDAS: ";
    for(int i = 0; i < j->vidasActuales; i++){
        std::cout << "♥ ";
    }
    std::cout << " | PISTAS: " << j->pistasRes << "\n";

    std::cout << "============================================================\n\n";
}


void uireal::mostrar_pregunta(Pregunta*p){
    std::cout << p->enuncionado << "\n\n";
    for(int i=0;i<4;i++){
        std::cout << "[" << char('A' +i) << "]" << p->opciones[i]<< "\n";   }
}

void uireal::mostrar_feedback(int esCorrecto, char respuesta_real){
    if(esCorrecto){
        std::cout <<"\n¡CORRECTO!\n";
    }
    else{
        std::cout <<"\n¡INCORRECTO!\n";
        std::cout << "La respuesta correcta era: " << respuesta_real << "\n";  
    }
    presionar_enter();
}

void uireal::pantalla_transicion(int tipo,int nivelActual){
    limpiar_pantalla();
    std::cout<<"\n";

    switch(tipo){
        case 1:
            std::cout<<"¡OBJETIVO LOGRADO!\n";
            std::cout<<"Has completado el nivel"<<nivelActual<<"\n";
            std::cout << "Tus vidas y pistas fueron restauradas.\n";
            break;

         case 2:
            std::cout << "¡GAME OVER!\n";
            std::cout << "Te quedaste sin vidas en el Nivel "<< nivelActual<< "\n";
            break;

        case 3:
            std::cout << "¡FELICIDADES, TERMINASTE EL JUEGO!\n";
            break;

}