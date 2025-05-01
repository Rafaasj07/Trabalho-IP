#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao de recuperacao de senha
void recuperar_senha(Cadastro *dados) // Lembre-se, dados é o ponteiro para a instancia la na main.
{
    char tentativa_resposta[100], tentativa_nome[50];
    int continuar_tent, nome_existe;

    ir_para(25, 9);
    printf("Nome: ");
    fgets(tentativa_nome, 50, stdin);
    tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';
    nome_existe = verificar_nome(dados, tentativa_nome);
    while (nome_existe == 0)
    {
        int deseja_sair;
        printf("\033[1;31mUsuario nao existe![1] Tente outro [2] Sair\033[0m \n");
        scanf("%d", &deseja_sair);
        apaga_buffer();
        switch (deseja_sair)
        {
        case 1:
            ir_para(25, 9);
            printf("Nome: ");
            fgets(tentativa_nome, 50, stdin);
            tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';
            nome_existe = verificar_nome(dados, tentativa_nome);
            break;
        case 2:
            exit(0);
        default:
            limpar();
            break;
        }
    }
    do
    {
        if (nome_existe == 1)
        {
            printf("%s\n", dados->pergunta);
            fgets(tentativa_resposta, 100, stdin);
            tentativa_resposta[strcspn(tentativa_resposta, "\n")] = '\0';
            if (strcmp(tentativa_resposta, dados->resposta) == 0)
            {
                limpar();
                alterar_senha(dados);
            }
            else
            {
                do
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
                    case 2:
                        exit(0);
                    default:
                        limpar();
                        break;
                    }
                } while (continuar_tent != 1 && continuar_tent != 2);
            }
        }
    }while (strcmp(tentativa_resposta, dados->resposta) != 0);
}
