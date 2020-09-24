#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
/* Lista encadeada com uma estrutura de nó */
/* Material : https://www.cos.ufrj.br/~rfarias/cos121/aula_11.html */
typedef struct no {
    int dado;
    struct no *prox;
}No;

struct pilha {
    
    struct no *topo;
};


Pilha * criar_pilha() { 
    
    Pilha *nova_pilha;
    nova_pilha = (Pilha *) malloc(sizeof(Pilha));
    if(nova_pilha == NULL)
        return NULL;
    nova_pilha->topo = NULL;

    return nova_pilha;
}

void remover_todos(Pilha * pilha) {
    if (pilha == NULL) {
        printf("tentativa de remover todos sem antes criar uma pilha\n");
        exit(0);
    }

    while(desempilhar(pilha));



}

int empilhar(Pilha *pilha, int valor) {

    if (pilha == NULL) {
        printf("Estantiva de empilhar sem antes de empilhar a pilha\n");
        exit(0);
    }
    /*Preparando o nó para inseri-lo*/
    No *novo;
    novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    
    if(novo == NULL) {
        return 0;
    }

    if(pilha->topo == NULL) {

        pilha->topo = novo;
    }

    else {
        novo->prox = pilha->topo;
        pilha->topo = novo;
    }

    return 1;
}

int desempilhar(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Estantiva de desempilhar sem antes de empilhar a pilha\n");
        exit(0);
    }

    if(pilha->topo == NULL) {
        return 0;
    }

    No *p;
    p = pilha->topo;
    pilha->topo = p->prox;

    free(p);

    return 1;
}

int topo(Pilha *pilha) {
    if(pilha == NULL) {
        printf("Tentativa consultar o topo sem antes criar a pilha\n");
        exit(0);
    }

    if(pilha->topo == NULL) {
        printf("Tentativa de retornar o topo de uma pilha que está vazia\n");
        exit(0);
    }

    return pilha->topo->dado;
}

int pilha_vazia(Pilha *pilha) {
    if (pilha == NULL) {
        printf("tentativa de consultar uma pilha sem ter criado uma pilha\n");
        exit(0);
    }

    if(pilha->topo == NULL) {
        return 1;
    }

    return 0;
}

void mostrar_pilha(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Estantiva de empilhar sem antes de empilhar a pilha\n");
        exit(0);
    }
    No *p;
    for(p=pilha->topo; p!=NULL; p=p->prox) {
        printf("%i\n", p->dado);
    }
}   
