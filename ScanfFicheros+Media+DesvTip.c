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
	//FUNCIONES
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
	
	//VARIABLES
	float pH;
	float mediapHCar, mediapHLav, mediapHVall, despHCar, despHLav, despHVall;
	float mediaConCar, mediaConLav, mediaConVall, desConCar, desConLav, desConVall;
	float mediaTurCar, mediaTurLav, mediaTurVall, desTurCar, desTurLav, desTurVall;
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
	NumFuentesCar = i;
	
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
	
	
	//DEFINIR
	mediapHCar = fmediapHCar(FuenteCar, NumFuentesCar);
	mediapHLav = fmediapHLav(FuenteLav, NumFuentesLav);
	mediapHVall = fmediapHVall(FuenteVall, NumFuentesVall);
	
	despHCar = fdespHCar(FuenteCar, mediapHCar, NumFuentesCar);
	despHLav = fdespHLav(FuenteLav, mediapHLav, NumFuentesLav);
	despHVall = fdespHVall(FuenteCar, mediapHVall, NumFuentesVall);
	
	mediaConCar = fmediaConCar(FuenteCar, NumFuentesCar);
	mediaConLav = fmediaConLav(FuenteLav, NumFuentesLav);
	mediaConVall = fmediaConVall(FuenteVall, NumFuentesVall);
	
	desConCar = fdesConCar(FuenteCar, mediaConCar, NumFuentesCar);
	desConLav = fdesConLav(FuenteLav, mediaConLav, NumFuentesLav);
	desConVall = fdesConVall(FuenteCar, mediaConVall, NumFuentesVall);
	
	mediaTurCar = fmediaTurCar(FuenteCar, NumFuentesCar);
	mediaTurLav = fmediaTurLav(FuenteLav, NumFuentesLav);
	mediaTurVall = fmediaTurVall(FuenteVall, NumFuentesVall);
	
	desTurCar = fdesTurCar(FuenteCar, mediaTurCar, NumFuentesCar);
	desTurLav = fdesTurLav(FuenteLav, mediaTurLav, NumFuentesLav);
	desTurVall = fdesTurVall(FuenteCar, mediaTurVall, NumFuentesVall);
	
	
	//IMPRIMIR
	printf("La de media de pH de Carabanchel es: %.2f\n", mediapHCar);
	printf("La de media de pH de Lavapies es: %.2f\n", mediapHLav);
	printf("La de media de pH de Vallecas es: %.2f\n", mediapHVall);
	
	printf("La de desviacion tipica de pH de Carabanchel es: %.2f\n", despHCar);
	printf("La de desviacion tipica de pH de Lavapies es: %.2f\n", despHLav);
	printf("La de desviacion tipica de pH de Vallecas es: %.2f\n", despHVall);
	
	printf("La de media de conductividad de Carabanchel es: %.2f\n", mediaConCar);
	printf("La de media de conductividad de Lavapies es: %.2f\n", mediaConLav);
	printf("La de media de conductividad de Vallecas es: %.2f\n", mediaConVall);
	
	printf("La de desviacion tipica de conductividad de Carabanchel es: %.2f\n", desConCar);
	printf("La de desviacion tipica de conductividad de Lavapies es: %.2f\n", desConLav);
	printf("La de desviacion tipica de conductividad de Vallecas es: %.2f\n", desConVall);
	
	printf("La de media de turbidez de Carabanchel es: %.2f\n", mediaTurCar);
	printf("La de media de turbidez de Lavapies es: %.2f\n", mediaTurLav);
	printf("La de media de turbidez de Vallecas es: %.2f\n", mediaTurVall);
	
	printf("La de desviacion tipica de turbidez de Carabanchel es: %.2f\n", desTurCar);
	printf("La de desviacion tipica de turbidez de Lavapies es: %.2f\n", desTurLav);
	printf("La de desviacion tipica de turbidez de Vallecas es: %.2f\n", desTurVall);
	
	return 0;
}

//FUCIONES

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
