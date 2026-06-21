#include"juego.hpp"

/*defino el constructor aqui, como juego es una clase de clases ya que sus atributos son clases
el constructor debe tomar unos valores para iniciar el objeto por lo que debo definir
cada una de las variables de antemano para que el objeto juego se construya sin problemas*/
juego::juego():Rmapa(1),Rjugador(1,1),Renemigo(Rmapa.obtdimension() -2,Rmapa.obtdimension() -2) {}

//Funcion inutilizada debido a que ahora no se usa system() en QT
/*void juego::dibujar(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif*/

std::string juego::obtener_mapa_string() {
    std::string resultado= "";
    int dimensionact = Rmapa.obtdimension();
    int posxjug=Rjugador.obtenerx();
    int posyjug=Rjugador.obtenery();
    int posxene=Renemigo.obtenerx();
    int posyene=Renemigo.obtenery();

    for(int i=0;i<dimensionact;i++){
        for(int j=0;j<dimensionact;j++){
            if(j==posxjug && j==posxene && i==posyjug && i== posyene){
                resultado +="C"; // Colisión
            } else if(j==posxjug && i==posyjug){
			    resultado +="P"; // Jugador
            } else if(j==posxene && i==posyene){
                resultado += "E"; //Enemigo
            } else{
		    resultado += Rmapa.obtenercasilla(j,i);
            }   
        }
    }
    resultado += "\n";
}