#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "prototipos.h"

// Função que realiza o cadastro do usuário ou administrador.
// Recebe um ponteiro para a struct 'dados' para poder modificar seus campos diretamente.
void cadastro(Cadastro *dados) {
    // Limpa a tela e desenha a interface de cadastro.
    limpar();
    bordas();
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c             Cadastro            %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

    int nome_existe;
    char tentativa_nome[37];
    // --- COLETA E VALIDAÇÃO DO NOME ---
    // Loop 'do-while' para garantir que um nome válido e único seja inserido.
    do {
        ir_para(25, 9);
        limpar_linha();
        ir_para(25, 9);
        printf("Nome: ");
        fgets(tentativa_nome, sizeof(tentativa_nome), stdin); // Lê o nome.

        // Limpa o buffer se a entrada for maior que o esperado.
        if (strchr(tentativa_nome, '\n') == NULL)
            apaga_buffer();
        else // Remove o '\n' do final da string.
            tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';

        // Valida o tamanho do nome.
        if (strlen(tentativa_nome) > 35) {
            ir_para(20, 14);
            printf("\033[1;31mA quantidade maxima de caracteres eh 35!\033[0m");
        }

        // Verifica se o nome já existe no banco de dados.
        nome_existe = verificar_nome(dados, tentativa_nome);
        if (nome_existe == 1) {
            ir_para(30, 14);
            limpar_linha();
            ir_para(30, 14);
            printf("\033[1;31mUsuario ja cadastrado!\033[0m");
        }
    } while (nome_existe == 1 || strlen(tentativa_nome) > 35); // Repete se o nome existe ou é muito longo.

    ir_para(30, 14);
    limpar_linha();
    strcpy(dados->nome, tentativa_nome); // Copia o nome válido para a struct.

    // --- COLETA E VALIDAÇÃO DA SENHA ---
    int senha_valida;
    do {
        senha_valida = 1; // Assume que a senha é válida.
        ir_para(25, 10);
        limpar_linha();
        ir_para(25, 10);
        printf("Senha: ");
        fgets(dados->senha, sizeof(dados->senha), stdin);

        if (strchr(dados->senha, '\n') == NULL)
            apaga_buffer();
        else
            dados->senha[strcspn(dados->senha, "\n")] = '\0';

        int tamanho = strlen(dados->senha);
        int contem_digito = 0;

        // Valida o tamanho da senha.
        if (tamanho > 20) {
            ir_para(20, 14);
            printf("\033[1;31mO tamanho maximo da senha eh 20 caracteres!\033[0m");
            senha_valida = 0;
        } else if (tamanho < 6) {
            ir_para(20, 14);
            limpar_linha();
            ir_para(20, 14);
            printf("\033[1;31mO tamanho minimo da senha eh 6 caracteres!\033[0m");
            senha_valida = 0;
        } else {
            // Verifica se a senha contém pelo menos um número.
            for (int i = 0; i < tamanho; i++) {
                if (isdigit(dados->senha[i])) { // isdigit() verifica se o caractere é um dígito.
                    contem_digito = 1;
                    break;
                }
            }
            if (!contem_digito) {
                ir_para(20, 14);
                limpar_linha();
                ir_para(20, 14);
                printf("\033[1;31mA senha deve conter pelo menos um numero!\033[0m");
                senha_valida = 0;
            }
        }
    } while (!senha_valida); // Repete se a senha for inválida.
    ir_para(20, 14);
    limpar_linha();

    // --- COLETA E VALIDAÇÃO DA PERGUNTA SECRETA ---
    int pergunta_valida;
    do {
        pergunta_valida = 1; // Assume que a pergunta é válida.
        ir_para(25, 11);
        printf("Pergunta secreta: \n");
        ir_para(25, 12);
        limpar_linha();
        ir_para(25, 12);
        fgets(dados->pergunta, sizeof(dados->pergunta), stdin);

        if (strchr(dados->pergunta, '\n') == NULL)
            apaga_buffer();
        else
            dados->pergunta[strcspn(dados->pergunta, "\n")] = '\0';

        int tamanho = strlen(dados->pergunta);
        // Valida o tamanho da pergunta.
        if (tamanho > 50) {
            ir_para(20, 15);
            printf("\033[1;31mO tamanho maximo da pergunta eh 50 caracteres!\033[0m");
            pergunta_valida = 0;
        } else if (tamanho < 10) {
            ir_para(20, 15);
            printf("\033[1;31mO tamanho minimo da pergunta eh 10 caracteres!\033[0m");
            pergunta_valida = 0;
        }
    } while (!pergunta_valida); // Repete se a pergunta for inválida.
    ir_para(20, 15);
    limpar_linha();

    // --- COLETA E VALIDAÇÃO DA RESPOSTA ---
    int resposta_valida;
    do {
        resposta_valida = 1; // Assume que a resposta é válida.
        ir_para(25, 13);
        printf("Resposta da pergunta secreta: ");
        ir_para(25, 14);
        limpar_linha();
        ir_para(25, 14);
        fgets(dados->resposta, sizeof(dados->resposta), stdin);

        if (strchr(dados->resposta, '\n') == NULL)
            apaga_buffer();
        else
            dados->resposta[strcspn(dados->resposta, "\n")] = '\0';

        int tamanho = strlen(dados->resposta);
        // Valida o tamanho da resposta.
        if (tamanho > 50) {
            ir_para(20, 17);
            printf("\033[1;31mO tamanho maximo da resposta eh 50 caracteres!\033[0m");
            resposta_valida = 0;
        }
    } while (!resposta_valida); // Repete se a resposta for inválida.
    ir_para(20, 17);
    limpar_linha();

    // --- COLETA E VALIDAÇÃO DO CPF ---
    do {
        ir_para(25, 15);
        limpar_linha();
        ir_para(25, 15);
        printf("CPF (11 digitos): ");
        fgets(dados->cpf, sizeof(dados->cpf), stdin);

        // Verifica se a entrada excedeu o buffer.
        if (strchr(dados->cpf, '\n') == NULL) {
            apaga_buffer();
            ir_para(25, 17);
            printf("\033[1;31mEntrada muito longa!\033[0m");
            continue; // Pula para a próxima iteração do loop.
        }

        dados->cpf[strcspn(dados->cpf, "\n")] = '\0'; // Remove o '\n'.
        int cpf_valido_formatado = 1;

        // Verifica se todos os caracteres são dígitos.
        for (int i = 0; i < 11; i++) {
            if (!isdigit(dados->cpf[i])) {
                cpf_valido_formatado = 0;
                break;
            }
        }

        // Valida se o CPF tem exatamente 11 dígitos e todos são numéricos.
        if (cpf_valido_formatado == 0 || strlen(dados->cpf) != 11) {
            ir_para(25, 17);
            limpar_linha();
            ir_para(25, 17);
            printf("\033[1;31mCPF invalido.\033[0m");
        } else {
            break; // Sai do loop se o CPF for válido.
        }
    } while (1); // Loop infinito que só é quebrado com 'break'.
    ir_para(25, 17);
    limpar_linha();

    // --- COLETA E VALIDAÇÃO DO E-MAIL ---
    int eh_email;
    do {
        eh_email = 1; // Assume que o e-mail é inválido (1 = true, para "não contém @").
        ir_para(25, 16);
        limpar_linha();
        ir_para(25, 16);
        printf("Email: ");
        fgets(dados->email, sizeof(dados->email), stdin);
        dados->email[strcspn(dados->email, "\n")] = '\0';

        int tamanho = strlen(dados->email);

        // Procura pelo caractere '@' para uma validação simples.
        for (int i = 0; i < tamanho; i++) {
            if (dados->email[i] == '@') {
                eh_email = 0; // Encontrou '@', então o e-mail é potencialmente válido.
                break;
            }
        }

        // Se o e-mail não tem '@' ou é muito curto, exibe erro.
        if (eh_email == 1 || tamanho < 6) {
            ir_para(32, 19);
            printf("\033[1;31mEmail Invalido!\033[0m");
        }
    } while (eh_email == 1 || strlen(dados->email) < 6); // Repete se inválido.
    ir_para(32, 19);
    limpar_linha();
}