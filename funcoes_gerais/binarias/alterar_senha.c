#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

int alterar_senha(Cadastro *dados)
{
    printf("Mude sua senha:\n");
    fgets(dados->senha, 100, stdin);
    dados->senha[strcspn(dados->senha, "\n")] = '\0';

    FILE *arquivo;      // O ponteiro q faz referencia aos dados do meu arquivo.
    Cadastro ler_dados; // Instância temporária para ler os dados do arquivo.

    // Abrir o arquivo
    arquivo = fopen("dados_cadastrados.bin", "r+b"); // fopen abre o arquivo e o r+b tem a função de abri-lo caso exista e abre para leitura e modificação.

    if (arquivo == NULL) // Tratando possiveis erros.
    {
        printf("Nao foi possuvel abrir ou criar o arquivo.\n");
        exit(1);
    }

    // Lê cada registro (um por vez) e compara com os dados digitados
    /* "== 1" Essa comparação é para verificar se a função fread() leu com sucesso os dados. O fread() retorna o número de elementos que
     conseguiu ler, e o que esperamos é que ele consiga ler um único registro (da struct Cadastro). Se ele conseguir ler, ele retornará 1,
     indicando que um registro foi lido com sucesso. Se não conseguir, ele retornará 0. Ent ele repete enqunto tiver registro para ele ler.
     Se for 0, isso significa que o final do arquivo foi alcançado e que não há mais registros para ler.*/
    while (fread(&ler_dados, sizeof(Cadastro), 1, arquivo) == 1)
    {
        // Se encontrar nome igual ao digitado
        if (strcmp(ler_dados.nome, dados->nome) == 0)
        {
            fseek(arquivo, -sizeof(Cadastro), SEEK_CUR); // Volta o ponteiro para o início desse registro, dentro do arquivo onde encontrou o nome.
            fwrite(dados, sizeof(Cadastro), 1, arquivo); // Atualiza os novos dados (com a senha alterada), no antigo registro.
            break;
        }
    }

    printf("Senha atualizada com sucesso.");
    fclose(arquivo); 
    return 0;
}