#include <stdio.h>
#include <string.h>

int main() {
    int OPmenu, OPmenuLog, Password, OPmenuADM;
    char newName[50], Name[50];
    char Pergunta[100], resposta[100];

    printf("\n------------------------------------------\n"
           "-------------  MENU PRINCIPAL  -----------\n"
           "------------------------------------------\n"
           "---------------  1. USER -----------------\n"
           "------------- 2. ADMINISTRATOR -----------\n"
           "--------------   3 - EXIT  ---------------\n"
           "------------------------------------------\n");

    scanf("%d", &OPmenu);

    switch (OPmenu) {
        case 1: // Usuario
            printf("\n------------------------------------------\n"
                   "--------------- MENU - USER --------------\n"
                   "------------------------------------------\n"
                   "---------  1. LOGIN REGISTRATION ---------\n"
                   "----------------  2. LOGIN ---------------\n"
                   "---------  3. PASSWORD RECOVERY ----------\n"
                   "------------------------------------------\n");

            scanf("%d", &OPmenuLog);

            switch (OPmenuLog) {
                case 1:
                    printf("\nName:\n");
                    scanf("%s", newName);
                    printf("Password:\n");
                    scanf("%d", &Password);
                    printf("Security question:\n");
                    scanf("%s", Pergunta);
                    printf("Security question answer:\n");
                    scanf("%s", resposta);
                    break;

                case 2:
                    printf("\nName:\n");
                    scanf("%s", Name);
                    printf("Password:\n");
                    scanf("%d", &Password);
                    break;

                case 3:
                    printf("\nName:\n");
                    scanf("%s", Name);
                    printf("Simulando recuperação de senha para %s...\n", Name);
                    break;

                default:
                    printf("ERROR : Enter a valid value for USER menu\n");
            }
            break;

        case 2: // ADMIN
            printf("\n------------------------------------------\n"
                   "---------------  MENU - ADM  -------------\n"
                   "------------------------------------------\n"
                   "---------   1 - ADM REGISTRATION  --------\n"
                   "-------------  2 - ADM LOGIN -------------\n"
                   "------------------------------------------\n");

            scanf("%d", &OPmenuADM);

            switch (OPmenuADM) {
                case 1:
                    printf("\nName:\n");
                    scanf("%s", Name);
                    printf("Password:\n");
                    scanf("%d", &Password);
                    break;

                case 2:
                    printf("\nName:\n");
                    scanf("%s", Name);
                    printf("Password:\n");
                    scanf("%d", &Password);
                    break;

                default:
                    printf("ERROR : Enter a valid value for ADMIN menu\n");
            }
            break;

        case 3: // EXIT
            printf("Saindo...\n");
            break;

        default:
            printf("ERROR : Enter a valid value for MAIN menu\n");
    }

    return 0;
}
