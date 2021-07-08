/*
	rand y srand info: http://www.chuidiang.org/clinux/funciones/rand.php
					   https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
	
	Simular un piedra papel o tijera

	Aspectos a tener en cuenta:
		- Simular el jugador 2 con un "bot", este bot debe poder aleatoriamente elegir piedra papel o tijera
		- El jugador 1 es el usuario
		- Gana el que elija la mejor opcion, si hay empate comienza otra ronda
		
	Requisitos:
		- Generar un  numero aleatorio para la eleccion del bot
		- Desplegar un menu para el usuario correspondiente al juego
		- El programa termina cunado gana algun jugador
		- Informar la situacion al finalizar el programa
	
	EXTRA 1: implementar al mejor de 3 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define PIEDRA  0
#define PAPEL  1
#define TIJERA  2

const int MAX_RANGO = 2;

const bool HAY_EMPATE = true;
const bool NO_EMPATE = false;

const bool GANO_USUARIO = true;
const bool NO_GANO_USUARIO = false;


int main(){
	srand (time(NULL));

	int opcUsuario = 0;
	int opcBot = 0;

	bool empateEstado = NO_EMPATE;

	do{
		printf("Piedra - 0\nPapel - 1\nTijera - 2\n");
		scanf("%i", &opcUsuario);
	
		printf("\nUsaste ");
		switch(opcUsuario){
			case PIEDRA:
				printf("Piedra\n");
				break;
			case PAPEL:
				printf("papel\n");
				break;
			case TIJERA:
				printf("Tijera\n");
		}

		opcBot = rand() % MAX_RANGO + 1;
	
		printf("El bot uso ");
		switch(opcBot){
			case PIEDRA:
				printf("Piedra\n");
				break;
			case PAPEL:
				printf("papel\n");
				break;
			case TIJERA:
				printf("Tijera\n");
		}
	
		if(opcUsuario != opcBot){
			printf("\nResultado: Gano el");
			if(((opcUsuario == PIEDRA) && (opcBot == TIJERA)) || ((opcUsuario == PAPEL) && (opcBot == PIEDRA)) || ((opcUsuario == TIJERA) && (opcBot == PAPEL)) ){
				printf(" usuario\n");
			}else{
				printf(" bot\n");
			}
			empateEstado = NO_EMPATE;
		}else{
			printf("\n\n\tHAY UN EMPATE!\nComienza otra ronda!\n");
			empateEstado = HAY_EMPATE;
		}
	}while(empateEstado == HAY_EMPATE);

	return 0;
}