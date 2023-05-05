#include <stdio.h>

float recorrido (float mayor, float menor); 

int main(){
	float num, mayor, menor,i,reco1;
	for(i=0; i<5; i++){
		printf("Dime el ph de la fuente: ");
		scanf("%f",&num);
		if (i==0) {
			mayor = num;
			menor = num;
		}
		else{
			if (num>mayor) mayor=num;
			if (num<menor) menor=num;
		}
	}
	printf("el numero mayor era %f\nel numero menor era %f \n", mayor, menor);
	
	reco1 = recorrido(mayor,menor);
	
	printf ("el recorrido es %f\n",reco1);
	
	printf("\n\n\n");
	return 0;
}
float recorrido (float mayor, float menor){
	
	float recorrido=0;
	
	//suma = x + y;
	recorrido = mayor-menor;
	
	return recorrido;
	
}








