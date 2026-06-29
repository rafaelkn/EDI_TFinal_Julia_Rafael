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

void cadastrarLivro(Livro **l, int *nextId);
void cadastrarUsuario(Usuario **u);
void Cadastro(Livro **livros, Usuario **usuarios, int *nextId);

void consultarLivroPorCodigo(Livro *l);
void consultarLivroPorAutor(Livro *l);
void consultarUsuarioPorEmail(Usuario *u);
void consultarUsuarioPorNome(Usuario *u);
void consultarEmprestimos(Livro *l, Usuario *u);
void consulta(Livro *l, Usuario *u);

void excluirLivro(Livro **l);
void excluirUsuario(Usuario **u);
void exclusao(Livro **l, Usuario **u);