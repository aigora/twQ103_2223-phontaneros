#include <stdio.h>

int main(){
	int x=0,y=0,valor_repetido,tmp1=0,veces=0,u=0;
	
	int numeros[10];
	
	numeros[0]=2;
	numeros[1]=10;
	numeros[2]=3;
	numeros[3]=3;
	numeros[4]=10;
	numeros[5]=3;
	numeros[6]=2;
	numeros[7]=11;
	numeros[8]=3;
	numeros[9]=2;
	numeros[10]=1;
	
	for (x=0;x<10;x++)
	{
		for (y=0;y<10;y++)
		{
			if(numeros[x]==numeros[y])
			{
				tmp1=tmp1+1;
			}
		}
		
	if (tmp1>veces)
	{
		u=tmp1;
		valor_repetido=numeros[x];
	}
	
	veces=tmp1;
	tmp1=0;
	}
	
	printf("El numero mas repetido fue el %d \n",valor_repetido);
	printf("y se repitio %d veces \n", u);
	
	
	return 0;
}

