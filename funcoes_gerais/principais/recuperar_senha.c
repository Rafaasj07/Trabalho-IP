#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao de recuperacao de senha
void recuperar_senha(Cadastro *dados) // Lembre-se, dados é o ponteiro para a instancia la na main.
{
    char tentativa_resposta[100], tentativa_nome[50];
    int nome_existe;

    limpar();
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
        char deseja_sair;
        ir_para(25, 9);                                         
        limpar_linha();
        ir_para(27, 8);
        printf("\033[1;31m      Usuario nao existe!       \033[0m");
        ir_para(20, 10);
        printf("         Deseja tentar outro usuario?         ");
        ir_para(31, 11);
        printf("   [1] SIM  [2] SAIR : ");
        scanf("%c", &deseja_sair);
        apaga_buffer();
        switch (deseja_sair)
        {
        case '1':
            ir_para(27, 8);
            limpar_linha();
            ir_para(20, 10);
            limpar_linha();
            ir_para(31, 11);
            limpar_linha();
            ir_para(25, 9);
            printf("Nome: ");
            fgets(tentativa_nome, 50, stdin);
            tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';
            nome_existe = verificar_nome(dados, tentativa_nome);
            break;
        case '2':
            ir_para(17, 13);
            printf("\033[1;31mTentativa de recuperacao de senha, mal sucessida.\033[0m");
            exit(0);
            break;
        default:
            break;
        }
    }
    do
    {
        if (nome_existe == 1)
        {
            ir_para(25, 10);
            printf("Pergunta: %s", dados->pergunta);
            bordas();
            ir_para(25, 11);
            limpar_linha();
            ir_para(25, 11);
            printf("Resposta: ");
            fgets(tentativa_resposta, 100, stdin);
            tentativa_resposta[strcspn(tentativa_resposta, "\n")] = '\0';
            cifrar_cesar(tentativa_resposta, 6);
            
            if (strcmp(tentativa_resposta, dados->resposta) == 0)
            {
                alterar_senha(dados);
            }
            else
            {
                char continuar_tent;
                do
                {
                    ir_para(21, 13);
                    printf("Resposta Incorreta, quer continuar tentando?");
                    ir_para(34, 14);
                    printf("[1] SIM  [2] SAIR : ");
                    scanf("%c", &continuar_tent);
                    apaga_buffer();
                    switch (continuar_tent)
                    {
                    case '1':
                        ir_para(21, 13);
                        limpar_linha();
                        ir_para(34, 14);
                        limpar_linha();
                        bordas();
                        break;
                    case '2':
                        ir_para(17, 16);
                        printf("\033[1;31mTentativa de recuperacao de senha, mal sucessida.\033[0m");
                        exit(0);
                    default:
                        break;
                    }
                } while (continuar_tent != '1' && continuar_tent != '2');
            }
        }
    } while (strcmp(tentativa_resposta, dados->resposta) != 0);
}
