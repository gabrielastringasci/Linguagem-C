#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define saldo_inicial 5000.0
#define transacoes 20

void login(double *saldo);
void menu(char userinput[], double *saldo, double extrato[], int *ntransacoes);
void depositar(char userinput[], double *saldo, double extrato[], int *ntransacoes);
void sacar(char userinput[], double *saldo, double extrato[], int *ntransacoes);
void verificarsaldo(char userinput[], double *saldo, double extrato[], int *ntransacoes);
void calculadora(char userinput[], double *saldo, double extrato[], int *ntransacoes);
void sair();
double extrato[transacoes];
int ntransacoes = 0;

int main(void) {
    double saldo = saldo_inicial;
    int ntransacoes = 0;
    
    printf("Ola! Seja bem vindo ao BankingFam.\n");
    
    login(&saldo);
    
    return 0;
}

void login(double *saldo) {
    char user[] = "pipoca", userinput[10];
    int senha = 1609, senhainput;

    while (1) {
        printf("Digite o seu login:\n");
        scanf("%s", userinput);

        if (strcmp(userinput, user) == 0) {
            printf("Digite sua senha:\n");
            scanf("%d", &senhainput);

            if (senhainput == senha) {
                menu(userinput, saldo, extrato, &ntransacoes);
            } else {
                printf("Senha incorreta! Por favor, comece novamente.\n");
            }
        	} else {
            printf("Login incorreto! Por favor, comece novamente.\n");
        }
    }
}

void menu(char userinput[], double *saldo, double extrato[], int *ntransacoes) {
    int input;

    printf("Olá, %s!\nMENU:\nSelecione a opcao que deseja:\n", userinput);
    printf("Opção 1: Depositar\nOpção 2: Sacar\nOpção 3: Verificar Saldo\nOpção 4: Calcular Investimentos\nOpção 5: Sair\n");

    scanf("%d", &input);
    fflush(stdin);

    switch (input) {
        case 1:
            depositar(userinput, saldo, extrato, ntransacoes);
            break;
        case 2:
            sacar(userinput, saldo, extrato, ntransacoes);
            break;
        case 3:
            verificarsaldo(userinput, saldo, extrato, ntransacoes);
            break;
        case 4:
            calculadora(userinput, saldo, extrato, ntransacoes);
            break;
        case 5:
            sair();
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
   		 }
	}

void depositar(char userinput[], double *saldo, double extrato[], int *ntransacoes) {
    double deposito;

    printf("Saldo: %.3f\n", *saldo);
    
    printf("Digite o valor que deseja depositar:\n");
    scanf("%lf", &deposito);

    printf("-----------Executando deposito-----------");
    extrato[*ntransacoes] = deposito;
    *ntransacoes += 1;

    *saldo += deposito;

    printf("Saldo: %.1f\n", *saldo);
    menu(userinput, saldo, extrato, ntransacoes);
}

void sacar(char userinput[], double *saldo, double extrato[], int *ntransacoes) {
    double saque;

    printf("Saldo:%.1f\n", *saldo);
    printf("Digite o valor a sacar:\n");
    scanf("%lf", &saque);

    if (saque <= *saldo) {
        printf("-----------Executando saque-----------");
        extrato[*ntransacoes] = -saque;
        *ntransacoes += 1;

        *saldo -= saque;

        printf("Saldo: %.1f\n", *saldo);
    } else {
        printf("O saldo da conta é insuficiente!\n");
    }

    menu(userinput, saldo, extrato, ntransacoes);
}

void verificarsaldo(char userinput[], double *saldo, double extrato[], int *ntransacoes) {
    int pos;
    
    printf("Saldo da conta:%.1f\n", *saldo);

    for (pos = 0; pos < *ntransacoes; pos++) {
        printf("Extrato:%.1f\n", extrato[pos]);
    }

    menu(userinput, saldo, extrato, ntransacoes);
}

void calculadora(char userinput[], double *saldo, double extrato[], int *ntransacoes) {
    double investimentoTotal, taxaMensal;
    int meses;

    printf("Informe o valor total do investimento: ");
    scanf("%lf", &investimentoTotal);

    printf("Informe a taxa de juros mensal (em porcentagem): ");
    scanf("%lf", &taxaMensal);

    printf("Informe o período de investimento em meses: ");
    scanf("%d", &meses);

    double rendimentoMensal = investimentoTotal * (taxaMensal / 100);
    double rendimentoAnual = rendimentoMensal * 12;
    double lucroTotal = rendimentoMensal * meses;

    printf("\nResultados:\n");
    printf("Rendimento por mês: %.2lf\n", rendimentoMensal);
    printf("Rendimento por ano: %.2lf\n", rendimentoAnual);
    printf("Diferença entre lucro e total investido: %.2lf\n", lucroTotal);
    menu(userinput, saldo, extrato, ntransacoes);
}

void sair() {
    printf("--------Sessão encerrada--------");
}
