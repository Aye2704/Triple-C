#include "entidades.hpp"
#include <cstdlib> // necesario para rand()

//constructor de entidad
entidad::entidad(int x, int y) : posicionx (x), posiciony (y), avanzar(1) {}

void entidad::set_posicion (int nx, int ny) {
    posicionx = nx;
    posiciony = ny;
}

//agrego nuevos metodos para poder terminar juego.cpp y dibujar el mapa correctamente
int entidad::obtenerx() const{
    return posicionx;
}
int entidad::obtenery() const{
    return posiciony;
}


player::player(int x , int y) :entidad(x,y){}


//codigo bastante analogo con el que hize en movi.c
bool player::mov(mapa& mapaactual, char direccion){
    int nx=posicionx;
    int ny=posiciony;
    //No se usa std::cin en QT
    /*char nuevovalor;
    std::cin>> nuevovalor;*/

    if(direccion=='w'){
        ny-=avanzar;
    }
    if(direccion=='a'){
        nx-= avanzar;
    }
    if(direccion=='s'){
        ny+= avanzar;
    }
    if(direccion=='d'){
        nx+= avanzar;
    }
    if(direccion=='q'){ //No es una direccion pero si sirve como tecla de salida en la UI
        return false;
    }

/*lo que hago en esta parte es crear variables en el metodo para hacer las verificaciones
si no hay ningun problema el mov actualizara las posiciones x e y*/
    if(mapaactual.obtenercasilla(nx,ny)!='#'){
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

bool enemigo::mov(mapa& mapaactual, char){

return true;

}

//con esta logica el enemigo te persigue entero terrorifico asi que agrego el tema turno
//enemigo pa que se calme un poco
void enemigo::nuevomov(mapa& mapaactual, int targetX, int targetY){
    int enex= posicionx;
    int eney= posiciony;

    if (targetX > posicionx) enex += avanzar;
    else if (targetX < posicionx) enex -= avanzar;

    if(targetY>posiciony)eney+=avanzar;
    else if(targetY<posiciony)eney-=avanzar;

    if(mapaactual.obtenercasilla(enex,eney)!='#'){
        posicionx=enex;
        posiciony=eney;
    }

}

