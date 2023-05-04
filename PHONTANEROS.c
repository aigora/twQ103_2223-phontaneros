#include <stdio.h>

int main () {
	
	//Declaracion de variables
	int op;
	int potable;
	float ph;
	int conductividad;
	int turbidez;
	int i;
	
	printf ("\t\t\t=========PHONTANEROS========= \n\n");
	//Seleccionar programa
	do {
	printf ("Introduzca una opcion: \n\n");
	printf ("1 - Buscar datos \n");
	printf ("2 - Ordenar datos \n");
	printf ("3 - Comparar datos \n");
	printf ("4 - Salir del programa \n\n");
	scanf ("%d", &op);
	} while (op<1 || op>4);
	
	//Programa principal
	switch (op) {
		
		//Buscar datos
		case 1: 
			do {
			printf ("\nSeleccione una opcion: \n");
			printf ("1 - Ver ficheros \n");
			printf ("2 - Buscar una fuente \n");
			printf ("3 - Buscar un dato \n\n");
			scanf("%d", &op);
			} while (op<1 || op>3);
			
			switch (op) {
				
				//Ver ficheros
				case 1:
					do {
					printf ("\nSeleccione un barrio: \n");
					printf ("1 - Lavapies \n");
					printf ("2 - Carabanchel \n");
					printf ("3 - Vallecas \n\n");
					scanf ("%d", &op);
					} while (op<1 || op>3);
					
					switch (op) {
						
						//Lavapies
						case 1:
							printf ("");
						break;
						
						//Carabanchel
						case 2:
							printf ("");
						break;
				
						//Vallecas
						case 3:
							printf ("");
						break;
					}
				break;
				
				//Buscar una fuente
				case 2:
					do {
					printf ("\nSeleccione un barrio: \n");
					printf ("1 - Lavapies \n");
					printf ("2 - Carabanchel \n");
					printf ("3 - Vallecas \n\n");
					scanf ("%d", &op);
					} while (op<1 || op>3);
					
					switch (op) {
						
						//Buscar fuentes en Lavapies
						case 1:
							printf ("Introduzca el numero de la fuente: \n");
						break;
						
						//Buscar fuentes en Carabanchel
						case 2:
							printf ("Introduzca el numero de la fuente: \n");
						break;
				
						//Buscar fuentes en Vallecas
						case 3:
							printf ("Introduzca el numero de la fuente: \n");
						break;
					}
				break;
				
				//Buscar un dato
				case 3:
					do {
					printf ("\nSeleccione una opcion: \n");
					printf ("1 - Lavapies \n");
					printf ("2 - Carabanchel \n");
					printf ("3 - Vallecas \n\n");
					scanf ("%d", &op);
					} while (op<1 || op>3);
				break;
			}
		break;
		
		//Ordenar datos
		case 2:
				
		break;
		
		//Comparar datos
		case 3:
				
		break;
		
		//Salir programa
		case 4: 
			printf("\nSaliendo del programa...");
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
