#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h"

int main()
{
    limpar();
    /* Formata o terminal/console para que o mesmo tenha 80 colunas e 25 linhas (IBM),
    para o uso da funcao ir_para() e bordas()*/
    system("mode con:cols=80 lines=25");
    bordas();

    // Variaveis do menu principal
    int menu_principal;

    // Variaveis do Administrador
    int menu_adm, senha_adm;

    // Variaveis do Usuario
    int menu_usuario, quer_login;

    // Variaveis Admin e Usuario
    char nome_cadastro[50], nome_login[50], pergunta[100], resposta[100], senha[50];

    // Opcoes do menu principal
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196,196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c          Menu Principal         %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196,196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

    ir_para(23, 9);
    printf("            1. MENU USUARIO            ");
    ir_para(23, 10);
    printf("         2. MENU ADMINISTRADOR         ");
    ir_para(23, 11);
    printf("                3. SAIR                ");
    ir_para(26, 13);
    printf("Digite a opcao que deseja: ");

    scanf("%d", &menu_principal);
    apaga_buffer();
    switch (menu_principal)
    {
    case 1: // Usuario
        // Opcoes do menu do usuario
        limpar();
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196,196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c           Menu Usuario          %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196,196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    
        ir_para(23, 9);
        printf("            1. CADASTRO            ");
        ir_para(23, 10);
        printf("           2. FAZER LOGIN          ");
        ir_para(23, 11);
        printf("       3. RECUPERACAO DE SENHA     ");
        ir_para(26, 13);
        printf("Digite a opcao que deseja: ");
        scanf("%d", &menu_usuario);
        apaga_buffer();

        switch (menu_usuario)
        {
        case 1:
            limpar();
            cadastro(nome_cadastro, pergunta, resposta, senha);

            ir_para(33, 15);
            printf("\033[1;32mUsuario Cadastrado.\033[0m\n");

            do
            {
                ir_para(33, 17);
                printf("Deseja fazer login?");
                ir_para(30, 18);
                printf("[1] SIM ou [2] NAO : ");
                scanf("%d", &quer_login);
                apaga_buffer();
                switch (quer_login)
                {
                case 1:
                    limpar();
                    login(nome_login, nome_cadastro, senha, pergunta, resposta, 1); // Se o usuario quiser login depois de cadastro, chama a funcao de login
                    break;
                case 2:
                    break;
                default:
                    ir_para( 35, 20);
                    printf("\033[1;31mDIGITO INVALIDO!\033[0m");
                    continue;
                }
            } while (quer_login != 1 && quer_login != 2);

            break;
        case 2:
            // Nao funciona por enquanto porque os valores das variaveis se perdem e assim o
            // vetor do usuario e a variavel da senha sempre tem um valor diferente.
            limpar();
            login(nome_login, nome_cadastro, senha, pergunta, resposta, 1);
            break;
        case 3:
            printf("Digite seu nome: ");
            fgets(nome_login, 50, stdin);
            nome_login[strcspn(nome_login, "\n")] = '\0';
            recuperar_senha(nome_login, nome_cadastro, senha, pergunta, resposta);
            printf("Simulando recuperacao de senha para %s...\n", nome_cadastro);
            break;

        default:
            printf("DIGITO INVALIDO!");
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
        apaga_buffer();
        limpar();

        switch (menu_adm)
        {
        case 1:
            cadastro(nome_cadastro, pergunta, resposta, senha);
            printf("Deseja fazer login? SIM [1] NAO [2]\n");
            scanf("%d", &quer_login);
            apaga_buffer();

            switch (quer_login)
            {
            case 1:
                login(nome_login, nome_cadastro, senha, pergunta, resposta, 1);
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
            login(nome_login, nome_cadastro, senha, pergunta, resposta, 1);
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