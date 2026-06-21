#include"juego.hpp"

/*defino el constructor aqui, como juego es una clase de clases ya que sus atributos son clases
el constructor debe tomar unos valores para iniciar el objeto por lo que debo definir
cada una de las variables de antemano para que el objeto juego se construya sin problemas*/
juego::juego():Rmapa(1),Rjugador(1,1),Renemigo(Rmapa.obtdimension() -2,Rmapa.obtdimension() -2) {}

//elimino dibujar pq con mapitawidget se dibujara en la ventanita
// y a actualizar le agrego el parametro tecla que tambien se lo agrege a jugador en entidades


bool juego::actualizar(char tecla) {
    bool continuar = Rjugador.mov(Rmapa,tecla);
    if (continuar) {
        Renemigo.mov(Rmapa);
    }
    return continuar;
}

bool juego::hay_colision() {
    return  (Rjugador.obtenerx() == Renemigo.obtenerx() &&
             Rjugador.obtenery() == Renemigo.obtenery());
}

void juego::reset_enemigo() {
    //Mueve al enemigo temporalmente a una esquina predefinida libre
    Renemigo.set_posicion(Rmapa.obtdimension() -2, Rmapa.obtdimension() -2);
}



//De aqui para abajo agregare nuevos metodos para ocuparlos en mapitawidgets y hacer que todo se mueva
//correctamente los metodos son para sacar info necesaria solamente
char juego::obtcasillamapa(int x,int y){
    return Rmapa.obtenercasilla(x,y);
}

int juego::obtdimensionmapa(){
    return Rmapa.obtdimension();
}

int juego::obtjugX(){
    return Rjugador.obtenerx();
}
int juego::obtjugY(){
    return Rjugador.obtenery();
}


int juego::obteneX(){
    return Renemigo.obtenerx();
}
int juego::obteneY(){
    return Renemigo.obtenery();
}
