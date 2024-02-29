#include <stdio.h>

int main() {
    int numeros[10];
    int i, j, numero;

    printf("Digite 10 números:\n");

    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numero);

        // Verifica se o número já foi inserido anteriormente
        for (j = 0; j < i; j++) {
            if (numeros[j] == numero) {
                printf("Número repetido. Digite novamente.\n");
                i--; // Decrementa o índice para repetir a entrada
                break;
            }
        }

        // Se o número não foi repetido, armazena no vetor
        if (j == i) {
            numeros[i] = numero;
        }
    }

    printf("Números digitados:\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}

