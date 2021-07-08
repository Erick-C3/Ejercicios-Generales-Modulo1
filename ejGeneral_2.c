/*	
	rand y srand info: http://www.chuidiang.org/clinux/funciones/rand.php
					   https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
	
	Simular un juego de azar donde hay un numero ganador y el usuario podra intentar ganar
	un premio

	Aspectos a tener en cuenta:
		- el numero ganador es 8
		- fichas hasta 10 con posibilidad de volver a comprar
		- costo de las fichas es de 149$
		- el usuario cuenta con un saldo inicial
		- premio es igual a la cantidad de fichas usadas multiplicado por el numero ganador y 1000
		- incialmente el usuario cuenta con una ficha de regalo
		- el rango de numeros aleatorios es de 0 a 20

	Requisitos:
		-Solicitar informacion inicial para el funcionamiento del programa
		-Desplegar un menu informando las opciones:
			-Probar suerte
			-Comprar fichas
			-Salir
		-El programa debe poder generar un numero aleatorio para simular la suerte
		-Si el usuario gana o sale se debe informar la situacion como corresponda
	
	

	EXTRA 1: Agregar opcion de aumentar saldo
	EXTRA 2: agregar oferta donde comprando 5 fichas se  realiza un descuento del 15%
	EXTRA 3: tirar de a 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


const int NUMERO_GANADOR = 8;
const int MAX_FICHAS = 10;
const int COSTO_FICHA = 149;

const int FICHAS_INICIALES = 1;
const int SIN_FICHAS = 0;

const int SALDO_MINIMO = COSTO_FICHA;
const int PREMIO_MULT =1000;

const int NUMERO_ALEATORIO_MIN = 0;
const int NUMERO_ALEATORIO_MAX = 20;

#define OPC_PROBAR_SUERTE 1
#define OPC_COMPRAR_FICHAS 2
#define OPC_SALIR 0

int main(){
	srand (time(NULL));

	int saldo = 0;
	int cantFichas = FICHAS_INICIALES;
	int fichasUsadas = 0;
	int opcUsuario = 0;

	int numAleatorio = 0;

	printf("Ingrese saldo inicial\n");
	scanf("%i", &saldo);

	do{
		printf("\nFichas:%i Saldo:%i\n\n",cantFichas, saldo );
		printf("Menu\n");
		printf("Probar suerte - 1 \n");
		printf("Comprar fichas - 2 \n");
		printf("Salir - 0 \n");
		scanf("%i", &opcUsuario);

		switch(opcUsuario){
			case OPC_PROBAR_SUERTE:
				if( cantFichas > SIN_FICHAS){
					fichasUsadas++;
					numAleatorio = rand() % (NUMERO_ALEATORIO_MAX - NUMERO_ALEATORIO_MIN + 1) + NUMERO_ALEATORIO_MIN; 
					printf("Numero obtenido es: %i\n", numAleatorio );
					printf("Numero ganador es %i\n",NUMERO_GANADOR );
					if(numAleatorio == NUMERO_GANADOR){
						printf("GANASTE!\n");
						printf("PREMIO DE: %i $\n", fichasUsadas * NUMERO_GANADOR * PREMIO_MULT);
						opcUsuario = OPC_SALIR;
					}else{
						printf("Suerte para la proxima!\n");
					}
					cantFichas--;
				}else{
					printf("Te quedaste sin fichas!\n");
				}
				break;
			case OPC_COMPRAR_FICHAS:
				if(saldo < SALDO_MINIMO ){
					printf("Te quedaste sin saldo\n");
				}else if(cantFichas >= MAX_FICHAS){
					printf("Alcanzaste el maximo de fichas\n");
				}else{
					printf("Comprando ficha\n");
					saldo-=COSTO_FICHA;
					cantFichas++;
				}
				break;
			case OPC_SALIR:
				printf("Saliendo\n");
				break;
			default: 
				printf("Ingreso no aceptado\n");
		}
	}while(opcUsuario != OPC_SALIR);

	return 0;
}