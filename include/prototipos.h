#pragma once // Diretiva de pré-processador para garantir que este arquivo seja incluído apenas uma vez durante a compilação.

// Definição da estrutura 'Cadastro'.
// Ela agrupa todos os dados relacionados a um usuário ou administrador.
// A definição está aqui para que possa ser usada em todas as funções do projeto.
typedef struct
{
    char nome[37];       // Armazena o nome do usuário (até 36 caracteres + '\0').
    char pergunta[52];   // Armazena a pergunta de segurança (até 51 caracteres + '\0').
    char resposta[52];   // Armazena a resposta da pergunta de segurança (até 51 caracteres + '\0').
    char senha[22];      // Armazena a senha do usuário (até 21 caracteres + '\0').
    char cpf[13];        // Armazena o CPF sem pontuação (11 dígitos + '\0').
    char email[50];      // Armazena o e-mail do usuário (até 49 caracteres + '\0').
    char menu_principal; // Opção do menu: '1' para usuário, '2' para administrador.
} Cadastro;

// --- Protótipos das Funções Principais ---
// Um protótipo declara a função para o compilador antes de sua implementação.
// O ponteiro '*dados' permite que as funções modifiquem a instância da struct 'Cadastro' criada na main.

void cadastro(Cadastro *dados);        // Função para registrar um novo usuário/adm.
void login(Cadastro *dados);           // Função para autenticar um usuário/adm.
void recuperar_senha(Cadastro *dados); // Função para recuperar a senha.

// --- Protótipos das Funções do Administrador ---
void adm_funcoes(Cadastro *dados);     // Exibe o menu de funções do administrador.
void listagem_usuario(void);           // Lista todos os usuários cadastrados.
void localiza_usuario(Cadastro *dados); // Busca e exibe os dados de um usuário específico.
void excluir_usuario(Cadastro *dados);  // Remove um usuário do sistema.

// --- Protótipos das Funções de Interface (Front-end do Terminal) ---
void ir_para(int x, int y); // Move o cursor para uma coordenada (coluna x, linha y) no terminal.
void bordas(void);          // Desenha as bordas da interface no terminal.

// --- Protótipos das Funções Secundárias (Utilitárias) ---
void limpar(void);                                 // Limpa a tela do terminal (compatível com Windows/Linux).
void apaga_buffer(void);                           // Limpa o buffer do teclado para evitar erros de leitura.
void limpar_linha(void);                           // Limpa uma linha específica no terminal.
void envia_email(Cadastro *dados, char mensagem_email[]); // Envia um e-mail para o usuário.

// --- Protótipos das Funções de Manipulação de Arquivos Binários ---
void inicializar_arquivo(char menu_principal); // Cria o arquivo binário (.bin) se ele não existir.
void incluir_dados(Cadastro *dados);           // Salva um novo registro (struct Cadastro) no arquivo binário.
int verificar_nome(Cadastro *dados, char tentativa_nome[]); // Verifica se um nome já existe no arquivo binário.
int alterar_senha(Cadastro *dados);           // Encontra um registro no arquivo e atualiza a senha.