#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Função para recuperar a senha do usuário.
// Recebe um ponteiro para 'dados' para carregar os dados do usuário e alterar a senha.
void recuperar_senha(Cadastro *dados) {
    char tentativa_resposta[52], tentativa_nome[37];
    int nome_existe;

    // Limpa a tela e desenha a interface de recuperação.
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

    // Pede o nome de usuário para iniciar a recuperação.
    ir_para(25, 9);
    printf("Nome: ");
    fgets(tentativa_nome, sizeof(tentativa_nome), stdin);
    tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';
    nome_existe = verificar_nome(dados, tentativa_nome); // Verifica se o usuário existe.

    // Loop caso o nome não seja encontrado.
    while (nome_existe == 0) {
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
        switch (deseja_sair) {
        case '1':
            // Limpa os campos para uma nova tentativa.
            ir_para(27, 8);
            limpar_linha();
            ir_para(20, 10);
            limpar_linha();
            ir_para(31, 11);
            limpar_linha();
            ir_para(25, 9);
            printf("Nome: ");
            fgets(tentativa_nome, sizeof(tentativa_nome), stdin);
            tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';
            nome_existe = verificar_nome(dados, tentativa_nome); // Tenta verificar o nome novamente.
            break;
        case '2':
            ir_para(17, 13);
            printf("\033[1;31mTentativa de recuperacao de senha, mal sucedida.\033[0m");
            exit(0); // Encerra o programa.
        default:
            break;
        }
    }

    // Loop para verificar a resposta da pergunta secreta.
    do {
        if (nome_existe == 1) { // Garante que o usuário foi encontrado.
            ir_para(25, 10);
            printf("Pergunta: %s", dados->pergunta); // Exibe a pergunta de segurança do usuário.
            bordas();
            ir_para(25, 11);
            limpar_linha();
            ir_para(25, 11);
            printf("Resposta: ");
            fgets(tentativa_resposta, sizeof(tentativa_resposta), stdin);
            tentativa_resposta[strcspn(tentativa_resposta, "\n")] = '\0';

            // Compara a resposta digitada com a resposta armazenada.
            if (strcmp(tentativa_resposta, dados->resposta) == 0) {
                // Se a resposta estiver correta, permite a alteração da senha.
                alterar_senha(dados);
            } else {
                // Se a resposta estiver incorreta.
                char continuar_tent;
                do {
                    ir_para(21, 13);
                    printf("Resposta Incorreta, quer continuar tentando?");
                    ir_para(34, 14);
                    printf("[1] SIM  [2] SAIR : ");
                    scanf("%c", &continuar_tent);
                    apaga_buffer();
                    switch (continuar_tent) {
                    case '1':
                        // Limpa as mensagens de erro para tentar novamente.
                        ir_para(21, 13);
                        limpar_linha();
                        ir_para(34, 14);
                        limpar_linha();
                        bordas();
                        break;
                    case '2':
                        ir_para(17, 16);
                        printf("\033[1;31mTentativa de recuperacao de senha, mal sucedida.\033[0m");
                        exit(0); // Encerra o programa.
                    default:
                        break;
                    }
                } while (continuar_tent != '1' && continuar_tent != '2');
            }
        }
    } while (strcmp(tentativa_resposta, dados->resposta) != 0); // Repete se a resposta for incorreta.
}