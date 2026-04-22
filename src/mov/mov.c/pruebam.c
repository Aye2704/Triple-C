#include<stdio.h>
#include "movi.h"

int main(){

    movjug p1={{0.0,0.0},2.0};
    char tecla;

    while (tecla!='q'){
        printf("MUEVASE CON EL WASD (PRESIONE P PARA SU POSICION Y Q PARA SALIR\n)");
        scanf(" %c",&tecla);
        
        procesomov(&p1,tecla);
    }
    



    return 0;
}