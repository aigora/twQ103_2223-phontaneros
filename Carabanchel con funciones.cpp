#include <stdio.h> 

struct TDatosFuente{
	char fuente[500];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};
//prototipos de las funciones
float fmaximo(struct TDatosFuente[]); 
float fminimo(struct TDatosFuente[]);
 
int main(){
	float pH;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int i=0, n, opcion; 
	struct TDatosFuente FuenteCar[500];
	int NumFuentes;
	float maximo=0, minimo=0;
	
	
	FILE *fCarabanchel;
	
	fCarabanchel = fopen("Carabanchel(sinFuente)2.txt", "r"); 
	
	if (fCarabanchel == NULL) {
		printf("ERROR, no se puede abrir el fichero.");
		return 0;
	}
	
	printf("Parametros\t pH\t   Conductividad Turbidez Coliformes\n");
	while(fscanf(fCarabanchel, "%s %f %d %d %d", FuenteCar[i].fuente, &pH, &conductividad, &turbidez, &coliformes)!= EOF){
		printf("%s \t%.2f\t%d\t    %d\t       %d\n", FuenteCar[i].fuente, pH, conductividad, turbidez, coliformes);
		
	//	FuenteCar[i].fuente=fuente;
		FuenteCar[i].pH = pH;
		FuenteCar[i].conductividad = conductividad;
		FuenteCar[i].turbidez = turbidez;
		FuenteCar[i].coliformes = coliformes;
		i++;
	}
	
	fclose(fCarabanchel);
	NumFuentes = i; //No haría falta crear variable NumFuentes ya que es la i al acabar el bucle directamente
	printf("\nEl numero de fuentes es %d\n", NumFuentes);
	
	printf("\n introduce que quieres comparar\n 1: pH \n 2: conductividad \n 3: turbidez \n 4:coliformes \n"); 
	scanf("%d", &opcion); 

	switch (opcion){
		case(1): 
			printf("comparacion de datos de ph\n"); 
			printf("para mostrar maximo escriba 1 y para mostrar minimo escriba 2\n"); 
			scanf("%d", &n);
				
			
			if(n==1) {
				maximo=fmaximo(FuenteCar); 
				printf("el pH maximo es: %f", maximo); 
			}
			
			if(n==2){
				minimo=fminimo(FuenteCar);
				printf("el pH minimo es: %f", minimo);
			}
	}
	return 0;
}

// funciones


	//MAXIMO
	float fmaximo(struct TDatosFuente FuenteCar[]) {
		int i; 
		float mayor=0;
		for (i=0;i<30; i++){
			if(FuenteCar[i].pH>mayor){
				mayor=FuenteCar[i].pH; 
			}
		}
	return mayor; 
	}
	
	//MINIMO
	float fminimo(struct TDatosFuente FuenteCar[]){
		int i; 
		float menor=0;
		for (i=0; i<30; i++){
			if(FuenteCar[i].pH<menor){
				menor=FuenteCar[i].pH; 
			}
		}
	return menor;
	}
