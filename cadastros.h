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
    long long int cpf; // o int normal nao comporta todos os digitos do cpf
    char tel[15];
    char email[100];
    char username[20];
    char senha[30]; // senha para acessar sua conta no gerenciador de senhas
};

void salvarUltimoId(int ultimoId) {
    FILE *arq = fopen("ultimoid.txt", "w");
    if (arq != NULL) {
        fprintf(arq, "%d", ultimoId);
        fclose(arq);
    } else {
        printf("Erro ao salvar o ultimo ID.\n");
    }
}

int carregarUltimoId() {
    int ultimoId = 1; // Valor para o id

    FILE *arq = fopen("ultimoid.txt", "r");
    if (arq != NULL) {
        fscanf(arq, "%d", &ultimoId);
        fclose(arq);
    }

    return ultimoId;
}



void registrarCadastro(struct cadastro *u) {
    system("cls");
    long long int cpf;
    char temp[22]; //u será usado apenas para ser passado por parametro

    

    int pxId = carregarUltimoId();
    u->id = pxId++; // aq é para somar o proximo id
    printf("Digite seu nome completo: ");
    fflush(stdin);
    gets(u->nome);
    fflush(stdin);

    do {
    printf("Digite sua data de nascimento:\n");
    printf("Dia (2 digitos): ");
    scanf("%i", &u->dia);
    printf("Mes (2 digito): ");
    scanf("%i", &u->mes);
    printf("Ano (4 digitos): ");
    scanf("%i", &u->ano);

        if (u->dia < 1 || u->dia > 31 || u->mes < 1 || u->mes > 12 || u->ano < 1900 || u->ano > 2023) {
            printf("\nData de nascimento invalida. Por favor, insira uma data valida.\n");
        }
    } while (u->dia < 1 || u->dia > 31 || u->mes < 1 || u->mes > 12 || u->ano < 1900 || u->ano > 2023);

    do {
        printf("Digite seu CPF: ");
        scanf("%lld", &cpf);

        u->cpf = cpf; // passando a variavel local para a struct, evitando erros

        sprintf(temp, "%lld", cpf);
    } while (verificaCPF(temp) == 0);

    do {
    printf("Digite seu telefone (sem espaços, com DDD): ");
    fflush(stdin);
    gets(u->tel);
    fflush(stdin);

        if (strlen(u->tel) != 11) {
            printf("\nFormato de telefone invalido. O telefone deve ter 11 digitos. Por favor, corrija.\n");
        }
        
    } while (strlen(u->tel) != 11);

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
    
    fprintf(arq, "%i %s %i %i %i %lld %s %s %s %s\n", u->id, u->nome,u->dia, u->mes,u->ano, u->cpf, u->tel, u->email, u->username, u->senha); 
    fclose(arq);

    salvarUltimoId(pxId);
    
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

    while (fscanf(arq, "%i %s %i %i %i %lld %s %s %s %s", &usuarioTemp.id, usuarioTemp.nome, &usuarioTemp.dia, &usuarioTemp.mes, &usuarioTemp.ano, &usuarioTemp.cpf, usuarioTemp.tel, usuarioTemp.email, usuarioTemp.username, usuarioTemp.senha) != EOF) {
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

int verificaCPF(char cpf[])
{
    int i, j;                   // contador
    int d1 = 0, d2 = 0;         // armazenam os digitos verificadores 1 e 2 para comparar ao cpf

    if (strlen(cpf) != 11)
    {
        return 0;
    }
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
             (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
             (strcmp(cpf, "99999999999") == 0)) // excluindo cpf's com numeros iguais, que passam batido pela verificação
    {
        return 0;
    }
    else
    {
        for (i = 0, j = 10; i < 9; i++, j--)
        {
            d1 += (cpf[i] - 48) * j; // como cpf é char, o 48 faz a conversao para tabela ascii
        }

        d1 %= 11; // d1 = d1 % 11

        if (d1 < 2) {
            d1 = 0;
        }
        else {
            d1 = 11 - d1;
        }

        if ((cpf[9] - 48) != d1) {
            return 0;
        }
        else
        {
            for (i = 0, j = 11; i < 10; i++, j--) {
                d2 += (cpf[i] - 48) * j;
            }

            d2 %= 11;

            if (d2 < 2) {
                d2 = 0;
            }
            else {
                d2 = 11 - d2;
            }
            if ((cpf[10] - 48) != d2)
                return 0;
        }
    }
    return 1;
}

// ==== Verificador cpf daqui para cima ====


// ==== Codigo para adicionar o APP daqui para baixo ====

struct app
{
    char site[50];
    char email_usado[100]; // email usado no dado app
    char user_usado[20];   // nome de usuário usado
    char senha_usada[100];
    int id;
};

void adicionarApp(struct cadastro *u) 
{
    system("cls");  
    struct app a;

    
    int respSenha;  


    printf("Nome do site/jogo/app: ");
    scanf("%s", a.site);
    printf("Email usado: ");
    scanf("%s", a.email_usado);
    printf("Nome de usuario (caso nao exista coloque seu primeiro nome): ");
    scanf("%s", a.user_usado);
    printf("Deseja gerar uma senha aleatoria? (0 - Não, 1 - Sim): ");    
    scanf("%d", &respSenha);
    
    if (respSenha == 1) {
        gerarSenha(a.senha_usada, 10); 
    } else {
        printf("Senha: ");
        scanf("%s", a.senha_usada);
    }
    
    a.id = u->id;
    
    
    FILE * arq = fopen("inforSite.txt", "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        
        return;
    }
    
    fprintf(arq, "%s %s %s %s %i \n", a.site, a.email_usado, a.user_usado, a.senha_usada, a.id );
    fclose(arq);

 
    printf("Informações do site/senha adicionadas com sucesso!\n");
}

// ==== Gerador de senhas ====

void gerarSenha(char* senha, int n)
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
    system("cls");
    struct app *a = (struct app *)malloc(sizeof(struct app));

    FILE * arq = fopen ("inforSite.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo .\n");
        return;
    };

    printf("Lista de Apps/Sites cadastrados para o usuario:\n\n");

    while (fscanf(arq, "%s %s %s %s %i", a->site, a->email_usado, a->user_usado, a->senha_usada, &a->id) != EOF)
    {
        // Verificar se o ID no arquivo corresponde ao ID do usuário logado
        if (a->id == u->id) 
        {
            printf("Site: %s\n", a->site);
            printf("Email usado: %s\n", a->email_usado);
            printf("Nome de usuario: %s\n", a->user_usado);
            printf("Senha: %s\n", a->senha_usada);
            printf("---------------------------\n");
        }
    }


    

    fclose(arq);    

};

// ==== Codigo para Listar os APPS do USER daqui para cima ====






// ==== Codigo para Remover Cliente daqui para baixo ====
/*
void removerCliente(int id){ 
    FILE *arq = fopen("usuarios.txt", "r"); 
    FILE *tempFile = fopen("tempFile.txt", "w"); // Abertura do arquivo temporário 
    if (arq == NULL || tempFile == NULL){ 
        printf("Erro ao abrir os arquivos. \n"); 
        return;
    } 

    struct cadastro cliente; 
    int encontrado = 0; 

    while (fscanf(arq, "%i %s %i %i %i %lld %s %s %s %s", &cliente.id, cliente.nome, 
        &cliente.dia, &cliente.mes, &cliente.ano, &cliente.cpf, cliente.tel, cliente.email, 
        cliente.username, cliente.senha) != EOF){ 
            if (cliente.id != id){ 
                fprintf(tempFile, "%i %s %i %i %i %lld %s %s %s %s\n", cliente.id, cliente.nome, 
                cliente.dia, cliente.mes, cliente.ano, cliente.cpf, cliente.tel, cliente.email, 
                cliente.username, cliente.senha); // verifica se o ID do cliente é diferente do ID informado pelo usuário
            } else{ 
                encontrado = 1; 
            }
        } 

        fclose(arq); 
        fclose(tempFile); 

        if(encontrado){ 
            remove("usuarios.txt"); 
            rename("tempFile.txt", "usuarios.txt"); 
            printf("Cliente removido com sucesso.\n"); // Se o cliente for encontrado, ele é removido arquivo
        } else{ 
            printf("Cliente não encontrado.\n"); 
            remove("tempFile.txt"); // Remove arquivo temporário se o cliente não foi encontrado
        }
}
*/
// ==== Codigo para Remover Cliente daqui para cima ====


// ==== Codigo para Listar CLiente daqui para baixo ====
/*
void bubbleSort(struct cadastro *arr, int n){ 
    int i, j; 
    struct cadastro temp; 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++){ 
            if (strcmp(arr[j].nome, arr[j + 1].nome) > 0){ 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp;
            }
        }
    }
}

void listarCliente() { 
    FILE *arq = fopen("usuarios.txt", "r"); 

    if (arq == NULL) { 
        printf("Erro ao abrir o arquivo.\n"); 
        return;
    } 

    int maxClientes = 100; 
    struct cadastro *cliente = malloc(maxClientes * sizeof(struct cadastro)); 
    int count = 0; 

    if (cliente == NULL){ 
        printf("Erro ao alocar memória.\n"); 
        fclose(arq); 
        return; 
    } 

    while (count < maxClientes && fscanf(arq, "%d %s %d %d %d %s %s %s %s %s", &cliente[count].id, cliente[count].nome,
            &cliente[count].dia, &cliente[count].mes, &cliente[count].ano, cliente[count].cpf, 
            cliente[count].tel, cliente[count].email, cliente[count].username, cliente[count].senha) ==10){ 
                count++; 
            } 

            fclose(arq); 
           
           printf("Você gostaria de listar em ordem alfabetica ou por ordem de ID? (1 para alfabetica , 2 para ID): "); 
           int ordem; 
           scanf("%d", &ordem); 

           if(ordem == 1){ 
            bubbleSort(cliente, count); 
           } 

           for (int i = 0; i < count; i++){ 
            printf("ID: %d\n, Nome: %s\n, Data de Nascimento: %d/%d/%d\n, CPF: %lld\n, Telefone: %s\n, Email: %s\n, Nome de usuario: %s\n, Senha: %s \n", cliente[i].id, cliente[i].nome, cliente[i].dia, cliente[i].mes, cliente[i].ano, cliente[i].cpf, cliente[i].tel, cliente[i].email, cliente[i].username, cliente[i].senha);

           } 

           free(cliente);  
}*/
// ==== Codigo para Listar CLiente daqui para cima ====


// ==== Codigo para Consultar Cliente daqui para baixo ====

void buscarPorCPF(struct cadastro *u) {
    long long int buscaCPF;
    
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%lld", &buscaCPF);
    
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }
    
    int encontrado = 0;  
    
    while (fscanf(arquivo, "%i %s %i %i %i %lld %s %s %s %s", &u->id, u->nome, &u->dia, &u->mes, &u->ano, &u->cpf, u->tel, u->email, u->username, u->senha) != EOF) {
        if (u->cpf == buscaCPF) {
            system("cls");
            printf("ID: %i\n", u->id);
            printf("Nome: %s\n", u->nome);
            printf("Data de Nascimento: %i/%i/%i\n", u->dia, u->mes, u->ano);
            printf("CPF: %lld\n", u->cpf);
            printf("Telefone: %s\n", u->tel);
            printf("Email: %s\n", u->email);
            printf("Username: %s\n", u->username);
            printf("Senha: %s\n", u->senha);
            encontrado = 1; 
            break;
        }
    }
    
    fclose(arquivo);
    
    if (!encontrado) {
        system("cls");
        printf("Usuário com CPF %lld nao encontrado.\n", buscaCPF);
    }
}



// ==== Codigo para Consultar Cliente daqui para cima ====





