#include "mapa.hpp"
#include "entidades.hpp"

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