#pragma once

void cadastro(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], char P_senha[]);
void login(char P_nome_login[], char P_nome_cadastro[], char P_senha[], char P_pergunta[], char P_resposta[], int nome_ja_verificado);
void recuperar_senha(char P_nome_login[], char P_nome_cadastro[], char P_senha[], char P_pergunta[], char P_resposta[]);
void functions_adm(void);
void limpar(void);
void ir_para(int x, int y);
void bordas(void);
void apaga_buffer(void);
