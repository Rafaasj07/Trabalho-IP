#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao de recuperacao de senha
void recuperar_senha(char P_nome_login[], char P_nome_cadastro[], char P_senha[], char P_pergunta[], char P_resposta[])
{
    char tentativa_resposta[100];
    int continuar_tent, deseja_login;
    do
    {
        printf("%s\n", P_pergunta);
        fgets(tentativa_resposta, 100, stdin);
        tentativa_resposta[strcspn(tentativa_resposta, "\n")] = '\0';
        if (strcmp(tentativa_resposta, P_resposta) == 0)
        {
            printf("Mude sua senha:\n");
            fgets(P_senha, 100, stdin);
            P_senha[strcspn(P_senha, "\n")] = '\0';
            limpar();
            do
            {
                printf("Senha altera com sucesso.\n");
                printf("Deseja fazer login novamente?\nSIM [1] ou Nao [2]\n");
                scanf("%d", &deseja_login);
                switch (deseja_login)
                {
                case 1:
                    login(P_nome_login, P_nome_cadastro, P_senha, P_pergunta, P_resposta, 0);
                    break;
                case 2:
                    exit(0);
                default:
                    limpar();
                    break;
                }
            } while (deseja_login != 1 && deseja_login != 2);

            break;
        }
        else
        {
            limpar();
            printf("Resposta Incorreta, quer continuar tentando?\nSIM [1] SAIR [2]\n");
            scanf("%d", &continuar_tent);
            apaga_buffer();
            switch (continuar_tent)
            {
            case 1:
                limpar();
                break;
            default:
                printf("Erro ao recuperar senha.");
                exit(0);
            }
        }

    } while (strcmp(tentativa_resposta, P_resposta) != 0);
}