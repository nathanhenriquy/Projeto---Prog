#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verificaCPF(int cpf[])
{
    int i;                      // contador
    int d1, d2;                 // armazenam os digitos verificadores 1 e 2 para comparar ao cpf
    int soma1 = 0, soma2 = 0;   // guardam a soma entre os digitos do cpf com seus respectivos pesos
    int peso1 = 10, peso2 = 11; // necessarios para a atribuição de pesos para os digitos
    int resto1, resto2;

    for (i = 0; i < 9; i++)
    {
        soma1 += cpf[0] * peso1;
        peso1--;
    }

    if ((soma1 % 11) == 0 || (soma1 % 11) == 1)
    {
        d1 = 0;
    }
    else
    {
        d1 = soma1 % 11;
    }

    for (i = 0; i < 10; i++)
    {
        soma2 += cpf[0] * peso2;
        peso2--;
    }
}