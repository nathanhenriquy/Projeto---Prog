#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "cadastros.h"
#include "adm.h"

int main()
{
    int escolha;

    struct cadastro u; // u seria de usuário, coloquei simplicado para não ficar muita coisa na hora de fazer os scanfs

    telaMenu();

    while (1)
    {

        telaMenu();
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            if ()// aqui vai ser a parte de login
            {
                printf("Login bem-sucedido!\n");
                while (1)
                {
                    gerenciadorUsuario();
                    scanf("%d", &escolha);

                    switch (escolha)
                    {
                    case 1:
                        // adicionar aqui é para adicionar site
                        break;
                    case 2:
                        // adicionar aqui é para listar sites
                        break;
                    case 3:
                        printf("Retornando ao menu principal...\n");
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                    }

                    if (escolha == 3)
                    {
                        break;
                    }
                }
            }
            else
            {
                printf("Login falhou. Verifique o nome de usuário e senha.\n");
            }
            break;

        case 2:
            // adicionar aqui é para cadastro de usuário
            break;

        case 3:
            while (1)
            {
                telaAdm();
                scanf("%d", &escolha);

                switch (escolha)
                {
                case 1:
                    // adicionar aqui é para remover usuário
                    break;
                case 2:
                    // adicionar aqui é para listar 
                    break;
                case 3:
                   // adicionar aqui é para consultar pelo cpf
                    break;
                case 4:
                    printf("Retornando ao menu principal...\n");
                    break;
                default:
                    printf("Opção inválida. Tente novamente.\n");
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
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
