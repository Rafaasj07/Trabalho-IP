#include <stdio.h>
#include <string.h>  
#include "prototipos.h"

// Funcao cadastro_usuario com os ponteiros
// atribuindo os enderecos das variaveis da main e os modificando
void cadastro(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], int *P_senha)
{
    printf("CADASTRO\n");
    printf("Nome:\n");
    scanf("%s", P_nome_cadastro);
    printf("Senha numerica:\n");
    scanf("%d", P_senha);
    getchar(); // Consome o "\n" deixado pelo scanf da senha
    printf("Pergunta secreta:\n");
    fgets(P_pergunta, 100, stdin);                // Armazena a string digitada na P_pergunta, com tamanho (100) e lida pelo teclado (stdin)
    P_pergunta[strcspn(P_pergunta, "\n")] = '\0'; // Retira o "\n" que seria armazenado na variavel
    printf("Resposta da pergunta secreta:\n");
    scanf("%s", P_resposta);
}
