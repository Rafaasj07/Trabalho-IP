#include <stdio.h>
#include <string.h>
#include "prototipos.h"

// Funcao cadastro_usuario com os ponteiros
// atribuindo os enderecos das variaveis da main e os modificando
void cadastro(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], char P_senha[])
{
    limpar();
    bordas();
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c             Cadastro            %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    
    ir_para(25, 9);
    printf("Nome: ");
    fgets(P_nome_cadastro, 50, stdin);
    P_nome_cadastro[strcspn(P_nome_cadastro, "\n")] = '\0';

    ir_para(25, 10);
    printf("Senha: ");
    fgets(P_senha, 50, stdin);
    P_senha[strcspn(P_senha, "\n")] = '\0';

    ir_para(25, 11);
    printf("Pergunta secreta: ");
    fgets(P_pergunta, 100, stdin);                // Armazena a string digitada na P_pergunta, com tamanho (100) e lida pelo teclado (stdin)
    P_pergunta[strcspn(P_pergunta, "\n")] = '\0'; // Retira o "\n" que seria armazenado na variavel

    ir_para(25, 12);
    printf("Resposta da pergunta secreta: ");
    fgets(P_resposta, 100, stdin);
    P_resposta[strcspn(P_resposta, "\n")] = '\0';
}