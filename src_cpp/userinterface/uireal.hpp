#ifndef ui_hpp
#define ui_hpp

#include <iostream>
#include <string>

//declaración de que existen x ahí XD
struct Jugador;
struct Pregunta;

class uireal {
    public:
    uireal()=default;

int menu_principal(int opcion_menu); //Menú principal

void limpiar_pantalla(); //Limpia consola

void mostrar_encabezado(Jugador*j); // Muestra vidas,nivel y pistas

void mostrar_pregunta(Pregunta*p); //Muestra pregunta 

char obtener_respuesta(); //Obtiene respuesta del usuario

void mostrar_feedback(int esCorrecto, char respuesta_real);//Muestra si la respuesta está bien o mal 

void pantalla_transicion(int tipo , int nivelactual); //Pantalla de transición entre niveles o si perdiste

void presionar_enter(); //Espera que el usuario presione enter para continuar


};

#endif