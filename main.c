#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int exibirMenu();
void opcaoMenu(int opcao, Livro **l, Usuario **u, int *nextId);
void iniciarMenu(Livro **l, Usuario **u, int *nextId);

int main()
{
    Livro *l = NULL;
    Usuario *u = NULL;
    int nextId = 1;

    iniciarMenu(&l, &u, &nextId);

    // libera livros
    Livro *aux1 = l;
    while (aux1 != NULL)
    {
        Livro *temp = aux1;
        aux1 = aux1->next;
        free(temp);
    }

    // libera usuario
    Usuario *aux2 = u;
    while (aux2 != NULL)
    {
        Usuario *temp = aux2;
        aux2 = aux2->next;
        free(temp);
    }

    return 0;
}

int exibirMenu()
{
    printf("====== MENU BIBLIOTECA ====== \n");
    printf("1. Cadastro \n");
    printf("2. Consulta \n");
    printf("3. Atualização \n");
    printf("4. Exclusão \n");
    printf("5. Empréstimo \n");
    printf("6. Devolução \n");
    printf("0. Sair\n\n");

    int opcao;
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    return opcao;
}

void opcaoMenu(int opcao, Livro **l, Usuario **u, int *nextId)
{
    switch (opcao)
    {
    case 1:
        cadastro(l, u, nextId);
        break;
    case 2:
        consulta(*l, *u);
        break;
    case 3:

    case 4:
        exclusao(l, u);
        break;
    case 5:

    case 6:
        devolucao(l);
        break;

    case 0:
        printf("Saindo do programa. Até mais!\n");
        break;

    default:
        printf("Opção inválida! \n");
    }
}

void iniciarMenu(Livro **l, Usuario **u, int *nextId)
{
    int opcao = -1;
    while (opcao != 0)
    {
        opcao = exibirMenu();
        opcaoMenu(opcao, l, u, nextId);
    }
    printf("Programa finalizado! \n");
}
