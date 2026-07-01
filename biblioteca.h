typedef struct usuario
{
    char email[100];
    char nome[100];
    struct usuario *next;
} Usuario;

typedef struct livro
{
    char titulo[100];
    char autor[100];
    int ano;
    int id;
    int status;
    char emailUsuario[100];
    struct livro *next;
} Livro;

// funcao de validação (valida se o que foi digitado pelo usuario é um inteiro, serve só para campos de int)
int lerInteiro(char mensagem[]);

// 1- Cadastro
void cadastrarLivro(Livro **l, int *nextId);
void cadastrarUsuario(Usuario **u);
void cadastro(Livro **livros, Usuario **usuarios, int *nextId);

// 2- Consulta
void consultarLivroPorCodigo(Livro *l);
void consultarLivroPorAutor(Livro *l);
void consultarUsuarioPorEmail(Usuario *u);
void consultarUsuarioPorNome(Usuario *u);
void consultarEmprestimos(Livro *l, Usuario *u);
void consulta(Livro *l, Usuario *u);

// 3- Altualização
void atualizarLivro(Livro **livros);
void atualizarUsuario(Usuario **usuarios);
void atualizacao(Livro **livros, Usuario **usuarios);

// 4- Exclusão
void excluirLivro(Livro **l);
void excluirUsuario(Usuario **u);
void exclusao(Livro **l, Usuario **u);

// 5- Empréstimo
void emprestimo(Livro **livros, Usuario **usuarios);

// 6- Devolução
void devolucao(Livro **l);
