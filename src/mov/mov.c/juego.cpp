#include"juego.hpp"

/*defino el constructor aqui, como juego es una clase de clases ya que sus atributos son clases
el constructor debe tomar unos valores para iniciar el objeto por lo que debo definir
cada una de las variables de antemano para que el objeto juego se construya sin problemas*/
juego::juego():Rmapa(1),Rjugador(1,1),Renemigo(15,15),flagjuego(true){
}


void juego::iniciar(){
    int dimensionact=Rmapa.obtdimension();

    while (flagjuego==true){
//ocupe system cls en este caso pq es windows ver como hacer el caso general de ser linux o windows
        system("cls");

        int posxjug=Rjugador.obtenerx();
        int posyjug=Rjugador.obtenery();
        int posxene=Renemigo.obtenerx();
        int posyene=Renemigo.obtenery();

    for(int i=0;i<dimensionact;i++){
        for(int j=0;j<dimensionact;j++){
            if(j==posxjug && j==posxene && i==posyjug && i== posyene){
        printf("C");
        }
		else if(j==posxjug && i==posyjug){
			printf("P");}
        else if(j==posxene && i==posyene){
            printf("E");
        }
        else{
		printf("%c",Rmapa.obtenercasilla(j,i));}
            }   
    printf("\n");
        }
    
    flagjuego=Rjugador.mov(Rmapa);

    if(flagjuego==true){
        Renemigo.mov(Rmapa);
    }
    
    }
    }
