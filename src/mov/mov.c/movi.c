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

/*Termino descartando primeras funciones RECUERDAAAAAAAAA*/



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
void dibujarmapa(movjug *p1,int nivel,map *p2){
    p2->dimension = MAX-(nivel*2);

for(int i= p2->dimension-1 ;i>=0 ;i--){
	for(int j=0; j<p2->dimension;j++){
		if(j==p1->posicion.x && i==p1->posicion.y){
			printf("P");}
		printf("%c",p2->mapa[i][j]);
    }printf("\n");}}

/*me aparece una columna de mas al imprimirlo en la terminal y segun yo esta logica esta buena
ya que la reutilzie de mi codigo original que no tenia problema*/



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
    

