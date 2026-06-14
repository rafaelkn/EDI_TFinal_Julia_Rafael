#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

void cadastrarLivro(Livro **l, int *nextId)
{
    Livro *new = malloc(sizeof(Livro));
    if (new == NULL)
    {
        printf("Erro de alocação!\n");
        return;
    }

    printf("Digite o título do livro: ");
    scanf("%s", new->titulo);
    printf("\n");

    printf("Digite o nome do(a) autor(a): ");
    scanf("%s", new->autor);
    printf("\n");

    printf("Digite o ano de publicação");
    scanf("%d", &new->ano);
    printf("\n");

    new->id = *nextId;
    *nextId += 1;

    new->status = 0;
    new->emailUsuario[0] = '\0';
    new->next = NULL;

    // pra inserir no inicio dda lista:
    new->next = *l;
    *l = new;

    printf("Livro Cadastrado com sucesso! \n\n");
}

void cadastrarUsuario(Usuario **u)
{
    char email[100];

    printf("Digite seu melhor email: ");
    scanf("%s", email);
    printf("\n");

    Usuario *aux = *u;
    while (aux != NULL)
    { // percorre a lista pra achar sse o email é duplicado
        int str;
        str = strcmp(aux->email, email);
        if (str == 0)
        {
            printf("Email já cadastrado! \n\n");
            return;
        }
        aux = aux->next;
    }

    // se toda aquela validaçao der certo, aloca pra castrar o novo email
    Usuario *new = malloc(sizeof(Usuario));
    if (new == NULL)
    {
        printf("Erro de alocação! \n");
        return;
    }

    strcpy(new->email, email);

    printf("Digite seu nome: ");
    scanf("%s", new->nome);
    printf("\n");

    new->next = *u;
    *u = new;

    printf("Usuário cadastrado com sucesso! \n\n");
}

void cadastro(Livro **livros, Usuario **usuarios, int *nextId)
{
    int opcao = -1;
    while (opcao != 0)
    {
        printf("==== CADASTRO ==== \n");
        printf("1. Livros \n");
        printf("2. Usuários \n");
        printf("0. Voltar \n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1)
        {
            cadastrarLivro(livros, nextId);
        }

        else if (opcao == 2)
        {
            cadastrarUsuario(usuarios);
        }

        else if (opcao != 0 && opcao != 1 && opcao != 2)
        {
            printf("Opção inválida!\n\n");
        }
    }
    printf("Sainddo de Cadastro... \n\n");
}