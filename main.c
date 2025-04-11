#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prototipos das Funcoes

void cadastro_usuario(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], int *P_senha);
void login_usuario(char P_nome_login[], char P_nome_cadastro[], int *P_senha);
void recuperar_senha();

int main()
{
    // Variaveis do menu principal
    int menu_principal;

    // Variaveis do Administrador
    int menu_adm, senha_adm;
    char nome_adm[50];

    // Variaveis do Usuario
    int menu_usuario, senha, quer_login;
    char nome_cadastro[50], nome_login[50], pergunta[100], resposta[100];

    // Opcoes do menu principal
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
    case 1: // Usuario
        // Opcoes do menu do usuario
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
           /* Funcao cadastro.
            Passagem de parametro por endereco nas funcoes, enderecos que serao atribuídos aos ponteiros. Dessa forma, quando os ponteiros
            forem modificados, tambem sera modificado o valor das variaveis criadas aqui na main. Essas variaveis serao usadas depois no login
            para comparar valores. Por exemplo: o vetor nome_cadastro foi modificado pela funcao cadastro_usuario e agora, aqui na main, ele 
            vale "Matheus", por exemplo. La na funcao login_usuario, vou usar outro ponteiro para atribuir a ele o endereco do vetor nome_cadastro,
            que foi atualizado pela funcao cadastro_usuario com o valor "Matheus". Assim, esse ponteiro agora tem acesso ao valor do vetor
            nome_cadastro. Agora, quando eu tentar logar com um usuario, esse nome de usuario tem que ser igual a "Matheus", que foi o usuario 
            cadastrado. Se nao for, o acesso ao sistema e negado.
            */

            cadastro_usuario(nome_cadastro, pergunta, resposta, &senha);
            printf("Deseja fazer login? SIM [1] NAO [2]\n");
            scanf("%d", &quer_login);
            switch (quer_login)
            {
            case 1:
                login_usuario(nome_login, nome_cadastro, &senha); // Se o usuario quiser login depois de cadastro, chama a funcao de login
                break;
            default:
                printf("Usuario cadastrado.\n");
                break;
            }
            break;
        case 2:
            // Nao funciona por enquanto porque os valores das variaveis se perdem e assim o
            // vetor do usuario e a variavel da senha sempre tem um valor diferente.
            login_usuario(nome_login, nome_cadastro, &senha);
            break;
        case 3:
            printf("\nNome:\n");
            scanf("%s", nome_cadastro);
            recuperar_senha();
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
            scanf("%d", &senha_adm);
            break;

        case 2:
            printf("\nNome:\n");
            scanf("%s", nome_adm);
            printf("Senha:\n");
            scanf("%d", &senha_adm);
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

// Funcao cadastro_usuario com os ponteiros
// atribuindo os enderecos das variaveis da main e os modificando
void cadastro_usuario(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], int *P_senha)
{
    printf("CADASTRO\n");
    printf("Nome:\n");
    scanf("%s", P_nome_cadastro);
    printf("Senha numerica:\n");
    scanf("%d", P_senha);
    printf("Pergunta secreta:\n");
    scanf("%s", P_pergunta);
    printf("Resposta da pergunta secreta:\n");
    scanf("%s", P_resposta);
}

// Funcao login_usuario com os ponteiros
// atribuindo os enderecos das variaveis da main e fazendo comparacoes e modificacoes
void login_usuario(char P_nome_login[], char P_nome_cadastro[], int *P_senha)
{
    do // Repete ate o nome do cadastro ser igual ao nome do login
    {
        int deseja_repetir_nome;
        printf("LOGIN\n");
        printf("Nome:\n");
        scanf("%s", P_nome_login);

        if (strcmp(P_nome_login, P_nome_cadastro) == 0)
        {
            int tentativa_senha, aux_tentativa_senha = 0;

            do // Repeticao ate a senha ser correta
            {
                int deseja_recuperar;
                printf("Senha numerica:\n");
                scanf("%d", &tentativa_senha);

                if (tentativa_senha == *P_senha)
                {
                    printf("Acesso ao programa liberado.\n");
                }
                else
                {
                    printf("Senha incorreta, tente novamente!\n");
                    aux_tentativa_senha++;

                    // A cada 5 tentativas, pergunta ao usuario se quer recuperar senha
                    if (aux_tentativa_senha % 5 == 0)
                    {
                        printf("Deseja recuperar a senha? SIM [1] CONTINUAR TENTANDO [2] SAIR [3]\n");
                        scanf("%d", &deseja_recuperar);
                        switch (deseja_recuperar)
                        {
                        case 1:
                            printf("FUNCAO RECUPERAR...\n");
                            recuperar_senha();
                            exit(0);
                        case 2:
                            break;
                        default:
                            printf("Tentativa de login mal sucedida.\n");
                            exit(0);
                        }
                    }
                }

            } while (tentativa_senha != *P_senha);
        }
        else
        {
            // Se o usuario cadastrado for diferente do login, oferece opcao de tentar de novo ou sair
            printf("Usuario nao existe, deseja repetir o nome do usuario? SIM [1] SAIR [2]\n");
            scanf("%d", &deseja_repetir_nome);
            if (deseja_repetir_nome != 1)
            {
                printf("Tentativa de login mal sucedida.\n");
                exit(0);
            }
        }
    } while (strcmp(P_nome_login, P_nome_cadastro) != 0);
}

// Funcao de recuperacao de senha (futura)
void recuperar_senha()
{
}
