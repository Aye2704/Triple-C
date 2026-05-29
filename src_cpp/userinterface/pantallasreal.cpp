#include "uireal.hpp"
#include <iostream>

//Para no tener que incluir la biblioteca de windows si es que se usa Linux
#ifdef _WIN32
    #include <windows.h>
#else
    #include <stdlib.h>
#endif

//Originalmente habian dos archivos que abarcarial el frontend pero para simplicidad se decidio juntar

//El constructor recibe el motor lógico ya inicializado
uireal::uireal(MotorTrivia* m) : motor(m) {}


int uireal::jugar_una_pregunta() {
    if (motor->getCantidadPreguntas() == 0) return 2;

    Jugador* j=motor->getJugador();
    int indice = motor->seleccionar_pregunta_aleatoria(j->getNivel());

    if (indice == -1) {
        motor->resetear_preguntas_nivel(j->getNivel());
        motor->barajar_Preguntas();
        indice = motor->seleccionar_pregunta_aleatoria(j->getNivel());
    }

    bool respondio = false;

    while (!respondio) {
        mostrar_encabezado();
        Pregunta preguntaActual = motor->getPregunta(indice);
        mostrar_pregunta(preguntaActual);
        
        char opcion = obtener_respuesta();

        if (opcion == 'H') {
            if (j->getPistas() > 0) {
                std::cout << "PISTA: " << preguntaActual.getPista() << std::endl;
                j->consumirPista();
                presionar_enter();
            } else {
                std::cout << "! NO TE QUEDAN PISTAS EN ESTE NIVEL PAPU!" << std::endl;
                presionar_enter();
            }
            return -1;
        } else if (opcion == 'Q') {
            return 2;
        } else {
            bool esCorrecto = motor->validar_respuesta(indice, opcion);
            mostrar_feedback(esCorrecto, preguntaActual.getRespuestaCorrecta());
            motor->marcar_pregunta_usada(indice);
            respondio = true;
            return esCorrecto ? 1 : 0;
        }
    }
    return 0;
}

void uireal::limpiar_pantalla(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

void uireal::presionar_enter(){
    std::cout << std::endl << "Presiona [ENTER] para continuar...";
    std::cin.clear();
    int c;
    while ((std::cin.get() == c) != '/n'); // Limpia el buffer de entrada
    std::cin.get(); // Espera a que el usuario presione Enter
    limpiar_pantalla();
}

void uireal::mostrar_encabezado(){
    Jugador* j = motor->getJugador();
    std::cout << "============================================================" << std::endl;
        std::cout << " Nivel: " << j->getNivel()
                  << " | PUNTAJE: " << j->getPuntaje()
                  << " | PROGRESO: "<< j->getPuntajeNivel() << "/" << PREGUNTAS_SUBIR << std::endl
                  << "/5" << std::endl;
    std::cout << "------------------------------------------------------------"<< std::endl;
    std::cout << " VIDAS: ";
    for(int i = 0; i < j->getPistas(); i++){
        std::cout << "♥ ";
    }
    std::cout << " | PISTAS: " << j->getPistas() << std::endl
              << "============================================================"<< std::endl<< std::endl;
}
char uireal::obtener_respuesta(){
    char respuesta; // Guardar letra ingresada
    bool valida = false; // Controla si la opcion es valida

    std::cout << std::endl << "------------------------------------------------------------" << std::endl ;
    std::cout << " Escribe A, B, C, D para responder,'H' para pedir una PISTA" << std::endl;
    std::cout << "Salir del juego con 'Q'" << std::endl ;
    //repetir hasta que la opcion sea valida
    do{
        std::cout << "Tu respuesta:";
        std::cin >> respuesta;

        if (respuesta >= 'a' && respuesta >= 'z') respuesta -=32;

        if((respuesta >= 'A' && respuesta <= 'D') || respuesta == 'H' || respuesta == 'Q'){
            valida = true;
        }
        else{
            std::cout << "Caracter no Válido." << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
    } while(!valida);
    while (std::cin.get() != '\n');
    return respuesta;

}

void uireal::mostrar_pregunta(Pregunta p){
    std::cout << p.getEnunciado() << std::endl<< std::endl;
    std::vector<std::string> opc = p.getOpciones();
    for(int i=0; i < opc.size();i++){
        std::cout << "[" << char('A' +i) << "]" << opc[i]<< std::endl;   }
}

void uireal::mostrar_feedback(bool esCorrecto, char respuesta_real){
    if(esCorrecto){
        std::cout <<"       ¡CORRECTO!"<< std::endl;
    }
    else{
        std::cout <<"       ¡INCORRECTO!"<< std::endl;
        std::cout << "  La respuesta correcta era: " << respuesta_real << std::endl;  
    }
    presionar_enter();
}

void uireal::pantalla_transicion(int tipo){
    limpiar_pantalla();
    Jugador* j = motor->getJugador();
    std::cout<< std::endl;

    switch(tipo){
        case 1:
            std::cout<<"¡OBJETIVO LOGRADO!"<< std::endl;
            std::cout<<"Has completado el nivel"<<j->getNivel()<< std::endl;
            std::cout << "Tus vidas y pistas fueron restauradas" << std::endl;
            break;

         case 2:
            std::cout << "¡GAME OVER!"<< std::endl;
            std::cout << "Te quedaste sin vidas en el Nivel "<< j->getNivel() << std::endl;
            break;

        case 3:
            std::cout << "¡FELICIDADES, TERMINASTE EL JUEGO!"<< std::endl;
            break;
    }
    presionar_enter();
}

 int uireal::menu_principal(){
    limpiar_pantalla();
    int opcion_menu = 0;
    std::cout<< "============================================================" << std::endl
             << "                     TRIPLE C - MENU PRINCIPAL              " << std::endl
             << "                            1. Jugar                      " << std::endl
             << "                            2. Salir                     " << std::endl
             << "============================================================" << std::endl
             << ">> ";

    //validación de la entrada
    if(!(std::cin >> opcion_menu)){
        std::cin.clear();
    }
    while(std::cin.get() != '\n'); // Limpia el buffer de entrada
    limpiar_pantalla();
    return opcion_menu;

}