#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ATENÇÃO: caso alguem q nao seja eu(paulo) vá implementar o verificador de cpf na main, coloquei a função com retorno 1,
// para sinalizar que o cpf tava errado e tem q repetir o printf/scanf, mas se estiver correto ele retorna 0

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