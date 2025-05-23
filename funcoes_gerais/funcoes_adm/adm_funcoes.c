#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void adm_funcoes(Cadastro *dados)
{
    char acao_adm;
    do
    {
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c        Menu Administrador       %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        ir_para(23, 9);
        ir_para(21, 9);
        printf("          1. LISTAGEM DE USUARIOS           ");
        ir_para(21, 10);
        printf("          2. LOCALIZAR USUARIO           ");
        ir_para(21, 11);
        printf("          3. EXCLUIR USUARIO           ");
        ir_para(21, 12);
        printf("          4. SAIR          ");
        ir_para(26, 14);
        printf("Digite a opcao que deseja: ");
        scanf("%c", &acao_adm);
        apaga_buffer();

        switch (acao_adm)
        {
        case '1':
            limpar();
            listagem_usuario();
            break;
        case '2':
            limpar();
            localiza_usuario(dados);
            break;
        case '3':
            limpar();
            excluir_usuario(dados);
            break;
        case '4': // adm quer sair
            ir_para(29, 16);
            limpar_linha();
            ir_para(32, 16);
            printf("\033[1;31mSaindo do programa...\033[0m");
            break;
        default:
            ir_para(29, 16);
            limpar_linha();
            ir_para(34, 16);
            printf("\033[1;31mDIGITO INVALIDO!\033[0m");
        }
    } while (acao_adm != '1' && acao_adm != '2' && acao_adm != '3' && acao_adm != '4');
}