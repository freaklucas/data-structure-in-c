#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
}No;

typedef struct lista {
    int dado;
    struct lista *prox;
}Lista;

void mostrar_lista_llse(Lista **lista) {
    Lista* p;
    if(p == NULL) {
        printf("A sua lista está vazia\n");
    }

    else {
        for( p=*lista; p!=NULL; p=p->prox) {
            printf("%i\n", p->dado);
        }
    }   
}


Lista* inserindo_inicio_llse(Lista **lista, int valor) {

    Lista *novo;
    novo = (Lista*) malloc(sizeof(Lista));

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return *lista;
}

int removendo_inicio_llse(Lista **lista) {
    if(*lista == NULL)
        return 0;
    
    Lista* p;
    p = *lista;
    *lista = p->prox;
    free(p);

    return 1;
}

Lista* inserindo_final_llse(Lista **lista, int valor) {

    Lista *novo;
    novo = (Lista*) malloc(sizeof(Lista));

    novo->dado = valor;
    novo->prox = NULL;
    *lista = novo;

    return *lista;
}





int main() {

    Lista* lista = NULL;
    printf("Teste 1\n");

    // inserindo_inicio_llse(&lista, 60);
    // removendo_inicio_llse(&lista);
    inserindo_final_llse(&lista, 20);

    mostrar_lista_llse(&lista);


    
}