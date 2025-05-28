#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

// Função para localizar um usuário específico pelo nome.
void localiza_usuario(Cadastro *dados) {
    Cadastro usuario_buscado;
    usuario_buscado.menu_principal = '1'; // Configura para buscar no arquivo de usuários.

    int nome_existe;
    // Loop para garantir que o admin possa tentar nomes diferentes caso o primeiro não seja encontrado.
    do {
        char usuario_procurado[37];

        // Desenha a interface de localização.
        limpar();
        bordas();
        ir_para(25, 2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
        ir_para(25, 3);
        printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
        ir_para(25, 4);
        printf("%c        Localizar Usuario        %c", 179, 179);
        ir_para(25, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
        
        // Pede o nome do usuário a ser localizado.
        ir_para(25, 10);
        printf("Nome do Usuario: ");
        fgets(usuario_procurado, sizeof(usuario_procurado), stdin);
        usuario_procurado[strcspn(usuario_procurado, "\n")] = '\0';

        // Usa a função verificar_nome para encontrar o usuário.
        // Se encontrado, os dados são carregados na struct 'usuario_buscado'.
        nome_existe = verificar_nome(&usuario_buscado, usuario_procurado);

        if (nome_existe == 1) { // Se o usuário foi encontrado.
            ir_para(25, 9);
            printf("Usuario : %s", usuario_buscado.nome);
            ir_para(25, 10);
            limpar_linha();
            ir_para(25, 10);
            printf("CPF: %s", usuario_buscado.cpf);
            ir_para(25, 11);
            printf("Email: %s", usuario_buscado.email);

            ir_para(4, 23);
            printf("Usuario localizado. Encerrando o programa...");
            exit(0); // Finaliza o programa após encontrar.
        } else { // Se o usuário não foi encontrado.
            char deseja_repetir_nome;
            do {
                ir_para(30, 12);
                printf("\033[1;31mUsuario nao encontrado\033[0m");
                ir_para(26, 14);
                printf("Deseja repetir o nome do Usuario?");
                ir_para(30, 15);
                printf("[1] SIM  ou  [2] NAO  : ");
                scanf("%c", &deseja_repetir_nome);
                apaga_buffer();
                switch (deseja_repetir_nome) {
                case '1':
                    limpar(); // Limpa a tela para uma nova tentativa.
                    break;
                case '2':
                    ir_para(24, 17);
                    printf("\033[1;31mSaindo do programa...\033[0m");
                    exit(0); // Sai do programa.
                default:
                    break;
                }
            } while (deseja_repetir_nome != '1' && deseja_repetir_nome != '2');
        }
    } while (nome_existe == 0); // O loop principal continua se o usuário não foi encontrado e o adm quis tentar de novo.
}