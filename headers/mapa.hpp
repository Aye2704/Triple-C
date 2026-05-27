#pragma once
#include<vector>
#include<iostream>
#include<string>

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

class entidad{
    protected:
        int posicionx;
        int posiciony;
        int avanzar;
    public:
        entidad(int x, int y);
        virtual void mov(mapa& mapactual);
};

class jugador : public entidad{};

class juego{};