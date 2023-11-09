#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ==== Cadastro daqui para baixo ====

struct cadastro
{
    char nome[50];
    int dia,mes,ano;
    char cpf[11];
    char tel[15];
    char email[100];
    char username[20];
    char senha[30]; // senha para acessar sua conta no gerenciador de senhas
};

void registrarCadastro(struct cadastro *u) {

    printf("Digite seu nome completo: ");
    fflush(stdin);
    gets(u->nome);
    fflush(stdin);
    printf("Digite sua data de nascimento:\n");
    printf("Dia (2 digitos): ");
    scanf("%i", &u->dia);
    printf("Mes (2 digitos): ");
    scanf("%i", &u->mes);
    printf("Ano (4 digitos): ");
    scanf("%i", &u->ano);
    printf("Digite seu CPF: ");
    scanf("%s", u->cpf);
    printf("Digite seu telefone (sem espacos): ");
    scanf("%s", u->tel);
    printf("Digite seu email: ");
    scanf("%s", u->email);
    printf("Digite um username para entrar no Gerenciador: ");
    scanf("%s", u->username);
    printf("Digite uma senha para entrar no Gerenciador: ");
    scanf("%s", u->senha); // usando seta pois estou passando um ponteiro para estrutura

    
    FILE * arq = fopen("usuarios.txt", "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de usuarios.\n"); // teste de abertura
        return;
    }
    
    fprintf(arq, "%s %i %i %i %s %s %s %s %s\n", u->nome,u->dia, u->mes,u->ano, u->cpf, u->tel, u->email, u->username, u->senha); 
    fclose(arq);
    
    printf("Usuario registrado!\n");
}


// ==== Cadastro daqui para cima ====

// ==== Login daqui para baixo ====


int login(struct cadastro *u) {
    printf("Nome de usuário: ");
    scanf("%s", u->username);
    printf("Senha: ");
    scanf("%s", u->senha);
    
    
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return 0;
    }

    struct cadastro usuarioTemp; // vai armazenar nesta variavel as informações lidas do arq para comparar

    while (fscanf(file, "%s %s", usuarioTemp.username, usuarioTemp.senha) != EOF) {
        if (strcmp(u->username, usuarioTemp.username) == 0 && strcmp(u->senha, usuarioTemp.senha) == 0) {

            fclose(file);
            return 1; // Login deu boa
        }
    }
    
    fclose(file);
    return 0; // Login deu memes
}


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
