#include <stdio.h> 

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
	
	float pH, mediapHCar, mediapHLav, mediapHVall;
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
	mediapHCar = fmediapHCar(FuenteCar);
	mediapHLav = fmediapHLav(FuenteLav);
	mediapHVall = fmediapHVall(FuenteVall);
	
	
	printf("La de media de pH de Carabanchel es: %.2f\n", mediapHCar);
	printf("La de media de pH de Carabanchel es: %.2f\n", mediapHLav);
	printf("La de media de pH de Carabanchel es: %.2f\n", mediapHVall);
}

//Falta buscar la forma de meter el numero de fuentes de cada sitio en las funciones sin meter el numero, y asi solo hacer una funcion para media

float fmediapHCar(struct TDatosFuente FuenteCar[]){
	int i;
	float mediapH = 0, mediapHCar;
	for(i=0; i<30; i++){
		mediapH += FuenteCar[i].pH;
	}
	mediapHCar = mediapH / 30;
	return mediapHCar;
}

float fmediapHLav(struct TDatosFuente FuenteLav[]){
	int i;
	float mediapH = 0, mediapHLav;
	for(i=0; i<25; i++){
		mediapH += FuenteLav[i].pH;
	}
	mediapHLav = mediapH / 25;
	return mediapHLav;
}

float fmediapHVall(struct TDatosFuente FuenteVall[]){
	int i;
	float mediapH = 0, mediapHVall;
	for(i=0; i<27; i++){
		mediapH += FuenteVall[i].pH;
	}
	mediapHVall = mediapH / 27;
	return mediapHVall;
}
