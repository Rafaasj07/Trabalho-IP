#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao login_usuario com os ponteiros
// atribuindo os enderecos das variaveis da main e fazendo comparacoes e modificacoes
void login(char P_nome_login[], char P_nome_cadastro[], char P_senha[], char P_pergunta[], char P_resposta[], int nome_ja_verificado)
{
    do // Repete ate o nome do cadastro ser igual ao nome do login
    {
        int deseja_repetir_nome;

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

        if (nome_ja_verificado == 1){ // Se o usuario existe eu não peço o nome do usuario, pois ele já existe. Caso ele não exista, eu peço o nome.
            ir_para(25, 10);          //1 para o usuario existir, 0 para não existir.
            printf("Nome: "); 
            fgets(P_nome_login, 50, stdin);
            P_nome_login[strcspn(P_nome_login, "\n")] = '\0';
        }else if(nome_ja_verificado == 0){ // Se ele existe, eu somente do um print do usuario q está fazendo a recuperação da senha. 
            ir_para(25, 10);
            printf("Nome: %s", P_nome_login);
        }
        if (strcmp(P_nome_login, P_nome_cadastro) == 0)
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

                if (strcmp(tentaiva_senha, P_senha) == 0)
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
                                recuperar_senha(P_nome_login, P_nome_cadastro,P_senha, P_pergunta, P_resposta);
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
    } while (strcmp(P_nome_login, P_nome_cadastro) != 0);
}
