#include <stdio.h>
#include "prototipos.h"

void functions_adm()
{
    int menu_adm2;

    printf("\n------------------------------------------\n"
           "------------------  ADMIN  ---------------\n"
           "------------------------------------------\n"
           "----   1. EXIBIR LISTA DE USUARIOS  ------\n"
           "----   2. CONVERTER USUARIO EM ADMIN  ----\n"
           "----   3. SAIR  --------------------------\n"
           "------------------------------------------\n"
           "\nDigite a opcao que deseja: ");

    scanf("%d", &menu_adm2);

    switch (menu_adm2)
    {
    case 1:
        break;

    case 2:
        break;

    case 3:
        printf("Voltando ao menu principal...");
        break;
    }
}