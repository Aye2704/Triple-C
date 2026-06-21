#pragma once
#include "mapa.hpp"
#include "entidades.hpp"

/*inicializo la clase juego , como esta clase es como el dios de todo
termina siendo una clase de clases , su unico metodo sera que corra el juego
con esta clase el main de prueba sera la nada misma*/
class juego {
    private:
        mapa Rmapa;
        player Rjugador;
        enemigo Renemigo;
        //Se agrega la funcion de meta en vez de progresar por juego de las preguntas
        int metax;
        int metay;
        bool enemigoDerrotado; //Nueva variable
    public:
        juego();
        bool actualizar(char inputTecla); // Recibe input de QT
        bool hay_colision();
        void enemigo_vencido(); //Cambio de nombre debido a que ahora se puede derrotar al enemigo y no solo se resetea
        //void dibujar();
        std::string obtener_mapa_string(); // Para dibujar en QLabel de QT
};