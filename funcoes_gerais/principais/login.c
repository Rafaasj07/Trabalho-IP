#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao login_usuario com o ponteiro da instancia dados.
// Atribuindo como argumento da função, o endereco da instancia dados na main que contém: Nome, Senha, Pergunta e Resposta. Fazendo comparacoes e modificacoes nessa instancia.
void login(Cadastro *dados) 
{
    char tentaiva_nome[50];
    int existe_nome;
    do // Repete ate o nome do cadastro ser igual ao nome do login
    {
        int deseja_repetir_nome, existe_senha;
        
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

        existe_nome = verificar_nome(dados, tentaiva_nome); //Caso o nome exista no arquivo, retorna 1. Senão retorna 0.

        if (existe_nome == 1)
        {
            char tentaiva_senha[50];
            int aux_tentativa_senha = 0;

            do // Repeticao ate a senha ser correta
            {
                int deseja_recuperar;
                ir_para(25, 11);
                printf("Senha: ");
                fgets(tentaiva_senha, 50, stdin);
                tentaiva_senha[strcspn(tentaiva_senha, "\n")] = '\0';

                existe_senha = verificar_senha(dados, tentaiva_senha); //Caso a senha exista no arquivo, retorna 1. Senão retorna 0.

                if (existe_senha == 1)
                {
                    ir_para(29, 15);
                    printf("\033[1;32mAcesso ao programa liberado!\033[0m"); 
                }
                else
                {
                    ir_para(27, 15);
                    printf("\033[1;31mSenha Incorreta! Tente novamente.\033[0m");
                    aux_tentativa_senha++;

                    // A cada 5 tentativas, pergunta ao usuario se quer recuperar senha
                    if (aux_tentativa_senha % 5 == 0)
                    {
                        limpar();
                        do
                        {
                            printf("Deseja recuperar a senha? SIM [1] CONTINUAR TENTANDO [2] SAIR [3]\n");
                            scanf("%d", &deseja_recuperar);
                            apaga_buffer();
                            switch (deseja_recuperar)
                            {
                            case 1:
                                limpar();
                                recuperar_senha(dados);
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

            } while (existe_senha == 0);
        }

        else
        {
            
            // Se o usuario cadastrado for diferente do login, oferece opcao de tentar de novo ou sair
            ir_para(35, 12);
            printf("\033[1;31mUsuario nao existe\033[0m");
            ir_para(26, 13);
            printf("Deseja repetir o nome do Usuario?");
            ir_para(30,14);
            printf("[1] SIM  ou  [2] NAO  : ");
            scanf("%d", &deseja_repetir_nome);
            apaga_buffer();
            switch (deseja_repetir_nome)
            {
            case 1:
                limpar();
                continue;
            case 2:
                ir_para(24, 15);
                printf("\033[1;31mTentativa de Login mal sucedida.\033[0m");
                exit(0);
            default:
                ir_para(36, 15);
                printf("\033[1;31mComando Invalido.\033[0m");
                break;
            }
        }
    } while (existe_nome == 0);
}
