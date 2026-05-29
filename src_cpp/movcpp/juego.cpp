#include"juego.hpp"

/*defino el constructor aqui, como juego es una clase de clases ya que sus atributos son clases
el constructor debe tomar unos valores para iniciar el objeto por lo que debo definir
cada una de las variables de antemano para que el objeto juego se construya sin problemas*/
juego::juego():Rmapa(1),Rjugador(1,1),Renemigo(Rmapa.obtdimension() -2,Rmapa.obtdimension() -2) {}

//nueva funcion intercambiando juego::iniciar
void juego::dibujar(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif


    int dimensionact = Rmapa.obtdimension();
    int posxjug=Rjugador.obtenerx();
    int posyjug=Rjugador.obtenery();
    int posxene=Renemigo.obtenerx();
    int posyene=Renemigo.obtenery();

    for(int i=0;i<dimensionact;i++){
        for(int j=0;j<dimensionact;j++){
            if(j==posxjug && j==posxene && i==posyjug && i== posyene){
                std::cout << "C";
            } else if(j==posxjug && i==posyjug){
			    std::cout << "P";
            } else if(j==posxene && i==posyene){
                std::cout << "E";
            } else{
		    std::cout << Rmapa.obtenercasilla(j,i);
            }   
        }
        std::cout << std::endl;
    }
}

bool juego::actualizar() {
    dibujar();
    bool continuar = Rjugador.mov(Rmapa);
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