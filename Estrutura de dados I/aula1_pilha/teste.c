#include <stdio.h>
#include "pilha.h"

int main() {

    Pilha  *p1;

    p1 = criar_pilha();

    if(p1 == NULL){
        printf("Erro ao criar\na");
    }
    else {
        printf("Pilha criada!\n");
    }

    printf("Teste 1\n");


    empilhar(p1, 10);
    mostrar_pilha(p1);

    printf("Teste 2\n");

    empilhar(p1, 20);
    mostrar_pilha(p1);

    printf("Teste 3\n");

    empilhar(p1, 30);
    mostrar_pilha(p1);

    printf("Teste 4\n");

    desempilhar(p1);
    mostrar_pilha(p1);
    
    // printf("Teste 5\n");

    // desempilhar(p1);
    // mostrar_pilha(p1);

    // printf("Teste 6\n");

    // desempilhar(p1);
    // mostrar_pilha(p1);

    //printf("O elemento de topo é: %d\n", topo(p1));

    remover_todos(p1);

    if(pilha_vazia(p1)) {
        printf("A pilha está vazia\n");
    }
    else {
        printf("A pilha nao está vazia\n");
    }

    return 0;
}

