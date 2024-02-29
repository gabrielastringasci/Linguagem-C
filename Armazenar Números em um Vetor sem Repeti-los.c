#include <stdio.h>

int main() {
    int numeros[10];
    int i, j, numero;

    printf("Digite 10 n�meros:\n");

    for (i = 0; i < 10; i++) {
        printf("N�mero %d: ", i + 1);
        scanf("%d", &numero);

        // Verifica se o n�mero j� foi inserido anteriormente
        for (j = 0; j < i; j++) {
            if (numeros[j] == numero) {
                printf("N�mero repetido. Digite novamente.\n");
                i--; // Decrementa o �ndice para repetir a entrada
                break;
            }
        }

        // Se o n�mero n�o foi repetido, armazena no vetor
        if (j == i) {
            numeros[i] = numero;
        }
    }

    printf("N�meros digitados:\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}

