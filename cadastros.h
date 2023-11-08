#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cadastro
{
    char nome[20];
    char sobrenome[20];
    char cpf[11];
    char tel[15];
    int dia;
    int mes;
    int ano;
    char email[100];
    char username[20];
    char senha[30]; // senha para acessar sua conta no gerenciador de senhas
};

struct login
{
    char username[20];
    char senha[20];   
};

struct app
{
    char site[20];
    char user_usado[20];   // nome de usuário usado
    char email_usado[100]; // email usado no dado app
};

struct senha_usada
{
    char senha_usada[100]; // caso a pessoa não queira gerar uma senha
};

// Colocar todas novas structs acima desse comentário


// gerador de senhas, gera 10 caracteres aleatórios.

void gerarSenha()
{
    int n = 10;
    char senha[n + 1];

    srand(time(NULL));

    char numeros[] = "0123456789";
    char letrasMinusculas[] = "abcdefghijklmnopqrstuvwxyz";
    char letrasMaiusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char simbolos[] = "!@#$&*";

    for (int i = 0; i < n; i++)
    {
        int categoria = rand() % 4;
        switch (categoria)
        {
        case 0:
            senha[i] = numeros[rand() % 10];
            break;
        case 1:
            senha[i] = letrasMinusculas[rand() % 26];
            break;
        case 2:
            senha[i] = letrasMaiusculas[rand() % 26];
            break;
        case 3:
            senha[i] = simbolos[rand() % 6];
            break;
        }
    }
}

// Coisas para fazer:
// fazer o calculo para validação do cpf

// já fazer aqui toda a parte de receber os dados criação de arquivos etc

// também aqui a parte de solicitação para ver o a senha do app
