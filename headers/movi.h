#ifndef movim_h
#define movim_h

#define MAX 22
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x;
    int y;
}vector;

/*Aqui el el movimiento podria ser int o float pero lo dejare como int para que el moviemiento
sea discreto y sea en la terminal se nota
mejor, a futuro podriamos cambiar esto*/

typedef struct
{vector posicion;
    int avanzar;
}movjug;

typedef struct{
    char mapa[MAX][MAX];
    int dimension;
}map;
/*VER SI CONSIDERO O NO ESTA DECLARACION*/
/*extern char mapa[MAX][MAX];*/


/*defino las funciones (Recordar que reciben direcciones de memoria)*/

void procesomov(movjug *p1,char comandou,map *p2);
void procesomovE(movjug *PE,map*p2);
void iniciarmapa(map *p2,int nivel);
void dibujarmapa(movjug *p1,movjug*PE,int nivel,map *p2);




#endif