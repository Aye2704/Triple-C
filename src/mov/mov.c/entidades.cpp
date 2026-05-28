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

//limites de mi mapa ver movi.c procesomov
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
//luego de realizar mov y limites hago verificacion para que pueda hacer el mov
if(mapaactual.obtenercasilla(nx,ny)==' '){
    posicionx=nx;
    posiciony=ny;
}
}
//reutilizo el constructor de jugador pero le cambio el nombre ya que son iguales
//lo unico que hare sera cambiar el proceso mov para esta clase hija ya que busco 
//un movimiento random reutilizare las mismas verificaciones

enemigo::enemigo(int x , int y) :entidad(x,y){}

void enemigo::mov(mapa& mapaactual){
    int nx=posicionx;
    int ny=posiciony;
    int ndireccion = rand() %4;

    char nvalor;
    if (ndireccion==1){
        nvalor='w';
    }
    if (ndireccion==2){
        nvalor='d';
    }
    if (ndireccion==3){
        nvalor='a';
    }
    if (ndireccion==0){
        nvalor='s';
    }

    if(nvalor=='w'){
        ny-=avanzar;
    }
    if(nvalor=='a'){
        nx-= avanzar;
    }
    if(nvalor=='s'){
        ny+= avanzar;
    }
    if(nvalor=='d'){
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

if(mapaactual.obtenercasilla(nx,ny)==' '){
    posicionx=nx;
    posiciony=ny;
}

}