#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

int alterar_senha(Cadastro *dados)
{
    FILE *arquivo;
    Cadastro ler_dados;
    char nova_senha[50];

    ir_para(27, 11);
    printf("Digite a nova senha: ");
    fgets(nova_senha, 50, stdin);
    nova_senha[strcspn(nova_senha, "\n")] = '\0'; // Remove o \n

    strcpy(dados->senha, nova_senha); // Atualiza a senha no struct

    const char *nome_arquivo = NULL;
    if (dados->menu_principal == 1)
    {
        nome_arquivo = "usuarios_cadastrados.bin";
    }
    else if (dados->menu_principal == 2)
    {
        nome_arquivo = "adms_cadastrados.bin";
    }
    arquivo = fopen(nome_arquivo, "r+b");

    if (arquivo == NULL)
    {
        ir_para(27, 13);
        printf("Nao foi possivel abrir ou criar o arquivo.\n");
        return 1;
    }

    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1)
    {
        if (strcmp(ler_dados.nome, dados->nome) == 0)
        {
            fseek(arquivo, -sizeof(Cadastro), SEEK_CUR);
            fwrite(dados, sizeof(Cadastro), 1, arquivo);
            break;
        }
    }

    fclose(arquivo);
    ir_para(27, 13);
    printf("Senha atualizada com sucesso.\n");
    return 0;
}
