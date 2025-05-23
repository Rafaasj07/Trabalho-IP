#pragma once
// ISSO É SÓ A ESTRUTURA!!! A APLICAÇÃO DISSO TA NA MAIN.
typedef struct
{                       // Definição da struct aq, pois será usada em todas funções. Explicação: se você definir a struct dentro do arquivo de cabeçalho
    char nome[50];      //(.h) e instanciar a variável dessa struct apenas na função main(), tudo será armazenado na main(). O que acontece é que,
    char pergunta[100]; // embora a definição da struct esteja acessível em várias funções (pois você a declarou no .h), você só cria uma instância
    char resposta[100]; // dessa struct na main(), o que significa que os dados ficam armazenados na variável que você criar na main().
    char senha[50];
    char cpf[12]; // Para CPF sem pontuação
    char email[50];
    char menu_principal; // 1 usuario, 2 adm
} Cadastro;

// Prototipos das funcoes principais
void cadastro(Cadastro *dados); // Acessando a instancia da struct cadastro, no caso dados. Dados é a instancia criada na main!!!
void login(Cadastro *dados);
void recuperar_senha(Cadastro *dados);

// Prototipos das funcoes do adm
void adm_funcoes(Cadastro *dados);
void listagem_usuario(void);
void localiza_usuario(Cadastro *dados);
void excluir_usuario(Cadastro *dados);

// Prototipos das funcoes do front
void ir_para(int x, int y);
void bordas(void);

// Prototipos das funcoes secundarias
void limpar(void);
void apaga_buffer(void);
void limpar_linha(void);
int cpf_valido(const char *cpf);
void envia_email(Cadastro *dados, char mensagem_email[]);
void cifrar_cesar(char *codificada, int deslocamento);

// Prototipos das funcoes binarias
void inicializar_arquivo(char menu_principal);
void incluir_dados(Cadastro *dados);
int verificar_nome(Cadastro *dados, char tentativa_nome[]);
int alterar_senha(Cadastro *dados);

/*Explicação mais abstrata: Essa struct é como se fosse uma receita de bolo, o bolo mesmo é a instancia dados. A struct funciona como uma
 receita de bolo: ela define a forma e a estrutura dos dados que você quer armazenar, mas o bolo real, ou seja, os dados, são representados
 pela instância da struct que você cria na main().*/