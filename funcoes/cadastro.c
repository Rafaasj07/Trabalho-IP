#include <stdio.h>
#include <string.h>
#include "prototipos.h"

// Funcao cadastro_usuario com os ponteiros
// atribuindo os enderecos das variaveis da main e os modificando
void cadastro(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], char P_senha[])
{
    printf("CADASTRO\n");
    printf("Nome:\n");
    getchar();
    fgets(P_nome_cadastro, 50, stdin);         
    P_nome_cadastro[strcspn(P_nome_cadastro, "\n")] = '\0';

    printf("Senha:\n");
    fgets(P_senha, 50, stdin);         
    P_senha[strcspn(P_senha, "\n")] = '\0';

    printf("Pergunta secreta:\n");
    fgets(P_pergunta, 100, stdin);                // Armazena a string digitada na P_pergunta, com tamanho (100) e lida pelo teclado (stdin)
    P_pergunta[strcspn(P_pergunta, "\n")] = '\0'; // Retira o "\n" que seria armazenado na variavel
    
    printf("Resposta da pergunta secreta:\n");
    fgets(P_resposta, 100, stdin);         
    P_resposta[strcspn(P_resposta, "\n")] = '\0';

    printf("Usuario cadastrado.\n");
}
