#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

int main()
{
    // Variaveis do menu principal
    int menu_principal;

    // Variaveis do Administrador
    int menu_adm, senha_adm;

    // Variaveis do Usuario
    int menu_usuario, quer_login;

    // Variaveis Admin e Usuario
    char nome_cadastro[50], nome_login[50], pergunta[100], resposta[100], senha[50];

    // Opcoes do menu principal
    printf("\n------------------------------------------\n"
           "-------------  MENU PRINCIPAL  -----------\n"
           "------------------------------------------\n"
           "--------------1. MENU USUARIO-------------\n"
           "--------------2. MENU ADMINISTRADOR-------\n"
           "--------------3. SAIR---------------------\n"
           "------------------------------------------\n"
           "\nDigite a opcao que deseja: ");

    scanf("%d", &menu_principal);
    switch (menu_principal)
    {
    case 1: // Usuario
        // Opcoes do menu do usuario
        limpar();
        printf("\n--------------------------------------------\n"
               "--------------- MENU USUARIO ---------------\n"
               "--------------------------------------------\n"
               "--------------1. CADASTRO-------------------\n"
               "--------------2. FAZER LOGIN----------------\n"
               "--------------3. RECUPERACAO DE SENHA-------\n"
               "--------------------------------------------\n"
               "\nDigite a opcao que deseja: ");

        scanf("%d", &menu_usuario);

        switch (menu_usuario)
        {
        case 1:
            limpar();
            cadastro(nome_cadastro, pergunta, resposta, senha);
            limpar();

            printf("Usuario cadastrado.\n");

            do
            {
                printf("Deseja fazer login? SIM [1] NAO [2]\n");
                scanf("%d", &quer_login);
                switch (quer_login)
                {
                case 1:
                    limpar();
                    login(nome_login, nome_cadastro, senha, pergunta, resposta); // Se o usuario quiser login depois de cadastro, chama a funcao de login
                    break;
                case 2:
                    break;
                default:
                    limpar();
                    printf("DIGITO INVALIDO!\n");
                    continue;
                }
            } while (quer_login != 1 && quer_login != 2);

            break;
        case 2:
            // Nao funciona por enquanto porque os valores das variaveis se perdem e assim o
            // vetor do usuario e a variavel da senha sempre tem um valor diferente.
            limpar();
            login(nome_login, nome_cadastro, senha, pergunta, resposta);
            break;
        case 3:
            printf("Digite seu nome: ");
            getchar();
            fgets(nome_login, 50, stdin);
            nome_login[strcspn(nome_login, "\n")] = '\0';
            recuperar_senha(senha, pergunta, resposta);
            printf("Simulando recuperacao de senha para %s...\n", nome_cadastro);
            break;

        default:
            printf("ERRO: Digite uma opcao valida no menu de USUARIO\n");
            break;
        }
        break;

    case 2: // Administrador
        limpar();
        printf("\n------------------------------------------\n"
               "-------------  MENU - ADMIN  -------------\n"
               "------------------------------------------\n"
               "-----   1. CADASTRO DE ADMINISTRADOR  ----\n"
               "---------   2. LOGIN ADMINISTRADOR  ------\n"
               "------------------------------------------\n"
               "\nDigite a opcao que deseja: ");

        scanf("%d", &menu_adm);
        limpar();

        switch (menu_adm)
        {
        case 1:
            cadastro(nome_cadastro, pergunta, resposta, senha);
            printf("Deseja fazer login? SIM [1] NAO [2]\n");
            scanf("%d", &quer_login);

            switch (quer_login)
            {
            case 1:
                login(nome_login, nome_cadastro, senha, pergunta, resposta);
                functions_adm();
                break;
            case 2:
                printf("Administrador cadastrado.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
            break;

        case 2:
            login(nome_login, nome_cadastro, senha, pergunta, resposta);
            functions_adm();
            break;

        default:
            printf("ERRO: Digite uma opcao valida no MENU ADMINISTRADOR\n");
            break;
        }
        break;

    case 3: // Sair
        printf("Saindo do programa...\n");
        break;
    default:
        printf("Digito invalido\n");
        break;
    }
    return 0;
}
