#include <stdio.h>
#include <string.h>
#include "prototipos.h"

// Funcao de recuperacao de senha 
void recuperar_senha(char P_senha[], char P_pergunta[], char P_resposta[])
{
    char tentativa_resposta[100];

    printf("%s\n", P_pergunta);
    getchar();
    fgets(tentativa_resposta, 100, stdin);
    tentativa_resposta[strcspn(tentativa_resposta, "\n")] = '\0';

    if (strcmp(tentativa_resposta, P_resposta) == 0){
        printf("Mude sua senha:\n");
        fgets(P_senha, 100, stdin);
        P_senha[strcspn(P_senha, "\n")] = '\0';
        printf("Senha alterada com sucesso\n");
    }
}
