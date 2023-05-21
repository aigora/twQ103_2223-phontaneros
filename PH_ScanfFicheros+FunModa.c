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
float fmodaLavpH(struct TDatosFuente[], int);
float fmodaCarpH(struct TDatosFuente[], int);
float fmodaVallpH(struct TDatosFuente[], int);

float fmodaCarCon(struct TDatosFuente[], int);
float fmodaLavCon(struct TDatosFuente[], int);
float fmodaVallCon(struct TDatosFuente[], int);

float fmodaCarTur(struct TDatosFuente[], int);
float fmodaLavTur(struct TDatosFuente[], int);
float fmodaVallTur(struct TDatosFuente[], int);

float fmodaCarCol(struct TDatosFuente[], int);
float fmodaLavCol(struct TDatosFuente[], int);
float fmodaVallCol(struct TDatosFuente[], int);



int main () {

	//Declaracion de variables
	int op;
	int NumFuentesCar, NumFuentesLav, NumFuentesVall;
	int potable;
	int i=0, n;
	float pH;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int opcion;
	float valor_repetidopH, valor_repetidoCon, valor_repetidoTur, valor_repetidoCol;
	struct TDatosFuente FuenteLav[500];
	struct TDatosFuente FuenteCar[500];
	struct TDatosFuente FuenteVall[500];
	
	
	
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
	
	valor_repetidopH = fmodaCarpH(FuenteCar, NumFuentesCar);
	printf("El pH mas repetido de Carabanchel %.2f \n", valor_repetidopH);
	
	valor_repetidopH = fmodaLavpH(FuenteLav, NumFuentesLav);
	printf("El pH mas repetido de Lavapies es %.2f \n", valor_repetidopH);
	
	valor_repetidopH = fmodaVallpH(FuenteVall, NumFuentesVall);
	printf("El pH mas repetido de Vallecas es %.2f \n", valor_repetidopH);	
	
	valor_repetidoCon = fmodaCarCon(FuenteCar, NumFuentesCar);
	printf("El valor de conductividad mas repetido de Carabanchel es %.2f \n", valor_repetidoCon);
	
	valor_repetidoCon = fmodaLavCon(FuenteLav, NumFuentesLav);
	printf("El valor de conductividad mas repetido de Lavapies es %.2f \n", valor_repetidoCon);
	
	valor_repetidoCon = fmodaVallCon(FuenteVall, NumFuentesVall);
	printf("El valor de conductividad mas repetido de Vallecas es %.2f \n", valor_repetidoCon);
	
	valor_repetidoTur = fmodaCarTur(FuenteCar, NumFuentesCar);
	printf("El valor de turbidez mas repetido de Carabanchel es %.2f \n", valor_repetidoTur);
	
	valor_repetidoTur = fmodaLavTur(FuenteLav, NumFuentesLav);
	printf("El valor de turbidez mas repetido de Lavapies es %.2f \n", valor_repetidoTur);
	
	valor_repetidoTur = fmodaVallTur(FuenteVall, NumFuentesVall);
	printf("El valor de turbidez mas repetido de Vallecas es %.2f \n", valor_repetidoTur);
	
	valor_repetidoCol = fmodaCarCol(FuenteCar, NumFuentesCar);
	printf("El valor de coliformes mas repetido de Carabanchel es %.2f \n", valor_repetidoCol);
	
	valor_repetidoCol = fmodaLavCol(FuenteLav, NumFuentesLav);
	printf("El valor de coliformes mas repetido de Lavapies es %.2f \n", valor_repetidoCol);
	
	valor_repetidoCol = fmodaVallCol(FuenteVall, NumFuentesVall);
	printf("El valor de coliformes mas repetido de Vallecas es %.2f \n", valor_repetidoCol);		
	
	
	//Cerrar ficheros
	fclose (fLavapies);
	fclose (fCarabanchel);
	fclose (fVallecas);

	return 0;
}

//pH
	//Carabanchel
	
	float fmodaCarpH(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux1;
	
	    for (i = 0; i < NumFuentesCar; i++) {
	        for (j = 0; j < NumFuentesCar; j++) {
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
	
	//Lavapies
	
	float fmodaLavpH(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux2;
	
	    for (i = 0; i < NumFuentesLav; i++) {
	        for (j = 0; j < NumFuentesLav; j++) {
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
	
	float fmodaVallpH(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesVall; i++) {
	        for (j = 0; j < NumFuentesVall; j++) {
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

//Conductividad
	//Carabanchel
	float fmodaCarCon(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesCar; i++) {
	        for (j = 0; j < NumFuentesCar; j++) {
	            if (FuenteCar[i].conductividad == FuenteCar[j].conductividad && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteCar[i].conductividad;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}
	
	float fmodaLavCon(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesLav; i++) {
	        for (j = 0; j < NumFuentesLav; j++) {
	            if (FuenteLav[i].conductividad == FuenteLav[j].conductividad && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteLav[i].conductividad;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}
	
	//Vallecas
	float fmodaVallCon(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesVall; i++) {
	        for (j = 0; j < NumFuentesVall; j++) {
	            if (FuenteVall[i].conductividad == FuenteVall[j].conductividad && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteVall[i].conductividad;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}

//Turbidez
	//Carabanchel
	float fmodaCarTur(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesCar; i++) {
	        for (j = 0; j < NumFuentesCar; j++) {
	            if (FuenteCar[i].turbidez == FuenteCar[j].turbidez && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteCar[i].turbidez;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}
	
	//Lavapies
	float fmodaLavTur(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesLav; i++) {
	        for (j = 0; j < NumFuentesLav; j++) {
	            if (FuenteLav[i].turbidez == FuenteLav[j].turbidez && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteLav[i].turbidez;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}
	
	//Vallecas
	float fmodaVallTur(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesVall; i++) {
	        for (j = 0; j < NumFuentesVall; j++) {
	            if (FuenteVall[i].turbidez == FuenteVall[j].turbidez && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteVall[i].turbidez;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}
	
//Coliformes
	//Carabanchel
	float fmodaCarCol(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesCar; i++) {
	        for (j = 0; j < NumFuentesCar; j++) {
	            if (FuenteCar[i].coliformes == FuenteCar[j].coliformes && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteCar[i].coliformes;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}
	
	//Lavapies
	float fmodaLavCol(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesLav; i++) {
	        for (j = 0; j < NumFuentesLav; j++) {
	            if (FuenteLav[i].coliformes == FuenteLav[j].coliformes && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteLav[i].coliformes;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}
	
	//Vallecas
	float fmodaVallCol(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
	    int i, j, cont2 = 0, cont1 = 0;
	    float aux3;
	
	    for (i = 0; i < NumFuentesVall; i++) {
	        for (j = 0; j < NumFuentesVall; j++) {
	            if (FuenteVall[i].coliformes == FuenteVall[j].coliformes && i != j) {
	                cont1++;
	            }
	        }
	
	        if (cont1 > cont2) {
	            cont2 = cont1;
	            aux3 = FuenteVall[i].coliformes;
	        }
	        cont1 = 0;
	    }
	    return aux3;  
	}
