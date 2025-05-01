#include <stdio.h>
#include <string.h>
#include "prototipos.h"

// Funcao login_usuario com o ponteiro da instancia dados.
// atribuindo os enderecos das variaveis da main e os modificando
void cadastro(Cadastro *dados)
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
    fgets(dados->nome, 50, stdin);                 //dados->nome: Quando você usa o operador ->, vc está acessando o campo nome dentro da instância 
    dados->nome[strcspn(dados->nome, "\n")] = '\0';//da struct apontada pelo ponteiro *dados. O ponteiro *dados aponta para a instancia criada na main, que tambem
                                                   //chama dados. Não confunda, o *dados daqui é um PONTEIRO, ele aponta para o OBJETO dados.

    ir_para(25, 10);
    printf("Senha: ");
    fgets(dados->senha, 50, stdin);
    dados->senha[strcspn(dados->senha, "\n")] = '\0';

    ir_para(25, 11);
    printf("Pergunta secreta: ");
    fgets(dados->pergunta, 100, stdin);
    dados->pergunta[strcspn(dados->pergunta, "\n")] = '\0';

    ir_para(25, 12);
    printf("Resposta da pergunta secreta: ");
    fgets(dados->resposta, 100, stdin);
    dados->resposta[strcspn(dados->resposta, "\n")] = '\0';
    
}
