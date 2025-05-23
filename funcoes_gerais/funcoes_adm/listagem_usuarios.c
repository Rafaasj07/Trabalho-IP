#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void listagem_usuario(void)
{
    FILE *arquivo;
    Cadastro ler_dados;

    arquivo = fopen("usuarios_cadastrados.bin", "rb");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c      Listagem de Usuarios       %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    printf("\n");
    int total_cadastros = 0;
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1) // Enquanto tiver structs para ler, ele vai printando.
    {
        total_cadastros++;
        printf("Nome: %s\n", ler_dados.nome);
        printf("CPF: %s\n", ler_dados.cpf);
        printf("EMAIL: %s\n", ler_dados.email);
        printf("Senha: %s\n", ler_dados.senha);
        printf("Resposta: %s\n", ler_dados.resposta);
        printf("\n");
    }
    fclose(arquivo);
    printf("TOTAL DE USUARIOS CADASTRADOS: %d", total_cadastros);
}
