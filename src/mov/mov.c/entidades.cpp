#include "entidades.hpp"
#include "mapa.hpp"


entidad::entidad(int x, int y){

    posicionx =x;
    posiciony =y;
    avanzar=1;
}

jugador::jugador(int x , int y) :entidad(x,y){}

void jugador::mov(mapa& mapaactual){
    int nx=posicionx;
    int ny=posiciony;
    char nuevovalor;
    std::cin>> nuevovalor;


    if(nuevovalor=='w'){
        ny-=avanzar;
    }
    if(nuevovalor=='a'){
        nx-= avanzar;
    }
    if(nuevovalor=='s'){
        ny+= avanzar;
    }
    if(nuevovalor=='d'){
        nx+= avanzar;
}

int dimensionactual=mapaactual.obtdimension();
if (nx>dimensionactual){
    nx--;
}
if (nx==0){
    nx++;
}
if (ny>dimensionactual){
    ny--;
}
if (ny==0){
    ny++;
}
}