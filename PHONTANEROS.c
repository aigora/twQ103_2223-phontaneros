#include <stdio.h>

int main () {
	
	//Declaracion de variables
	int op;
	int potable;
	float ph;
	int conductividad;
	int turbidez;
	int i;
	
	
	//Seleccionar programa
	do {
	printf ("\t\t\t=========PHONTANEROS========= \n\n");
	printf ("Introduzca una opcion: \n\n");
	printf ("1 - Buscar lista de datos \n");
	printf ("2 - Ordenar datos \n");
	printf ("3 - Comparar datos \n");
	printf ("4 - Salir del programa \n");
	scanf ("%d", &op);
	} while (op<1 || op>4);
	
	//Programa principal
	switch (op) {
		
		//Buscar datos
		case 1: 
		break;
		
		//Ordenar datos
		case 2:
		break;
		
		//Comparar datos
		case 3:
		break;
		
		//Salir programa
		case 4: printf("\nSaliendo del programa...");
		break;
	}
	
	return 0;
}


/*
	if (ph<6.5 || ph>8) {
		printf("La fuente %d tiene mal ph\n", i);
	} else {
		printf("La fuente %d tiene buen ph\n", i);
	}
	
	if (turbidez>5) {
		printf("El agua de la fuente %d es turbia\n", i);
	} else {
		printf("El agua de la fuente %d no es turbia\n", i);
	}	
	
	if (coliformes == 1) {
		printf("El agua de la fuente %d esta contaminada con coliformes\n", i);
	} else {
		printf("El agua de la fuente %d no esta contaminada \n", i);
	}
	
	if(coliformes==0 && turbidez<=5 && ph>=6.5 && ph<=8){
		printf("El agua es potable\n");
	} else {
		printf("El agua no es potable\n");
	}
	*/
