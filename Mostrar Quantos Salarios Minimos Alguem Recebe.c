#include <stdio.h>
int main (void) {
	float salmin, salpes;
	
	printf("Digite o valor do salario minimo:  ");
	scanf("%f", &salmin);
	
	printf("Digite o seu salario agora:  ");
	scanf("%f", &salpes);
	
	printf("Uma pessoa que ganha %.3f recebe %1.f salarios minimos!", salpes, salpes/salmin);
	
return 0;
}
