#include <stdio.h> 
#include <math.h>

struct TDatosFuente {
	char fuente[500];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};

int main(){
	
	void fBuscarCar(struct TDatosFuente[], int);
	void fBuscarLav(struct TDatosFuente[], int);
	void fBuscarVall(struct TDatosFuente[], int);
	
	float pH;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int i=0, n, op; 
	struct TDatosFuente FuenteCar[500];
	struct TDatosFuente FuenteLav[500];
	struct TDatosFuente FuenteVall[500];
	int NumFuentesCar, NumFuentesLav, NumFuentesVall;
	float maximo=0, minimo=0;
	float mediapH(float);
	float desviacionTipica(float);
	
	FILE *fCarabanchel;
	
	fCarabanchel = fopen("fCarabanchel.txt", "r"); 
	
	if (fCarabanchel == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0;
	}
	
	while (fscanf (fCarabanchel, "%s %f %d %d %d", FuenteCar[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
		
	//	FuenteCar[i].fuente=fuente;
		FuenteCar[i].pH = pH;
		FuenteCar[i].conductividad = conductividad;
		FuenteCar[i].turbidez = turbidez;
		FuenteCar[i].coliformes = coliformes;
		i++;
	}
	fclose (fCarabanchel);
	NumFuentesCar = i; //No haría falta crear variable NumFuentes ya que es la i al acabar el bucle directamente
	
	FILE *fLavapies;

	fLavapies = fopen ("fLavapies.txt", "r"); 
	
	if (fLavapies == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0; 	
	}
	i=0;	
	while (fscanf (fLavapies, "%s %f %d %d %d", FuenteLav[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
		//FuenteLav[i].fuente = fuente;
		FuenteLav[i].pH = pH;
		FuenteLav[i].conductividad = conductividad;
		FuenteLav[i].turbidez = turbidez;
		FuenteLav[i].coliformes = coliformes;
		i++;
	}	
	
	fclose (fLavapies);
	NumFuentesLav = i;
	
	FILE *fVallecas;

	fVallecas = fopen ("fVallecas.txt", "r"); 
	
	if (fVallecas == NULL) {
		printf ("ERROR, no se puede abrir el fichero.");
		return 0; 	
	}
	i=0;	
	while (fscanf (fVallecas, "%s %f %d %d %d", FuenteVall[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
		//FuenteLav[i].fuente = fuente;
		FuenteVall[i].pH = pH;
		FuenteVall[i].conductividad = conductividad;
		FuenteVall[i].turbidez = turbidez;
		FuenteVall[i].coliformes = coliformes;
		i++;
	}	
	
	fclose (fVallecas);
	NumFuentesVall = i;

	do {
		printf ("Introduzca una opcion: \n\n");
		printf ("1 - Carabanchel \n");
		printf ("2 - Lavapies \n");
		printf ("3 - Vallecas \n");
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
	return 0;
}

//FUNCIONES
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
