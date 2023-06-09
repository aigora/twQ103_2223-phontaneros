#include <stdio.h>
	
//Declaracion de structs
	struct TDatosFuente {
	char fuente[500];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
	};
		
//Prototipos de las funciones
	float fmaximoLav(struct TDatosFuente[]);
	float fmaximoCar(struct TDatosFuente[]);
	float fmaximoVall(struct TDatosFuente[]);
	
	float fminimoLav(struct TDatosFuente[]);
	float fminimoCar(struct TDatosFuente[]);
	float fminimoVall(struct TDatosFuente[]);
	
	float fmenoramayorLav(struct TDatosFuente[]);
	float fmenoramayorCar(struct TDatosFuente[]);
	float fmenoramayorVall(struct TDatosFuente[]);
	
	float fmayoramenorLav(struct TDatosFuente[]);
	float fmayoramenorCar(struct TDatosFuente[]);
	float fmayoramenorVall(struct TDatosFuente[]);

int main () {

//Declaracion de variables
	int op;
	int NumFuentesCar, NumFuentesLav, NumFuentesVall;
	int potable;
	int i, j, n;
	float pH;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int opcion;
	float maximo, minimo;
	struct TDatosFuente FuenteLav[500];
	struct TDatosFuente FuenteCar[500];
	struct TDatosFuente FuenteVall[500];
	float menoramayor;
	float mayoramenor;
	
//Abrir ficheros y escanearlos	

	//Abrir Lavapies
	FILE *fLavapies;

	fLavapies = fopen ("fLavapies.txt", "r"); 
	
	if (fLavapies == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0; 	
	}
	i=0;	
	while (fscanf (fLavapies, "%s %f %d %d %d", FuenteLav[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
	
		FuenteLav[i].pH = pH;
		FuenteLav[i].conductividad = conductividad;
		FuenteLav[i].turbidez = turbidez;
		FuenteLav[i].coliformes = coliformes;
		i++;
	}	
	
	fclose (fLavapies);
	NumFuentesLav = i;
	
	//Abrir Carabanchel
	FILE *fCarabanchel;
	
	fCarabanchel = fopen("fCarabanchel.txt", "r"); 
	
	if (fCarabanchel == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0;
	}
	i=0;
	while (fscanf (fCarabanchel, "%s %f %d %d %d", FuenteCar[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
		
		FuenteCar[i].pH = pH;
		FuenteCar[i].conductividad = conductividad;
		FuenteCar[i].turbidez = turbidez;
		FuenteCar[i].coliformes = coliformes;
		i++;
	}
	fclose (fCarabanchel);
	NumFuentesCar = i; 
	
	//Abrir Vallecas
	FILE *fVallecas;

	fVallecas = fopen ("fVallecas.txt", "r"); 
	
	if (fVallecas == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0; 	
	}
	i=0;	
	while (fscanf (fVallecas, "%s %f %d %d %d", FuenteVall[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){

		FuenteVall[i].pH = pH;
		FuenteVall[i].conductividad = conductividad;
		FuenteVall[i].turbidez = turbidez;
		FuenteVall[i].coliformes = coliformes;
		i++;
	}	
	
	fclose (fVallecas);
	NumFuentesVall = i;

	//SELECCIONAR PROGRAMA
	printf ("\t\t\t\t=================== PHONTANEROS =================== \n\n");
	do {
	printf ("Introduzca una opcion: \n\n");
	printf ("1 - Buscar datos \n");
	printf ("2 - Comparar datos \n");
	printf ("3 - Ordenar datos \n");
	printf ("4 - Estadisticas \n");
	printf ("5 - Salir del programa \n\n");
	scanf ("%d", &op);
	} while (op<1 || op>4);
	
	//PROGRAMA PRINCIPAL
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
					printf ("1 - Carabanchel \n");
					printf ("2 - Lavapies \n");
					printf ("3 - Vallecas \n\n");
					scanf ("%d", &op);
					} while (op<1 || op>3);
					
					switch (op) {
						
						//Ver Carabanchel
						case 1:
							printf ("\nDatos de Carabanchel:\n");
							printf ("Parametros\tpH\t   Conductividad Turbidez Coliformes\n");
							for(i=0; i<NumFuentesCar; i++) {
								printf ("%s \t%.2f\t\t%d\t    %d\t       %d\n", FuenteCar[i].fuente, FuenteCar[i].pH, FuenteCar[i].conductividad, FuenteCar[i].turbidez, FuenteCar[i].coliformes);
							}
							printf ("\nEl numero de fuentes de Lavapies es %d\n", NumFuentesCar);
						break;
						
						//Ver Lavapies
						case 2:
							printf ("\nDatos de Lavapies:\n");
							printf ("Parametros\tpH\t   Conductividad Turbidez Coliformes\n");
							for(i=0; i<NumFuentesLav; i++) {
								printf ("%s \t%.2f\t\t%d\t    %d\t       %d\n", FuenteLav[i].fuente, FuenteLav[i].pH, FuenteLav[i].conductividad, FuenteLav[i].turbidez, FuenteLav[i].coliformes);
							}
							printf ("\nEl numero de fuentes de Lavapies es %d\n", NumFuentesLav);
						break;
				
						//Ver Vallecas
						case 3:
							printf ("\nDatos de Vallecas:\n");
							printf ("Parametros\tpH\t   Conductividad Turbidez Coliformes\n");
							for(i=0; i<NumFuentesVall; i++) {
								printf ("%s \t%.2f\t\t%d\t    %d\t       %d\n", FuenteVall[i].fuente, FuenteVall[i].pH, FuenteVall[i].conductividad, FuenteVall[i].turbidez, FuenteVall[i].coliformes);
							}
							printf ("\nEl numero de fuentes de Vallecas es %d\n", NumFuentesVall);
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
							printf ("\nIntroduzca el numero de la fuente: \n");
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
					
					switch (op) {
						
						//Buscar un dato en Lavapies
						case 1:
							do{
								printf ("\nElija un dato a buscar:\n");
								printf ("1 - pH \n");
								printf ("2 - Conductividad \n");
								printf ("3 - Turbidez \n");
								printf ("4 - Coliformes \n");
								scanf ("%d", &op);
							} while (op<1 || op>4);
							
							switch (op) {
								
								case 1:
									
								break;
								
								case 2:
									
								break;
								
								case 3:
								
								break;
								
								case 4:
									
								break;
							}
						break;
						
						//Buscar un dato en Carabanchel
						case 2:
							do{
								printf ("\nElija un dato a buscar:\n");
								printf ("1 - pH \n");
								printf ("2 - Conductividad \n");
								printf ("3 - Turbidez \n");
								printf ("4 - Coliformes \n");
								scanf ("%d", &op);
							} while (op<1 || op>4);
							
							switch (op) {
								
								case 1:
									
								break;
								
								case 2:
									
								break;
								
								case 3:
								
								break;
								
								case 4:
									
								break;
							}
						break;
						
						//Buscar un dato en Vallecas
						case 3:
							do{
								printf ("\nElija un dato a buscar:\n");
								printf ("1 - pH \n");
								printf ("2 - Conductividad \n");
								printf ("3 - Turbidez \n");
								printf ("4 - Coliformes \n");
								scanf ("%d", &op);
							} while (op<1 || op>4);
							
							switch (op) {
								
								case 1:
									
								break;
								
								case 2:
									
								break;
								
								case 3:
								
								break;
								
								case 4:
									
								break;
							}
						break;
					}	
				break;
			}
		break;
		
		//Comparar datos
		case 2:
			do{
				printf ("\nIntroduce que quieres comparar: \n");
				printf ("1 - pH \n");
				printf ("2 - Conductividad \n");
				printf ("3 - Turbidez \n");
				printf ("4 - Coliformes \n\n");
				scanf ("%d", &op); 
			} while (op<1 || op>4);
			
			switch (op) {
			
				//Comparar pH
				case 1: 
					do {
					printf ("\nComparacion de datos de pH de un barrio, elija el barrio: \n"); 
					printf ("\n 1 - Carabanchel \n 2 - Lavapies \n 3 - Vallecas \n");
					scanf ("%d", &op); 
					} while (op<1 || op>3);
				
					switch (op) {
							
						case 1:
							printf ("\n 1: pH maximo \n 2: pH minimo \n");
							scanf ("%d", &op); 
							
							switch (op) {
							
								case 1:
									maximo=fmaximoCar(FuenteCar); 
									printf ("El pH maximo es: %f \n", maximo); 
								break;
							
								case 2:
									minimo=fminimoCar(FuenteCar);
									printf ("El pH minimo es: %f \n", minimo);
								break;
							}
						break;
						
						case 2:
							printf ("\n 1: pH maximo \n 2: pH minimo \n");
							scanf ("%d", &op); 
							
							switch (op) {
							
								case 1:
									maximo=fmaximoLav(FuenteLav); 
									printf ("El pH maximo es: %f \n", maximo); 
								break;
							
								case 2:
									minimo=fminimoLav(FuenteLav);
									printf ("El pH minimo es: %f \n", minimo);
								break;
							}
						break;
						
						case 3:
							printf ("\n 1 - pH maximo \n 2 - pH minimo \n");
							scanf ("%d", &op); 
							
							switch (op) {
							
								case 1:
									maximo=fmaximoVall(FuenteVall); 
									printf ("El pH maximo es: %f \n", maximo); 
								break;
							
								case 2:
									minimo=fminimoLav(FuenteVall);
									printf ("El pH minimo es: %f \n", minimo);
								break;
							}
						break;
					}
				break;
				
				//Comparar conductividad
				case 2:
					printf ("\nComparacion de datos de conductividad \n");
				break;
				
				//Comparar turbidez
				case 3:
					printf ("\nComparacion de datos de turbidez \n");
				break;
				
				//Comparar coliformes
				case 4:
					printf ("\nComparacion de datos de coliformes \n");
				break;
			}
		break;
		
		//Ordenar datos
		case 3:
			do {
				printf ("\nSeleccione una opcion: \n");
				printf ("1 - Lavapies \n");
				printf ("2 - Carabanchel \n");
				printf ("3 - Vallecas \n\n");
				scanf ("%d", &op);
			} while (op<1 || op>3);
			
			switch (op) {
				
				//Ordenar Lavapies
				case 1:
					do {
						printf ("\nIntroduce que quieres ordenar: \n");
						printf ("1 - pH \n");
						printf ("2 - Conductividad \n");
						printf ("3 - Turbidez \n\n");
						scanf ("%d", &op); 
					} while (op<1 || op>3);
			
					switch (op) {
				
						//Ordenar pH Lavapies
						case 1:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
							
							switch (op) {
								
								case 1:
									menoramayor=fmenoramayorLav(FuenteLav);
									for(i=0;i<25;i++) {
										printf("%.2f \n",FuenteLav[i].pH);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorLav(FuenteLav);
									for(i=0;i<25;i++) {
										printf("%s: ", FuenteLav[i].fuente);
										printf("%.2f \n",FuenteLav[i].pH);
									}
								break;
							}
						break;
						
						//Ordenar conductividad Lavapies
						case 2:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
						break;
					
						//Ordenar turbidez Lavapies
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
						break;
					}
				break;
				
				//Ordenar Carabanchel
				case 2:
					do {
						printf ("\nIntroduce que quieres ordenar: \n");
						printf ("1 - pH \n");
						printf ("2 - Conductividad \n");
						printf ("3 - Turbidez \n\n");
						scanf ("%d", &op); 
					} while (op<1 || op>3);
			
					switch (op) {
				
						//Ordenar pH Carabanchel
						case 1:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
							
							switch (op) {
								
								case 1:
									menoramayor=fmenoramayorCar(FuenteCar);
									for(i=0;i<30;i++) {
										printf("%.2f \n",FuenteCar[i].pH);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorCar(FuenteCar);
									for(i=0;i<30;i++) {
										printf("%s: ", FuenteCar[i].fuente);
										printf("%.2f \n",FuenteCar[i].pH);
									}
								break;
							}
						break;
						
						//Ordenar conductividad Carabanchel
						case 2:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
						break;
					
						//Ordenar turbidez Carabanchel
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
						break;
					}
				break;
				
				//Ordenar Vallecas
				case 3:
					do {
						printf ("\nIntroduce que quieres ordenar: \n");
						printf ("1 - pH \n");
						printf ("2 - Conductividad \n");
						printf ("3 - Turbidez \n\n");
						scanf ("%d", &op); 
					} while (op<1 || op>3);
			
					switch (op) {
				
						//Ordenar pH Vallecas
						case 1:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
							
							switch (op) {
								
								case 1:
									menoramayor=fmenoramayorVall(FuenteVall);
									for(i=0;i<27;i++) {
										printf("%.2f \n",FuenteVall[i].pH);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorVall(FuenteVall);
									for(i=0;i<27;i++) {
										printf("%s: ", FuenteVall[i].fuente);
										printf("%.2f \n",FuenteVall[i].pH);
									}
								break;
							}
						break;
						
						//Ordenar conductividad Vallecas
						case 2:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
						break;
					
						//Ordenar turbidez Vallecas
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
						break;
					}
				break;
			}
		break;
		
		//Estadisticas
		case 4:
			
		break;
		//Salir del programa
		case 5: 
			printf ("\nSaliendo del programa...\n");
		break;
	}
	
	//Cerrar ficheros
	fclose (fLavapies);
	fclose (fCarabanchel);
	fclose (fVallecas);

	return 0;
}


//FUNCIONES

	//MAXIMO
		
		//Carabanchel
			float fmaximoCar (struct TDatosFuente FuenteCar[]) {
			int i; 
			float mayor=0;
			
			for (i=0;i<30; i++) {
				if (FuenteCar[i].pH>mayor) {
					mayor=FuenteCar[i].pH; 
				}
			}
			return mayor; 
			}
		//Lavapies
			float fmaximoLav (struct TDatosFuente FuenteLav[]) {
			int i; 
			float mayor=0;
			
			for (i=0;i<25; i++) {
				if (FuenteLav[i].pH>mayor) {
					mayor=FuenteLav[i].pH; 
				}
			}
			return mayor; 
			}
		//Vallecas
			float fmaximoVall (struct TDatosFuente FuenteVall[]) {
			int i; 
			float mayor=0;
			
			for (i=0;i<27; i++) {
				if (FuenteVall[i].pH>mayor) {
					mayor=FuenteVall[i].pH; 
				}
			}
			return mayor; 
			}
	
	//MINIMO
	
		//Carabanchel
			float fminimoCar (struct TDatosFuente FuenteCar[]) {
			int i;
			float menor=14;
			
			for (i=0; i<30; i++) {
				if (FuenteCar[i].pH<menor) {
					menor=FuenteCar[i].pH; 
				}
			}
			return menor;
			}
			
		//Lavapies
			float fminimoLav (struct TDatosFuente FuenteLav[]) {
			int i;
			float menor=14;
			
			for (i=0; i<25; i++) {
				if (FuenteLav[i].pH<menor) {
					menor=FuenteLav[i].pH; 
				}
			}
			return menor;
			}
			
		//Vallecas
			float fminimoVall (struct TDatosFuente FuenteVall[]) {
			int i;
			float menor=14;
			
			for (i=0; i<27; i++) {
				if (FuenteVall[i].pH<menor) {
					menor=FuenteVall[i].pH; 
				}
			}
			return menor;
			}

	//MENOR A MAYOR
		
		//Carabanchel
			float fmenoramayorCar (struct TDatosFuente FuenteCar[]) {
	
			int i,j;
			float aux;
	
			for (i=0;i<30;i++) {
				for (j=i+1;j<30;j++) {
					if (FuenteCar[i].pH>FuenteCar[j].pH) {
						aux=FuenteCar[i].pH;
						FuenteCar[i].pH=FuenteCar[j].pH;
						FuenteCar[j].pH=aux;
					}
				}
			}
			return aux;
			}
		
		//Lavapies
			float fmenoramayorLav (struct TDatosFuente FuenteLav[]) {
	
			int i,j;
			float aux;
	
			for (i=0;i<25;i++) {
				for (j=i+1;j<25;j++) {
					if (FuenteLav[i].pH>FuenteLav[j].pH) {
						aux=FuenteLav[i].pH;
						FuenteLav[i].pH=FuenteLav[j].pH;
						FuenteLav[j].pH=aux;
					}
				}
			}
			return aux;
			}
		
		//Vallecas
			float fmenoramayorVall (struct TDatosFuente FuenteVall[]) {
	
			int i,j;
			float aux;
	
			for (i=0;i<27;i++) {
				for (j=i+1;j<27;j++) {
					if (FuenteVall[i].pH>FuenteVall[j].pH) {
						aux=FuenteVall[i].pH;
						FuenteVall[i].pH=FuenteVall[j].pH;
						FuenteVall[j].pH=aux;
					}
				}
			}
			return aux;
			}
	
	//MAYOR A MENOR

		//Carabanchel
		float fmayoramenorCar (struct TDatosFuente FuenteCar[]) {
	
			int i,j;
			float aux;
	
			for (i=0;i<30;i++) {
				for (j=i+1;j<30;j++) {
					if (FuenteCar[i].pH<FuenteCar[j].pH) {
						aux=FuenteCar[i].pH;
						FuenteCar[i].pH=FuenteCar[j].pH;
						FuenteCar[j].pH=aux;
					}
				}
			}
		return aux;
		}
		
		//Lavapies
		float fmayoramenorLav (struct TDatosFuente FuenteLav[]) {
	
			int i,j;
			float aux;
	
			for (i=0;i<25;i++) {
				for (j=i+1;j<25;j++) {
					if (FuenteLav[i].pH<FuenteLav[j].pH) {
						aux=FuenteLav[i].pH;
						FuenteLav[i].pH=FuenteLav[j].pH;
						FuenteLav[j].pH=aux;
					}
				}
			}
			return aux;
		}
		
		//Vallecas
		float fmayoramenorVall (struct TDatosFuente FuenteVall[]) {
	
			int i,j;
			float aux;
	
			for (i=0;i<27;i++) {
				for (j=i+1;j<27;j++) {
					if (FuenteVall[i].pH<FuenteVall[j].pH) {
						aux=FuenteVall[i].pH;
						FuenteVall[i].pH=FuenteVall[j].pH;
						FuenteVall[j].pH=aux;
					}
				}
			}
		return aux;
		}
