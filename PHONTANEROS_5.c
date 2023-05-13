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

	void fcompararpHCar(struct TDatosFuente[], int);
	void fcompararpHLav(struct TDatosFuente[]); 
	
	void comprobarAgua(struct TDatosFuente[]);
	
		
int main () {

//Declaracion de variables
	int op;
	int NumFuentesCar=0, NumFuentesLav=0, NumFuentesVall=0;
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
	int o;
	float menoramayor;
	
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
	
	for(i=0; i<NumFuentesCar; i++){ //cambie esto tmbien para ver si salia y quite un fallo
	 	//fscanf (fCarabanchel, "%s %f %d %d %d", FuenteCar[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF;
		FuenteCar[i].pH = pH;
		FuenteCar[i].conductividad = conductividad;
		FuenteCar[i].turbidez = turbidez;
		FuenteCar[i].coliformes = coliformes;
		fscanf (fCarabanchel, "%s %f %d %d %d", FuenteCar[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF;
	}
//	rewind(fCarabanchel); intente meter esto para quue el fichero se mostrara entero en opcion1, pero no lo consegui -ale
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
	printf ("4 - Salir del programa \n\n");
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
					do{
						printf ("\nElija un dato a buscar:\n");
						printf ("1 - pH \n");
						printf ("2 - Conductividad \n");
						printf ("3 - Turbidez \n");
						printf ("4 - Coliformes \n");
						scanf ("%d", &op);
					} while (op<1 || op>4);
						
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
				break;
			}
		break;
		
//		//Comparar datos
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
				case (1): 
					do {
					
					printf ("\nComparacion de datos de pH\n\n");
					printf ("Elija una opcion: \n");
					printf ("1 - maximo \n");
					printf ("2 - minimo \n");
					printf ("3 - Comparar pH de 2 fuentes de un mismo barrio \n");
					printf ("4 - Comparar pH de 2 fuentes de barrios diferentes \n");
					scanf ("%d", &op); 
					} while (op<1 || op>5);
					
					switch(op){
						case(1):
							do{
							printf ("Elija un barrio: \n");
							printf ("1 - Carabanchel\n");
							printf ("2 - Lavapies \n");
							printf ("3 - Vallecas \n");
							scanf ("%d", &op); 
							} while (op<1 || op>4);
							switch(op){
								case(1):
									maximo=fmaximoCar(FuenteCar); 
									printf ("El pH maximo es: %f \n", maximo);
								break;
								case(2):
									maximo=fmaximoLav(FuenteLav); 
									printf ("El pH maximo es: %f \n", maximo); 
								break;
								case(3):
									maximo=fmaximoVall(FuenteVall); 
										printf ("El pH maximo es: %f \n", maximo); 
								break;	
							}break;
						case(2):
							do{
							printf ("Elija un barrio: \n");
							printf ("1 - Carabanchel\n");
							printf ("2 - Lavapies \n");
							printf ("3 - Vallecas \n");
							scanf ("%d", &op); 
							}while (op<1 || op>4);
							switch(op){
								case(1):
									minimo=fminimoCar(FuenteCar);
										printf ("El pH minimo es: %f \n", minimo);
									break;
								case(2):
									minimo=fminimoLav(FuenteLav);
										printf ("El pH minimo es: %f \n", minimo);
									break;
								case(3):
									minimo=fminimoVall(FuenteVall);
										printf ("El pH minimo es: %f \n", minimo);
									break;				
							}break;
						case(3):
							do{
							printf ("Elija un barrio: \n");
							printf ("1 - Carabanchel\n");
							printf ("2 - Lavapies \n");
							printf ("3 - Vallecas \n");
							scanf ("%d", &op); 
							}while (op<1 || op>4);
							
							switch(op){
								case(1):
									fcompararpHCar(FuenteCar, NumFuentesCar);	
								break;	
								case (2): 
									fcompararpHLav(FuenteLav); 
								break; 
							//	case(3): 
								//	fcompararpHVall (FuenteVall); 
							//	break; 
							}break;
					}break;
				
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
								scanf("%d", op);
							} while (op<1 || op>2);
							
							switch (op) {
								
								case 1:
									menoramayor=fmenoramayorLav(FuenteLav);
									for(o=0;o<25;o++) {
										printf("%s %.2f \n",FuenteLav[i].fuente, FuenteLav[o].pH);
									}
								break;
								
								case 2:
									
								break;
							}
						break;
						
						//Ordenar conductividad Lavapies
						case 2:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", op);
							} while (op<1 || op>2);
						break;
					
						//Ordenar turbidez Lavapies
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", op);
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
								scanf("%d", op);
							} while (op<1 || op>2);
						break;
						
						//Ordenar conductividad Carabanchel
						case 2:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", op);
							} while (op<1 || op>2);
						break;
					
						//Ordenar turbidez Carabanchel
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", op);
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
								scanf("%d", op);
							} while (op<1 || op>2);
						break;
						
						//Ordenar conductividad Vallecas
						case 2:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", op);
							} while (op<1 || op>2);
						break;
					
						//Ordenar turbidez Vallecas
						case 3:
							do {
								printf("\nSeleccione una opcion:\n");
								printf("1 - De menor a mayor\n");
								printf("2 - De mayor a menor\n\n");
								scanf("%d", op);
							} while (op<1 || op>2);
						break;
					}
				break;
			}
		break;
		
		//Salir del programa
		case 4: 
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
	
			int o,h;
			float aux;
	
			for (o=0;o<30;o++) {
				for (h=o+1;h<30;h++) {
					if (FuenteCar[o].pH>FuenteCar[h].pH) {
						aux=FuenteCar[o].pH;
						FuenteCar[o].pH=FuenteCar[h].pH;
						FuenteCar[h].pH=aux;
					}
				}
			}
			return aux;
			}
		
		//Lavapies
			float fmenoramayorLav (struct TDatosFuente FuenteLav[]) {
	
			int o,h;
			float aux;
	
			for (o=0;o<25;o++) {
				for (h=o+1;h<25;h++) {
					if (FuenteLav[o].pH>FuenteLav[h].pH) {
						aux=FuenteLav[o].pH;
						FuenteLav[o].pH=FuenteLav[h].pH;
						FuenteLav[h].pH=aux;
					}
				}
			}
			return aux;
			}
		
		//Vallecas
			float fmenoramayorVall (struct TDatosFuente FuenteVall[]) {
	
			int o,h;
			float aux;
	
			for (o=0;o<27;o++) {
				for (h=o+1;h<27;h++) {
					if (FuenteVall[o].pH>FuenteVall[h].pH) {
						aux=FuenteVall[o].pH;
						FuenteVall[o].pH=FuenteVall[h].pH;
						FuenteVall[h].pH=aux;
					}
				}
			}
			return aux;
			}
	
	//MAYOR A MENOR

		//Carabanchel
		
		
		//Lavapies
		
		
		//Vallecas
		
	//COMPARAR DATOS
	
		//MISMO BARRIO
			//pH
				//Carabanchel
				void fcompararpHCar (struct TDatosFuente FuenteCar [], int NumFuentesCar){
				int i,j;
				char a[40], b[40]; //esto solucionaba el error que nos salia esta tarde -ale
				float ph1, ph2;
				printf("Introduce el nombre de la primera fuente a comparar. Por ejemplo, Fuente_4.\n");
				scanf("%s", a);
				printf("Introduce el nombre de la segunda fuente a comparar. Por ejemplo, Fuente_5. \n");
				scanf("%s", b);
				for(i=1; i<=NumFuentesCar; i++){
		
					if(FuenteCar[i].fuente==a){
						ph1=FuenteCar[i].pH;
					//	printf("Ph1=%f \n", FuenteCar[i].pH); 
					} 
				}
				for(j=1; j<=NumFuentesCar; j++){
					if(FuenteCar[j].fuente==b){
						ph2=FuenteCar[j].pH;
					}
				}
				if (ph1<ph2){ //el error es que la funcion lee los signos al reves, si ph es menor te va a decir que es mayor, y viceversa -ale
					printf("El pH de la %s es menor que el de la %s", a, b);
				}else if (ph1>ph2){
					printf("El pH de la %s es mayor que el de la %s", a, b);
				}else if (ph1==ph2){
					printf("La %s y la %s tienen el mismo pH", a, b);
				}
			}
				//Lavapiés
				void fcompararpHLav(struct TDatosFuente FuenteLav[]){
					int  n, i; 
					char a[40], b[40]; 
					float ph1, ph2; 
					printf("Introduce el nombre de la primera fuente que quieres comaparar. Por ejemplo: Fuente_4. \n");
					scanf("%s", a);
					printf("Introduce el nombre de la segunda fuente que quieres comparar. Por ejemplo: Fuente_5. \n");
					scanf("%s", b);
					for (i=0; i<25; i++){
						if(FuenteLav[i].fuente==a){
							ph1=FuenteLav[i].pH; 
						}else if (FuenteLav[i].fuente==b){
							ph2=FuenteLav[i].pH; 
						}
					}
					if (ph1<ph2){
						printf("El pH de la %s es menor que el de la %s \n", a, b);
					}else if (ph1>ph2){
						printf("El pH de la %s es mayor que el de la %s \n", a, b);
					}else if (ph1==ph2){
						printf("La %s y la %s tienen el mismo pH", a, b);
					}
				}
		//DIFERENTE BARRIO
		
	
	//ComprobarAgua
	
   /* printf("Introduzca el numero de la fuente");
    scanf("%d", &i);
    
	void comprobarAgua(struct FuenteLav[i].pH, struct FuenteLav[i].conductividad, struct FuenteLav[i].turbidez, struct FuenteLav[i].coliformes){
	if (pH < 6.5 || pH > 8) {
        printf("La fuente %f tiene mal pH\n", FuenteLav[i].pH);
    } else {
        printf("La fuente %f tiene buen pH\n", FuenteLav[i].ph);
    }
    
    if (turbidez > 5) {
        printf("El agua de la fuente %d es turbia\n", FuenteLav[i].turbidez);
    } else {
        printf("El agua de la fuente %d no es turbia\n", FuenteLav[i].turbidez);
    }
    
    if (coliformes == 1) {
        printf("El agua de la fuente %d esta contaminada con coliformes\n", FuenteLav[i].coliformes);
    } else {
        printf("El agua de la fuente %d no esta contaminada \n", FuenteLav[i].coliformes);
    }
    
    if (coliformes == 0 && turbidez <= 5 && pH >= 6.5 && pH <= 8){
        printf("El agua es potable\n");
    } else {
        printf("El agua no es potable\n");
    }
}



//METER ESTO EN UNA FUNCION

/*
	if (pH<6.5 || pH>8) {
		printf ("La fuente %d tiene mal ph\n", i);
	} else {
		printf ("La fuente %d tiene buen ph\n", i);
	}
	
	if (turbidez>5) {
		printf ("El agua de la fuente %d es turbia\n", i);
	} else {
		printf ("El agua de la fuente %d no es turbia\n", i);
	}	
	
	if (coliformes == 1) {
		printf ("El agua de la fuente %d esta contaminada con coliformes\n", i);
	} else {
		printf ("El agua de la fuente %d no esta contaminada \n", i);
	}
	
	if (coliformes==0 && turbidez<=5 && pH>=6.5 && pH<=8){
		printf ("El agua es potable\n");
	} else {
		printf ("El agua no es potable\n");0
	}
	*/
