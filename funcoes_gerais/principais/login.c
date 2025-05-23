#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao login_usuario com o ponteiro da instancia dados.
// Atribuindo como argumento da função, o endereco da instancia dados na main que contém: Nome, Senha, Pergunta e Resposta. Fazendo comparacoes e modificacoes nessa instancia.
void login(Cadastro *dados)
{
    char tentaiva_nome[50];
    int nome_existe;
    do // Repete ate o nome do cadastro ser igual ao nome do login
    {
        limpar();
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c              Login              %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        ir_para(24, 9);

        ir_para(25, 10);
        printf("Nome: ");
        fgets(tentaiva_nome, 50, stdin);
        tentaiva_nome[strcspn(tentaiva_nome, "\n")] = '\0';

        nome_existe = verificar_nome(dados, tentaiva_nome); // Caso o nome exista no arquivo, retorna 1. Senão retorna 0.

        if (nome_existe == 1)
        {
            char tentaiva_senha[50];
            int aux_tentativa_senha = 0;

            do // Repeticao ate a senha ser correta
            {
                ir_para(6, 11);
                limpar_linha();
                ir_para(25, 11);
                printf("Senha: ");
                fgets(tentaiva_senha, 50, stdin);
                tentaiva_senha[strcspn(tentaiva_senha, "\n")] = '\0';
                cifrar_cesar(tentaiva_senha, 6);
                
                if (strcmp(dados->senha, tentaiva_senha) == 0)
                {
                    ir_para(25, 15);
                    printf("                                               ");
                    ir_para(29, 16);
                    printf("\033[1;32mAcesso ao programa liberado!\033[0m");
                    break;
                }
                else
                {
                    ir_para(25, 15);
                    printf("\033[1;31mSenha Incorreta! Tente novamente.\033[0m");
                    aux_tentativa_senha++;

                    // A cada 5 tentativas erradas, pergunta ao usuario se quer recuperar senha
                    if (aux_tentativa_senha % 3 == 0)
                    {
                        char deseja_recuperar;
                        do
                        {
                            ir_para(25, 15);
                            printf("     Deseja recuperar a senha?     ");
                            ir_para(22, 16);
                            printf("[1] SIM [2] CONTINUAR TENTANDO [3] SAIR : ");
                            scanf("%c", &deseja_recuperar);
                            apaga_buffer();
                            switch (deseja_recuperar)
                            {
                            case '1':
                                limpar();
                                recuperar_senha(dados);
                                char mensagem_email[200];
                                snprintf(mensagem_email, sizeof(mensagem_email), "%s você alterou sua senha em nosso Sistema.", dados->nome);
                                envia_email(dados, mensagem_email);
                                exit(0);
                            case '2':
                                ir_para(25, 15);
                                limpar_linha();
                                ir_para(22, 16);
                                limpar_linha();
                                bordas();
                                break; // Fecha o laço
                            case '3':
                                ir_para(29, 19);
                                printf("\033[1;31mTentativa de login mal sucedida.\033[0m");
                                exit(0);
                            default:
                                break;
                            }
                        } while (deseja_recuperar != '1' && deseja_recuperar != '2' && deseja_recuperar != '3');
                    }
                }

            } while (strcmp(dados->senha, tentaiva_senha) != 0);
        }

        else
        {
            // Se o usuario cadastrado for diferente do login, oferece opcao de tentar de novo ou sair
            char deseja_repetir_nome;
            do
            {
                ir_para(35, 12);
                printf("\033[1;31mUsuario nao existe\033[0m");
                ir_para(26, 14);
                printf("Deseja repetir o nome do usuario?");
                ir_para(30, 15);
                printf("[1] SIM  ou  [2] NAO  : ");
                scanf("%c", &deseja_repetir_nome);
                apaga_buffer();
                switch (deseja_repetir_nome)
                {
                case '1':
                    limpar();
                    continue;
                case '2':
                    ir_para(29, 19);
                    printf("\033[1;31mTentativa de Login mal sucedida.\033[0m");
                    exit(0);
                default:
                    ir_para(36, 17);
                    printf("\033[1;31mDigito Invalido.\033[0m");
                    break;
                }
            } while (deseja_repetir_nome != '1' && deseja_repetir_nome != '2');
        }
    } while (nome_existe == 0);
}
