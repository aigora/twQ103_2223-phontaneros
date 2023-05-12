#include <stdio.h> 
#define NUMFUENTES_CAR 30
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
void menormayor(struct TDatosFuente[]);

void fcompararpHCar (struct TDatosFuente[]);
void fcompararpHLav (struct TDatosFuente[]);
void fcompararpHVal (struct TDatosFuente[]);

int main(){
	float pH;
	int conductividad, turbidez, coliformes;
	char fuente[500];
	int i=0, n, opcion; 
	struct TDatosFuente FuenteCar[500];
	int NumFuentes;
	float maximo=0, minimo=0, menormayor=0;
	char barrio[600];
	int op;
	
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
	printf("Eliga un barrio:\n");
	scanf("%d", &op);
	printf("1-Carabanchel\n2-Lavapies\n3-Vallecas");
	switch (op){
		case(1):
			fcompararpHCar(FuenteCar);
		break;
		case(2):
			fcompararpHLav(FuenteLav);
		break;
		case(3):
			fcompararpHVal(FuenteVal);
		break;
		default;	
			
			
	}

	
	return 0;
}

void fcompararpHCar (struct TDatosFuente FuenteCar [], ){
	int i,j,a,b;
	float ph1, ph2;
	printf("Introduce el numero de la primera fuente.\n");
	scanf("%d", &a);
	printf("Introduce el numero de la segunda fuente.\n");
	scanf("%d", &b);
	for(i=0; i<30; i++){
		
		if(FuenteCar[i].fuente==a){
			ph1=FuenteCar[i].pH;
		}else if (FuenteCar[i].fuente==b){
			ph2=FuenteCar[i].pH;
		}
	}
	if (ph1<ph2){
		printf("El pH de la Fuente_%d es menor que el de la Fuente_%d", a, b);
	}else if (ph1>ph2){
		printf("El pH de la Fuente_%d es mayor que el de la Fuente_%d", a, b);
	}else if (ph1==ph2){
		printf("La fuente %d y la fuente %d tienen el mismo pH", a, b);
	}
}
void fcompararpHLav(struct TDatosFuente FuenteLav[]){
	int i,j,a,b;
	float ph1, ph2;
	printf("Introduce el numero de la primera fuente.\n");
	scanf("%d", &a);
	printf("Introduce el numero de la segunda fuente.\n");
	scanf("%d", &b);
	for(i=0; i<25; i++){
		
		if(FuenteLav[i].fuente==a){
			ph1=FuenteLav[i].pH;
		}else if (FuenteLav[i].fuente==b){
			ph2=FuenteLav[i].pH;
		}
	}
	if (ph1<ph2){
		printf("El pH de la Fuente_%d es menor que el de la Fuente_%d", a, b);
	}else if (ph1>ph2){
		printf("El pH de la Fuente_%d es mayor que el de la Fuente_%d", a, b);
	}else if (ph1==ph2){
		printf("La fuente %d y la fuente %d tienen el mismo pH", a, b);
	}
}
void fcompararpHVal (struct TDatosFuente FuenteVal []){
	int i,j,a,b;
	float ph1, ph2;
	
	printf("Introduce el numero de la primera fuente.\n");
	scanf("%d", &a);
	printf("Introduce el numero de la segunda fuente.\n");
	scanf("%d", &b);
	for(i=0; i<27; i++){
		
		if(FuenteLav[i].fuente==a){
			ph1=FuenteLav[i].pH;
		}else if (FuenteLav[i].fuente==b){
			ph2=FuenteLav[i].pH;
		}
	}
	if (ph1<ph2){
		printf("El pH de la Fuente_%d es menor que el de la Fuente_%d", a, b);
	}else if (ph1>ph2){
		printf("El pH de la Fuente_%d es mayor que el de la Fuente_%d", a, b);
	}else if (ph1==ph2){
		printf("La fuente %d y la fuente %d tienen el mismo pH", a, b);
	}
}
