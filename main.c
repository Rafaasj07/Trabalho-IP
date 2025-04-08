#include <stdio.h>
#include <string.h>

//inicio das Funções. O pq de iniciar elas aq: “Ei, essas funções existem, eu vou usá-las aqui na main(), e depois eu explico como elas funcionam.”

void cadastro_usuario(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], int *P_senha);
void login_usuario(char P_nome_login[], char P_nome_cadastro[], int *P_senha, int *P_tentativa_senha);

int main()
{
    //Principal
    int menu_principal;

    //Adm
    int menu_adm, senha_adm;
    char nome_adm[100];

    //Usuario
    int menu_usuario, senha, tentativa_senha, quer_login;
    char nome_cadastro[50], nome_login[50], pergunta[100], resposta[100];


    printf("\n------------------------------------------\n"
           "-------------  MENU PRINCIPAL  -----------\n"
           "------------------------------------------\n"
           "--------------1. MENU USUARIO-------------\n"
           "--------------2. MENU ADMINISTRADOR-------\n"
           "--------------3. SAIR---------------------\n"
           "------------------------------------------\n");

    scanf("%d", &menu_principal);

    switch (menu_principal)
    {
    case 1: // Usuário
        printf("\n--------------------------------------------\n"
               "--------------- MENU USUARIO ---------------\n"
               "--------------------------------------------\n"
               "--------------1. CADASTRO-------------------\n"
               "--------------2. FAZER LOGIN----------------\n"
               "--------------3. RECUPERACAO DE SENHA-------\n"
               "--------------------------------------------\n");

        scanf("%d", &menu_usuario);

        switch (menu_usuario)
        {
        case 1:
            cadastro_usuario(nome_cadastro, pergunta, resposta, &senha);
                printf("Se deseja fazer login, digite [1]. Se nao, digite qualquer outra coisa. \n");
                scanf("%d", &quer_login);
                    switch (quer_login)
                    {
                    case 1:
                        login_usuario(nome_login, nome_cadastro, &senha, &tentativa_senha);
                        break;
                    default:
                        printf("Encerrando programa!!!");
                        break;
                    }
                break;
        case 2:
            login_usuario(nome_login, nome_cadastro, &senha, &tentativa_senha);
            break;
        case 3:
            printf("\nNome:\n");
            scanf("%s", nome_cadastro);
            printf("Simulando recuperacao de senha para %s...\n", nome_cadastro);
            break;

        default:
            printf("ERRO: Digite uma opcao valida no menu de USUARIO\n");
        }
        break;

    case 2: // Administrador
        printf("\n------------------------------------------\n"
               "-------------  MENU - ADMIN  -------------\n"
               "------------------------------------------\n"
               "-----   1. CADASTRO DE ADMINISTRADOR  ----\n"
               "---------   2. LOGIN ADMINISTRADOR  ------\n"
               "------------------------------------------\n");

        scanf("%d", &menu_adm);

        switch (menu_adm)
        {
        case 1:
            printf("\nNome:\n");
            scanf("%s", nome_adm);
            printf("Senha:\n");
            scanf("%d", &senha);
            break;

        case 2:
            printf("\nNome:\n");
            scanf("%s", nome_adm);
            printf("Senha:\n");
            scanf("%d", &senha);
            break;

        default:
            printf("ERRO: Digite uma opcao valida no menu de ADMINISTRADOR\n");
        }
        break;

    case 3: // Sair
        printf("Saindo...\n");
        break;

    default:
        printf("ERRO: Digite uma opcao valida no MENU PRINCIPAL\n");
    }

    return 0;
}

// Corpo das funções 
void cadastro_usuario(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], int *P_senha)
{
    printf("CASDASTRO\n");
    printf("Nome:\n");
    scanf("%s", P_nome_cadastro);
    printf("Senha:\n");
    scanf("%d", &*P_senha);
    printf("Pergunta secreta:\n");
    scanf("%s", P_pergunta);
    printf("Resposta da pergunta secreta:\n");
    scanf("%s", P_resposta);
}

void login_usuario(char P_nome_login[], char P_nome_cadastro[], int *P_senha, int *P_tentativa_senha)
{
    printf("LOGIN\n");
    printf("Nome:\n");
    scanf("%s", &*P_nome_login);
    if (strcmp(P_nome_login, P_nome_cadastro) == 0)// Verifica se o usuario cadastrado é igual ao usuario q esta tentando o login
    { 
        printf("Senha:\n");
        scanf("%d", &*P_tentativa_senha);

        if (*P_tentativa_senha == *P_senha)
        {
            printf("Acesso ao programa liberado");
        }else {
            printf("Senha Incorreta!");
        }
        
    }
    else
        printf("Usuario Invalido!!!");

}