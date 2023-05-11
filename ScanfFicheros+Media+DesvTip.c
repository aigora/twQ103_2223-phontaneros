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
	float fmediapHCar(struct TDatosFuente[]);
	float fmediapHLav(struct TDatosFuente[]);
	float fmediapHVall(struct TDatosFuente[]);
	
	float fdespHCar(struct TDatosFuente[], float);
	float fdespHLav(struct TDatosFuente[], float);
	float fdespHVall(struct TDatosFuente[], float);
	
	
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
	NumFuentesCar = i; //No har�a falta crear variable NumFuentes ya que es la i al acabar el bucle directamente
	
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
	mediapHCar = fmediapHCar(FuenteCar);
	mediapHLav = fmediapHLav(FuenteLav);
	mediapHVall = fmediapHVall(FuenteVall);
	
	despHCar = fdespHCar(FuenteCar, mediapHCar);
	despHLav = fdespHLav(FuenteLav, mediapHLav);
	despHVall = fdespHVall(FuenteCar, mediapHVall);
	
	printf("La de media de pH de Carabanchel es: %.2f\n", mediapHCar);
	printf("La de media de pH de Lavapies es: %.2f\n", mediapHLav);
	printf("La de media de pH de Vallecas es: %.2f\n", mediapHVall);
	
	printf("La de desviacion tipica de pH de Carabanchel es: %.2f\n", despHCar);
	printf("La de desviacion tipica de pH de Lavapies es: %.2f\n", despHLav);
	printf("La de desviacion tipica de pH de Vallecas es: %.2f\n", despHVall);
	
	return 0;
}

//Falta buscar la forma de meter el numero de fuentes de cada sitio en las funciones sin meter el numero, y asi solo hacer una funcion para media

float fmediapHCar(struct TDatosFuente FuenteCar[]){
	int i, nFuen = 30;
	float mediapH = 0, mediapHCar;
	for(i=0; i<nFuen; i++){
		mediapH += FuenteCar[i].pH;
	}
	mediapHCar = mediapH / 30;
	return mediapHCar;
}

float fmediapHLav(struct TDatosFuente FuenteLav[]){
	int i, nFuen = 25;
	float mediapH = 0, mediapHLav;
	for(i=0; i<nFuen; i++){
		mediapH += FuenteLav[i].pH;
	}
	mediapHLav = mediapH / 25;
	return mediapHLav;
}

float fmediapHVall(struct TDatosFuente FuenteVall[]){
	int i, nFuen = 27;
	float mediapH = 0, mediapHVall;
	for(i=0; i<nFuen; i++){
		mediapH += FuenteVall[i].pH;
	}
	mediapHVall = mediapH / 27;
	return mediapHVall;
}

float fdespHCar(struct TDatosFuente FuenteCar[], float mediapHCar){
	int i, nFuen = 30;
	float sumdespH = 0, despHCar=0;
	for(i=0; i<nFuen; i++){
		sumdespH += (FuenteCar[i].pH - mediapHCar)*(FuenteCar[i].pH - mediapHCar);
	}
	despHCar = sqrt(sumdespH/nFuen);
	return despHCar;
}

float fdespHLav(struct TDatosFuente FuenteLav[], float mediapHLav){
	int i, nFuen = 25;
	float sumdespH = 0, despHLav=0;
	for(i=0; i<nFuen; i++){
		sumdespH += (FuenteLav[i].pH - mediapHLav)*(FuenteLav[i].pH - mediapHLav);
	}
	despHLav = sqrt(sumdespH/nFuen);
	return despHLav;
}

float fdespHVall(struct TDatosFuente FuenteVall[], float mediapHVall){
	int i, nFuen = 27;
	float sumdespH = 0, despHVall=0;
	for(i=0; i<nFuen; i++){
		sumdespH += (FuenteVall[i].pH - mediapHVall)*(FuenteVall[i].pH - mediapHVall);
	}
	despHVall = sqrt(sumdespH/nFuen);
	return despHVall;
}