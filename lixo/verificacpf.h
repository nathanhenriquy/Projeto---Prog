#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ATENÇÃO: caso alguem q nao seja eu(paulo) vá implementar o verificador de cpf na main, coloquei a função com retorno 1,
// para sinalizar que o cpf tava errado e tem q repetir o printf/scanf, mas se estiver correto ele retorna 0

int verificaCPF(char cpf[]) {
    int i, j;                      // contador
    int d1= 0, d2 = 0;                 // armazenam os digitos verificadores 1 e 2 para comparar ao cpf
    int soma1 = 0, soma2 = 0;   // guardam a soma entre os digitos do cpf com seus respectivos pesos
    int peso1 = 10, peso2 = 11; // necessarios para a atribuição de pesos para os digitos

    if (strlen(cpf) != 11)
    {
        return 0;
    }
    else if ( (strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
              (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
              (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
              (strcmp(cpf,"99999999999") == 0) ) 
    {
        return 0;
    }
    else
    {
        for (i = 0, j = 10; i < 9; i++, j--)
        {
            
        }
        







    }

    
}