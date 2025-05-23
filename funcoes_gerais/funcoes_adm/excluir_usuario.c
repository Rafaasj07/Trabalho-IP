#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

void excluir_usuario(Cadastro *dados)
{
    limpar();
    bordas();
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c         Excluir Usuario         %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

    FILE *arquivo, *copia_arquivo;
    Cadastro ler_dados;
    char usuario[50];
    int encontrado = 0;

    ir_para(25, 10);
    printf("Nome do Usuario: ");
    fgets(usuario, 50, stdin);
    usuario[strcspn(usuario, "\n")] = '\0';

    arquivo = fopen("usuarios_cadastrados.bin", "rb");
    copia_arquivo = fopen("usuarios_copia.bin", "ab");
    
    if (arquivo == NULL || copia_arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1) // Enquanto tiver structs para ler, ele vai printando.
    {
        if (strcmp(ler_dados.nome, usuario) != 0) // Copia toda struct que tiver o nome diferente daquele q eu quero excluir
        {
            fwrite(&ler_dados, sizeof(Cadastro), 1, copia_arquivo); // Escreve a struct q tem o nome diferente daquele q eu quero excluir
        }
        else
        {
            encontrado = 1; //SE o nome for encontrado e não escrito no novo arquivo.
        }
    }

    fclose(arquivo);
    fclose(copia_arquivo);

    remove("usuarios_cadastrados.bin");
    rename("usuarios_copia.bin", "usuarios_cadastrados.bin");

    if (encontrado)
    {
        ir_para(29, 12);
        printf("\033[1;32mO usuario %s foi excluido.\033[0m",usuario );
    }else{
        ir_para(28, 12);
        printf("\033[1;31mO usuario %s nao foi encontrado.\033[0m",usuario);
    }
}
