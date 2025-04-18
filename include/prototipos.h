#pragma once

void cadastro(char P_nome_cadastro[], char P_pergunta[], char P_resposta[], char P_senha[]);
void login(char P_nome_login[], char P_nome_cadastro[], char P_senha[], char P_pergunta[], char P_resposta[]);
void recuperar_senha(char P_senha[], char P_pergunta[], char P_resposta[]);
void functions_adm();
void limpar();