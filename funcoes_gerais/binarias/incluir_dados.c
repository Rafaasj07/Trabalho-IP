#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void incluir_dados(Cadastro *dados)
{
    FILE *arquivo = fopen("dados_cadastrados.bin", "ab"); //Alem da função ab criar o arquivo, ela tambem abre para gravaçã.
    if (arquivo == NULL)//Caso o arquivo não exista
    {
        printf("Erro ao abrir o arquivo para gravar.\n");
        exit(1);
    }

    fwrite(dados, sizeof(Cadastro), 1, arquivo);//Grava os arquivos
    fclose(arquivo);
}
