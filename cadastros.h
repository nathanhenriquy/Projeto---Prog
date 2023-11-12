#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ==== Cadastro daqui para baixo ====

int verificaCPF(int cpf[]); // declarando aqui só pra funcionar no cadastro;

struct cadastro
{
    int id;
    char nome[50];
    int dia,mes,ano;
    int cpf[11]; // alterei pra int pq char nao tava funcionando, acredito q nao vai mudar nada
    char tel[15];
    char email[100];
    char username[20];
    char senha[30]; // senha para acessar sua conta no gerenciador de senhas
};

int pxId = 1; // para a contagem do id

void registrarCadastro(struct cadastro *u) {
    int resultadoVerificacao;
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
    do {
        printf("Digite seu CPF: ");
        for (int i = 0; i < 11; i++) 
        {
            scanf("%1i", &u->cpf[i]);
        }

        resultadoVerificacao = verificaCPF(u->cpf);

        if (resultadoVerificacao != 0){
            printf("\nCPF inválido. Por favor, digite novamente.\n");
        }
        else if (resultadoVerificacao == 0)
        {
            printf("\ncorreto\n");
        }
    } while(resultadoVerificacao != 0);

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
    
    printf("Nome de usuario: ");
    scanf("%s", u->username);
    printf("Senha: ");
    scanf("%s", u->senha);
    
    
    FILE *arq = fopen("usuarios.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    struct cadastro usuarioTemp; // vai armazenar nesta variavel as informações lidas do arq para comparar

    while (fscanf(arq, "%i %s %i %i %i %s %s %s %s %s", &usuarioTemp.id, usuarioTemp.nome, &usuarioTemp.dia, &usuarioTemp.mes, &usuarioTemp.ano, usuarioTemp.cpf, usuarioTemp.tel, usuarioTemp.email, usuarioTemp.username, usuarioTemp.senha) != EOF) {
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

int verificaCPF(int cpf[]) {
    int i;                      // contador
    int d1= 0, d2 = 0;                 // armazenam os digitos verificadores 1 e 2 para comparar ao cpf
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
    struct app *a = (struct app *)malloc(sizeof(struct app));

    if (a == NULL) {
        printf("\nerro na alocação\n");
        return;
    }

    int respSenha;  


    printf("Nome do site/jogo/app: ");
    scanf("%s", a->site);
    printf("Email usado: ");
    scanf("%s", a->email_usado);
    printf("Nome de usuario (caso nao exista coloque seu primeiro nome): ");
    scanf("%s", a->user_usado);
    printf("Deseja gerar uma senha aleatoria? (0 - Não, 1 - Sim): ");    
    scanf("%d", &respSenha);
    
    if (respSenha == 1) {
        gerarSenha(a->senha_usada, 10); 
    } else {
        printf("Senha: ");
        scanf("%s", a->senha_usada);
    }
    
    strcpy(a->cpf, u->cpf);
    
    
    FILE * arq = fopen("inforSite.txt", "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fprintf(arq, "%s %s %s %s %s \n", a->site, a->email_usado, a->user_usado, a->senha_usada, a->cpf );
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

};

// ==== Codigo para adicionar o APP daqui para cima ====


// ==== Codigo para Listar os APPS do USER daqui para baixo ====

void listarSitesUsuario(struct cadastro *u)
{
    struct app a;

    FILE * arq = fopen ("inforSite.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo .\n");
        return;
    };


    

    fclose(arq);    

}
;
// ==== Codigo para Listar os APPS do USER daqui para cima ====






// ==== Codigo para Remover Cliente daqui para baixo ====



// ==== Codigo para Remover Cliente daqui para cima ====


// ==== Codigo para Listar CLiente daqui para baixo ====



// ==== Codigo para Listar CLiente daqui para cima ====


// ==== Codigo para Consultar Cliente daqui para baixo ====



// ==== Codigo para Consultar Cliente daqui para cima ====






