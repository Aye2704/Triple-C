#include<stdio.h>
#include<stdlib.h>
#include "mapa.h"
#include "player.h"

int main(){
	Player p1={1,2,3,' '};
	iniciarmapa();
	char tecla;
	

	while(tecla!='q'){
		system("cls");
		dibujarmapa(p1.x,p1.y);
		printf("muevase con WASD");
		scanf("%c",&tecla);
		if(tecla=='a'){
			p1.x=p1.x-1;}
		if(tecla=='w'){
			p1.y=p1.y+1;}
		if(tecla=='d'){
			p1.x=p1.x+1;}
		if(tecla=='s'){
			p1.y=p1.y-1;}
		if(tecla=='q'){
			break;}}

	
	return 0;}
