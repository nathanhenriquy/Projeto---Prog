#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ==== Cadastro daqui para baixo ====

struct cadastro
{
    char nome[20];
    char sobrenome[20];
    char cpf[11];
    char tel[15];
    char email[100];
    char username[20];
    char senha[30]; // senha para acessar sua conta no gerenciador de senhas
};

void registrarCadastro(struct cadastro *u) {

    printf("Digite seu nome: ");
    scanf("%s", u->nome);
    printf("Digite seu primeiro sobrenome: ");
    scanf("%s", u->sobrenome);
    printf("Digite seu CPF: ");
    scanf("%s", u->cpf);
    printf("Digite seu telefone: ");
    scanf("%s", u->tel);
    printf("Digite seu email: ");
    scanf("%s", u->email);
    printf("Digite um username para entrar no Gerenciador: ");
    scanf("%s", u->username);
    printf("Digite uma senha para entrar no Gerenciador: ");
    scanf("%s", u->senha); // usando seta pois estou passando um ponteiro para estrutura

    
    FILE * arq = fopen("usuarios.txt", "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de usuários.\n"); // teste de abertura
        return;
    }
    
    fprintf(arq, "%s %s %s %s  %s %s %s\n", u->nome, u->sobrenome, u->cpf, u->tel, u->email, u->username, u->senha); 
    fclose(arq);
    
    printf("Usuário registrado!\n");
}


// ==== Cadastro daqui para cima ====

// ==== Login daqui para baixo ====

struct login
{
    char username[20];
    char senha[20];   
};

// ==== Login daqui para cima ====








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

// Coisas para fazer:
// fazer o calculo para validação do cpf

// já fazer aqui toda a parte de receber os dados criação de arquivos etc

// também aqui a parte de solicitação para ver o a senha do app
