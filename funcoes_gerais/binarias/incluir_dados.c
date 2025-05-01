#include <stdio.h>
#include "prototipos.h"

void incluir_dados(Cadastro *dados)
{
    FILE *arquivo; // O ponteiro q faz referencia aos dados do meu arquivo.
    arquivo = fopen("dados_cadastrados.bin", "ab"); // fopen abre o arquivo e o ab tem a função de abri-lo caso exista e abre para gravação, (conserva o conteudo já gravado anteriormente).Caso não exista ele cria o arquivo "dados_cadastrados.dat".
    if (arquivo == NULL) // Tratando possiveis erros.
    {
        printf("Não foi possível criar ou abrir o arquivo.\n");
    }
    else
    {
        // Gravar dados no final do arquivo
        fwrite(dados, sizeof(Cadastro), 1, arquivo);
        fclose(arquivo);
    }
}
