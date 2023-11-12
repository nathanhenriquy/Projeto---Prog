#include <stdio.h>
#include <stdbool.h>

int verificaCPF(int cpf[]) {
    int i;                      // contador
    int d1, d2;                 // armazenam os digitos verificadores 1 e 2 para comparar ao cpf
    int soma1 = 0, soma2 = 0;   // guardam a soma entre os digitos do cpf com seus respectivos pesos
    int peso1 = 10, peso2 = 11; // necessarios para a atribuição de pesos para os digitos

    for (i = 0; i < 9; i++) {
        soma1 += cpf[i] * peso1;
        peso1--;
    }

    d1 = (soma1 % 11 < 2) ? 0 : 11 - (soma1 % 11);

    if (cpf[9] != d1) {
        return 1;
    }

    soma2 = 0;
    peso2 = 11;

    for (i = 0; i < 10; i++) {
        soma2 += cpf[i] * peso2;
        peso2--;
    }

    d2 = (soma2 % 11 < 2) ? 0 : 11 - (soma2 % 11);

    return (cpf[10] != d2); // se for incorreto, vai retornar 1 e se for correto, 0
}

int main() {
    int cpf[11];

    printf("Digite o CPF (apenas números): ");
    for (int i = 0; i < 11; i++) 
    {
        scanf("%1d", &cpf[i]);
    }

    if (verificaCPF(cpf) == 0) 
    {
        printf("\nCPF válido\n");
    } 
    else 
    {
        printf("\nCPF inválido\n");
    }

    return 0;
}