#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    int dado;
    struct no *prox;
}No;

struct lista {
    No *cabeca;
};

Lista* criar_lista_llse() {
    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));

    lista->cabeca = NULL;

    return lista;
}

int inserir_inicio_llse(Lista *lista, int valor) {
    if(lista == NULL) {
        return 0;
    }

    No *novo;
    novo = (No*) malloc(sizeof(No));
    if(novo == NULL)
        return 0;

    novo->dado = valor;
    novo->prox = NULL;

    if(lista->cabeca == NULL) {
        lista->cabeca = novo;
    }
    else {
        novo->prox = lista->cabeca;
        lista->cabeca = novo; 
    }
    return 1;
}

void mostrar_lista_llse(Lista *lista) {
    printf("Lista linear simplismente encadeada:\n");
    if(lista == NULL) {
        printf("Não é possível exibir uma lista vazia");
        return;
    }
    if(lista->cabeca == NULL) {
        printf("Não é possível exibir uma lista vazia");
        return;
    }
    No *p;
    for(p=lista->cabeca; p!=NULL; p=p->prox) {
        printf("%i\n", p->dado);
    }
}

// Lista *remover_inicio_lista_llse(Lista *lista) {
//     if(lista == NULL)
//         return lista;
    
//     Lista *p;
//     p = lista;
//     lista = lista->cabeca;    

//     free(p);

//     return lista;
// }

int *remover_inicio_lista_llse(No *lista) {
    if(lista == NULL)
        return lista;
    
    No *p;
    p = lista;
    lista = lista->prox;    

    free(p);

    return lista;
}