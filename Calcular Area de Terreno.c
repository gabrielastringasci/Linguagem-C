#include <stdio.h>
int main (void){
float comprimento, largura, area;
    printf("Digite o comprimento do terreno: ");
    scanf("%f", &comprimento);
    printf("Digite a largura do terreno: ");
    scanf("%f", &largura);
    area = comprimento * largura;
    
    if (comprimento < largura){
        printf("O terreno possui %.3fmetros quadrados e e retangular! Podemos vender.", area);
    }
    else{
        printf("Que pena, o terreno possui %.3f metros quadrados e nao e retangular, nao vendemos terrenos desse tipo.", area);
    }
    
return 0;
}

