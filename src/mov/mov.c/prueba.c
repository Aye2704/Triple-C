#include<stdio.h>
#include"movi.h"

int main(){
    movjug p1={{0.0, 0.0}, 1.0};
    char tecla;

    while (tecla!='q')
    {
        printf("Muevase en la direccion que quiera con WASD, en caso de querer saber tu posicion apreta P \n");
        scanf("%c",&tecla);
        if(tecla=='w'){
            movarriba(&p1);
        printf("te haz movido hacia arriba\n");}
        if(tecla=='s'){
            movabajo(&p1);
        printf("te haz movido hacia abajo\n");}
        if(tecla=='d'){
            movderecha(&p1);
        printf("te haz movido hacia la derecha\n");}
        if(tecla=='a'){
            movizquierda(&p1);
        printf("te haz movido hacia la izquierda\n");}
        if(tecla=='p'){
            printf("x=%2.f,y=%2.f \n",p1.posicion.x,p1.posicion.y);
        }
        }
        return 0;
    }
    
    

