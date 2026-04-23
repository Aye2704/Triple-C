#include<stdio.h>
#include<stdlib.h>
#include "movi.h"

/*Trabajare con punteros para hacer paso por referencia y afectar a las variables
fuera de mi funcion*/

/*Reutilizo las funciones que ocupe pa el primer codigo corrigiendo variables*/



/*Esta funcion crea el mapa en el cual se estara moviendo el pj
recordar que las filas van de arriba hacia abajo(por como se crea en la terminal)
osea que mi fila 0 es la que esta en el principio (el techo)*/


void iniciarmapa(map *p2,int nivel){
/*inicializo otra variable de dimension ya que esta ira variando 
dependiendo del nivel en el que estemos*/
    p2->dimension = MAX-(nivel*2);
	for(int i=0;i< p2->dimension; i++){
		for(int j=0; j<p2->dimension;j++){
            if (i==0 ||i==p2->dimension -1|| j==0 || j==p2->dimension -1){
                p2->mapa[i][j]='#';} /*esto seran las paredes del mapa*/
            else{
			    p2->mapa[i][j]=' ';}/*espacio por el cual se movera*/
            }
        }
    }

/*con la primera creo el espacio y luego con este lo dibujo en la terminal
*/
void dibujarmapa(movjug *p1,movjug *PE,int nivel,map *p2){
    p2->dimension = MAX-(nivel*2);

for(int i= p2->dimension-1 ;i>=0 ;i--){
	for(int j=0; j<p2->dimension;j++){
        if(j==PE->posicion.x && j==p1->posicion.x && i==PE->posicion.y&& i== p1->posicion.y){
        printf("C");
        }
		else if(j==p1->posicion.x && i==p1->posicion.y){
			printf("P");}
        else if(j==PE->posicion.x && i==PE->posicion.y){
            printf("E");
        }
        else{
		printf("%c",p2->mapa[i][j]);}
    }printf("\n");}}





void procesomov(movjug*p1,char comandou, map *p2){
    int nx= p1->posicion.x;
    int ny= p1->posicion.y;
/*trabajo con variables locales de la funcion ya que necesito
hacer las verificaciones de si toca o no la pared  y luego de que se hagan las verificaciones
hago el cambio en el mov original trabajando todo con punteros */
    if(comandou=='w'){
        ny+= p1->avanzar;
    }
    if(comandou=='a'){
        nx-= p1->avanzar;
    }
    if(comandou=='s'){
        ny-= p1->avanzar;
    }
    if(comandou=='d'){
        nx+= p1->avanzar;
    }
    
/*hago limites para el mapa*/
    if(nx>=p2->dimension){
        nx-=1;
    }
    if (nx==0){
        nx+=1;
    }
    if(ny>=p2->dimension){
        ny+=1;
    }
    if(ny==0){
        ny-=1;
    }
    /*hago el cambio a la variable original y hago logica de colision con enemigo */
    char destino = p2->mapa[ny][nx];
    if (destino==' '){
        p1->posicion.x=nx;
        p1->posicion.y= ny;}
    else if(destino=='E'){
        /*LOGICA PREGUNTAS*/}
    if(comandou=='p'){
        printf("x=%d,y=%d",p1->posicion.x,p1->posicion.y);
    }

    }

    /*reutilizare gran parte de procesomov*/
void procesomovE(movjug*PE, map*p2){
    int nx= PE->posicion.x;
    int ny= PE->posicion.y;

    int direccion= rand() %4;
    char comandoe;
    if (direccion==1){
        comandoe='w';
    }
    if (direccion==2){
        comandoe='d';
    }
    if (direccion==3){
        comandoe='a';
    }
    if (direccion==0){
        comandoe='s';
    }
    
    

    if(comandoe=='w'){
        ny+= PE->avanzar;
    }
    if(comandoe=='a'){
        nx-= PE->avanzar;
    }
    if(comandoe=='s'){
        ny-= PE->avanzar;
    }
    if(comandoe=='d'){
        nx+= PE->avanzar;
    }
    
/*hago limites para el mapa*/
    if(nx>=p2->dimension){
        nx-=1;
    }
    if (nx==0){
        nx+=1;
    }
    if(ny>=p2->dimension){
        ny+=1;
    }
    if(ny==0){
        ny-=1;
}
    char destino = p2->mapa[ny][nx];
    if (destino==' '){
        PE->posicion.x=nx;
        PE->posicion.y= ny;}
}

        
    /*CODIGO QUE TENIA ANTES DEJO COMENTADO EN CASO DE VOLVER A NECESITARLO*/
    /*switch (comandou)
    {
    case 'w':
        movarriba(p1);
        printf("te has movido hacia arriba\n");
        break;
    case 'd':
        movderecha(p1);
        printf("te has movido hacia la derecha\n");
        break;
    case 's':
        movabajo(p1);
        printf("te has movido hacia abajo\n");
        break;
    case 'a':
        movizquierda(p1);
        printf("te has movido hacia la izquierda\n");
        break;
    case 'p':
        printf("x=%d, y=%d \n",p1->posicion.x,p1->posicion.y);
        break;
    default:
        break;*/
    

