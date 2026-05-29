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
    public:
        juego();
        bool actualizar();
        bool hay_colision();
        void reset_enemigo();
        void dibujar();
};