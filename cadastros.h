#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ==== Cadastro daqui para baixo ====

struct cadastro
{
    int id;
    char nome[50];
    int dia,mes,ano;
    char cpf[11];
    char tel[15];
    char email[100];
    char username[20];
    char senha[30]; // senha para acessar sua conta no gerenciador de senhas
};

int pxId = 0; // para a contagem do id

void registrarCadastro(struct cadastro *u) {
    system("cls");

    u->id = pxId++;
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
    fflush(stdin);
    gets(u->tel);
    fflush(stdin);
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
    
    fprintf(arq, "%i %s %i %i %i %s %s %s %s %s\n", u->id, u->nome,u->dia, u->mes,u->ano, u->cpf, u->tel, u->email, u->username, u->senha); 
    fclose(arq);
    
    printf("Usuario registrado!\n");
}


// ==== Cadastro daqui para cima ====

// ==== Login daqui para baixo ====


int login(struct cadastro *u) {
    system("cls");
    
    printf("Nome de usuário: ");
    scanf("%s", u->username);
    printf("Senha: ");
    scanf("%s", u->senha);
    
    
    FILE *arq = fopen("usuarios.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return 0;
    }

    struct cadastro usuarioTemp; // vai armazenar nesta variavel as informações lidas do arq para comparar

    while (fscanf(arq, "%d %s %i %i %i %s %s %s %s %s", usuarioTemp.id, usuarioTemp.nome, &usuarioTemp.dia, &usuarioTemp.mes, &usuarioTemp.ano, usuarioTemp.cpf, usuarioTemp.tel, usuarioTemp.email, usuarioTemp.username, usuarioTemp.senha) != EOF) {
        if (strcmp(u->username, usuarioTemp.username) == 0 && strcmp(u->senha, usuarioTemp.senha) == 0) {

            fclose(arq);
            return 1; // Login deu boa
        }
    }
    
    fclose(arq);
    return 0; // Login deu memes
}


// ==== Login daqui para cima ====

// ==== Verificador cpf daqui para baixo ====




// ==== Verificador cpf daqui para cima ====



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

// já fazer aqui toda a parte de receber os dados criação de arquivos etc

// também aqui a parte de solicitação para ver o a senha do app
