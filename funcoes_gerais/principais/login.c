#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Função que realiza o login do usuário ou administrador.
// Recebe um ponteiro para a struct 'dados' para carregar as informações do usuário logado.
void login(Cadastro *dados) {
    char tentativa_nome[37];
    int nome_existe;

    // Loop principal de login, repete até que um usuário existente seja inserido.
    do {
        limpar();
        bordas();
        // Desenha a interface de login.
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c              Login              %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        ir_para(24, 9);

        // Pede o nome de usuário.
        ir_para(25, 10);
        printf("Nome: ");
        fgets(tentativa_nome, sizeof(tentativa_nome), stdin);
        tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';

        // Verifica se o nome existe no arquivo binário.
        // Se existir, os dados do usuário são carregados na struct 'dados'.
        nome_existe = verificar_nome(dados, tentativa_nome);

        if (nome_existe == 1) { // Se o nome foi encontrado.
            char tentativa_senha[22];
            int aux_tentativa_senha = 0;

            // Loop para a senha, repete até a senha estar correta.
            do {
                ir_para(6, 11);
                limpar_linha();
                ir_para(25, 11);
                printf("Senha: ");
                fgets(tentativa_senha, sizeof(tentativa_senha), stdin);
                tentativa_senha[strcspn(tentativa_senha, "\n")] = '\0';

                // Compara a senha digitada com a senha armazenada (carregada pelo verificar_nome).
                if (strcmp(dados->senha, tentativa_senha) == 0) {
                    ir_para(25, 15);
                    printf("                                               ");
                    ir_para(29, 16);
                    printf("\033[1;32mAcesso ao programa liberado!\033[0m");
                    break; // Senha correta, sai do loop da senha.
                } else {
                    // Se a senha estiver incorreta.
                    ir_para(25, 15);
                    printf("\033[1;31mSenha Incorreta! Tente novamente.\033[0m");
                    aux_tentativa_senha++; // Incrementa o contador de tentativas.

                    // A cada 3 tentativas erradas, oferece a opção de recuperação de senha.
                    if (aux_tentativa_senha % 3 == 0) {
                        char deseja_recuperar;
                        do {
                            ir_para(25, 15);
                            printf("     Deseja recuperar a senha?     ");
                            ir_para(22, 16);
                            printf("[1] SIM [2] CONTINUAR TENTANDO [3] SAIR : ");
                            scanf("%c", &deseja_recuperar);
                            apaga_buffer();
                            switch (deseja_recuperar) {
                            case '1': // Inicia a recuperação de senha.
                                limpar();
                                recuperar_senha(dados);
                                char mensagem_email[200];
                                snprintf(mensagem_email, sizeof(mensagem_email), "%s você alterou sua senha em nosso Sistema.", dados->nome);
                                envia_email(dados, mensagem_email);
                                exit(0); // Encerra o programa após a recuperação.
                            case '2': // Volta para a tentativa de senha.
                                ir_para(25, 15);
                                limpar_linha();
                                ir_para(22, 16);
                                limpar_linha();
                                bordas();
                                break;
                            case '3': // Sai do programa.
                                ir_para(29, 19);
                                printf("\033[1;31mTentativa de login mal sucedida.\033[0m");
                                exit(0);
                            default: // Opção inválida.
                                break;
                            }
                        } while (deseja_recuperar != '1' && deseja_recuperar != '2' && deseja_recuperar != '3');
                    }
                }
            } while (strcmp(dados->senha, tentativa_senha) != 0);
        } else { // Se o nome de usuário não foi encontrado.
            char deseja_repetir_nome;
            do {
                ir_para(35, 12);
                printf("\033[1;31mUsuario nao existe\033[0m");
                ir_para(26, 14);
                printf("Deseja repetir o nome do usuario?");
                ir_para(30, 15);
                printf("[1] SIM  ou  [2] NAO  : ");
                scanf("%c", &deseja_repetir_nome);
                apaga_buffer();
                switch (deseja_repetir_nome) {
                case '1':
                    limpar(); // Limpa a tela para tentar de novo.
                    continue; // Pula para a próxima iteração do loop 'do-while' principal.
                case '2':
                    ir_para(29, 19);
                    printf("\033[1;31mTentativa de Login mal sucedida.\033[0m");
                    exit(0); // Sai do programa.
                default:
                    ir_para(36, 17);
                    printf("\033[1;31mDigito Invalido.\033[0m");
                    break;
                }
            } while (deseja_repetir_nome != '1' && deseja_repetir_nome != '2');
        }
    } while (nome_existe == 0); // Repete o processo de login se o nome não existir.
}