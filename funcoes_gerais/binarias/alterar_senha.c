#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Função para alterar a senha de um usuário já existente.
int alterar_senha(Cadastro *dados) {
    FILE *arquivo;
    Cadastro ler_dados;
    char nova_senha[22];

    // Pede ao usuário para digitar a nova senha.
    ir_para(25, 12);
    printf("Digite a nova senha: ");
    fgets(nova_senha, sizeof(nova_senha), stdin);
    nova_senha[strcspn(nova_senha, "\n")] = '\0';

    // Atualiza a senha na struct 'dados' que está em memória.
    strcpy(dados->senha, nova_senha);

    // Determina qual arquivo binário deve ser modificado (usuários ou administradores).
    const char *nome_arquivo = NULL;
    if (dados->menu_principal == '1') {
        nome_arquivo = "usuarios_cadastrados.bin";
    } else if (dados->menu_principal == '2') {
        nome_arquivo = "adms_cadastrados.bin";
    }

    // Abre o arquivo em modo "r+b": leitura e escrita em binário.
    // O "+" permite que o arquivo seja atualizado sem ser completamente apagado.
    arquivo = fopen(nome_arquivo, "r+b");

    if (arquivo == NULL) {
        ir_para(20, 16);
        printf("\033[1;31mNao foi possivel abrir ou criar o arquivo.\033[0m");
        return 1; // Retorna 1 para indicar erro.
    }

    // Lê o arquivo registro por registro.
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1) {
        // Compara o nome do registro lido com o nome do usuário que está alterando a senha.
        if (strcmp(ler_dados.nome, dados->nome) == 0) {
            // Se encontrou o usuário, o "ponteiro" de leitura do arquivo está no final do registro lido.
            // A função fseek() é usada para mover o ponteiro de volta para o início desse mesmo registro.
            fseek(arquivo, -(long)sizeof(Cadastro), SEEK_CUR);

            // Agora, com o ponteiro na posição correta, sobrescreve o registro antigo com os novos dados.
            fwrite(dados, sizeof(Cadastro), 1, arquivo);
            break; // Sai do loop, pois o trabalho está feito.
        }
    }

    fclose(arquivo); // Fecha o arquivo.
    ir_para(27, 14);
    printf("\033[1;32mSenha atualizada com sucesso.\033[0m");
    return 0; // Retorna 0 para indicar sucesso.
}