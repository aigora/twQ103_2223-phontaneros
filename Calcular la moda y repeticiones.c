#include <stdio.h>

	int moda(int a[10]);
		
	
	int main(){
	
	int num[10],valor_repetido;
	
	num[0]=2;
	num[1]=10;
	num[2]=3;
	num[3]=3;
	num[4]=10;
	num[5]=3;
	num[6]=2;
	num[7]=11;
	num[8]=3;
	num[9]=2;
	num[10]=1;
	
	valor_repetido = moda(num[10]);
	
	printf("El numero mas repetido es el %d \n",valor_repetido);

	
	return 0;
	}
	
	int moda (int a[10]){
		
	int x,y,cont2=0,cont1=0,aux;
		
	for (x=0;x<10;x++)
	{	
		for (y=0;y<10;y++)
		{
			if(a[x]==a[y] && x!=y) //Aqui se van comparando los elementos es decir inicializa en 0 cogiendo el 2 y los compara con todos los elementos para ver cuantas veces se repite 
			{
				cont1++;
			}
		}
		
	if (cont1>cont2){
		cont2=cont1;
		aux=a[x];
	}
	
	cont1 =0;
    }	
	
	return aux;		
	}
	
