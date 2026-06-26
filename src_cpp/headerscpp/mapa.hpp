#pragma once
#include<vector>

class mapa{
    //aqui hago los atributos de mi mapa
    private:
        int dimension;
        std::vector<std::vector<char>> terreno;
    
    public:
    //el constructor
    mapa(int nivel);

    //no le puse destructor pq trabajo con datos basicos y contenedores

    //metodous
    int obtdimension();
    char obtenercasilla(int x,int y);
};

