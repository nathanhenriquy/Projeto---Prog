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

int pxId = 1; // para a contagem do id

void registrarCadastro(struct cadastro *u) {
    system("cls");

    u->id = pxId++; // aq é para somar o proximo id
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
        printf("Erro ao abrir o arquivo.\n"); // teste de abertura
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
        printf("Erro ao abrir o arquivo.\n");
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


// ==== Codigo para adicionar o APP daqui para baixo ====

struct app
{
    char site[50];
    char email_usado[100]; // email usado no dado app
    char user_usado[20];   // nome de usuário usado
    char senha_usada[100];
    char cpf[11];
};

void adicionarApp(struct cadastro *u) {
    struct app a;
    int respSenha;  


    printf("Nome do site/jogo/app: ");
    scanf("%s", a.site);
    printf("Email usado: ");
    scanf("%s", a.email_usado);
    printf("Nome de usuário (caso não exista coloque seu primeiro nome): ");
    scanf("%s", a.user_usado);
    printf("Deseja gerar uma senha aleatória? (0 - Não, 1 - Sim): ");    
    scanf("%d", &respSenha);
    
    if (respSenha == 1) {
        gerarSenha(a.senha_usada, 10); 
    } else {
        printf("Senha: ");
        scanf("%s", a.senha_usada);
    }
    
    strcpy(a.cpf, u->cpf);
    
    
    FILE * arq = fopen("inforSite.txt", "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fprintf(arq, "%s %s %s %s %s \n", a.site, a.email_usado, a.user_usado, a.senha_usada, a.cpf );
    fclose(arq);
    
    printf("Informações do site/senha adicionadas com sucesso!\n");
}

// ==== Gerador de senhas ====

void gerarSenha(char senha[], int n)
{
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

    senha[n] = '\0';

}

// ==== Codigo para adicionar o APP daqui para cima ====


// ==== Codigo para Listar os APPS do USER daqui para baixo ====



// ==== Codigo para Listar os APPS do USER daqui para cima ====


// ==== Codigo para Remover Cliente daqui para baixo ====



// ==== Codigo para Remover Cliente daqui para cima ====


// ==== Codigo para Listar CLiente daqui para baixo ====



// ==== Codigo para Listar CLiente daqui para cima ====


// ==== Codigo para Consultar Cliente daqui para baixo ====



// ==== Codigo para Consultar Cliente daqui para cima ====






