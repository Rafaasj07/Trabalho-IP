#include <stdio.h>
#include <string.h>

int main() {
    int menu_principal, menu_usuario, menu_adm, senha;
    char novo_nome[50], nome[50];
    char pergunta[100], resposta[100];

    printf("\n------------------------------------------\n"
           "-------------  MENU PRINCIPAL  -----------\n"
           "------------------------------------------\n"
           "---------------  1. USUARIO ---------------\n"
           "------------- 2. ADMINISTRADOR ------------\n"
           "--------------   3. SAIR  -----------------\n"
           "------------------------------------------\n");

    scanf("%d", &menu_principal);

    switch (menu_principal) {
        case 1: // Usuário
            printf("\n------------------------------------------\n"
                   "------------- MENU - USUÁRIO -------------\n"
                   "------------------------------------------\n"
                   "-------  1. CADASTRO DE LOGIN  -----------\n"
                   "-----------  2. FAZER LOGIN  -------------\n"
                   "-----  3. RECUPERAÇÃO DE SENHA  ----------\n"
                   "------------------------------------------\n");

            scanf("%d", &menu_usuario);

            switch (menu_usuario) {
                case 1:
                    printf("\nNome:\n");
                    scanf("%s", novo_nome);
                    printf("Senha:\n");
                    scanf("%d", &senha);
                    printf("Pergunta secreta:\n");
                    scanf("%s", pergunta);
                    printf("Resposta da pergunta secreta:\n");
                    scanf("%s", resposta);
                    break;

                case 2:
                    printf("\nNome:\n");
                    scanf("%s", nome);
                    printf("Senha:\n");
                    scanf("%d", &senha);
                    break;

                case 3:
                    printf("\nNome:\n");
                    scanf("%s", nome);
                    printf("Simulando recuperacao de senha para %s...\n", nome);
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

            switch (menu_adm) {
                case 1:
                    printf("\nNome:\n");
                    scanf("%s", nome);
                    printf("Senha:\n");
                    scanf("%d", &senha);
                    break;

                case 2:
                    printf("\nNome:\n");
                    scanf("%s", nome);
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
            printf("ERRO: Digite uma opção valida no MENU PRINCIPAL\n");
    }

    return 0;
}
