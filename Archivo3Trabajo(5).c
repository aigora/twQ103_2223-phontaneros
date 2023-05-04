#include <stdio.h> 

struct TDatosFuente{
	char fuente;
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};
 
int main(){
	float pH;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int i=0;
	struct TDatosFuente FuenteCar[500];
	struct TDatosFuente FuenteLav[500];
	int NumFuentesCar, NumFuentesLav;
	
	
	FILE *fCarabanchel;
	
	fCarabanchel = fopen("fCarabanchel.txt", "r"); 
	
	if (fCarabanchel == NULL) {
		printf("ERROR, no se puede abrir el fichero.");
		return 0; 	
	}
	printf("Datos de Carabanche:\n");
	printf("Parametros\tpH\t   Conductividad Turbidez Coliformes\n");
	while(fscanf(fCarabanchel, "%s %f %d %d %d", fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
		printf("%s \t%.2f\t\t%d\t    %d\t       %d\n", fuente, pH, conductividad, turbidez, coliformes);
		FuenteCar[i].fuente = fuente;
		FuenteCar[i].pH = pH;
		FuenteCar[i].conductividad = conductividad;
		FuenteCar[i].turbidez = turbidez;
		FuenteCar[i].coliformes = coliformes;
		i++;
	}
	
	fclose(fCarabanchel);
	NumFuentesCar = i;
	printf("\nEl numero de fuentes de Lavapies es %d\n\n", NumFuentesCar);
	
	
	FILE *fLavapies;

	fLavapies = fopen("fLavapies.txt", "r"); 
	
	if (fLavapies == NULL) {
		printf("ERROR, no se puede abrir el fichero.");
		return 0; 	
	}
	i=0;	
	printf("Datos de Lavapies:\n");
	printf("Parametros\tpH\t   Conductividad Turbidez Coliformes\n");
	while(fscanf(fLavapies, "%s %f %d %d %d", fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
		printf("%s \t%.2f\t\t%d\t    %d\t       %d\n", fuente, pH, conductividad, turbidez, coliformes);
		FuenteLav[i].fuente = fuente;
		FuenteCar[i].pH = pH;
		FuenteLav[i].conductividad = conductividad;
		FuenteLav[i].turbidez = turbidez;
		FuenteLav[i].coliformes = coliformes;
		i++;
	}	
	
	fclose(fLavapies);
	NumFuentesLav = i;
	printf("\nEl numero de fuentes de Carabanchel es %d\n", NumFuentesLav);
	
	return 0;
}
