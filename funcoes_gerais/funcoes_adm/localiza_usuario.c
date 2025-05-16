#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

char *localiza_usuario(Cadastro *dados, char localiza_usuario[50])
{
    FILE *arquivo;      // O ponteiro q faz referencia aos dados do meu arquivo.
    Cadastro ler_dados; // Instância temporária para ler os dados do arquivo.

    system("cls");
    int nome_existe;
    do // Repete ate o nome do cadastro ser igual ao nome a ser localizado
    {
        int deseja_repetir_nome, encontrou = 0;

        limpar();
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c              Localizar Usuario              %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        ir_para(24, 9);

        ir_para(25, 10);
        printf("Nome do Usuario: ");
        fgets(localiza_usuario, 50, stdin);
        localiza_usuario[strcspn(localiza_usuario, "\n")] = '\0';

        nome_existe = verificar_nome(dados, localiza_usuario); // Caso o nome exista no arquivo, retorna 1. Senão retorna 0.

        if (nome_existe == 1)
        {
            fread(&localiza_usuario, sizeof(Cadastro), 1, arquivo);
            while (encontrou == 0 && !feof(arquivo))
            {
                ir_para(23, 13);
                printf("Usuario : %s", dados->nome);
                ir_para(10, 15);
                printf("Pergunta secreta: %s", dados->pergunta);
                ir_para(10, 16);
                printf("Resposta: %s", dados->resposta);
                ir_para(10, 17);
                printf("Senha: ********** ");

                encontrou = 1;
            }
        }
        else
        {
            // Se o usuario não for encontrado, oferece opcao de tentar de novo ou sair
            ir_para(35, 12);
            printf("\033[1;31mUsuario nao encontrado\033[0m");
            ir_para(26, 13);
            printf("Deseja repetir o nome do Usuario?");
            ir_para(30, 14);
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
                printf("\033[1;31mUsuário não encontrado\033[0m");
                exit(0);
            default:
                ir_para(36, 15);
                printf("\033[1;31mComando Invalido.\033[0m");
                break;
            }
        }

    } while (nome_existe == 0);

    return 0;
}