#pragma once
#include<vector>
#include<iostream>
#include<string>
#include"mapa.hpp"
#include<stdlib.h>

class entidad{
    protected:
        int posicionx;
        int posiciony;
        int avanzar;
    public:
        entidad(int x, int y);
        virtual void mov(mapa& mapaactual)=0;

};

class jugador : public entidad{
    public:
        jugador(int x , int y);
        void mov(mapa& mapaactual);

};

class enemigo : public entidad{
    public:
        enemigo(int x, int y);
        void mov(mapa& mapaactual);
};
