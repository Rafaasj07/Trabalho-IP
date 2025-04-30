#pragma once
                        //ISSO É SÓ A ESTRUTURA!!! A APLICAÇÃO DISSO TA NA MAIN.
typedef struct {        //Definição da struct aq, pois será usada em todas funções. Explicação: se você definir a struct dentro do arquivo de cabeçalho
    char nome[50];      //(.h) e instanciar a variável dessa struct apenas na função main(), tudo será armazenado na main(). O que acontece é que,
    char pergunta[100]; //embora a definição da struct esteja acessível em várias funções (pois você a declarou no .h), você só cria uma instância 
    char resposta[100]; //dessa struct na main(), o que significa que os dados ficam armazenados na variável que você criar na main().
    char senha[50];
} Cadastro;

void cadastro(Cadastro *dados); //Acessando a instancia da struct cadastro, no caso dados. Dados é a instancia criada na main!!!
void login(Cadastro *dados, int nome_ja_verificado); 
void recuperar_senha(Cadastro *dados);

void functions_adm(void);
void limpar(void);
void ir_para(int x, int y);
void bordas(void);
void apaga_buffer(void);
void incluir(Cadastro *dados);

/*Explicação mais abstrata: Essa struct é como se fosse uma receita de bolo, o bolo mesmo é a instancia dados. A struct funciona como uma
 receita de bolo: ela define a forma e a estrutura dos dados que você quer armazenar, mas o bolo real, ou seja, os dados, são representados 
 pela instância da struct que você cria na main().*/