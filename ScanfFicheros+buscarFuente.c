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
	float fmediapHCar(struct TDatosFuente[], int);
	float fmediapHLav(struct TDatosFuente[], int);
	float fmediapHVall(struct TDatosFuente[], int);
	
	float fdespHCar(struct TDatosFuente[], float, int);
	float fdespHLav(struct TDatosFuente[], float, int);
	float fdespHVall(struct TDatosFuente[], float, int);
	
	float fmediaConCar(struct TDatosFuente[], int);
	float fmediaConLav(struct TDatosFuente[], int);
	float fmediaConVall(struct TDatosFuente[], int);
	
	
	float pH, mediapHCar, mediapHLav, mediapHVall, despHCar, despHLav, despHVall;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int i=0, n, opcion; 
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
	
	fBuscarpHCar(FuenteCar, NumFuentesCar);
	fBuscarpHLav(FuenteLav, NumFuentesLav);
	fBuscarpHVall(FuenteVall, NumFuentesVall);
	
	return 0;
}

			void fBuscarpHCar(struct TDatosFuente FuenteCar[], int NumFuentesCar) {
				int i,j,resultado;
				int con, tur, col;
				char a[40], b[40];
				float pH;
				printf ("Introduce el nombre de la fuente que quieres buscar:\n");
				scanf ("%s", a);
				for (i=0; i<NumFuentesCar; i++) {
					resultado = strcmp(a, FuenteCar[i].fuente);
					if (resultado == 0){
					pH = FuenteCar[i].pH;
					con = FuenteCar[i].conductividad;
					tur = FuenteCar[i].turbidez;
					col = FuenteCar[i].coliformes;
					}
				}
				printf("El pH de la fuente es: %.2f\n", pH);
				printf("La conductividad de la fuente es: %d\n", con);
				printf("La turbidez fuente es: %d\n", tur);
				printf("Los coliformes de la fuente es: %d\n\n", col);
			}
			
			void fBuscarpHLav(struct TDatosFuente FuenteLav[], int NumFuentesLav) {
				int i,j,resultado;
				int con, tur, col;
				char a[40], b[40];
				float pH;
				printf ("Introduce el nombre de la fuente que quieres buscar:\n");
				scanf ("%s", a);
				for (i=0; i<NumFuentesLav; i++) {
					resultado = strcmp(a, FuenteLav[i].fuente);
					if (resultado == 0){
					pH = FuenteLav[i].pH;
					con = FuenteLav[i].conductividad;
					tur = FuenteLav[i].turbidez;
					col = FuenteLav[i].coliformes;
					}
				}
				printf("El pH de la fuente es: %.2f\n", pH);
				printf("La conductividad de la fuente es: %d\n", con);
				printf("La turbidez fuente es: %d\n", tur);
				printf("Los coliformes de la fuente es: %d\n\n", col);
			}
			
			void fBuscarpHVall(struct TDatosFuente FuenteVall[], int NumFuentesVall) {
				int i,j,resultado;
				int con, tur, col;
				char a[40], b[40];
				float pH;
				printf ("Introduce el nombre de la fuente que quieres buscar:\n");
				scanf ("%s", a);
				for (i=0; i<NumFuentesVall; i++) {
					resultado = strcmp(a, FuenteVall[i].fuente);
					if (resultado == 0){
					pH = FuenteVall[i].pH;
					con = FuenteVall[i].conductividad;
					tur = FuenteVall[i].turbidez;
					col = FuenteVall[i].coliformes;
					}
				}
				printf("El pH de la fuente es: %.2f\n", pH);
				printf("La conductividad de la fuente es: %d\n", con);
				printf("La turbidez fuente es: %d\n", tur);
				printf("Los coliformes de la fuente es: %d\n\n", col);
			}	

