#include "mapa.hpp"
#include "entidades.hpp"

/*inicializo la clase juego , como esta clase es como el dios de todo
termina siendo una clase de clases , su unico metodo sera que corra el juego
con esta clase el main de prueba sera la nada misma*/
class juego {
    private:
        mapa Rmapa;
        jugador Rjugador;
        enemigo Renemigo;
        bool flagjuego;
    public:
        juego();
        void iniciar();
};