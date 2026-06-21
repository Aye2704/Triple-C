#pragma once
#include "mapa.hpp"
#include "entidades.hpp"

/*inicializo la clase juego , como esta clase es como el dios de todo
termina siendo una clase de clases , su unico metodo sera que corra el juego
con esta clase el main de prueba sera la nada misma*/


//defino algunos metodos extra y cambia actualizar que ahora dependera de la tecla que se toque
//elimino dibujar ya que no sera necesario por como funciona QtWidgets
class juego {
    private:
        mapa Rmapa;
        player Rjugador;
        enemigo Renemigo;
    public:
        juego();
        bool actualizar(char tecla);
        bool hay_colision();
        void reset_enemigo();
        int obtdimensionmapa();
        char obtcasillamapa(int x,int y);
        int obtjugX();
        int obtjugY();
        int obteneX();
        int obteneY();
};