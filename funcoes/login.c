#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao login_usuario com os ponteiros
// atribuindo os enderecos das variaveis da main e fazendo comparacoes e modificacoes
void login(char P_nome_login[], char P_nome_cadastro[], char P_senha[], char P_pergunta[], char P_resposta[])
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
                getchar();
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
                        limpar();
                        do
                        {
                            printf("Deseja recuperar a senha? SIM [1] CONTINUAR TENTANDO [2] SAIR [3]\n");
                            scanf("%d", &deseja_recuperar);
                            switch (deseja_recuperar)
                            {
                            case 1:
                                limpar();
                                recuperar_senha(P_senha, P_pergunta, P_resposta);
                                exit(0);
                            case 2:
                                limpar();
                                break; // Fecha o laço
                            case 3:
                                printf("Tentativa de login mal sucedida.\n");
                                exit(0);
                            default:
                                limpar();
                                continue; // Pula pro proximo laço
                            }
                        } while (deseja_recuperar != 1 && deseja_recuperar != 2 && deseja_recuperar != 3);
                    }
                }

            } while (strcmp(tentaiva_senha, P_senha) != 0);
        }

        else
        {
            limpar();
            // Se o usuario cadastrado for diferente do login, oferece opcao de tentar de novo ou sair
            printf("Usuario nao existe, deseja repetir o nome do usuario? SIM [1] SAIR [2]\n");
            scanf("%d", &deseja_repetir_nome);
            switch (deseja_repetir_nome)
            {
            case 1:
                limpar();
                continue;
            case 2:
                printf("Tentativa de login mal sucedida.\n");
                exit(0);
            default:
                printf("Comando invalido.");
                break;
            }
        }
    } while (strcmp(P_nome_login, P_nome_cadastro) != 0);
}