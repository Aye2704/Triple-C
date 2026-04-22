#ifndef movim_h
#define movim_h

#include<stdio.h>

typedef struct{
    float x;
    float y;
}vector;

/*Aqui el el movimiento podria ser int o float pero lo dejare como float para que el moviemiento
no sea discreta y sea mas fluido al momento de migrar(osea que cuando lo grafiquemos
no se mueva tepeandose sino fluido)*/


typedef struct
{vector posicion;
    float avanzar;
}movjug;


/*defino las funciones (Recordar que reciben direcciones de memoria)*/
void movderecha(movjug *p1);
void movizquierda(movjug *p1);
void movarriba(movjug *p1);
void movabajo(movjug *p1);
void procesomov(movjug *p1,char comandou);



#endif