#include <stdio.h>
#include <stdlib.h> // contiene la definicion de las funciones
					// rand() y srand()

#include<time.h> // contiene la definicion de la funcion time()


int main(){

	srand (time(NULL));//altere la semilla para que use el horario del equipo
	
	int numeroAleatorio = 0;

	// entre 0 y N_MAX
	numeroAleatorio = rand();
	printf("%i\n", numeroAleatorio );

	// entre 0 y 10
	numeroAleatorio = rand() % 11; 
	printf("%i\n", numeroAleatorio );
	
	// entre 20 y 30
	numeroAleatorio = rand() % 11 + 20; // con cada uso rand() obtengo un numero aleatorio
	printf("%i\n", numeroAleatorio );


	return 0;
}