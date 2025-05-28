#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

// Função para excluir um usuário do arquivo de cadastros.
void excluir_usuario(Cadastro *dados) {
    Cadastro busca_dados;
    busca_dados.menu_principal = '1'; // Configura para pesquisar no arquivo de usuários.

    // Desenha a interface de exclusão.
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
    char usuario[37];
    int encontrado = 0;
    int nome_existe;

    // Loop para garantir que um nome de usuário existente seja fornecido.
    do {
        ir_para(25, 9);
        limpar_linha();
        ir_para(25, 9);
        printf("Nome: ");
        fgets(usuario, sizeof(usuario), stdin);

        // Trata a entrada do usuário, limpando o buffer se necessário.
        if (strchr(usuario, '\n'))
            usuario[strcspn(usuario, "\n")] = '\0';
        else
            apaga_buffer();

        // Verifica se o usuário a ser excluído realmente existe.
        nome_existe = verificar_nome(&busca_dados, usuario);

        if (nome_existe == 0) {
            ir_para(33, 14);
            printf("\033[1;31mUsuario nao existe!\033[0m");
        }
    } while (nome_existe == 0);

    ir_para(33, 14);
    limpar_linha();

    // Abre o arquivo original para leitura e um arquivo de cópia para escrita.
    arquivo = fopen("usuarios_cadastrados.bin", "rb");
    copia_arquivo = fopen("usuarios_copia.bin", "ab");

    if (arquivo == NULL || copia_arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    // Lê o arquivo original registro por registro.
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1) {
        // Se o nome lido for diferente do nome a ser excluído,
        // escreve o registro no arquivo de cópia.
        if (strcmp(ler_dados.nome, usuario) != 0) {
            fwrite(&ler_dados, sizeof(Cadastro), 1, copia_arquivo);
        } else {
            encontrado = 1; // Marca que o usuário foi encontrado (e não copiado).
        }
    }

    fclose(arquivo);
    fclose(copia_arquivo);

    // Remove o arquivo original e renomeia o arquivo de cópia para o nome original.
    // Este é o método padrão para "excluir" um item de um arquivo.
    remove("usuarios_cadastrados.bin");
    rename("usuarios_copia.bin", "usuarios_cadastrados.bin");

    if (encontrado) {
        ir_para(29, 14);
        printf("\033[1;32mO usuario %s foi excluido.\033[0m", usuario);
    } else {
        ir_para(28, 14);
        printf("\033[1;31mO usuario %s nao foi encontrado.\033[0m", usuario);
    }

    // Finaliza o programa após a operação.
    ir_para(4, 23);
    printf("Operacao de exclusao finalizada. Encerrando o programa...");
    exit(0);
}