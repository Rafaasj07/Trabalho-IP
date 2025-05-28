#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Função para incluir (gravar) os dados de uma struct 'Cadastro' em um arquivo binário.
void incluir_dados(Cadastro *dados) {
    // Determina o nome do arquivo com base na escolha do menu (usuário ou adm).
    const char *nome_arquivo = NULL;
    if (dados->menu_principal == '1') {
        nome_arquivo = "usuarios_cadastrados.bin";
    } else if (dados->menu_principal == '2') {
        nome_arquivo = "adms_cadastrados.bin";
    }

    // Abre o arquivo em modo "ab": append (adicionar) em modo binário.
    // Este modo abre o arquivo para escrita no final. Se o arquivo não existir, ele é criado.
    FILE *arquivo = fopen(nome_arquivo, "ab");
    if (arquivo == NULL) {
        ir_para(20, 16);
        printf("\033[1;31mNao foi possivel abrir ou criar o arquivo.\033[0m");
        exit(1); // Encerra o programa se houver falha.
    }

    // A função fwrite() escreve o bloco de dados da struct 'dados' no arquivo.
    // 1º arg: Ponteiro para os dados a serem escritos.
    // 2º arg: Tamanho de cada item a ser escrito.
    // 3º arg: Quantidade de itens a serem escritos.
    // 4º arg: Ponteiro para o arquivo.
    fwrite(dados, sizeof(Cadastro), 1, arquivo);
    fclose(arquivo); // Fecha o arquivo para garantir que os dados sejam salvos.
}