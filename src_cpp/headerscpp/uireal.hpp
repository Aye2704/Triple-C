#ifndef ui_hpp
#define ui_hpp

#include "preg.hpp"

class uireal {
private:
    MotorTrivia* motor; //Puntero al backend
public:
    uireal(MotorTrivia* m);

    int jugar_una_pregunta();

    int menu_principal(); //Menú principal
    void limpiar_pantalla(); //Limpia consola
    void mostrar_encabezado(); // Muestra vidas,nivel y pistas
    void mostrar_pregunta(Pregunta p); //Muestra pregunta 
    char obtener_respuesta(); //Obtiene respuesta del usuario
    void mostrar_feedback(bool esCorrecto, char respuesta_real);//Muestra si la respuesta está bien o mal 
    void pantalla_transicion(int tipo); //Pantalla de transición entre niveles o si perdiste
    void presionar_enter(); //Espera que el usuario presione enter para continuar
};

#endif