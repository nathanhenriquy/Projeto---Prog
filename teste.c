#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaCPF(int cpf[])
{
    int i;                      // contador
    int d1, d2;                 // armazenam os digitos verificadores 1 e 2 para comparar ao cpf
    int soma1 = 0, soma2 = 0;   // guardam a soma entre os digitos do cpf com seus respectivos pesos
    int peso1 = 10, peso2 = 11; // necessarios para a atribuição de pesos para os digitos

    for (i = 0; i < 9; i++)
    {
        soma1 += cpf[i] * peso1;
        peso1--;
    }

    if ((soma1 % 11) == 0 || (soma1 % 11) == 1)
    {
        d1 = 0;
    }
    else
    {
        d1 = 11 - (soma1 % 11);
    }

    //

    if (cpf[9] == d1)
    {
        soma2 = 0;
        peso2 = 11;
        
        for (i = 0; i < 10; i++)
        {
            soma2 += cpf[i] * peso2;
            peso2--;
        }

        if ((soma2 % 11) == 0 || (soma2 % 11) == 1)
        {
            d2 = 0;
        }
        else
        {
            d2 = 11 - (soma2 % 11);
        }

        if (cpf[10] == d2)
        {
            printf("\ncpf valido\n");
            return 0;
        }
        else 
        {
            printf("\ncpf invalido\n");
            return 1;
        }

    }
    else
    {
        printf("\no cpf é invalido\n");
        return 1;
    }

}

int main()
{
    int cpf[11];

    printf("digite um cpf\n");
    scanf("%i", cpf);

    verificaCPF(cpf);



    return 0;
}