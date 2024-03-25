#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define tamanho 50000
int main (void) {
	int vet[tamanho];
	clock_t inicio, fim, tempo_decorrido;
	register int aux, externo, interno;
	srand(time(NULL));
	for(interno=0; interno<tamanho; interno++){
		vet[interno] = rand();
	}
	
	inicio = clock();

	for(externo = 0; externo < tamanho - 1; externo++){
		for(interno = externo + 1; interno < tamanho; interno++){
			if(vet[externo] > vet[interno]){
			aux = vet[externo];
			vet[externo] = vet[interno];
			vet[interno] = aux;
			}
		}
	}

	fim = clock();
	tempo_decorrido = fim - inicio;
	
	printf("Duracao = %fms\n", (double)tempo_decorrido / (CLOCKS_PER_SEC/1000));

	return 0;
}
