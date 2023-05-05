#include <stdio.h>

int main () {
	
	//Declaracion de structs
	struct TDatosFuente {
	char fuente[500];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
	};
	
	//Declaracion de variables
	int op;
	int potable;
	int i=0, n;
	float pH;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int opcion;
	struct TDatosFuente FuenteLav[500];
	struct TDatosFuente FuenteCar[500];
	struct TDatosFuente FuenteVal[500];
	int NumFuentesCar, NumFuentesLav, NumFuentesVal;
	
	
	//Abrir ficheros	
	FILE *fLavapies;

	fLavapies = fopen ("fLavapies.txt", "r"); 
	
	if (fLavapies == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0; 	
	}
	
	FILE *fCarabanchel;
	
	fCarabanchel = fopen ("fCarabanchel.txt", "r"); 
	
	if (fCarabanchel == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0;
	}
	
	FILE *fVallecas;
	
	fVallecas = fopen ("fVallecas.txt", "r"); 
	
	if (fVallecas == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0;
	}
	
	//Seleccionar programa
	printf ("\t\t=========PHONTANEROS========= \n\n");
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
							printf ("Datos de Lavapies:\n");
							printf ("Parametros\tpH\t   Conductividad Turbidez Coliformes\n");
							while (fscanf(fLavapies, "%s %f %d %d %d", FuenteLav[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
								printf ("%s \t%.2f\t\t%d\t    %d\t       %d\n", FuenteLav[i].fuente, pH, conductividad, turbidez, coliformes);
	
								FuenteLav[i].pH = pH;
								FuenteLav[i].conductividad = conductividad;
								FuenteLav[i].turbidez = turbidez;
								FuenteLav[i].coliformes = coliformes;
								i++;
							}
							printf ("\nEl numero de fuentes de Lavapies es %d\n", i);
						break;
						
						//Carabanchel
						case 2:
							i=0;
							printf ("Datos de Carabanchel:\n");
							printf ("\nParametros\t pH\t   Conductividad Turbidez Coliformes\n");
							while (fscanf(fCarabanchel, "%s %f %d %d %d", FuenteCar[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF) {
								printf ("%s \t%.2f\t\t%d\t    %d\t       %d\n", FuenteCar[i].fuente, pH, conductividad, turbidez, coliformes);

								FuenteCar[i].pH = pH;
								FuenteCar[i].conductividad = conductividad;
								FuenteCar[i].turbidez = turbidez;
								FuenteCar[i].coliformes = coliformes;
								i++;	
							}
							printf ("\nEl numero de fuentes de Carabanchel es %d\n", i);
						break;
				
						//Vallecas
						case 3:
							i=0;
							printf ("Datos de Vallecas:\n");
							printf ("\nParametros\t pH\t   Conductividad Turbidez Coliformes\n");
							while (fscanf(fVallecas, "%s %f %d %d %d", FuenteVal[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF) {
								printf ("%s \t%.2f\t\t%d\t    %d\t       %d\n", FuenteVal[i].fuente, pH, conductividad, turbidez, coliformes);

								FuenteVal[i].pH = pH;
								FuenteVal[i].conductividad = conductividad;
								FuenteVal[i].turbidez = turbidez;
								FuenteVal[i].coliformes = coliformes;
								i++;
							}
							printf ("\nEl numero de fuentes de Vallecas es %d\n", i);
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
	
	//Cerrar ficheros
	fclose (fLavapies);
	fclose (fCarabanchel);
	fclose (fVallecas);

	return 0;
}


//METER ESTO EN UNA FUNCION

/*
	if (pH<6.5 || pH>8) {
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
	
	if(coliformes==0 && turbidez<=5 && pH>=6.5 && pH<=8){
		printf("El agua es potable\n");
	} else {
		printf("El agua no es potable\n");
	}
	*/
