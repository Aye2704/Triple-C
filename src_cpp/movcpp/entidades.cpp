#include "entidades.hpp"
#include "mapa.hpp"

//constructor de entidad
entidad::entidad(int x, int y){

    posicionx =x;
    posiciony =y;
    avanzar=1;
}

//agrego nuevos metodos para poder terminar juego.cpp y dibujar el mapa correctamente
int entidad::obtenerx(){
    return posicionx;
}
int entidad::obtenery(){
    return posiciony;
}


player::player(int x , int y) :entidad(x,y){}


//codigo bastante analogo con el que hize en movi.c
bool player::mov(mapa& mapaactual){
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
    if(nuevovalor=='q'){
        return false;
    }


/*lo que hago en esta parte es crear variables en el metodo para hacer las verificaciones
si no hay ningun problema el mov actualizara las posiciones x e y*/
if(mapaactual.obtenercasilla(nx,ny)==' '){
    posicionx=nx;
    posiciony=ny;
}
return true;
}

/*reutilizo el constructor de jugador pero le cambio el nombre ya que son iguales
lo unico que hare sera cambiar el proceso mov para esta clase hija ya que busco 
un movimiento random reutilizare las mismas verificaciones*/

enemigo::enemigo(int x , int y) :entidad(x,y){}

/*anteriormente utilize simplemente la biblioteca stdlib y rand sobre una arreglo de 4 numeros
pero parece que el enemigo siempre realizaba el mismo movimiento cuando se ejecutaba para arreglar
esto utilizare la biblioteca srand (semilla random) para que cada ejecucion sea unica y el mov
distinto y ocupare time null que era un tiempo que se cuenta en segundos desde una fecha de 1970 
si no me equivoco lo importante es que el time null siempre sera un tiempo distinto osea siempre
una semilla distinta esto se agregara en el main y cada ejecucion sera distinta*/

bool enemigo::mov(mapa& mapaactual){
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
/*quite algunos ifs que ocupen anteriormente en movi.c para verificaciones de los limites del mapa
pero con este if de mapaactual ahorre unas lineas de codigo*/
if(mapaactual.obtenercasilla(nx,ny)==' '){
    posicionx=nx;
    posiciony=ny;
}
//enemigo no afectaba en nada asi que simplemente deje que siempre devolviera true
return true;
}

void entidad::set_posicion(int nx, int ny) {
    posicionx = nx;
    posiciony = ny;
}