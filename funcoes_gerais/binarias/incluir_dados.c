#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void incluir_dados(Cadastro *dados)
{
    const char *nome_arquivo = NULL;
    if (dados->menu_principal == 1)
    {
        nome_arquivo = "usuarios_cadastrados.bin";
    }
    else if (dados->menu_principal == 2)
    {
        nome_arquivo = "adms_cadastrados.bin";
    }

    FILE *arquivo = fopen(nome_arquivo, "ab"); // Alem da função ab criar o arquivo, ela tambem abre para gravação.
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para gravar.\n");
        exit(1);
    }

    fwrite(dados, sizeof(Cadastro), 1, arquivo); // Grava os arquivos
    fclose(arquivo);
}
