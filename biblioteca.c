#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"


void cadastarLivro (Livro *livros) {
    printf ("Digite o título do livro: ");
    scanf ("%s", livros->titulo);
    printf("\n");

    printf("Digite o nome do(a) autor(a): ");
    scanf ("%s", livros->autor);
    printf("\n");

    printf ("Digite o ano de publicação");
    scanf ("%d", &livros->ano);
    printf("\n");

    printf ("Digite o código (ID) do livro: ");
    scanf ("%d", &livros->id);
    printf("\n");

    livros->status = 1;

    printf("Digite o email cadastrado para adquirir o empréstimo: ");
    scanf ("%s", livros->emailUsuario);
    printf("\n");
}

void cadastrarUsuarios (Usuario *usuarios) {

}

void cadastro (Livro *livros, Usuario *usuarios) {
    int opcao = -1;
    while (opcao != 0) {
        printf ("==== CADASTRO ==== \n");
        printf("1. Livros \n");
        printf("2. Usuários \n");
        printf("0. Voltar \n");

        scanf ("%d", &opcao);

        if (opcao == 1){
            cadastarLivro(livros);
        }
        else if (opcao == 2) {
            cadastrarUsuarios(usuarios);
        }
    }
}