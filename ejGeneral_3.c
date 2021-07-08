#include <stdio.h>

/*
	
	Simulando un termo 

	Crear un programa que permita desplegar una simulacion del estado actual
	del contenido en un termo visualmente

	Aspectos a tener en cuenta:
		- El termo tiene una capacidad de 1 litro
		- Cada uso consume  un 10% del contenido
		- Cada carga aumenta en un 10% del contenido

	Requisitos:
		- Representar un termo visualmente, a su criterio, con el estado del contenido 
		- Menu que permita:
			- usar termo
			- cargar termo
			- terminar simulacion
		- Realizar las acciones necesarias bajo las situaciones donde
			- El contenido llegue a su maximo
			- No hay contenido

	Extra: informar en cada uso el porcentaje del contenido
	Extra: permitir al usuario poder variar la cantidad de carga del contenido asi como el uso	

*/

#define OPC_USAR 1
#define OPC_AUMENTAR 2
#define OPC_SALIR 3

const int CONSUMO_PORCENTAJE = 10;
const int CARGA_PORCENTAJE = 10;

const int CAPACIDAD_PORCENTAJE = 100;
const int TERMO_VACIO_PORCENTAJE = 0;

const int PORCENTAJE_FRANJA = 10;

#define TERMO_TAPA_1  "______"
#define TERMO_TAPA_2 "|......|"
#define TERMO_TAPA_3 "|^^^^^^|"

#define TERMO_CONT_VACIO "      "
#define TERMO_INDIC_CONT "______"

#define TERMO_BORDE_IZQ "|"
#define TERMO_BORDE_DER "|"

#define TERMPO_BASE "|~~~~~~|"

int main(){

	int cantTermo = 70;
	int opc = 0;

	do{
		printf("Termpo a un %i porciento\n", cantTermo);
		printf("  %s\n", TERMO_TAPA_1);
		printf(" %s\n", TERMO_TAPA_2);
		printf(" %s\n", TERMO_TAPA_3);
		for(int i = 0 ; i < CAPACIDAD_PORCENTAJE/PORCENTAJE_FRANJA ; i++){
			printf(" %s", TERMO_BORDE_IZQ);
			if(i < ( CAPACIDAD_PORCENTAJE -cantTermo)/PORCENTAJE_FRANJA){
				printf(TERMO_CONT_VACIO);
			}else{
				printf(TERMO_INDIC_CONT);
			}
			printf("%s\n", TERMO_BORDE_DER);
		}
		printf(" %s\n", TERMPO_BASE);
		
		printf("Usar 1\n");
		printf("Aumentar 2\n");
		printf("Salir 3\n");
		scanf("%i", &opc);

		switch(opc){
			case OPC_USAR:
				if(cantTermo > TERMO_VACIO_PORCENTAJE){
					cantTermo-=CONSUMO_PORCENTAJE;
				}else{
					printf("Te quedaste sin agua!\n");
				}
				break;
			case OPC_AUMENTAR:
				if(cantTermo<CAPACIDAD_PORCENTAJE){
					cantTermo+=CARGA_PORCENTAJE;
				}else{
					printf("Maximo alcanzado cuidado!\n");
				}
				break;
		}
	}while(opc != OPC_SALIR);

	return 0;
}