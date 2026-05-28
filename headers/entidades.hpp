#pragma once
#include<vector>
#include<iostream>
#include<string>
#include"mapa.hpp"
#include<stdlib.h>
#include<ctime>

/*defino la clase padre entidad con sus atributos correspondientes , constructor y su unico
metodo de interes el cual es un metodo virtual puro para que solo lo tengan sus clases hijas
hago 2 mov distintos pq el mov de jugador lo produce 1 y el mov de enemigo es aleatorio */
class entidad{
    protected:
        int posicionx;
        int posiciony;
        int avanzar;
    public:
        entidad(int x, int y);
        virtual bool mov(mapa& mapaactual)=0;
        int obtenerx();
        int obtenery();
};

class jugador : public entidad{
    public:
        jugador(int x , int y);
        bool mov(mapa& mapaactual);

};

class enemigo : public entidad{
    public:
        enemigo(int x, int y);
        bool mov(mapa& mapaactual);
};
