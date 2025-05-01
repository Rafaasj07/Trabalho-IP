#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void inicializar_arquivo()
{
    FILE *arquivo = fopen("dados_cadastrados.bin", "ab"); //Cria o arquivo
    if (arquivo == NULL)//Se não for possivel criar, gera erro.
    {
        printf("Erro ao criar o arquivo de dados.\n");
        exit(1); //	Finalização com erro
    }
    fclose(arquivo);
}
