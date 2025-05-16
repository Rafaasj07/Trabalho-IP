#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao de recuperacao de senha
void recuperar_senha(Cadastro *dados) // Lembre-se, dados é o ponteiro para a instancia la na main.
{
    char tentativa_resposta[100], tentativa_nome[50];
    int continuar_tent, nome_existe;

    bordas();
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c       Recuperacao de Senha      %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

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
            ir_para(22, 10);
            printf("Pergunta: %s", dados->pergunta);
            ir_para(30, 11);
            printf("\33[2K\r");
            bordas();
            ir_para(30, 11);
            printf("Resposta: ");
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
                    ir_para(21, 13);
                    printf("Resposta Incorreta, quer continuar tentando?");
                    ir_para(36, 14);
                    printf("[1] SIM  [2] SAIR");
                    ir_para(40, 15);
                    printf("R: ");

                    scanf("%d", &continuar_tent);
                    apaga_buffer();
                    switch (continuar_tent)
                    {
                    case 1:
                        ir_para(21, 13);
                        printf("\33[2K\r");
                        ir_para(36, 14);
                        printf("\33[2K\r");
                        ir_para(40, 15);
                        printf("\33[2K\r");
                        bordas();
                        break;
                    case 2:
                        exit(0);
                    default:
                        ir_para(21, 13);
                        printf("\33[2K\r");
                        ir_para(36, 14);
                        printf("\33[2K\r");
                        ir_para(40, 15);
                        printf("\33[2K\r");
                        bordas();
                        break;
                    }
                } while (continuar_tent != 1 && continuar_tent != 2);
            }
        }
    } while (strcmp(tentativa_resposta, dados->resposta) != 0);
}
