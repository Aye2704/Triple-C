#include<stdio.h>
#include<stdlib.h>
#include "movi.h"

/*VER PUNTEROS */

/*Trabajare con punteros para hacer paso por referencia y afectar a las variables
fuera de mi funcion*/

void movderecha(movjug *p1){
    p1->posicion.x += p1->avanzar;

}
void movizquierda(movjug *p1){
    p1->posicion.x -= p1->avanzar;

}
void movarriba(movjug *p1){
    p1->posicion.y += p1->avanzar;
}
void movabajo(movjug *p1){
    p1->posicion.y -= p1->avanzar;
}

void procesomov(movjug*p1,char comandou){
    switch (comandou)
    {
    case 'w':
        movarriba(p1);
        printf("te haz movido hacia arriba\n");
        break;
    case 'd':
        movderecha(p1);
        printf("te haz movido hacia la derecha\n");
        break;
    case 's':
        movabajo(p1);
        printf("te haz movido hacia abajo\n");
        break;
    case 'a':
        movizquierda(p1);
        printf("te haz movido hacia la izquierda\n");
        break;
    case 'p':
        printf("x=%2.f, y=%2.f \n",p1->posicion.x,p1->posicion.y);
        break;
    default:
        break;
    }
}
