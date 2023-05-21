#include <stdio.h>
#include <string.h>
#include <math.h>
	
//Declaracion de structs
	struct TDatosFuente {
	char fuente[500];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
	};
		
//Prototipos de las funciones

//MAX Y MIN
	float fmaximoLav(struct TDatosFuente[]);
	float fmaximoCar(struct TDatosFuente[]);
	float fmaximoVall(struct TDatosFuente[]);
	
	float fminimoLav(struct TDatosFuente[]);
	float fminimoCar(struct TDatosFuente[]);
	float fminimoVall(struct TDatosFuente[]);
//ORDENAR
	float fmenoramayorLavpH(struct TDatosFuente[]);
	float fmenoramayorCarpH(struct TDatosFuente[]);
	float fmenoramayorVallpH(struct TDatosFuente[]);
	
	float fmayoramenorLavpH(struct TDatosFuente[]);
	float fmayoramenorCarpH(struct TDatosFuente[]);
	float fmayoramenorVallpH(struct TDatosFuente[]);
	
	int fmenoramayorLavConductividad(struct TDatosFuente[]);
	int fmenoramayorCarConductividad(struct TDatosFuente[]);
	int fmenoramayorVallConductividad(struct TDatosFuente[]);
	
	int fmayoramenorLavConductividad(struct TDatosFuente[]);
	int fmayoramenorCarConductividad(struct TDatosFuente[]);
	int fmayoramenorVallConductividad(struct TDatosFuente[]);
	
	int fmenoramayorLavTurbidez(struct TDatosFuente[]);
	int fmenoramayorCarTurbidez(struct TDatosFuente[]);
	int fmenoramayorVallTurbidez(struct TDatosFuente[]);
	
	int fmayoramenorLavTurbidez(struct TDatosFuente[]);
	int fmayoramenorCarTurbidez(struct TDatosFuente[]);
	int fmayoramenorVallTurbidez(struct TDatosFuente[]);
//RECORRIDO
	float frecorridoLav(struct TDatosFuente[]);
	float frecorridoCar(struct TDatosFuente[]);
	float frecorridoVall(struct TDatosFuente[]);
//MODA
	float fmodaLav(struct TDatosFuente[]);
    float fmodaCar(struct TDatosFuente[]);
    float fmodaVall(struct TDatosFuente[]);
//COMPARAR
	void fcompararpHCar(struct TDatosFuente[], int);
	void fcompararpHLav(struct TDatosFuente[], int); 
	void fcompararpHVall(struct TDatosFuente[], int);
	
	void fcompararConductividadCar(struct TDatosFuente[], int);
	void fcompararConductividadLav(struct TDatosFuente[], int);
	void fcompararConductividadVall(struct TDatosFuente[], int);
	
	void fcompararTurbidezCar(struct TDatosFuente[], int);
	void fcompararTurbidezLav(struct TDatosFuente[], int);
	void fcompararTurbidezVall(struct TDatosFuente[], int);
	
	void fcompararColiformesCar(struct TDatosFuente[], int);
	void fcompararColiformesLav(struct TDatosFuente[], int);
	void fcompararColiformesVall(struct TDatosFuente[], int);
	
	void fcompararpHLavCar(struct TDatosFuente[], int, struct TDatosFuente[], int);
	void fcompararpHLavVall(struct TDatosFuente[], int, struct TDatosFuente[], int);
	void fcompararpHCarVall(struct TDatosFuente[], int, struct TDatosFuente[], int);
//MEDIA Y DESV
	float fmediapHCar(struct TDatosFuente[], int);
	float fmediapHLav(struct TDatosFuente[], int);
	float fmediapHVall(struct TDatosFuente[], int);
	
	float fdespHCar(struct TDatosFuente[], float, int);
	float fdespHLav(struct TDatosFuente[], float, int);
	float fdespHVall(struct TDatosFuente[], float, int);
	
	float fmediaConCar(struct TDatosFuente[], int);
	float fmediaConLav(struct TDatosFuente[], int);
	float fmediaConVall(struct TDatosFuente[], int);
	
	float fdesConCar(struct TDatosFuente[], float, int);
	float fdesConLav(struct TDatosFuente[], float, int);
	float fdesConVall(struct TDatosFuente[], float, int);
	
	float fmediaTurCar(struct TDatosFuente[], int);
	float fmediaTurLav(struct TDatosFuente[], int);
	float fmediaTurVall(struct TDatosFuente[], int);
	
	float fdesTurCar(struct TDatosFuente[], float, int);
	float fdesTurLav(struct TDatosFuente[], float, int);
	float fdesTurVall(struct TDatosFuente[], float, int);
//BUSCAR FUENTE
	void fBuscarCar(struct TDatosFuente[], int);
	void fBuscarLav(struct TDatosFuente[], int);
	void fBuscarVall(struct TDatosFuente[], int);
//
		
int main () {

//Declaracion de variables
	int op;
	int NumFuentesCar=0, NumFuentesLav=0, NumFuentesVall=0;
	int potable;
	int i = 0, j, n;
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
	float valor_repetidoCar, valor_repetidoLav, valor_repetidoVall;
	float mediapHCar, mediapHLav, mediapHVall, despHCar, despHLav, despHVall;
	float mediaConCar, mediaConLav, mediaConVall, desConCar, desConLav, desConVall;
	float mediaTurCar, mediaTurLav, mediaTurVall, desTurCar, desTurLav, desTurVall;

//Abrir ficheros y escanearlos	

	//Abrir Lavapies
	FILE *fLavapies;

	fLavapies = fopen ("fLavapies.txt", "r"); 
	
	if (fLavapies == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0; 	
	}
	i=0;	
//	fscanf(fLavapies, "%d", &ndatos);
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
	fscanf(fCarabanchel, "%d", &NumFuentesCar); 
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
	do {
	
	printf ("\t\t\t\t==================== PHONTANEROS ==================== \n\n");
	do {
	printf ("Introduzca una opcion: \n\n");
	printf ("1 - Buscar datos \n");
	printf ("2 - Comparar datos \n");
	printf ("3 - Ordenar datos \n");
	printf ("4 - Estadisticas \n");
	printf ("0 - Salir del programa \n\n");
	scanf ("%d", &opcion);
	} while (opcion<0 || opcion>4);
	
	//PROGRAMA PRINCIPAL
	switch (opcion) {
		
		//Buscar datos
		case 1: 
			printf("\n-----BUSCAR DATOS-----\n");
			do {
				printf ("\nSeleccione una opcion: \n");
				printf ("1 - Ver ficheros \n");
				printf ("2 - Buscar una fuente \n");
				printf ("3 - Buscar un dato \n");
				printf("0 - Volver al menu \n\n");
				scanf("%d", &op);
			} while (op<0 || op>3);
			
			switch (op) {
				
				//Ver ficheros
				case 1:
					printf("\n-----VER FICHEROS-----\n");
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
							printf ("\nEl numero de fuentes de Carabanchel es %d\n", NumFuentesCar);
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
					printf("\n-----BUSCAR FUENTE-----\n");
					do {
						printf ("Introduzca una opcion: \n\n");
						printf ("1 - Carabanchel \n");
						printf ("2 - Lavapies \n");
						printf ("3 - Vallecas \n\n");
						scanf ("%d", &op);
					} while (op<1 || op>3);
					
					switch (op) {
						
						case 1:
							fBuscarCar(FuenteCar, NumFuentesCar);
						break;
						
						case 2:
							fBuscarLav(FuenteLav, NumFuentesLav);
						break;
						
						case 3:
							fBuscarVall(FuenteVall, NumFuentesVall);
						break;
					}
				break;
			}
		break;
		
		//Comparar datos
		case 2:
			printf("\n-----COMPARAR DATOS-----\n");
			do{
				printf ("\nIntroduce que quieres comparar: \n");
				printf ("1 - pH \n");
				printf ("2 - Conductividad \n");
				printf ("3 - Turbidez \n");
				printf ("4 - Coliformes \n");
				printf("0 - Volver al menu \n\n");
				scanf ("%d", &op); 
			} while (op<0 || op>4);
			
			switch (op) {
			
				//Comparar pH
				case 1: 
					printf("\n-----COMPARAR PH-----\n");
					do {
						printf ("\nComparacion de datos de pH \n\n");
						printf ("Elija una opcion: \n");
						printf ("1 - Maximo \n");
						printf ("2 - Minimo \n");
						printf ("3 - Recorrido\n");
						printf ("4 - Comparar pH de 2 fuentes de un mismo barrio \n");
						printf ("5 - Comparar pH de 2 fuentes de barrios diferentes \n");
						scanf ("%d", &op); 
					} while (op<1 || op>5);
					
					switch (op) {
						
						//Maximo pH
						case 1:
							do {
								printf ("Elija un barrio: \n");
								printf ("1 - Carabanchel\n");
								printf ("2 - Lavapies \n");
								printf ("3 - Vallecas \n");
								scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									maximo=fmaximoCar(FuenteCar); 
									printf ("El pH maximo es: %f \n", maximo);
								break;
								
								case 2:
									maximo=fmaximoLav(FuenteLav); 
									printf ("El pH maximo es: %f \n", maximo); 
								break;
								
								case 3:
									maximo=fmaximoVall(FuenteVall); 
										printf ("El pH maximo es: %f \n", maximo); 
								break;	
							}
						break;
						
						//Minimo pH
						case 2:
							do {
							printf ("Elija un barrio: \n");
							printf ("1 - Carabanchel\n");
							printf ("2 - Lavapies \n");
							printf ("3 - Vallecas \n");
							scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									minimo=fminimoCar(FuenteCar);
									printf ("El pH minimo es: %f \n", minimo);
								break;
								
								case 2:
									minimo=fminimoLav(FuenteLav);
									printf ("El pH minimo es: %f \n", minimo);
								break;
									
								case 3:
									minimo=fminimoVall(FuenteVall);
									printf ("El pH minimo es: %f \n", minimo);
								break;				
							}
						break;
						
						//Recorrido pH
						case 3:
							do {
							printf ("Elija un barrio: \n");
							printf ("1 - Carabanchel\n");
							printf ("2 - Lavapies \n");
							printf ("3 - Vallecas \n");
							scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									printf ("El recorrido es: %f \n", frecorridoCar(FuenteCar));
								break;
								
								case 2:
									printf ("El recorrido es: %f \n",frecorridoLav(FuenteLav));
								break;
									
								case 3:
									printf ("El recorrido es: %f \n",frecorridoVall(FuenteVall));
								break;				
							}
						break;
						
						//Mismo barrio pH
						case 4:
							do {
								printf ("Elija un barrio: \n");
								printf ("1 - Carabanchel\n");
								printf ("2 - Lavapies \n");
								printf ("3 - Vallecas \n");
								scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									fcompararpHCar(FuenteCar, NumFuentesCar);	
								break;
									
								case 2: 
									fcompararpHLav(FuenteLav, NumFuentesLav); 
								break; 
								
								case 3: 
									fcompararpHLav(FuenteVall, NumFuentesVall); 
								break;
							}
						break;
						
						//Diferente barrio pH
						case 5:
							do {
								printf ("Elija entre dos barrios: \n");
								printf ("1 - Lavapies<->Carabanchel\n");
								printf ("2 - Lavapies<->Vallecas \n");
								printf ("3 - Carabanchel<->Vallecas \n");
								scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									fcompararpHLavCar(FuenteLav, NumFuentesLav, FuenteCar, NumFuentesCar);	
								break;
									
								case 2: 
									fcompararpHLavVall(FuenteLav, NumFuentesLav, FuenteVall, NumFuentesVall); 
								break; 
								
								case 3: 
									fcompararpHCarVall(FuenteCar, NumFuentesCar, FuenteVall, NumFuentesVall); 
								break;
							}
						break;		
					}
				break;
				
				//Comparar conductividad
				case 2:
					printf("\n-----COMPARAR CONDUCTIVIDAD-----\n");
					do {
						printf ("Elija una opcion: \n");
						printf ("1 - Maximo \n");
						printf ("2 - Minimo \n");
						printf ("3 - Recorrido\n");
						printf ("4 - Comparar conductividad de 2 fuentes de un mismo barrio \n");
						printf ("5 - Comparar conductividad de 2 fuentes de barrios diferentes \n");
						scanf ("%d", &op); 
					} while (op<1 || op>5);
					
					switch (op) {
						
						//Maximo Con
						case 1:
							do {
								printf ("Elija un barrio: \n");
								printf ("1 - Carabanchel\n");
								printf ("2 - Lavapies \n");
								printf ("3 - Vallecas \n");
								scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									maximo=fmaximoCar(FuenteCar); 
									printf ("El pH maximo es: %f \n", maximo);
								break;
								
								case 2:
									maximo=fmaximoLav(FuenteLav); 
									printf ("El pH maximo es: %f \n", maximo); 
								break;
								
								case 3:
									maximo=fmaximoVall(FuenteVall); 
										printf ("El pH maximo es: %f \n", maximo); 
								break;	
							}
						break;
						
						//Minimo Con
						case 2:
							do {
							printf ("Elija un barrio: \n");
							printf ("1 - Carabanchel\n");
							printf ("2 - Lavapies \n");
							printf ("3 - Vallecas \n");
							scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									minimo=fminimoCar(FuenteCar);
									printf ("El pH minimo es: %f \n", minimo);
								break;
								
								case 2:
									minimo=fminimoLav(FuenteLav);
									printf ("El pH minimo es: %f \n", minimo);
								break;
									
								case 3:
									minimo=fminimoVall(FuenteVall);
									printf ("El pH minimo es: %f \n", minimo);
								break;				
							}
						break;
						
						//Recorrido Con
						case 3:
							do {
							printf ("Elija un barrio: \n");
							printf ("1 - Carabanchel\n");
							printf ("2 - Lavapies \n");
							printf ("3 - Vallecas \n");
							scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									printf ("El recorrido es: %f \n", frecorridoCar(FuenteCar));
								break;
								
								case 2:
									printf ("El recorrido es: %f \n",frecorridoLav(FuenteLav));
								break;
									
								case 3:
									printf ("El recorrido es: %f \n",frecorridoVall(FuenteVall));
								break;				
							}
						break;
						
						//Mismo barrio Con
						case 4:
							do {
								printf ("Elija un barrio: \n");
								printf ("1 - Carabanchel\n");
								printf ("2 - Lavapies \n");
								printf ("3 - Vallecas \n");
								scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									fcompararConductividadCar(FuenteCar, NumFuentesCar);	
								break;
									
								case 2: 
									fcompararConductividadLav(FuenteLav, NumFuentesLav); 
								break; 
								
								case 3: 
									fcompararConductividadVall(FuenteVall, NumFuentesVall); 
								break;
							}
						break;
						
						//Diferente barrio Con
						case 5:
							do {
								printf ("Elija entre dos barrios: \n");
								printf ("1 - Lavapies<->Carabanchel\n");
								printf ("2 - Lavapies<->Vallecas \n");
								printf ("3 - Carabanchel<->Vallecas \n");
								scanf ("%d", &op); 
							} while (op<1 || op>3);
							
							switch (op) {
								
								case 1:
									fcompararpHLavCar(FuenteLav, NumFuentesLav, FuenteCar, NumFuentesCar);	
								break;
									
								case 2: 
									fcompararpHLavVall(FuenteLav, NumFuentesLav, FuenteVall, NumFuentesVall); 
								break; 
								
								case 3: 
									fcompararpHCarVall(FuenteCar, NumFuentesCar, FuenteVall, NumFuentesVall); 
								break;
							}
						break;		
					}
				break;
				
				//Comparar turbidez
				case 3:
					printf("\n-----COMPARAR TURBIDEZ-----\n");
				break;
				
				//Comparar coliformes
				case 4:
					printf("\n-----COMPARAR COLIFORMES-----\n");
				break;
			}
		break;
		
		//Ordenar datos
		case 3:
			printf("\n-----ORDENAR DATOS-----\n");
			do {
				printf ("\nSeleccione una opcion: \n");
				printf ("1 - Lavapies \n");
				printf ("2 - Carabanchel \n");
				printf ("3 - Vallecas \n");
				printf("0 - Volver al menu \n\n");
				scanf ("%d", &op);
			} while (op<0 || op>3);
			
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
									menoramayor=fmenoramayorLavpH(FuenteLav);
									for(i=0;i<NumFuentesLav;i++) {
										printf("%s: ", FuenteLav[i].fuente);
										printf("%.2f \n",FuenteLav[i].pH);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorLavpH(FuenteLav);
									for(i=0;i<NumFuentesLav;i++) {
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
							
							switch (op) {
							
								case 1:
									menoramayor=fmenoramayorLavConductividad(FuenteLav);
									for(i=0;i<NumFuentesLav;i++) {
										printf("%s: ", FuenteLav[i].fuente);
										printf("%d \n",FuenteLav[i].conductividad);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorLavConductividad(FuenteLav);
									for(i=0;i<NumFuentesLav;i++) {
										printf("%s: ", FuenteLav[i].fuente);
										printf("%d\n",FuenteLav[i].conductividad);
									}
								break;
							}
						break;
					
						//Ordenar turbidez Lavapies
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
							
							switch (op) {
							
								case 1:
									menoramayor=fmenoramayorLavTurbidez(FuenteLav);
									for(i=0;i<NumFuentesLav;i++) {
										printf("%s: ", FuenteLav[i].fuente);
										printf("%d \n",FuenteLav[i].turbidez);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorLavTurbidez(FuenteLav);
									for(i=0;i<NumFuentesLav;i++) {
										printf("%s: ", FuenteLav[i].fuente);
										printf("%d \n",FuenteLav[i].turbidez);
									}
								break;
							}
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
									menoramayor=fmenoramayorCarpH(FuenteCar);
									for(i=0;i<NumFuentesCar;i++) {
										printf("%s: ", FuenteCar[i].fuente);
										printf("%.2f \n",FuenteCar[i].pH);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorCarpH(FuenteCar);
									for(i=0;i<NumFuentesCar;i++) {
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
							
							switch (op) {
								
								case 1:
									menoramayor=fmenoramayorCarConductividad(FuenteCar);
									for(i=0;i<NumFuentesCar;i++) {
										printf("%s: ", FuenteCar[i].fuente);
										printf("%d \n",FuenteCar[i].conductividad);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorCarConductividad(FuenteCar);
									for(i=0;i<NumFuentesCar;i++) {
										printf("%s: ", FuenteCar[i].fuente);
										printf("%d \n",FuenteCar[i].conductividad);
									}
								break;
							}
						break;
					
						//Ordenar turbidez Carabanchel
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
							
							switch (op) {
								
								case 1:
									menoramayor=fmenoramayorCarTurbidez(FuenteCar);
									for(i=0;i<NumFuentesCar;i++) {
										printf("%s: ", FuenteCar[i].fuente);
										printf("%d \n",FuenteCar[i].turbidez);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorCarTurbidez(FuenteCar);
									for(i=0;i<NumFuentesCar;i++) {
										printf("%s: ", FuenteCar[i].fuente);
										printf("%d \n",FuenteCar[i].turbidez);
									}
								break;
							}
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
									menoramayor=fmenoramayorVallpH(FuenteVall);
									for(i=0;i<NumFuentesVall;i++) {
										printf("%s: ", FuenteVall[i].fuente);
										printf("%.2f \n",FuenteVall[i].pH);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorVallpH(FuenteVall);
									for(i=0;i<NumFuentesVall;i++) {
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
							
							switch (op) {
								
								case 1:
									menoramayor=fmenoramayorVallConductividad(FuenteVall);
									for(i=0;i<NumFuentesVall;i++) {
										printf("%s: ", FuenteVall[i].fuente);
										printf("%d \n",FuenteVall[i].conductividad);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorVallConductividad(FuenteVall);
									for(i=0;i<NumFuentesVall;i++) {
										printf("%s: ", FuenteVall[i].fuente);
										printf("%d \n",FuenteVall[i].conductividad);
									}
								break;
							}
						break;
					
						//Ordenar turbidez Vallecas
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", &op);
							} while (op<1 || op>2);
							
							switch (op) {
								
								case 1:
									menoramayor=fmenoramayorVallTurbidez(FuenteVall);
									for(i=0;i<NumFuentesVall;i++) {
										printf("%s: ", FuenteVall[i].fuente);
										printf("%d \n",FuenteVall[i].turbidez);
									}
								break;
								
								case 2:
									mayoramenor=fmayoramenorVallTurbidez(FuenteVall);
									for(i=0;i<NumFuentesVall;i++) {
										printf("%s: ", FuenteVall[i].fuente);
										printf("%d \n",FuenteVall[i].turbidez);
									}
								break;
							}
						break;
					}
				break;
			}
		break;
		
		//Estadisticas
		case 4:
			printf("\n-----ESTADISTICAS-----\n");
			do{
				printf("\nSeleccione una opcion: \n\n");
				printf("1 - Potabilidad \n");
				printf("2 - Media \n");
				printf("3 - Moda \n");
				printf("4 - Desviacion \n");
				printf("0 - Volver al menu \n\n");
				scanf("%d", &op);
			} while (op<0 || op>4);
			
			switch (op){
				
				//Potabilidad
				case 1: 
					do {
						printf ("Introduzca una opcion: \n\n");
						printf ("1 - Carabanchel \n");
						printf ("2 - Lavapies \n");
						printf ("3 - Vallecas \n");
						scanf ("%d", &op);
					} while (op<1 || op>3);
	
					switch (op) {
					
						//Carabanchel
						case 1:
							do {
				    			printf("Introduzca una fuente:\n\n");
				    			scanf("%d", &i);
								i=i-1;
							} while (i<1 || i>NumFuentesCar);
					
				    		if (FuenteCar[i].pH < 6.5 || FuenteCar[i].pH > 8) {
				       			printf("\nLa fuente %s tiene mal ph\n", FuenteCar[i].fuente);
				    		} else {
				       			printf("\nLa fuente %s tiene buen ph\n", FuenteCar[i].fuente);
							}
				
				   			if (FuenteCar[i].turbidez > 5) {
				   				printf("El agua de la fuente %s es turbia\n", FuenteCar[i].fuente);
				    		} else {
				        		printf("El agua de la fuente %s no es turbia\n", FuenteCar[i].fuente);
				    		}
				
				    		if (FuenteCar[i].coliformes == 1) {
				     			printf("El agua de la fuente %s esta contaminada con coliformes\n", FuenteCar[i].fuente);
				    		} else {
				    			printf("El agua de la fuente %s no esta contaminada\n", FuenteCar[i].fuente);
				   		 	}
				
				   			if (FuenteCar[i].coliformes == 0 && FuenteCar[i].turbidez <= 5 && FuenteCar[i].pH >= 6.5 && FuenteCar[i].pH <= 8) {
				        		printf("El agua es potable\n");
				    		} else {
				    			printf("El agua no es potable\n");
				    		}
						break;
					
						//Lavapies
						case 2:
							do {
				    			printf("Introduzca una fuente:\n\n");
				    			scanf("%d", &i);
								i=i-1;
							} while (i<1 || i>NumFuentesLav);
					
				    		if (FuenteLav[i].pH < 6.5 || FuenteLav[i].pH > 8) {
				       			printf("\nLa fuente %s tiene mal ph\n", FuenteLav[i].fuente);
				    		} else {
				       			printf("\nLa fuente %s tiene buen ph\n", FuenteLav[i].fuente);
							}
				
				   			if (FuenteLav[i].turbidez > 5) {
				   				printf("El agua de la fuente %s es turbia\n", FuenteLav[i].fuente);
				    		} else {
				        		printf("El agua de la fuente %s no es turbia\n", FuenteLav[i].fuente);
				    		}
				
				    		if (FuenteLav[i].coliformes == 1) {
				     			printf("El agua de la fuente %s esta contaminada con coliformes\n", FuenteLav[i].fuente);
				    		} else {
				    			printf("El agua de la fuente %s no esta contaminada\n", FuenteLav[i].fuente);
				   		 	}
				
				   			if (FuenteLav[i].coliformes == 0 && FuenteLav[i].turbidez <= 5 && FuenteLav[i].pH >= 6.5 && FuenteLav[i].pH <= 8) {
				        		printf("El agua es potable\n");
				    		} else {
				    			printf("El agua no es potable\n");
				    		}
						break;
						
						//Vallecas
						case 3:
							do {
				    			printf("Introduzca una fuente:\n\n");
				    			scanf("%d", &i);
								i=i-1;
							} while (i<1 || i>NumFuentesVall);
					
				    		if (FuenteVall[i].pH < 6.5 || FuenteVall[i].pH > 8) {
				       			printf("\nLa fuente %s tiene mal ph\n", FuenteVall[i].fuente);
				    		} else {
				       			printf("\nLa fuente %s tiene buen ph\n", FuenteVall[i].fuente);
							}
				
				   			if (FuenteVall[i].turbidez > 5) {
				   				printf("El agua de la fuente %s es turbia\n", FuenteVall[i].fuente);
				    		} else {
				        		printf("El agua de la fuente %s no es turbia\n", FuenteVall[i].fuente);
				    		}
				
				    		if (FuenteVall[i].coliformes == 1) {
				     			printf("El agua de la fuente %s esta contaminada con coliformes\n", FuenteVall[i].fuente);
				    		} else {
				    			printf("El agua de la fuente %s no esta contaminada\n", FuenteVall[i].fuente);
				   		 	}
				
				   			if (FuenteVall[i].coliformes == 0 && FuenteVall[i].turbidez <= 5 && FuenteVall[i].pH >= 6.5 && FuenteVall[i].pH <= 8) {
				        		printf("El agua es potable\n");
				    		} else {
				    			printf("El agua no es potable\n");
				    		}
						break;
					}
				break;
				
				//Media
				case 2:
					do {
						printf ("Introduzca una opcion: \n\n");
						printf ("1 - Carabanchel \n");
						printf ("2 - Lavapies \n");
						printf ("3 - Vallecas \n");
						scanf ("%d", &op);
					} while (op<1 || op>3);
					
						mediapHCar = fmediapHCar(FuenteCar, NumFuentesCar);
						mediapHLav = fmediapHLav(FuenteLav, NumFuentesLav);
						mediapHVall = fmediapHVall(FuenteVall, NumFuentesVall);
						
						mediaConCar = fmediaConCar(FuenteCar, NumFuentesCar);
						mediaConLav = fmediaConLav(FuenteLav, NumFuentesLav);
						mediaConVall = fmediaConVall(FuenteVall, NumFuentesVall);
						
						mediaTurCar = fmediaTurCar(FuenteCar, NumFuentesCar);
						mediaTurLav = fmediaTurLav(FuenteLav, NumFuentesLav);
						mediaTurVall = fmediaTurVall(FuenteVall, NumFuentesVall);
						
					switch (op)	{
										
						//Carabanchel
						case 1:
							printf("La media de pH de Carabanchel es: %.2f\n", mediapHCar);
							printf("La media de conductividad de Carabanchel es: %.2f\n", mediaConCar);
							printf("La media de turbidez de Carabanchel es: %.2f\n", mediaTurCar);
						break;
					
						//Lavapies
						case 2:
							printf("La media de pH de Lavapies es: %.2f\n", mediapHLav);
							printf("La media de conductividad de Lavapies es: %.2f\n", mediaConLav);
							printf("La media de turbidez de Lavapies es: %.2f\n", mediaTurLav);
						break;
						
						//Vallecas
						case 3:
							printf("La de media de pH de Vallecas es: %.2f\n", mediapHVall);
							printf("La de media de conductividad de Vallecas es: %.2f\n", mediaConVall);
							printf("La media de turbidez de Vallecas es: %.2f\n", mediaTurVall);
						break;
					}
				break;
				
				//Moda
				case 3:
				do {
					printf ("Elija un barrio: \n");
					printf ("1 - Carabanchel\n");
					printf ("2 - Lavapies \n");
					printf ("3 - Vallecas \n");
					scanf ("%d", &op); 
				} while (op<1 || op>3);
				
				switch (op) {
					
					case 1:
					valor_repetidoCar = fmodaCar(FuenteCar);
	                printf("El pH que mas veces se repite de Carabanchel es el:%.2f \n", valor_repetidoCar);
	                break;
				
					case 2:
					valor_repetidoLav = fmodaLav(FuenteLav);
                    printf("El pH que mas veces se repite de Lavapies es el: %.2f \n", valor_repetidoLav);
					break;
					case 3:		
					valor_repetidoVall = fmodaVall(FuenteVall);
                	printf("El pH que mas veces se repite de Vallecas es el: %.2f \n", valor_repetidoVall);
                	break;
				}
				break;
				
				//Desviacion
				case 4:
					do {
						printf ("Introduzca una opcion: \n\n");
						printf ("1 - Carabanchel \n");
						printf ("2 - Lavapies \n");
						printf ("3 - Vallecas \n");
						scanf ("%d", &op);
					} while (op<1 || op>3);
					
						despHCar = fdespHCar(FuenteCar, mediapHCar, NumFuentesCar);
						despHLav = fdespHLav(FuenteLav, mediapHLav, NumFuentesLav);
						despHVall = fdespHVall(FuenteCar, mediapHVall, NumFuentesVall);
						
						desConCar = fdesConCar(FuenteCar, mediaConCar, NumFuentesCar);
						desConLav = fdesConLav(FuenteLav, mediaConLav, NumFuentesLav);
						desConVall = fdesConVall(FuenteVall, mediaConVall, NumFuentesVall);
						
						desTurCar = fdesTurCar(FuenteCar, mediaTurCar, NumFuentesCar);
						desTurLav = fdesTurLav(FuenteLav, mediaTurLav, NumFuentesLav);
						desTurVall = fdesTurVall(FuenteCar, mediaTurVall, NumFuentesVall);
					
					switch (op)	{
										
						//Carabanchel
						case 1:
							printf("La de desviacion tipica de pH de Carabanchel es: %.2f\n", despHCar);
							printf("La de desviacion tipica de conductividad de Carabanchel es: %.2f\n", desConCar);
							printf("La de desviacion tipica de turbidez de Carabanchel es: %.2f\n", desTurCar);
						break;
					
						//Lavapies
						case 2:
							printf("La de desviacion tipica de pH de Lavapies es: %.2f\n", despHLav);
							printf("La de desviacion tipica de conductividad de Lavapies es: %.2f\n", desConLav);
							printf("La de desviacion tipica de turbidez de Lavapies es: %.2f\n", desTurLav);
						break;
						
						//Vallecas
						case 3:
							printf("La de desviacion tipica de pH de Vallecas es: %.2f\n", despHVall);
							printf("La de desviacion tipica de conductividad de Vallecas es: %.2f\n", desConVall);
							printf("La de desviacion tipica de turbidez de Vallecas es: %.2f\n", desTurVall);
						break;
					}
				break;
			}
		break;
		
		//Salir del programa
		case 0: 
     	printf ("\nSaliendo del programa...\n");
		break;
	}
	} while (opcion != 0);
	
	//Cerrar ficheros
	fclose (fLavapies);
	fclose (fCarabanchel);
	fclose (fVallecas);

	return 0;
}


//FUNCIONES

	//MAXIMO (FALTA TODO MENOS PH)
		
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
	
	//MINIMO (FALTA TODO MENOS PH)
	
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

	//MENOR A MAYOR PH
		
		//Carabanchel
			float fmenoramayorCarpH (struct TDatosFuente FuenteCar[]) {
	
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
			float fmenoramayorLavpH (struct TDatosFuente FuenteLav[]) {
	
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
			float fmenoramayorVallpH (struct TDatosFuente FuenteVall[]) {
	
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
	
	//MAYOR A MENOR PH

		//Carabanchel
		float fmayoramenorCarpH (struct TDatosFuente FuenteCar[]) {
	
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
		float fmayoramenorLavpH (struct TDatosFuente FuenteLav[]) {
	
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
		float fmayoramenorVallpH (struct TDatosFuente FuenteVall[]) {
	
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
		
	//MENOR A MAYOR CONDUCTIVIDAD

		//Carabanchel
			int fmenoramayorCarConductividad (struct TDatosFuente FuenteCar[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<30;i++) {
				for (j=i+1;j<30;j++) {
					if (FuenteCar[i].conductividad>FuenteCar[j].conductividad) {
						aux=FuenteCar[i].conductividad;
						FuenteCar[i].conductividad=FuenteCar[j].conductividad;
						FuenteCar[j].conductividad=aux;
					}
				}
			}
			return aux;
			}
		
		//Lavapies
			int fmenoramayorLavConductividad (struct TDatosFuente FuenteLav[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<25;i++) {
				for (j=i+1;j<25;j++) {
					if (FuenteLav[i].conductividad>FuenteLav[j].conductividad) {
						aux=FuenteLav[i].conductividad;
						FuenteLav[i].conductividad=FuenteLav[j].conductividad;
						FuenteLav[j].conductividad=aux;
					}
				}
			}
			return aux;
			}
		
		//Vallecas
			int fmenoramayorVallConductividad (struct TDatosFuente FuenteVall[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<27;i++) {
				for (j=i+1;j<27;j++) {
					if (FuenteVall[i].conductividad>FuenteVall[j].conductividad) {
						aux=FuenteVall[i].conductividad;
						FuenteVall[i].conductividad=FuenteVall[j].conductividad;
						FuenteVall[j].conductividad=aux;
					}
				}
			}
			return aux;
			}
			
	//MAYOR A MENOR CONDUCTIVIDAD
	
		//Carabanchel
		int fmayoramenorCarConductividad (struct TDatosFuente FuenteCar[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<30;i++) {
				for (j=i+1;j<30;j++) {
					if (FuenteCar[i].conductividad<FuenteCar[j].conductividad) {
						aux=FuenteCar[i].conductividad;
						FuenteCar[i].conductividad=FuenteCar[j].conductividad;
						FuenteCar[j].conductividad=aux;
					}
				}
			}
		return aux;
		}
		
		//Lavapies
		int fmayoramenorLavConductividad (struct TDatosFuente FuenteLav[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<25;i++) {
				for (j=i+1;j<25;j++) {
					if (FuenteLav[i].conductividad<FuenteLav[j].conductividad) {
						aux=FuenteLav[i].conductividad;
						FuenteLav[i].conductividad=FuenteLav[j].conductividad;
						FuenteLav[j].conductividad=aux;
					}
				}
			}
			return aux;
		}
		
		//Vallecas
		int fmayoramenorVallConductividad (struct TDatosFuente FuenteVall[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<27;i++) {
				for (j=i+1;j<27;j++) {
					if (FuenteVall[i].conductividad<FuenteVall[j].conductividad) {
						aux=FuenteVall[i].conductividad;
						FuenteVall[i].conductividad=FuenteVall[j].conductividad;
						FuenteVall[j].conductividad=aux;
					}
				}
			}
		return aux;
		}
		
	//MENOR A MAYOR TURBIDEZ
	
		//Carabanchel
			int fmenoramayorCarTurbidez (struct TDatosFuente FuenteCar[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<30;i++) {
				for (j=i+1;j<30;j++) {
					if (FuenteCar[i].turbidez>FuenteCar[j].turbidez) {
						aux=FuenteCar[i].turbidez;
						FuenteCar[i].turbidez=FuenteCar[j].turbidez;
						FuenteCar[j].turbidez=aux;
					}
				}
			}
			return aux;
			}
		
		//Lavapies
			int fmenoramayorLavTurbidez (struct TDatosFuente FuenteLav[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<25;i++) {
				for (j=i+1;j<25;j++) {
					if (FuenteLav[i].turbidez>FuenteLav[j].turbidez) {
						aux=FuenteLav[i].turbidez;
						FuenteLav[i].turbidez=FuenteLav[j].turbidez;
						FuenteLav[j].turbidez=aux;
					}
				}
			}
			return aux;
			}
		
		//Vallecas
			int fmenoramayorVallTurbidez (struct TDatosFuente FuenteVall[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<27;i++) {
				for (j=i+1;j<27;j++) {
					if (FuenteVall[i].turbidez>FuenteVall[j].turbidez) {
						aux=FuenteVall[i].turbidez;
						FuenteVall[i].turbidez=FuenteVall[j].turbidez;
						FuenteVall[j].turbidez=aux;
					}
				}
			}
			return aux;
			}
	
	//MAYOR A MENOR TURBIDEZ
	
		//Carabanchel
		int fmayoramenorCarTurbidez (struct TDatosFuente FuenteCar[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<30;i++) {
				for (j=i+1;j<30;j++) {
					if (FuenteCar[i].turbidez<FuenteCar[j].turbidez) {
						aux=FuenteCar[i].turbidez;
						FuenteCar[i].turbidez=FuenteCar[j].turbidez;
						FuenteCar[j].turbidez=aux;
					}
				}
			}
		return aux;
		}
		
		//Lavapies
		int fmayoramenorLavTurbidez (struct TDatosFuente FuenteLav[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<25;i++) {
				for (j=i+1;j<25;j++) {
					if (FuenteLav[i].turbidez<FuenteLav[j].turbidez) {
						aux=FuenteLav[i].turbidez;
						FuenteLav[i].turbidez=FuenteLav[j].turbidez;
						FuenteLav[j].turbidez=aux;
					}
				}
			}
			return aux;
		}
		
		//Vallecas
		int fmayoramenorVallTurbidez (struct TDatosFuente FuenteVall[]) {
	
			int i,j;
			int aux;
	
			for (i=0;i<27;i++) {
				for (j=i+1;j<27;j++) {
					if (FuenteVall[i].turbidez<FuenteVall[j].turbidez) {
						aux=FuenteVall[i].turbidez;
						FuenteVall[i].turbidez=FuenteVall[j].turbidez;
						FuenteVall[j].turbidez=aux;
					}
				}
			}
		return aux;
		}
		
    //RECORRIDO (FALTA TODO MENOS PH)
	
		//Carabanchel
			float frecorridoCar (struct TDatosFuente FuenteCar[]) {
			
			int i; 
			float mayor=0;
			float menor=14;
			float recorr;
			
			for (i=0;i<30; i++) {
				if (FuenteCar[i].pH>mayor) {
					mayor=FuenteCar[i].pH; 
				}
			}
			
			for (i=0; i<30; i++) {
				if (FuenteCar[i].pH<menor) {
					menor=FuenteCar[i].pH; 
				}
			}
			
			recorr = mayor-menor;
			
			return recorr;
			}
			
		//Lavapies
			float frecorridoLav (struct TDatosFuente FuenteLav[]) {
			int i; 
			float mayor=0;
			float menor=14;
			float recorr;
			
			for (i=0;i<25; i++) {
				if (FuenteLav[i].pH>mayor) {
					mayor=FuenteLav[i].pH; 
				}
			}
			
			for (i=0; i<25; i++) {
				if (FuenteLav[i].pH<menor) {
					menor=FuenteLav[i].pH; 
				}
			}
			
			recorr = mayor-menor;
			
			return recorr;
			}
			
		//Vallecas
			float frecorridoVall (struct TDatosFuente FuenteVall[]) {
			int i; 
			float mayor=0;
			float menor=14;
			float recorr;
			
			for (i=0;i<27; i++) {
				if (FuenteVall[i].pH>mayor) {
					mayor=FuenteVall[i].pH; 
				}
			}
			
			for (i=0; i<27; i++) {
				if (FuenteVall[i].pH<menor) {
					menor=FuenteVall[i].pH; 
				}
			}
			
			recorr = mayor-menor;
			
			return recorr;
			}	

    //MODA (FALTA TODO MENOS PH)

       	//Carabanchel 
        float fmodaCar(struct TDatosFuente FuenteCar[]) {
        int i, j, cont2 = 0, cont1 = 0;
        float aux1;

        for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            if (FuenteCar[i].pH == FuenteCar[j].pH && i != j) {
                cont1++;
            }
        }

        if (cont1 > cont2) {
            cont2 = cont1;
            aux1 = FuenteCar[i].pH;
        }

           cont1 = 0;
        }

    return aux1;  
        }
		
		//Lavapiés
        float fmodaLav(struct TDatosFuente FuenteLav[]) {
        int i, j, cont2 = 0, cont1 = 0;
        float aux2;

        for (i = 0; i < 25; i++) {
        for (j = 0; j < 25; j++) {
            if (FuenteLav[i].pH == FuenteLav[j].pH && i != j) {
                cont1++;
            }
        }

        if (cont1 > cont2) {
            cont2 = cont1;
            aux2 = FuenteLav[i].pH;
        }

        cont1 = 0;
    }

    return aux2;  
}

    	//Vallecas
    	float fmodaVall(struct TDatosFuente FuenteVall[]) {
		    int i, j, cont2 = 0, cont1 = 0;
		    float aux3;
		
		    for (i = 0; i < 30; i++) {
		        for (j = 0; j < 30; j++) {
		            if (FuenteVall[i].pH == FuenteVall[j].pH && i != j) {
		                cont1++;
		            }
		        }
		
		        if (cont1 > cont2) {
		            cont2 = cont1;
		            aux3 = FuenteVall[i].pH;
		        }
		
		        cont1 = 0;
		    }
		
		    return aux3;  
		}
			
//COMPARAR DATOS
	//MISMO BARRIO
		//pH
			//Carabanchel
			void fcompararpHCar(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
				int i,j,resultado;
				char a[40], b[40]; //esto solucionaba el error que nos salia esta tarde -ale
				float ph1, ph2;
				printf ("Introduce el nombre de la primera fuente a comparar. Por ejemplo, Fuente_4.\n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente a comparar. Por ejemplo, Fuente_5. \n");
				scanf ("%s", b);
				for (i=0; i<NumFuentesCar; i++) {
					resultado = strcmp(a, FuenteCar[i].fuente);
					if (resultado == 0){
					ph1=FuenteCar[i].pH;
					}
				}
				
				for (j=0; j<NumFuentesCar; j++) {
					resultado = strcmp(b, FuenteCar[j].fuente);
					if (resultado == 0){
					ph2=FuenteCar[j].pH;
					}
				}
				if (ph1<ph2) {
					printf ("El pH de la %s: %.2f es menor que el de la %s: %.2f", a, ph1, b, ph2);
				} else if (ph1>ph2) {
					printf ("El pH de la %s: %.2f es mayor que el de la %s: %.2f \n", a, ph1, b, ph2);
				} else if (ph1==ph2) {
					printf ("La %s, %.2f y la %s: %.2f tienen el mismo pH", a, ph1, b, ph2);
				}
			}
			
			//Lavapiés
			void fcompararpHLav(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
				int i, j, resultado; 
				char a[40], b[40]; 
				float ph1, ph2; 
				printf ("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
				scanf("%s",b);
				for (i=0; i<NumFuentesLav; i++) {
					resultado = strcmp(a, FuenteLav[i].fuente);
					if (resultado == 0){
					ph1=FuenteLav[i].pH;
					}
				}
				
				for (j=0; j<NumFuentesLav; j++) {
					resultado = strcmp(b, FuenteLav[j].fuente);
					if (resultado == 0){
					ph2=FuenteLav[j].pH;
					}
				}
				
				if (ph1<ph2) {
					printf ("El pH de la %s: %.2f es menor que el de la %s: %.2f", a, ph1, b, ph2);
				} else if (ph1>ph2) {
					printf ("El pH de la %s: %.2f es mayor que el de la %s: %.2f \n", a, ph1, b, ph2);
				} else if (ph1==ph2) {
					printf ("La %s, %.2f y la %s: %.2f tienen el mismo pH", a, ph1, b, ph2);
				}
			}
			
			//Vallecas
			void fcompararpHVall(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
				int i, j, resultado; 
				char a[40], b[40]; 
				float ph1, ph2; 
				printf ("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
				scanf("%s",b);
				for (i=0; i<NumFuentesVall; i++) {
					resultado = strcmp(a, FuenteVall[i].fuente);
					if (resultado == 0){
					ph1=FuenteVall[i].pH;
					}
				}
				
				for (j=0; j<NumFuentesVall; j++) {
					resultado = strcmp(b, FuenteVall[j].fuente);
					if (resultado == 0){
					ph2=FuenteVall[j].pH;
					}
				}
				
				if (ph1<ph2) {
					printf ("El pH de la %s: %.2f es menor que el de la %s: %.2f", a, ph1, b, ph2);
				} else if (ph1>ph2) {
					printf ("El pH de la %s: %.2f es mayor que el de la %s: %.2f \n", a, ph1, b, ph2);
				} else if (ph1==ph2) {
					printf ("La %s, %.2f y la %s: %.2f tienen el mismo pH", a, ph1, b, ph2);
				}
			}
		
		//Conductividad
			//Carabanchel
			void fcompararConductividadCar(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
				int i,j,resultado;
				char a[40], b[40]; 
				int conductividad1, conductividad2;
				printf ("Introduce el nombre de la primera fuente a comparar. Por ejemplo, Fuente_4.\n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente a comparar. Por ejemplo, Fuente_5. \n");
				scanf ("%s", b);
				for (i=0; i<NumFuentesCar; i++) {
					resultado = strcmp(a, FuenteCar[i].fuente);
					if (resultado == 0){
					conductividad1=FuenteCar[i].conductividad;
					}
				}
				
				for (j=0; j<NumFuentesCar; j++) {
					resultado = strcmp(b, FuenteCar[j].fuente);
					if (resultado == 0){
					conductividad2=FuenteCar[j].conductividad;
					}
				}
				if (conductividad1<conductividad2) {
					printf ("La conductividad de la %s: %.2f es menor que la de la %s: %.2f", a, conductividad1, b, conductividad2);
				} else if (conductividad1>conductividad2) {
					printf ("La conductividad de la %s: %.2f es mayor que la de la %s: %.2f \n", a, conductividad1, b, conductividad2);
				} else if (conductividad1==conductividad2) {
					printf ("La %s, %d y la %s: %d tienen la misma conductividad", a, conductividad1, b, conductividad2);
				}
			}
			
			//Lavapiés
			void fcompararConductividadLav(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
				int i, j, resultado; 
				char a[40], b[40]; 
				int conductividad1, conductividad2; 
				printf ("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
				scanf("%s",b);
				for (i=0; i<NumFuentesLav; i++) {
					resultado = strcmp(a, FuenteLav[i].fuente);
					if (resultado == 0){
					conductividad1=FuenteLav[i].conductividad;
					}
				}
				
				for (j=0; j<NumFuentesLav; j++) {
					resultado = strcmp(b, FuenteLav[j].fuente);
					if (resultado == 0){
					conductividad2=FuenteLav[j].conductividad;
					}
				}
				
				if (conductividad1<conductividad2) {
					printf ("La conductividad de la %s: %d es menor que la de la %s: %.2f", a, conductividad1, b, conductividad2);
				} else if (conductividad1>conductividad2) {
					printf ("La conductividad de la %s: %d es mayor que la de la %s: %.2f \n", a, conductividad1, b, conductividad2);
				} else if (conductividad1==conductividad2) {
					printf ("La conductividad %s, %d y la %s: %d tienen la misma conductividad", a, conductividad1, b, conductividad2);
				}
			}
			
			//Vallecas
				void fcompararConductividadVall(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
				int i, j, resultado; 
				char a[40], b[40]; 
				int conductividad1, conductividad2; 
				printf ("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
				scanf("%s",b);
				for (i=0; i<NumFuentesVall; i++) {
					resultado = strcmp(a, FuenteVall[i].fuente);
					if (resultado == 0){
					conductividad1=FuenteVall[i].conductividad;
					}
				}
				
				for (j=0; j<NumFuentesVall; j++) {
					resultado = strcmp(b, FuenteVall[j].fuente);
					if (resultado == 0){
					conductividad2=FuenteVall[j].conductividad;
					}
				}
				
				if (conductividad1<conductividad2) {
					printf ("La conductividad de la %s: %d es menor que la de la %s: %.2f", a, conductividad1, b, conductividad2);
				} else if (conductividad1>conductividad2) {
					printf ("La conductividad de la %s: %d es mayor que la de la %s: %.2f \n", a, conductividad1, b, conductividad2);
				} else if (conductividad1==conductividad2) {
					printf ("La conductividad %s, %d y la %s: %d tienen la misma conductividad", a, conductividad1, b, conductividad2);
				}
			}
		
		//Turbidez
			//Carabanchel
			void fcompararTurbidezCar(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
				int i,j,resultado;
				char a[40], b[40]; //esto solucionaba el error que nos salia esta tarde -ale
				int turbidez1, turbidez2;
				printf ("Introduce el nombre de la primera fuente a comparar. Por ejemplo, Fuente_4.\n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente a comparar. Por ejemplo, Fuente_5. \n");
				scanf ("%s", b);
				for (i=0; i<NumFuentesCar; i++) {
					resultado = strcmp(a, FuenteCar[i].fuente);
					if (resultado == 0){
					turbidez1=FuenteCar[i].turbidez;
					}
				}
				
				for (j=0; j<NumFuentesCar; j++) {
					resultado = strcmp(b, FuenteCar[j].fuente);
					if (resultado == 0){
					turbidez2=FuenteCar[j].turbidez;
					}
				}
				if (turbidez1<turbidez2) {
					printf ("La turbidez de la %s: %d es menor que la de la %s: %d", a, turbidez1, b, turbidez2);
				} else if (turbidez1>turbidez2) {
					printf ("La turbidez de la %s: %d es mayor que el de la %s: %d \n", a, turbidez1, b, turbidez2);
				} else if (turbidez1==turbidez2) {
					printf ("La %s, %d y la %s: %d tienen la misma pH", a, turbidez1, b, turbidez2);
				}
			}
			
			//Lavapiés
			void fcompararTurbidezLav(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
				int i, j, resultado; 
				char a[40], b[40]; 
				int turbidez1, turbidez2; 
				printf ("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
				scanf("%s",b);
				for (i=0; i<NumFuentesLav; i++) {
					resultado = strcmp(a, FuenteLav[i].fuente);
					if (resultado == 0){
					turbidez1=FuenteLav[i].turbidez;
					}
				}
				
				for (j=0; j<NumFuentesLav; j++) {
					resultado = strcmp(b, FuenteLav[j].fuente);
					if (resultado == 0){
					turbidez2=FuenteLav[j].turbidez;
					}
				}
				
				if (turbidez1<turbidez2) {
					printf ("La turbidez de la %s: %d es menor que la de la %s: %d", a, turbidez1, b, turbidez2);
				} else if (turbidez1>turbidez2) {
					printf ("La turbidez de la %s: %d es mayor que el de la %s: %d \n", a, turbidez1, b, turbidez2);
				} else if (turbidez1==turbidez2) {
					printf ("La %s, %d y la %s: %d tienen la misma pH", a, turbidez1, b, turbidez2);
				}
			}
			
			//Vallecas
			void fcompararTurbidezVall(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
				int i, j, resultado; 
				char a[40], b[40]; 
				int turbidez1, turbidez2; 
				printf ("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
				scanf("%s",b);
				for (i=0; i<NumFuentesVall; i++) {
					resultado = strcmp(a, FuenteVall[i].fuente);
					if (resultado == 0){
					turbidez1=FuenteVall[i].turbidez;
					}
				}
				
				for (j=0; j<NumFuentesVall; j++) {
					resultado = strcmp(b, FuenteVall[j].fuente);
					if (resultado == 0){
					turbidez2=FuenteVall[j].turbidez;
					}
				}
				
				if (turbidez1<turbidez2) {
					printf ("La turbidez de la %s: %d es menor que la de la %s: %d", a, turbidez1, b, turbidez2);
				} else if (turbidez1>turbidez2) {
					printf ("La turbidez de la %s: %d es mayor que el de la %s: %d \n", a, turbidez1, b, turbidez2);
				} else if (turbidez1==turbidez2) {
					printf ("La %s, %d y la %s: %d tienen la misma pH", a, turbidez1, b, turbidez2);
				}
			}
		
		//Coliformes	
			//Carabanchel
			void fcompararColiformesCar(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
				int i,j,resultado;
				char a[40], b[40]; //esto solucionaba el error que nos salia esta tarde -ale
				int coliformes1, coliformes2;
				printf ("Introduce el nombre de la primera fuente a comparar. Por ejemplo, Fuente_4.\n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente a comparar. Por ejemplo, Fuente_5. \n");
				scanf ("%s", b);
				for (i=0; i<NumFuentesCar; i++) {
					resultado = strcmp(a, FuenteCar[i].fuente);
					if (resultado == 0){
					coliformes1=FuenteCar[i].coliformes;
					}
				}
				
				for (j=0; j<NumFuentesCar; j++) {
					resultado = strcmp(b, FuenteCar[j].fuente);
					if (resultado == 0){
					coliformes2=FuenteCar[j].coliformes;
					}
				}
				if (coliformes1<coliformes2) {
					printf ("Los coliformes de la %s: %d son menores que los de la %s: %d", a, coliformes1, b, coliformes2);
				} else if (coliformes1>coliformes2) {
					printf ("Los coliformes de la %s: %d son mayores que los de la %s: %d \n", a, coliformes1, b, coliformes2);
				} else if (coliformes1==coliformes2) {
					printf ("La %s, %d y la %s: %d tienen los mismos coliformes", a, coliformes1, b, coliformes2);
				}
			}
			
			//Lavapiés
			void fcompararColiformesLav(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
				int i, j, resultado; 
				char a[40], b[40]; 
				int coliformes1, coliformes2; 
				printf ("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
				scanf("%s",b);
				for (i=0; i<NumFuentesLav; i++) {
					resultado = strcmp(a, FuenteLav[i].fuente);
					if (resultado == 0){
					coliformes1=FuenteLav[i].coliformes;
					}
				}
				
				for (j=0; j<NumFuentesLav; j++) {
					resultado = strcmp(b, FuenteLav[j].fuente);
					if (resultado == 0){
					coliformes2=FuenteLav[j].coliformes;
					}
				}
				
				if (coliformes1<coliformes2) {
					printf ("Los coliformes de la %s: %d son menores que los de la %s: %d \n", a, coliformes1, b, coliformes2);
				} else if (coliformes1>coliformes2) {
					printf ("Los coliformes de la %s: %d son mayores que los de la %s: %d \n", a, coliformes1, b, coliformes2);
				} else if (coliformes1==coliformes2) {
					printf ("La %s, %d y la %s: %d tienen los mismos coliformes \n", a, coliformes1, b, coliformes2);
				}
			}
			
			//Vallecas
			void fcompararColiformesVall(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
				int i, j, resultado; 
				char a[40], b[40]; 
				int coliformes1, coliformes2; 
				printf ("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
				scanf ("%s", a);
				printf ("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
				scanf("%s",b);
				for (i=0; i<NumFuentesVall; i++) {
					resultado = strcmp(a, FuenteVall[i].fuente);
					if (resultado == 0){
					coliformes1=FuenteVall[i].coliformes;
					}
				}
				
				for (j=0; j<NumFuentesVall; j++) {
					resultado = strcmp(b, FuenteVall[j].fuente);
					if (resultado == 0){
					coliformes2=FuenteVall[j].coliformes;
					}
				}
				
				if (coliformes1<coliformes2) {
					printf ("Los coliformes de la %s: %d son menores que los de la %s: %d \n", a, coliformes1, b, coliformes2);
				} else if (coliformes1>coliformes2) {
					printf ("Los coliformes de la %s: %d son mayores que los de la %s: %d \n", a, coliformes1, b, coliformes2);
				} else if ( coliformes1== coliformes2) {
					printf ("La %s, %d y la %s: %d tienen los mismos coliformes \n", a, coliformes1, b, coliformes2);
				}
			}

	//DIFERENTE BARRIO (FALTA TODO MENOS PH)
		//pH
			//lAVAPIES-CARABANCHEL
			void fcompararpHLavCar(struct TDatosFuente FuenteLav[], int NumFuentesLav, struct TDatosFuente FuenteCar[], int NumFuentesCar) {
			    int i, j, resultado;
			    char a[40], b[40];
			    float ph1 = 0, ph2 = 0;
			    
			    printf("Introduce el nombre de la fuente correspondiente a Lavapies. Por ejemplo, Fuente_4.\n");
			    scanf("%s", a);
			    printf("Introduce el nombre de la fuente correspondiente a Carabanchel. Por ejemplo, Fuente_5.\n");
			    scanf("%s", b);
			    
			    for (i = 0; i < NumFuentesLav; i++) {
			        resultado = strcmp(a, FuenteLav[i].fuente);
			        if (resultado == 0) {
			            ph1 = FuenteLav[i].pH;
			            break;  // Salir del bucle una vez se encuentra el pH de la fuente de Lavapies
			        }
			    }
			    
			    for (j = 0; j < NumFuentesCar; j++) {
			        resultado = strcmp(b, FuenteCar[j].fuente);
			        if (resultado == 0) {
			            ph2 = FuenteCar[j].pH;
			            break;  // Salir del bucle una vez se encuentra el pH de la fuente de Carabanchel
			        }
			    }
			    
			    if (ph1 < ph2) {
			        printf("El pH de la %s: %.2f de Lavapies es menor que el de la %s: %.2f de Carabanchel\n", a, ph1, b, ph2);
			    } else if (ph1 > ph2) {
			        printf("El pH de la %s: %.2f de Lavapies es mayor que el de la %s: %.2f de Carabanchel\n", a, ph1, b, ph2);
			    } else if (ph1 == ph2) {
			        printf("La %s: %.2f de Lavapies y la %s: %.2f de Carabanchel tienen el mismo pH\n", a, ph1, b, ph2);
			    }
			}
			
			//LAVAPIES-VALLECAS
			void fcompararpHLavVall(struct TDatosFuente FuenteLav[], int NumFuentesLav, struct TDatosFuente FuenteVall[], int NumFuentesVall) {
			    int i, j, resultado;
			    char a[40], b[40];
			    float ph1 = 0, ph2 = 0;
	
			    printf("Introduce el nombre de la fuente correspondiente a Lavapies. Por ejemplo, Fuente_4.\n");
			    scanf("%s", a);
			    printf("Introduce el nombre de la fuente correspondiente a Vallecas. Por ejemplo, Fuente_5.\n");
			    scanf("%s", b);
			    
			    for (i = 0; i < NumFuentesLav; i++) {
			        resultado = strcmp(a, FuenteLav[i].fuente);
			        if (resultado == 0) {
			            ph1 = FuenteLav[i].pH;
			            break;  // Salir del bucle una vez se encuentra el pH de la fuente de Lavapies
			        }
			    }
			    
			    for (j = 0; j < NumFuentesVall; j++) {
			        resultado = strcmp(b, FuenteVall[j].fuente);
			        if (resultado == 0) {
			            ph2 = FuenteVall[j].pH;
			            break;  // Salir del bucle una vez se encuentra el pH de la fuente de Carabanchel
			        }
			    }
			    
			    if (ph1 < ph2) {
			        printf("El pH de la %s: %.2f de Lavapies es menor que el de la %s: %.2f de Vallecas\n", a, ph1, b, ph2);
			    } else if (ph1 > ph2) {
			        printf("El pH de la %s: %.2f de Lavapies es mayor que el de la %s: %.2f de Vallecas\n", a, ph1, b, ph2);
			    } else if (ph1 == ph2) {
			        printf("La %s: %.2f de Lavapies y la %s: %.2f de Vallecas tienen el mismo pH\n", a, ph1, b, ph2);
			    }
			}
			
			//CARABANCHEL-VALLECAS
			void fcompararpHCarVall(struct TDatosFuente FuenteCar[], int NumFuentesCar, struct TDatosFuente FuenteVall[], int NumFuentesVall){
			    int i, j, resultado;
			    char a[40], b[40];
			    float ph1 = 0, ph2 = 0;
	
			    printf("Introduce el nombre de la fuente correspondiente a Carabanchel. Por ejemplo, Fuente_4.\n");
			    scanf("%s", a);
			    printf("Introduce el nombre de la fuente correspondiente a Vallecas. Por ejemplo, Fuente_5.\n");
			    scanf("%s", b);
			    
			    for (i = 0; i < NumFuentesCar; i++) {
			        resultado = strcmp(a, FuenteCar[i].fuente);
			        if (resultado == 0) {
			            ph1 = FuenteCar[i].pH;
			            break;  // Salir del bucle una vez se encuentra el pH de la fuente de Lavapies
			        }
			    }
			    
			    for (j = 0; j < NumFuentesVall; j++) {
			        resultado = strcmp(b, FuenteVall[j].fuente);
			        if (resultado == 0) {
			            ph2 = FuenteVall[j].pH;
			            break;  // Salir del bucle una vez se encuentra el pH de la fuente de Carabanchel
			        }
			    }
			    
			    if (ph1 < ph2) {
			        printf("El pH de la %s: %.2f de Carabanchel es menor que el de la %s: %.2f de Vallecas\n", a, ph1, b, ph2);
			    } else if (ph1 > ph2) {
			        printf("El pH de la %s: %.2f de Carabanchel es mayor que el de la %s: %.2f de Vallecas\n", a, ph1, b, ph2);
			    } else if (ph1 == ph2) {
			        printf("La %s: %.2f de Carabanchel y la %s: %.2f de Vallecas tienen el mismo pH\n", a, ph1, b, ph2);
			    }
			}
			
//MEDIA
	//pH
		//Car
			float fmediapHCar(struct TDatosFuente FuenteCar[], int NumFuentesCar){
				int i;
				float mediapH = 0, mediapHCar;
				for(i=0; i<NumFuentesCar; i++){
					mediapH += FuenteCar[i].pH;
				}
				mediapHCar = mediapH / 30;
				return mediapHCar;
			}
		//Lav
			float fmediapHLav(struct TDatosFuente FuenteLav[], int NumFuentesLav){
				int i;
				float mediapH = 0, mediapHLav;
				for(i=0; i<NumFuentesLav; i++){
					mediapH += FuenteLav[i].pH;
				}
				mediapHLav = mediapH / 25;
				return mediapHLav;
			}
		//Vall
			float fmediapHVall(struct TDatosFuente FuenteVall[], int NumFuentesVall){
				int i;
				float mediapH = 0, mediapHVall;
				for(i=0; i<NumFuentesVall; i++){
					mediapH += FuenteVall[i].pH;
				}
				mediapHVall = mediapH / 27;
				return mediapHVall;
			}
			
	//Conductividad
		//Car
			float fmediaConCar(struct TDatosFuente FuenteCar[], int NumFuentesCar){
				int i;
				float mediaCon = 0, mediaConCar;
				for(i=0; i<NumFuentesCar; i++){
					mediaCon += FuenteCar[i].conductividad;
				}
				mediaConCar = mediaCon / 30;
				return mediaConCar;
			}
		//Lav
			float fmediaConLav(struct TDatosFuente FuenteLav[], int NumFuentesLav){
				int i;
				float mediaCon = 0, mediaConLav;
				for(i=0; i<NumFuentesLav; i++){
					mediaCon += FuenteLav[i].conductividad;
				}
				mediaConLav = mediaCon / 25;
				return mediaConLav;
			}
		//Vall
			float fmediaConVall(struct TDatosFuente FuenteVall[], int NumFuentesVall){
				int i;
				float mediaCon = 0, mediaConVall;
				for(i=0; i<NumFuentesVall; i++){
					mediaCon += FuenteVall[i].conductividad;
				}
				mediaConVall = mediaCon / 27;
				return mediaConVall;
			}
			
	//Turbidez
		//Car
			float fmediaTurCar(struct TDatosFuente FuenteCar[], int NumFuentesCar){
				int i;
				float mediaTur = 0, mediaTurCar;
				for(i=0; i<NumFuentesCar; i++){
					mediaTur += FuenteCar[i].turbidez;
				}
				mediaTurCar = mediaTur / 30;
				return mediaTurCar;
			}
		//Lav
			float fmediaTurLav(struct TDatosFuente FuenteLav[], int NumFuentesLav){
				int i;
				float mediaTur = 0, mediaTurLav;
				for(i=0; i<NumFuentesLav; i++){
					mediaTur += FuenteLav[i].turbidez;
				}
				mediaTurLav = mediaTur / 25;
				return mediaTurLav;
			}
		//Vall
			float fmediaTurVall(struct TDatosFuente FuenteVall[], int NumFuentesVall){
				int i;
				float mediaTur = 0, mediaTurVall;
				for(i=0; i<NumFuentesVall; i++){
					mediaTur += FuenteVall[i].turbidez;
				}
				mediaTurVall = mediaTur / 27;
				return mediaTurVall;
			}
					
//DESVIACION
	//pH
		//Car
			float fdespHCar(struct TDatosFuente FuenteCar[], float mediapHCar, int NumFuentesCar){
				int i;
				float sumdespH = 0, despHCar=0;
				for(i=0; i<NumFuentesCar; i++){
					sumdespH += (FuenteCar[i].pH - mediapHCar)*(FuenteCar[i].pH - mediapHCar);
				}
				despHCar = sqrt(sumdespH/NumFuentesCar);
				return despHCar;
			}
		//Lav
			float fdespHLav(struct TDatosFuente FuenteLav[], float mediapHLav, int NumFuentesLav){
				int i;
				float sumdespH = 0, despHLav=0;
				for(i=0; i<NumFuentesLav; i++){
					sumdespH += (FuenteLav[i].pH - mediapHLav)*(FuenteLav[i].pH - mediapHLav);
				}
				despHLav = sqrt(sumdespH/NumFuentesLav);
				return despHLav;
			}
		//Vall
			float fdespHVall(struct TDatosFuente FuenteVall[], float mediapHVall, int NumFuentesVall){
				int i;
				float sumdespH = 0, despHVall=0;
				for(i=0; i<NumFuentesVall; i++){
					sumdespH += (FuenteVall[i].pH - mediapHVall)*(FuenteVall[i].pH - mediapHVall);
				}
				despHVall = sqrt(sumdespH/NumFuentesVall);
				return despHVall;
			}
			
	//Conductividad
		//Car
			float fdesConCar(struct TDatosFuente FuenteCar[], float mediaConCar, int NumFuentesCar){
				int i;
				float sumdesCon = 0, desConCar=0;
				for(i=0; i<NumFuentesCar; i++){
					sumdesCon += (FuenteCar[i].conductividad - mediaConCar)*(FuenteCar[i].conductividad - mediaConCar);
				}
				desConCar = sqrt(sumdesCon/NumFuentesCar);
				return desConCar;
			}
		//Lav
			float fdesConLav(struct TDatosFuente FuenteLav[], float mediaConLav, int NumFuentesLav){
				int i;
				float sumdesCon = 0, desConLav=0;
				for(i=0; i<NumFuentesLav; i++){
					sumdesCon += (FuenteLav[i].conductividad - mediaConLav)*(FuenteLav[i].conductividad - mediaConLav);
				}
				desConLav = sqrt(sumdesCon/NumFuentesLav);
				return desConLav;
			}
		//Vall
			float fdesConVall(struct TDatosFuente FuenteVall[], float mediaConVall, int NumFuentesVall){
				int i;
				float sumdesCon = 0, desConVall=0;
				for(i=0; i<NumFuentesVall; i++){
					sumdesCon += (FuenteVall[i].conductividad - mediaConVall)*(FuenteVall[i].conductividad - mediaConVall);
				}
				desConVall = sqrt(sumdesCon/NumFuentesVall);
				return desConVall;
			}
			
	//Turbidez
		//Car
			float fdesTurCar(struct TDatosFuente FuenteCar[], float mediaTurCar, int NumFuentesCar){
				int i;
				float sumdesTur = 0, desTurCar=0;
				for(i=0; i<NumFuentesCar; i++){
					sumdesTur += (FuenteCar[i].turbidez - mediaTurCar)*(FuenteCar[i].turbidez - mediaTurCar);
				}
				desTurCar = sqrt(sumdesTur/NumFuentesCar);
				return desTurCar;
			}
		//Lav
			float fdesTurLav(struct TDatosFuente FuenteLav[], float mediaTurLav, int NumFuentesLav){
				int i;
				float sumdesTur = 0, desTurLav=0;
				for(i=0; i<NumFuentesLav; i++){
					sumdesTur += (FuenteLav[i].turbidez - mediaTurLav)*(FuenteLav[i].turbidez - mediaTurLav);
				}
				desTurLav = sqrt(sumdesTur/NumFuentesLav);
				return desTurLav;
			}
		//Vall
			float fdesTurVall(struct TDatosFuente FuenteVall[], float mediaTurVall, int NumFuentesVall){
				int i;
				float sumdesTur = 0, desTurVall=0;
				for(i=0; i<NumFuentesVall; i++){
					sumdesTur += (FuenteVall[i].turbidez - mediaTurVall)*(FuenteVall[i].turbidez - mediaTurVall);
				}
				desTurVall = sqrt(sumdesTur/NumFuentesVall);
				return desTurVall;
			}	
			
//BUSCAR FUENTE
	//Car
		void fBuscarCar(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
			int i,j,resultado;
			int con, tur, col;
			char a[40], b[40];
			float pH;
			printf ("Introduce el nombre de la fuente que quieres buscar. Por ejemplo: Fuente_4\n");
			scanf ("%s", a);
			for (i=0; i<NumFuentesCar; i++) {
				resultado = strcmp(a, FuenteCar[i].fuente);
				if (resultado == 0) {
				pH = FuenteCar[i].pH;
				con = FuenteCar[i].conductividad;
				tur = FuenteCar[i].turbidez;
				col = FuenteCar[i].coliformes;
				}
			}
			printf("El pH de la fuente es: %.2f \n", pH);
			printf("La conductividad de la fuente es: %d \n", con);
			printf("La turbidez fuente es: %d \n", tur);
			printf("Los coliformes de la fuente es: %d \n\n", col);
		}
			
	//Lav
		void fBuscarLav(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
			int i,j,resultado;
			int con, tur, col;
			char a[40], b[40];
			float pH;
			printf ("Introduce el nombre de la fuente que quieres buscar. Por ejemplo: Fuente_4\n");
			scanf ("%s", a);
			for (i=0; i<NumFuentesLav; i++) {
				resultado = strcmp(a, FuenteLav[i].fuente);
				if (resultado == 0) {
				pH = FuenteLav[i].pH;
				con = FuenteLav[i].conductividad;
				tur = FuenteLav[i].turbidez;
				col = FuenteLav[i].coliformes;
				}
			}
			printf("El pH de la fuente es: %.2f \n", pH);
			printf("La conductividad de la fuente es: %d \n", con);
			printf("La turbidez fuente es: %d \n", tur);
			printf("Los coliformes de la fuente es: %d \n\n", col);
		}
		
	//Vall
		void fBuscarVall(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
			int i,j,resultado;
			int con, tur, col;
			char a[40], b[40];
			float pH;
			printf ("Introduce el nombre de la fuente que quieres buscar. Por ejemplo: Fuente_4\n");
			scanf ("%s", a);
			for (i=0; i<NumFuentesVall; i++) {
				resultado = strcmp(a, FuenteVall[i].fuente);
				if (resultado == 0) {
				pH = FuenteVall[i].pH;
				con = FuenteVall[i].conductividad;
				tur = FuenteVall[i].turbidez;
				col = FuenteVall[i].coliformes;
				}
			}
			printf("El pH de la fuente es: %.2f \n", pH);
			printf("La conductividad de la fuente es: %d \n", con);
			printf("La turbidez fuente es: %d \n", tur);
			printf("Los coliformes de la fuente es: % \n\n", col);
		}	
		
		
