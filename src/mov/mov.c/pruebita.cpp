#include "entidades.hpp"
#include "juego.hpp"
#include "mapa.hpp"

int main(){
    //inicio mi objeto y ocupo su metodo para que corra el juego
    juego Partida;
    srand(time(NULL));
    Partida.iniciar();

    return 0;

}