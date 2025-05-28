#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

// Função que lista todos os usuários cadastrados no arquivo "usuarios_cadastrados.bin".
void listagem_usuario(void) {
    FILE *arquivo;
    Cadastro ler_dados;

    // Abre o arquivo de usuários para leitura em modo binário ("rb").
    arquivo = fopen("usuarios_cadastrados.bin", "rb");
    if (arquivo == NULL) {
        // Se o arquivo não puder ser aberto (provavelmente não existe), informa o usuário.
        ir_para(28, 12);
        printf("Nenhum usuario cadastrado ainda.");
        ir_para(26, 14);
        printf("Encerrando o programa...");
        exit(0);
    }

    // Desenha a interface de listagem.
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c      Listagem de Usuarios       %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    printf("\n");

    int total_cadastros = 0;
    // Loop para ler o arquivo.
    // fread() lê um bloco de dados (sizeof(Cadastro)) do arquivo.
    // O loop continua enquanto fread() retornar 1 (significando que 1 bloco foi lido com sucesso).
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1) {
        total_cadastros++;
        // Imprime os dados de cada usuário lido.
        printf("  Nome: %s\n", ler_dados.nome);
        printf("  CPF: %s\n", ler_dados.cpf);
        printf("  EMAIL: %s\n", ler_dados.email);
        printf("\n");
    }
    fclose(arquivo); // Fecha o arquivo após a leitura.
    printf("  TOTAL DE USUARIOS CADASTRADOS: %d", total_cadastros);

    // Finaliza o programa após a listagem.
    ir_para(4, 23);
    printf("Listagem concluida. Encerrando o programa...");
    exit(0);
}