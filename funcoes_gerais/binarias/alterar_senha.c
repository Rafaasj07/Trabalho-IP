#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

int alterar_senha(Cadastro *dados)
{
    FILE *arquivo;
    Cadastro ler_dados;
    char nova_senha[50];

    ir_para(25, 12);
    printf("Digite a nova senha: ");
    fgets(nova_senha, 50, stdin);
    nova_senha[strcspn(nova_senha, "\n")] = '\0'; // Remove o \n
    cifrar_cesar(nova_senha, 6);

    strcpy(dados->senha, nova_senha); // Atualiza a senha no struct

    const char *nome_arquivo = NULL;
    if (dados->menu_principal == '1')
    {
        nome_arquivo = "usuarios_cadastrados.bin";
    }
    else if (dados->menu_principal == '2')
    {
        nome_arquivo = "adms_cadastrados.bin";
    }
    arquivo = fopen(nome_arquivo, "r+b");

    if (arquivo == NULL)
    {
        ir_para(30, 16);
        printf("\033[1;31mNao foi possivel abrir ou criar o arquivo.\033[0m");
        return 1;
    }

    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1)
    {
        if (strcmp(ler_dados.nome, dados->nome) == 0)
        {
            fseek(arquivo, -(long)sizeof(Cadastro), SEEK_CUR); // Volta ao inicio do arquivo
            fwrite(dados, sizeof(Cadastro), 1, arquivo); // Escreve a nova senha
            break;
        }
    }

    fclose(arquivo);
    ir_para(27, 14);
    printf("\033[1;32mSenha atualizada com sucesso.\033[0m");
    return 0;
}
