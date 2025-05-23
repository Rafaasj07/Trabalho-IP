#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

int verificar_nome(Cadastro *dados, char tentativa_nome[])
{
    FILE *arquivo;      // O ponteiro q faz referencia aos dados do meu arquivo.
    Cadastro ler_dados; // Instância temporária para ler os dados do arquivo. Do tipo Cadastro.

    const char *nome_arquivo = NULL;
    if (dados->menu_principal == '1')
    {
        nome_arquivo = "usuarios_cadastrados.bin";
    }
    else if (dados->menu_principal == '2')
    {
        nome_arquivo = "adms_cadastrados.bin";
    }

    // Abrir o arquivo
    arquivo = fopen(nome_arquivo, "rb"); // fopen abre o arquivo e o rb tem a função de abri-lo caso exista e abre para leitura.

    if (arquivo == NULL) // Tratando possiveis erros.
    {
        ir_para(30, 16);
        printf("\033[1;31mNao foi possivel abrir ou criar o arquivo.\033[0m");
        exit(1);
    }

    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1)
    {
        // Se encontrar nome iguail ao digitado
        if (strcmp(ler_dados.nome, tentativa_nome) == 0)
        {
            *dados = ler_dados; // Preencho o objeto lá na main com os dados encontrados.
            fclose(arquivo);
            return 1; // Nome válido
        }
    }

    fclose(arquivo);
    return 0; // Nome inválido, se não encontrar o nome
}
