#include <stdio.h>

int main() {
    float nota1, nota2, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    media = (nota1 + nota2) / 2;

    printf("Sua nota final: ");

    if (media >= 9.0) {
        printf("A\n");
    } else if (media >= 7.5) {
        printf("B\n");
    } else if (media >= 6.0) {
        printf("C\n");
    } else if (media >= 4.0) {
        printf("D\n");
    } else {
        printf("E\n");
    }

    return 0;
}

