#include"juego.hpp"

/*defino el constructor aqui, como juego es una clase de clases ya que sus atributos son clases
el constructor debe tomar unos valores para iniciar el objeto por lo que debo definir
cada una de las variables de antemano para que el objeto juego se construya sin problemas*/
juego::juego(int nivel)
    : Rmapa(nivel),
      Rjugador(1,1),
      Renemigo(Rmapa.obtdimension() -2,Rmapa.obtdimension() -2),
      enemigoDerrotado(false),
      nivelActual(nivel) 
{ //Meta en la esquina inferior derecha
    metax = Rmapa.obtdimension() - 2;
    metay = Rmapa.obtdimension() - 2;
}

//Funcion inutilizada debido a que ahora no se usa system() en QT
/*void juego::dibujar(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif*/

//Cambio: Actualizar ahora recibe tecla
bool juego::actualizar(char tecla) {
    bool continuar = Rjugador.mov(Rmapa, tecla);
    if (continuar && !enemigoDerrotado) {
        if (turnoenemi){
        Renemigo.nuevomov(Rmapa,Rjugador.obtenerx(),Rjugador.obtenery());
        }
        turnoenemi= !turnoenemi;
    }
    return continuar;
}


//TODOS ESTOS SON METODOS PARA RECUPERAR INFO
bool juego::hay_colision() const{
    if (enemigoDerrotado) return false;
    return (Rjugador.obtenerx() == Renemigo.obtenerx() &&
            Rjugador.obtenery() == Renemigo.obtenery());
}

bool juego::meta_alcanzada() const{
    return (Rjugador.obtenerx() == metax && Rjugador.obtenery() == metay);
}

void juego::reset_enemigo() {
    Renemigo.set_posicion(Rmapa.obtdimension() -3, Rmapa.obtdimension() -3);
}

void juego::setEnemigoDerrotado(bool estado) {
    enemigoDerrotado = estado;
}
bool juego::isEnemigoDerrotado() const {
    return enemigoDerrotado;
}

char juego::obtcasillamapa(int x, int y){
    return Rmapa.obtenercasilla(x, y);
}
int juego::obtdimensionmapa(){
    return Rmapa.obtdimension();
}

int juego::obtjugX() const{
    return Rjugador.obtenerx();
}
int juego::obtjugY() const{
    return Rjugador.obtenery();
}

int juego::obteneX() const{
    return Renemigo.obtenerx();
}
int juego::obteneY() const{
    return Renemigo.obtenery();
}

int juego::obtmetaX() const{
    return metax;
}
int juego::obtmetaY() const{
    return metay;
}