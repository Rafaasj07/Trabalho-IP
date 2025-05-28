#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipos.h" // Inclui o arquivo de cabeçalho com todas as declarações de funções e a struct.

// A função main é o ponto de entrada de qualquer programa em C.
int main() {
    // Formata o console do Windows para 80 colunas e 25 linhas.
    // Isso garante que a interface gráfica do terminal (bordas, etc.) seja exibida corretamente.
    system("mode con:cols=80 lines=25");

    Cadastro dados;           // Cria uma instância da struct 'Cadastro'. Esta variável armazenará os dados do usuário/adm durante a execução.
    char mensagem_email[200]; // Buffer para armazenar a mensagem que será enviada por e-mail.

    // Loop do Menu Principal.
    // O 'do-while' garante que o menu seja exibido pelo menos uma vez.
    do {
        // Funções para desenhar a interface gráfica no terminal.
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c          Menu Principal         %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        
        // Exibe as opções do menu.
        ir_para(23, 9);
        printf("            1. MENU USUARIO            ");
        ir_para(23, 10);
        printf("         2. MENU ADMINISTRADOR         ");
        ir_para(23, 11);
        printf("                3. SAIR                ");

        // Solicita a entrada do usuário.
        ir_para(26, 13);
        limpar_linha();
        ir_para(26, 13);
        printf("Digite a opcao que deseja: ");
        scanf("%c", &dados.menu_principal); // Lê a opção e armazena na struct 'dados'.
        apaga_buffer(); // Limpa o buffer do teclado.

        // Estrutura 'switch' para tratar a opção escolhida.
        switch (dados.menu_principal) {
            char menu_usuario; // Variável local para o submenu do usuário.
        case '1': // Caso o usuário escolha "MENU USUARIO".
            // Loop do Menu do Usuário.
            do {
                // Desenha a interface do menu do usuário.
                bordas();
                ir_para(25, 2);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
                ir_para(25, 3);
                printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
                ir_para(25, 4);
                printf("%c           Menu Usuario          %c", 179, 179);
                ir_para(25, 5);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
                
                // Exibe as opções do submenu.
                ir_para(21, 9);
                printf("       1. CADASTRO            ");
                ir_para(21, 10);
                limpar_linha();
                ir_para(21, 10);
                printf("       2. FAZER LOGIN          ");
                ir_para(21, 11);
                printf("       3. RECUPERACAO DE SENHA     ");
                ir_para(21, 12);
                printf("       4. SAIR    ");
                
                // Solicita a entrada do usuário.
                ir_para(26, 13);
                limpar_linha();
                ir_para(26, 14);
                limpar_linha();
                ir_para(26, 15);
                limpar_linha();
                ir_para(26, 14);
                printf("Digite a opcao que deseja: ");
                scanf("%c", &menu_usuario);
                apaga_buffer();

                // Switch para tratar a opção do submenu do usuário.
                switch (menu_usuario) {
                case '1': // Cadastro de novo usuário.
                    inicializar_arquivo(dados.menu_principal); // Garante que o arquivo 'usuarios_cadastrados.bin' exista.
                    cadastro(&dados);                          // Chama a função de cadastro para preencher os dados.
                    incluir_dados(&dados);                     // Salva os dados no arquivo binário.
                    snprintf(mensagem_email, sizeof(mensagem_email), "Parabéns, %s! Você fez cadastro em nosso Sistema.", dados.nome);
                    envia_email(&dados, mensagem_email);       // Envia um e-mail de boas-vindas.
                    ir_para(33, 18);
                    printf("\033[1;32mUsuario Cadastrado.\033[0m");

                    // Pergunta se o usuário deseja fazer login após o cadastro.
                    char quer_login;
                    do {
                        ir_para(33, 20);
                        printf("Deseja fazer login?");
                        ir_para(30, 21);
                        printf("                                ");
                        ir_para(30, 21);
                        printf("[1] SIM ou [2] NAO : ");
                        scanf("%c", &quer_login);
                        apaga_buffer();
                        switch (quer_login) {
                        case '1':
                            login(&dados); // Chama a função de login.
                            snprintf(mensagem_email, sizeof(mensagem_email), "Parabéns, %s! Você fez login em nosso Sistema.", dados.nome);
                            envia_email(&dados, mensagem_email);
                            break;
                        case '2':
                            ir_para(32, 18);
                            printf("\033[1;31mSaindo do programa...\033[0m");
                            break;
                        default:
                            ir_para(34, 18);
                            limpar_linha();
                            ir_para(33, 18);
                            printf("\033[1;31mDIGITO INVALIDO!\033[0m");
                            break;
                        }
                    } while (quer_login != '1' && quer_login != '2');
                    break;

                case '2': // Fazer Login.
                    login(&dados); // Chama a função de login.
                    snprintf(mensagem_email, sizeof(mensagem_email), "Parabéns, %s! Você fez login em nosso Sistema.", dados.nome);
                    envia_email(&dados, mensagem_email);
                    break;

                case '3': // Recuperação de Senha.
                    recuperar_senha(&dados); // Chama a função de recuperação.
                    snprintf(mensagem_email, sizeof(mensagem_email), "%s você alterou sua senha em nosso Sistema.", dados.nome);
                    envia_email(&dados, mensagem_email);
                    break;

                case '4': // Sair.
                    ir_para(34, 16);
                    printf("\033[1;31mSaindo do programa...\033[0m");
                    exit(0); // Encerra o programa.
                    break;

                default: // Opção inválida.
                    ir_para(34, 16);
                    printf("\033[1;31mDIGITO INVALIDO!\033[0m");
                    break;
                }
            } while (menu_usuario != '1' && menu_usuario != '2' && menu_usuario != '3' && menu_usuario != '4');
            break;

            char menu_adm; // Variável local para o submenu do administrador.
        case '2': // Caso o usuário escolha "MENU ADMINISTRADOR".
            // Loop do Menu do Administrador.
            do {
                // Desenha a interface do menu do administrador.
                bordas();
                ir_para(25, 2);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
                ir_para(25, 3);
                printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
                ir_para(25, 4);
                printf("%c        Menu Administrador       %c", 179, 179);
                ir_para(25, 5);
                printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
                
                // Exibe as opções do submenu.
                ir_para(21, 9);
                printf("           1. CADASTRAR ADMINISTRADOR           ");
                ir_para(21, 10);
                printf("           2. LOGIN ADMINISTRADOR            ");
                ir_para(21, 11);
                printf("           3. RECUPERAR SENHA ADM          ");
                ir_para(21, 12);
                printf("           4. SAIR         ");

                // Solicita a entrada do usuário.
                ir_para(26, 13);
                limpar_linha();
                ir_para(26, 14);
                limpar_linha();
                ir_para(26, 15);
                limpar_linha();
                ir_para(26, 14);
                printf("Digite a opcao que deseja: ");
                scanf("%c", &menu_adm);
                apaga_buffer();

                // Switch para tratar a opção do submenu do administrador.
                switch (menu_adm) {
                case '1': // Cadastro de novo administrador.
                    inicializar_arquivo(dados.menu_principal); // Garante que o arquivo 'adms_cadastrados.bin' exista.
                    cadastro(&dados);
                    incluir_dados(&dados);
                    snprintf(mensagem_email, sizeof(mensagem_email), "Parabéns, %s! Você fez cadastro em nosso Sistema como adm.", dados.nome);
                    envia_email(&dados, mensagem_email);
                    ir_para(33, 18);
                    printf("\033[1;32mAdministrador Cadastrado.\033[0m\n");

                    // Pergunta se o adm deseja fazer login após o cadastro.
                    char quer_login;
                    do {
                        ir_para(33, 20);
                        printf("Deseja fazer login?");
                        ir_para(30, 21);
                        printf("                                ");
                        ir_para(30, 21);
                        printf("[1] SIM ou [2] NAO : ");
                        scanf("%c", &quer_login);
                        apaga_buffer();
                        switch (quer_login) {
                        case '1':
                            login(&dados); // Chama o login de adm.
                            snprintf(mensagem_email, sizeof(mensagem_email), "Parabéns, %s! Você fez login em nosso Sistema como adm.", dados.nome);
                            envia_email(&dados, mensagem_email);
                            adm_funcoes(&dados); // Exibe o menu de funções do adm.
                            break;
                        case '2':
                            ir_para(32, 18);
                            limpar_linha();
                            ir_para(32, 18);
                            printf("\033[1;31mSaindo do programa...\033[0m");
                            break;
                        default:
                            ir_para(33, 18);
                            limpar_linha();
                            ir_para(34, 18);
                            printf("\033[1;31mDIGITO INVALIDO!\033[0m");
                            break;
                        }
                    } while (quer_login != '1' && quer_login != '2');
                    break;

                case '2': // Login do Administrador.
                    login(&dados);
                    snprintf(mensagem_email, sizeof(mensagem_email), "Parabéns, %s! Você fez login em nosso Sistema como adm.", dados.nome);
                    envia_email(&dados, mensagem_email);
                    adm_funcoes(&dados); // Após o login, mostra as funções de adm.
                    break;

                case '3': // Recuperação de Senha do Administrador.
                    recuperar_senha(&dados);
                    snprintf(mensagem_email, sizeof(mensagem_email), "%s você alterou sua senha em nosso Sistema.", dados.nome);
                    envia_email(&dados, mensagem_email);
                    break;

                case '4': // Sair.
                    ir_para(32, 16);
                    limpar_linha();
                    ir_para(32, 16);
                    printf("\033[1;31mSaindo do programa...\033[0m");
                    exit(0);
                    break;

                default: // Opção inválida.
                    ir_para(34, 16);
                    printf("\033[1;31mDIGITO INVALIDO!\033[0m");
                    break;
                }
            } while (menu_adm != '1' && menu_adm != '2' && menu_adm != '3' && menu_adm != '4');
            break;

        case '3': // Sair do programa principal.
            ir_para(32, 16);
            printf("\033[1;31mSaindo do programa...\033[0m");
            break;

        default: // Opção inválida no menu principal.
            ir_para(34, 16);
            printf("\033[1;31mDIGITO INVALIDO!\033[0m");
            break;
        }
    } while (dados.menu_principal != '1' && dados.menu_principal != '2' && dados.menu_principal != '3');

    // Retorno padrão da função main.
    return 0;
}