#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct pessoa{
	char nome[20];
	char sobrenome[20];
	char cpf[11];
    char tel[15];
    int dia; int mes; int ano;
	char nacionalidade[30]; // fazer para aceitar somente brasileiros
	char email[100];	    
    char senha[30]; // senha para acessar sua conta no gerenciador de senhas
};


struct app{
    char site[20];
    char user_usado[20]; // nome de usuário usado
    char email_usado[100]; // email usado no dado app
};

struct senha_usada{
    char senha_usada[100]; // caso a pessoa não queira gerar uma senha
};



// Colocar todas novas structs acima desse comentário

// Coisas para fazer:
// fazer o calculo para validação do cpf
// já fazer aqui toda a parte de receber os dados criação de arquivos etc
// também aqui a parte de solicitação para ver o a senha do app
