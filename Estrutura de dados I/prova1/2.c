#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    struct no *cabeca;
} Lista;

typedef struct no {
	int dado;
	struct no *prox;
} No;

Lista* criar_lista() {
    Lista* lista;
    lista = (Lista*) malloc(sizeof(Lista));
    lista->cabeca = NULL;
    return lista;
}

int inserir_inicio(Lista *lista, int valor) {
    No *novo;
    novo = (No*) malloc(sizeof(No));
    if(novo == NULL)
        return 0;

    novo->dado = valor;
    novo->prox = NULL;

    if(lista->cabeca == NULL) {
        lista->cabeca  = novo;
    }
    else {
        novo->prox = lista->cabeca ;
        lista->cabeca = novo;
    }

    return 1;
}

void mostrar_lista(Lista *lista) {

    if(lista != NULL) {
        No* no;
        no = lista->cabeca;
        do {
            printf("%d\n", no->dado);
            no = no->prox;
        } while (no !=  NULL);   
    }
}
void concatenar(Lista *lista1, Lista *lista2) {
    if(lista1->cabeca == NULL){
        return;
    }

    if(lista2->cabeca == NULL) {
        return;
    }

    No *controle;
    controle = lista1->cabeca;
    
    for ( ;controle->prox != NULL; controle = controle->prox) {
    }
    controle->prox = lista2->cabeca;
    lista2->cabeca = NULL;

    // free(lista2); /*lista 2 precisa ser liberada */
}


int main(){
    Lista *lista1, *lista2;
    lista1 = criar_lista();
    lista2 = criar_lista();

    inserir_inicio(lista1, 5);
    inserir_inicio(lista1, 10);
    inserir_inicio(lista1, 15);

    inserir_inicio(lista2, 20);
    inserir_inicio(lista2, 25);
    inserir_inicio(lista2, 30);

    printf("Concatenando:\n");

    concatenar(lista1, lista2);
    printf("Lista 1:\n");
    mostrar_lista(lista1);
    printf("Lista 2:\n");
    mostrar_lista(lista2);



    return 0;
}