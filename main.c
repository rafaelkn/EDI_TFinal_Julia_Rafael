#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


int exibirMenu(){
    printf("==== MENU BIBLIOTECA ==== \n");
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


void opcaoMenu (int opcao) {
    switch (opcao) {
        case 1:

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


void iniciarMenu () {
    int opcao = -1;
    while (opcao != 0) {
        opcao = exibirMenu();
        opcaoMenu(opcao); 
    }
    printf("Programa finalizado! \n");
}




 
int main () {
    iniciarMenu();

    return 0;
}