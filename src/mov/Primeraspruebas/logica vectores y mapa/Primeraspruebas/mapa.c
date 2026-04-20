#include<stdio.h>
#include "mapa.h"	

char mapa[FILAS][COLUMNAS];

void iniciarmapa(){
	for(int i=0;i<FILAS;i++){
		for(int j=0;j<COLUMNAS;j++){
			if(i==0){
			       mapa[i][j]='#';}
			else{
			mapa[i][j]=' ';}}}}

void dibujarmapa(int px,int py){
for(int i= FILAS -1;i>=0;i--){
	for(int j=0; j<COLUMNAS;j++){
		if(j==px && i==py){
			printf("p");}
		printf("%c",mapa[i][j]);}
		printf("\n");}}



