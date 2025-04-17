#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao login_usuario com os ponteiros
// atribuindo os enderecos das variaveis da main e fazendo comparacoes e modificacoes
void login(char P_nome_login[], char P_nome_cadastro[], char P_senha[])
{
    do // Repete ate o nome do cadastro ser igual ao nome do login
    {
        int deseja_repetir_nome;
        printf("LOGIN\n");
        printf("Nome:\n");
        getchar();
        fgets(P_nome_login, 50, stdin);
        P_nome_login[strcspn(P_nome_login, "\n")] = '\0';

        if (strcmp(P_nome_login, P_nome_cadastro) == 0)
        {
            char tentaiva_senha[50];
            int aux_tentativa_senha = 0;

            do // Repeticao ate a senha ser correta
            {
                int deseja_recuperar;
                printf("Senha:\n");
                fgets(tentaiva_senha, 50, stdin);
                tentaiva_senha[strcspn(tentaiva_senha, "\n")] = '\0';

                if (strcmp(tentaiva_senha, P_senha) == 0)
                {
                    printf("Acesso ao programa liberado.\n");
                }
                else
                {
                    printf("Senha incorreta, tente novamente!\n");
                    aux_tentativa_senha++;

                    // A cada 5 tentativas, pergunta ao usuario se quer recuperar senha
                    if (aux_tentativa_senha % 5 == 0)
                    {
                        printf("Deseja recuperar a senha? SIM [1] CONTINUAR TENTANDO [2] SAIR [3]\n");
                        scanf("%d", &deseja_recuperar);
                        switch (deseja_recuperar)
                        {
                        case 1:
                            printf("FUNCAO RECUPERAR...\n");
                            recuperar_senha();
                            exit(0);
                        case 2:
                            break;
                        default:
                            printf("Tentativa de login mal sucedida.\n");
                            exit(0);
                        }
                    }
                }

            } while (strcmp(tentaiva_senha, P_senha) != 0);
        }

        else
        {
            // Se o usuario cadastrado for diferente do login, oferece opcao de tentar de novo ou sair
            printf("Usuario nao existe, deseja repetir o nome do usuario? SIM [1] SAIR [2]\n");
            scanf("%d", &deseja_repetir_nome);
            if (deseja_repetir_nome == 2)
            {
                printf("Tentativa de login mal sucedida.\n");
                exit(0);
            }else if (deseja_repetir_nome == 1)
                continue; //Pula pro proximo ciclo do loop
        }
    } while (strcmp(P_nome_login, P_nome_cadastro) != 0);
}