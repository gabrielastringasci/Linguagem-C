#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define tamanho 50000

int main (void) {
	int vet[tamanho], troca;
	clock_t ti, tf, td;
	register int pos, aux;

	for(pos = 0; pos < tamanho; pos++){
		vet[pos]=rand();
	}

	 ti = clock();
	 troca = 1;

	 while(troca == 1){
		troca = 0;
		for(pos = 0; pos < tamanho-1; pos++){
			if(vet[pos]>vet[pos+1]){
	
			aux = vet[pos];
			vet[pos] = vet[pos+1];
			vet[pos + 1]=aux;
			troca = 1;
			}
		}	 
	}
	tf = clock();
	td=tf-ti;
	printf("Duracao= %.1f\n",(double)td/(CLOCKS_PER_SEC));

	return 0;
}
