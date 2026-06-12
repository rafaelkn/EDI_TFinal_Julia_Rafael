#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int exibirMenu();
void opcaoMenu (int opcao, Livro *l, Usuario *u);
void iniciarMenu (Livro *l, Usuario *u);

 
int main () {
    Livro l;
    Usuario u;
    iniciarMenu(&l, &u);

    return 0;
}


int exibirMenu(){
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


void opcaoMenu (int opcao, Livro *l, Usuario *u) {
    switch (opcao) {
        case 1:
            cadastro(l, u);
            break;
        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 0:
            printf ("Saindo do programa. Até mais!\n");
            break;

        default:
            printf ("Opção inválida! \n");

    } 
}


void iniciarMenu (Livro *l, Usuario *u) {
    int opcao = -1;
    while (opcao != 0) {
        opcao = exibirMenu();
        opcaoMenu(opcao, l, u); 
    }
    printf("Programa finalizado! \n");
}

