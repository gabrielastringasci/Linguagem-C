#include <stdio.h>
#include <stdlib.h>

struct listaNo {
    int elemento;
    struct listaNo *prox, *ant;
};

void mostrar(struct listaNo *pHead);
float calcularMedia(struct listaNo *pHead);
void mostrarAcimaMedia(struct listaNo *pHead, float media);
int listaContemValor(struct listaNo *pHead, int valor);

int main(void) {
    struct listaNo *head = NULL, *no;
    int pos, vet[3];

    for (pos = 0; pos < 5; pos++) {
        printf("Digite o elemento %d:\n", pos + 1);
        scanf("%d", &vet[pos % 3]);

        if (!(no = malloc(sizeof(struct listaNo)))) {
            printf("Faltou memoria!\n");
            exit(1);
        }

        no->elemento = vet[pos % 3];
        no->prox = head;
        no->ant = NULL;

        if (head != NULL) {
            head->ant = no;  // Atualiza o ponteiro ant do nó anterior
        }

        head = no;
    }

    printf("Mostrar a lista: \n");
    mostrar(head);

    float media = calcularMedia(head);
    printf("A média dos valores e: %.2f\n", media);

    int valorUsuario;
    printf("Digite o valor a ser verificado na lista: ");
    scanf("%d", &valorUsuario);

    if (listaContemValor(head, valorUsuario)) {
        printf("A lista contém o valor %d.\n", valorUsuario);
    } else {
        printf("A lista não contém o valor %d.\n", valorUsuario);
    }

    printf("Elementos acima da media: \n");
    mostrarAcimaMedia(head, media);

    printf("Destroi a lista:\n");
    no = head;

    while (no != NULL) {
        head = head->prox;
        free(no);
        no = head;
    }

    printf("\n Fim! \n");

    return 0;
}

void mostrar(struct listaNo *pHead) {
    struct listaNo *aux;
    aux = pHead;

    while (aux != NULL) {
        printf("Elemento = %d\n", aux->elemento);
        aux = aux->prox;
    }
}

float calcularMedia(struct listaNo *pHead) {
    struct listaNo *aux;
    aux = pHead;
    int soma = 0, contador = 0;

    while (aux != NULL) {
        soma += aux->elemento;
        contador++;
        aux = aux->prox;
    }

    if (contador > 0) {
        return (float)soma / contador;
    } else {
        return 0.0;
    }
}

void mostrarAcimaMedia(struct listaNo *pHead, float media) {
    struct listaNo *aux;
    aux = pHead;

    while (aux != NULL) {
        if (aux->elemento > media) {
            printf("Elemento acima da media--+: %d\n", aux->elemento);
        }
        aux = aux->prox;
    }
}

int listaContemValor(struct listaNo *pHead, int valor) {
    struct listaNo *aux;
    aux = pHead;

    while (aux != NULL) {
        if (aux->elemento == valor) {
            return 1; // Valor encontrado na lista
        }
        aux = aux->prox;
    }

    return 0; // Valor não encontrado na lista
}

