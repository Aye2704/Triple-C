#include "mapa.hpp"

mapa::mapa(int nivel){
    dimension=22-(nivel * 2);
    if (dimension <10) dimension = 10; //limite de tamaño

    /*resize sirve para cambiar dinamicamente el tamaño de un 
    vector mientras se ejecuta el programa
    este dice ya cuantos cosas quieres crear con el primer parametro
    y luego con que lo queremos rellenar 
    
    onda lo que estoy haciendo aqui es decir quiero un vector de tal dimension
    y en cada casilla rellenarlo con otro vector que tenga tal dimension y este vect
    interno lo relleno con espacios en blanco , asi creando el mapa 
    
    lo bueno de c++ es que como std vector es dinamico anteriormente tuve que trabajar con punteros
    ahora gracias a este elemento de la STL la pega taba mas simple*/
    terreno.resize(dimension,std::vector<char>(dimension,' '));

    /*ciclo for analogo al de movi.c recordar que le resto 1 pq parto del 0*/
    for(int i=0;i<dimension;i++){
        for(int j=0; j<dimension;j++){
            if(i==0 || i==dimension -1 || j==0 || j== dimension -1){
                terreno[i][j]='#';
            }
        }
    }
}

//metodos bien intuitivos
int mapa::obtdimension(){
        return dimension;
}

//recordar que en pantalla creo primero el eje y y lo recorro por eso
//el orden es [y][x] anteriormente recorre el ciclo for al reves para que
//el orden fuera [x][y] pero como solo afecta al mov en vez de sumar para arribar tendre que restar
char mapa::obtenercasilla(int x, int y){
    return terreno[y][x];
}










