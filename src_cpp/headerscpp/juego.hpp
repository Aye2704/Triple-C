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
        int nivelActual;
        bool turnoenemi;//nueva variable pa relajar al enemigo
    public:
        juego(int nivel = 1);
        bool actualizar(char tecla); // Recibe input de QT
        bool hay_colision() const;
        bool meta_alcanzada() const; //Funcion nueva
        void reset_enemigo();
        //void dibujar();
        void setEnemigoDerrotado(bool estado); //Funcion nueva
        bool isEnemigoDerrotado() const; //Funcion nueva

        int obtdimensionmapa();
        char obtcasillamapa(int x, int y);
        int obtjugX() const;
        int obtjugY() const;
        int obteneX() const;
        int obteneY() const;
        int obtmetaX() const;
        int obtmetaY() const;
};