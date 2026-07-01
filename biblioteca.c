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

void consultarLivroPorCodigo(Livro *l)
{
    int id;
    printf("Codigo do livro: ");
    scanf("%d", &id);
    printf("\n");
 
    Livro *aux = l;
    while (aux != NULL)
    {
        if (aux->id == id)
        {
            printf("ID: %d\n", aux->id);
            printf("Titulo: %s\n", aux->titulo);
            printf("Autor: %s\n", aux->autor);
            printf("Ano: %d\n", aux->ano);
            if (aux->status == 0)
                printf("Status: Disponivel\n\n");
            else
                printf("Status: Emprestado para %s\n\n", aux->emailUsuario);
            return;
        }
        aux = aux->next;
    }
 
    printf("Livro nao encontrado.\n\n");
}
 
void consultarLivroPorAutor(Livro *l)
{
    char autor[100];
    printf("Autor: ");
    scanf("%s", autor);
    printf("\n");
 
    int encontrou = 0;
    Livro *aux = l;
    while (aux != NULL)
    {
        if (strcmp(aux->autor, autor) == 0)
        {
            printf("ID: %d | Titulo: %s | Ano: %d\n", aux->id, aux->titulo, aux->ano);
            encontrou = 1;
        }
        aux = aux->next;
    }
 
    if (!encontrou)
        printf("Livro nao encontrado.\n\n");
    else
        printf("\n");
}
 
void consultarUsuarioPorEmail(Usuario *u)
{
    char email[100];
    printf("Email: ");
    scanf("%s", email);
    printf("\n");
 
    Usuario *aux = u;
    while (aux != NULL)
    {
        if (strcmp(aux->email, email) == 0)
        {
            printf("Nome: %s\n", aux->nome);
            printf("Email: %s\n\n", aux->email);
            return;
        }
        aux = aux->next;
    }
 
    printf("Usuario nao cadastrado.\n\n");
}
 
void consultarUsuarioPorNome(Usuario *u)
{
    char nome[100];
    printf("Nome: ");
    scanf("%s", nome);
    printf("\n");
 
    int encontrou = 0;
    Usuario *aux = u;
    while (aux != NULL)
    {
        if (strcmp(aux->nome, nome) == 0)
        {
            printf("Nome: %s | Email: %s\n", aux->nome, aux->email);
            encontrou = 1;
        }
        aux = aux->next;
    }
 
    if (!encontrou)
        printf("Usuario nao cadastrado.\n\n");
    else
        printf("\n");
}
 
void consultarEmprestimos(Livro *l, Usuario *u)
{
    char email[100];
    printf("Email do usuario: ");
    scanf("%s", email);
    printf("\n");
 
    // verifica se o usuario existe
    int usuarioExiste = 0;
    Usuario *auxU = u;
    while (auxU != NULL)
    {
        if (strcmp(auxU->email, email) == 0)
        {
            usuarioExiste = 1;
            break;
        }
        auxU = auxU->next;
    }
 
    if (!usuarioExiste)
    {
        printf("Usuario nao cadastrado.\n\n");
        return;
    }
 
    // busca os livros emprestados para esse usuario
    int encontrou = 0;
    Livro *auxL = l;
    while (auxL != NULL)
    {
        if (auxL->status == 1 && strcmp(auxL->emailUsuario, email) == 0)
        {
            printf("ID: %d | Titulo: %s | Autor: %s\n", auxL->id, auxL->titulo, auxL->autor);
            encontrou = 1;
        }
        auxL = auxL->next;
    }
 
    if (!encontrou)
        printf("Nenhum livro emprestado para este usuario.\n\n");
    else
        printf("\n");
}
 
void consulta(Livro *l, Usuario *u)
{
    int opcao = -1;
    while (opcao != 0)
    {
        printf("==== CONSULTA ====\n");
        printf("1. Livros\n");
        printf("2. Usuarios\n");
        printf("3. Emprestimos\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");
 
        if (opcao == 1)
        {
            int sub;
            printf("1. Por codigo\n2. Por autor\nOpcao: ");
            scanf("%d", &sub);
            printf("\n");
            if (sub == 1)
                consultarLivroPorCodigo(l);
            else if (sub == 2)
                consultarLivroPorAutor(l);
            else
                printf("Opcao invalida!\n\n");
        }
        else if (opcao == 2)
        {
            int sub;
            printf("1. Por email\n2. Por nome\nOpcao: ");
            scanf("%d", &sub);
            printf("\n");
            if (sub == 1)
                consultarUsuarioPorEmail(u);
            else if (sub == 2)
                consultarUsuarioPorNome(u);
            else
                printf("Opcao invalida!\n\n");
        }
        else if (opcao == 3)
            consultarEmprestimos(l, u);
        else if (opcao != 0)
            printf("Opcao invalida!\n\n");
    }
}
void excluirLivro(Livro **l)
{
    int id;
    printf("Codigo do livro a excluir: ");
    scanf("%d", &id);
    printf("\n");
 
    Livro *atual = *l;
    Livro *anterior = NULL;
 
    while (atual != NULL)
    {
        if (atual->id == id)
        {
            if (atual->status == 1)
            {
                printf("Nao e possivel excluir: livro esta emprestado.\n\n");
                return;
            }
 
            // se anterior for NULL, o livro era o primeiro da lista
            if (anterior == NULL)
                *l = atual->next;
            else
                anterior->next = atual->next;
 
            free(atual);
            printf("Livro excluido com sucesso!\n\n");
            return;
        }
        anterior = atual;
        atual = atual->next;
    }
 
    printf("Livro nao encontrado.\n\n");
}
 
void excluirUsuario(Usuario **u)
{
    char email[100];
    printf("Email do usuario a excluir: ");
    scanf("%s", email);
    printf("\n");
 
    Usuario *atual = *u;
    Usuario *anterior = NULL;
 
    while (atual != NULL)
    {
        if (strcmp(atual->email, email) == 0)//  strcmp precisei perguntar para ia poi não sabia como fazia para comparar
        //  duas strings!! Ela retorna 0 quando as duas são iguais, o problema é que em C você não pode comparar strings com == diretamente como faria com números por isso existe o strcmp.
        {
            if (anterior == NULL)
                *u = atual->next;
            else
                anterior->next = atual->next;
 
            free(atual);
            printf("Usuario excluido com sucesso!\n\n");
            return;
        }
        anterior = atual;
        atual = atual->next;
    }
 
    printf("Usuario nao cadastrado.\n\n");
}
 
void exclusao(Livro **l, Usuario **u)
{
    int opcao = -1;
    while (opcao != 0)
    {
        printf("==== EXCLUSAO ====\n");
        printf("1. Livros\n");
        printf("2. Usuarios\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");
 
        if (opcao == 1)
            excluirLivro(l);
        else if (opcao == 2)
            excluirUsuario(u);
        else if (opcao != 0)
            printf("Opcao invalida!\n\n");
    }
}

void devolucao(Livro **l)
{
    int id;
    printf("Codigo do livro a devolver: ");
    scanf("%d", &id);
    printf("\n");
 
    Livro *aux = *l;
    while (aux != NULL)
    {
        if (aux->id == id)
        {
            if (aux->status == 0)
            {
                printf("Este livro nao esta emprestado.\n\n");
                return;
            }
 
            aux->status = 0;
            aux->emailUsuario[0] = '\0';
            printf("Devolucao realizada com sucesso!\n\n");
            return;
        }
        aux = aux->next;
    }
 
    printf("Livro nao encontrado.\n\n");
}
 