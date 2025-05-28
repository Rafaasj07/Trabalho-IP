#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

// Função que exibe o menu de ações do administrador.
// O fluxo é controlado por um loop 'do-while' e uma estrutura 'switch'.
void adm_funcoes(Cadastro *dados) {
    char acao_adm;
    do {
        // Desenha a interface do menu do administrador.
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c        Menu Administrador       %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        
        // Exibe as opções disponíveis para o administrador.
        ir_para(23, 9);
        ir_para(21, 9);
        printf("          1. LISTAGEM DE USUARIOS           ");
        ir_para(21, 10);
        printf("          2. LOCALIZAR USUARIO           ");
        ir_para(21, 11);
        printf("          3. EXCLUIR USUARIO           ");
        ir_para(21, 12);
        printf("          4. SAIR          ");

        // Solicita a entrada do administrador.
        ir_para(26, 14);
        printf("Digite a opcao que deseja: ");
        scanf("%c", &acao_adm);
        apaga_buffer(); // Limpa o buffer do teclado.

        // Trata a opção escolhida.
        switch (acao_adm) {
        case '1':
            limpar();
            listagem_usuario(); // Chama a função para listar todos os usuários.
            break;
        case '2':
            limpar();
            localiza_usuario(dados); // Chama a função para encontrar um usuário específico.
            break;
        case '3':
            limpar();
            excluir_usuario(dados); // Chama a função para remover um usuário.
            break;
        case '4': // Sair.
            ir_para(29, 16);
            limpar_linha();
            ir_para(32, 16);
            printf("\033[1;31mSaindo do programa...\033[0m");
            break;
        default: // Opção inválida.
            ir_para(29, 16);
            limpar_linha();
            ir_para(34, 16);
            printf("\033[1;31mDIGITO INVALIDO!\033[0m");
        }
    } while (acao_adm != '1' && acao_adm != '2' && acao_adm != '3' && acao_adm != '4'); // Repete o menu se a opção for inválida.
}