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

int main() {
	
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
	int o;
	float menoramayor;
	
//Abrir ficheros y escanearlos
    
	//Carabanchel
	FILE *fCarabanchel;
	
	fCarabanchel = fopen("fCarabanchel.txt", "r"); 
	
	if (fCarabanchel == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0;
	}
	
	while (fscanf (fCarabanchel, "%s %f %d %d %d", FuenteCar[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
		
		FuenteCar[i].pH = pH;
		FuenteCar[i].conductividad = conductividad;
		FuenteCar[i].turbidez = turbidez;
		FuenteCar[i].coliformes = coliformes;
		i++;
	}
	fclose (fCarabanchel);
	NumFuentesCar = i; 
	
	//Lavapies
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
	
	//Vallecas
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
	i=0;

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
}

/*
//POTABILIDAD
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
 
    return 0;
}
*/
