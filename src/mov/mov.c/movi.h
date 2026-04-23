#ifndef movim_h
#define movim_h

#define MAX 22
#include<stdio.h>

typedef struct{
    int x;
    int y;
}vector;

/*Aqui el el movimiento podria ser int o float pero lo dejare como float para que el moviemiento
no sea discreta y sea mas fluido al momento de migrar(osea que cuando lo grafiquemos
no se mueva tepeandose sino fluido)*/

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
void movderecha(movjug *p1);
void movizquierda(movjug *p1);
void movarriba(movjug *p1);
void movabajo(movjug *p1);
void procesomov(movjug *p1,char comandou,map *p2);
void procesomovE(movjug *PE,map*p2);
void iniciarmapa(map *p2,int nivel);
void dibujarmapa(movjug *p1,movjug*PE,int nivel,map *p2);




#endif