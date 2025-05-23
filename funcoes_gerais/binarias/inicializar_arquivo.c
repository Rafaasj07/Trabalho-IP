#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

void inicializar_arquivo(char menu_principal)
{
    /*A declaração const char nome_arquivo = "usuarios_cadastrados.bin"; ou nome_arquivo = "adms_cadastrados.bin"; significa que a string literal
    "usuarios_cadastrados.bin" está armazenada em uma área de memória especial do programa que é somente leitura. A variável nome_arquivo é
    um ponteiro que aponta para o início dessa string. O uso do const indica que o conteúdo dessa string não deve ser modificado*/
    const char *nome_arquivo = NULL; // Aponta pra nada
    if (menu_principal == '1')
    {
        nome_arquivo = "usuarios_cadastrados.bin"; // Aponta para esse texto q foi salvo em uma área da memória chamada segmento de dados constantes
    }                                             // ou segmento de texto (text segment), que é uma região reservada para armazenar dados fixos do programa.
    else if (menu_principal == '2')
    {
        nome_arquivo = "adms_cadastrados.bin";
    }

    FILE *arquivo = fopen(nome_arquivo, "ab"); // Alem da função ab criar o arquivo, ela tambem abre para gravação.
    if (arquivo == NULL)
    {
        ir_para(30, 16);
        printf("\033[1;31mNao foi possivel abrir ou criar o arquivo.\033[0m");
        exit(1);
    }
    fclose(arquivo);
}
