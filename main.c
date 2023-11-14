#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "cadastros.h"


// ATENÇÃO: caso alguem q nao seja eu(paulo) vá implementar o verificador de cpf na main, coloquei a função com retorno 1,
// para sinalizar que o cpf tava errado e tem q repetir o printf/scanf, mas se estiver correto ele retorna 0

int main()
{
    int escolha;

    struct cadastro u; // u seria de usuário, coloquei simplicado para não ficar muita coisa na hora de fazer os scanfs

    system("cls");

    while (1)
    {
        //system("cls");

        telaMenu();
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            if (login(&u))// aqui vai ser a parte de login
            {
                system("cls");
                printf("Login bem-sucedido!\n");
                while (1)
                {
                    gerenciadorUsuario();
                    scanf("%d", &escolha);

                    switch (escolha)
                    {
                    case 1:
                        adicionarApp(&u); //adicionar app
                        break;
                    case 2:
                        listarSitesUsuario(&u);// listar apps
                        break;
                    case 3:
                        printf("Retornando ao menu principal...\n");
                        break;
                    default:
                        printf("Opção invalida. Tente novamente.\n");
                    }

                    if (escolha == 3)
                    {
                        system("cls");

                        break;
                    }
                    //system("cls");
                }
            }
            else
            {
                printf("Login falhou. Verifique o nome de usuario e senha.\n");
            }
            break;

        case 2:
            registrarCadastro (&u);//  cadastro de usuário
            break;

        case 3:
            system("cls");

            while (1)
            {
                telaAdm();
                scanf("%d", &escolha);

                switch (escolha)
                {
                case 1:
                    desativarPorCPF(&u);//  remover usuário
                    break;
                case 2:
                    listarClientes(&u);//  listar 
                    break;
                case 3:
                    buscarPorCPF(&u);// consultar pelo cpf
                    break;
                case 4:
                    printf("Retornando ao menu principal...\n");
                    break;
                default:
                    printf("Opção invalida. Tente novamente.\n");
                }

                if (escolha == 4)
                {
                    break;
                }
            }
            break;

        case 4:
            printf("Saindo...\n");
            exit(0);
        default:
            printf("Opção invalida. Tente novamente.\n");
        }
    }

    return 0;
}