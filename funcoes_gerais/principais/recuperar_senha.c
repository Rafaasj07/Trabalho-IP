#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

// Funcao de recuperacao de senha
void recuperar_senha(Cadastro *dados) //Lembre-se, dados é o ponteiro para a instancia la na main.
{
    char tentativa_resposta[100];
    int continuar_tent;
    do
    {
        printf("%s\n", dados->pergunta);
        fgets(tentativa_resposta, 100, stdin);
        tentativa_resposta[strcspn(tentativa_resposta, "\n")] = '\0';
        if (strcmp(tentativa_resposta, dados->resposta) == 0)
        {
            printf("Mude sua senha:\n");
            fgets(dados->senha, 100, stdin);
            dados->senha[strcspn(dados->senha, "\n")] = '\0';
            printf("Senha altera com sucesso.\n");      
        }
        else
        {
            limpar();
            printf("Resposta Incorreta, quer continuar tentando?\nSIM [1] SAIR [2]\n");
            scanf("%d", &continuar_tent);
            apaga_buffer();
            switch (continuar_tent)
            {
            case 1:
                limpar();
                break;
            default:
                printf("Erro ao recuperar senha.");
                exit(0);
            }
        }

    } while (strcmp(tentativa_resposta, dados->resposta) != 0);
}