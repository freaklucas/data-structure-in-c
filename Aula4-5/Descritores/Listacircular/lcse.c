#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
}No;

void inserir_fim_lcse(No **lista, int vlr) {
    No *novo;
    novo = (No*) malloc(sizeof(No));
    if(novo == NULL) {
        printf("Memória insuficiente\n");
        exit(0);
    }
    novo->dado = vlr;
    novo->prox= NULL;

    if(*lista == NULL) {
        *lista = novo;
        novo->prox = novo;
    }
    else {
        No *p;
        for ( p=*lista; p->prox != *lista; p=p->prox );
        p->prox = novo;
        novo->prox = *lista;
    }
}

void inserir_inicio_lcse(No **lista, int vlr) {
    No *novo;
    novo = (No*) malloc(sizeof(No));
    if(novo == NULL) {
        printf("Memória insuficiente\n");
        exit(0);
    }
    novo->dado = vlr;
    novo->prox= NULL;

    if(*lista == NULL) {
        *lista = novo;
        novo->prox = novo;
    }
    else {
        No *p;
        for( p=*lista; p->prox!=*lista; p=p->prox) {
            novo->prox = *lista;
            p->prox = novo;
            *lista = novo;
        }
    }
}

void mostrar_lista_lcse(No **lista) {
    if(*lista == NULL) {
        printf("Lista vazia\n");
        return;
    }
    No *p;
    for (p=*lista ; p->prox != *lista; p=p->prox) {
        printf("%i\n" p->dado);
    }
    printf("%i\n" p->dado);
}

void inserir_apos_primeiro_lcse(No **lista, int vlr) {
    No *novo;
    novo = (No*) malloc(sizeof(No));
    if(novo == NULL) {
        printf("Memória insuficiente\n");
        exit(0);
    }

    novo->dado = vlr;
    novo->prox = NULL;

    if(*lista == NULL) {
        *lista = novo;
        novo->prox = novo;
    }
    else {
        novo->prox = (*lista)->prox;
        (*lista)->prox = novo;

    }

}


int main() {
    
    No *lista = NULL;
    inserir_inicio_lcse(&lista, 10);
    inserir_inicio_lcse(&lista, 20);
    inserir_inicio_lcse(&lista, 30);

    mostrar_lcse(&lista);
}