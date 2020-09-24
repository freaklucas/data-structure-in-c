#include <stdlib.h>
#include <stdio.h>
#define ARRAY 10 

typedef struct pilha {
    int array[ARRAY];
    int topo;
}Pilha;

void mostrar_pilha(Pilha *pilha){
    if(pilha == NULL){
        return;
    }
    for( int i = 0; i < pilha->topo; ++i) {
        printf("%d\n", pilha->array[i]);
    }
}

Pilha * criar_pilha() {

    Pilha* novo = (Pilha* ) malloc(sizeof(Pilha));
    novo->topo = 0;

    return novo;
}

int empilhar(Pilha *pilha, int vlr) {
    
    if(pilha == NULL)
        return 0;

    pilha->array[pilha->topo] = vlr;
    pilha->topo++;

    return 1;
}


int main(){

    Pilha* pilha = criar_pilha();

    empilhar(pilha, 5);
    empilhar(pilha, 10);
    empilhar(pilha, 15);

    mostrar_pilha(pilha);

    return 0; 
}