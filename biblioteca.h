typedef struct usuario {
    char email[100];
    char nome[100];
    struct Usuario *prox;
} Usuario;

typedef struct livro {
    char titulo[100];
    char autor[100];
    int ano;
    int codigo;
    int status;
    char emailUsuario[100];
    struct Livro *prox;
} Livro;