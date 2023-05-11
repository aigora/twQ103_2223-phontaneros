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
	int i=0, n;
	float pH;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int opcion;
	float maximo, minimo;
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

	float menoramayor;
	menoramayor=fmenoramayorLav(FuenteLav);
	for(i=0;i<25;i++) {
		printf("%s: ", FuenteLav[i].fuente);
		printf("%.2f \n",FuenteLav[i].pH);
	}
		
		
	//Cerrar ficheros
	fclose (fLavapies);
	fclose (fCarabanchel);
	fclose (fVallecas);

	return 0;
}

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
