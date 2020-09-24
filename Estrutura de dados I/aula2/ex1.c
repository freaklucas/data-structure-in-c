#include <stdio.h>
#include <stdlib.h>

/* Lista Linear Duplamente Encadeada (LLDE) usando alocação dinâmica. */

typedef struct no {
    int dado;
    struct no *ant, *prox;
}No;


No* buscar_valor_llde(No **lista, int vlr) {
    No *novo;

    novo = (No*) malloc(sizeof(No));
    novo->ant = NULL;
    novo->prox = NULL;


    for ( novo=*lista; novo != NULL; novo=novo->prox) {
        if(novo->dado == vlr) {
            printf("%d\n", vlr);
        }
    }
    
    return 0;
}

void remover_por_valor_llde(No **lista, int vlr) {
    No *novo;

    novo = (No*) malloc(sizeof(No));
    novo->ant = NULL;
    novo->prox = NULL;

    for (novo=*lista; novo!=NULL; novo=novo->prox) {
        if(novo->dado = vlr) {
            free(novo);
            /* estou removendo a lista inteira */
        }
    }
}

void inserir_ini_llde(No **lista, int vlr) {
    No *novo;
    
    /* Preparação do nó */
    novo = (No*)malloc(sizeof(No));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->dado = vlr;

    if (*lista == NULL) {
        *lista = novo;
    }

    else {
        novo->prox = *lista;
        (*lista)->ant = novo;
        *lista = novo;
    }
}

void inserir_fim_llde(No **lista, int vlr) {
    No* novo;
    novo = (No*) malloc(sizeof(No));

    novo->ant = NULL;
    novo->prox = NULL;
    novo->dado = vlr;

    if(*lista == NULL) {
        *lista = novo;
    }
    else {
        novo->ant = *lista;
        (*lista)->ant= novo;
        *lista = novo;
    }
    /* Aparentemente está funcionando */
}

void mostrar_llde(No **lista) {
    No *p;
    if(*lista == NULL) {
        printf("lista vazia\n");
    }
    else {
        for(p=*lista; p!=NULL; p=p->prox){
            printf("%i\n", p->dado);
        }
    }
}

int verificar_integridade(No **lista) {
    if (*lista == NULL)
        return 1;
    int cont=0;
    No *p;

    /* Percurso de ida */
    for(p=*lista; p->prox!=NULL; p=p->prox) {
        cont++;
    }
    /* Percurso de volta */
    for( ; p->ant!=NULL; p=p->ant ) {
        cont--;
    }

    if( cont==0)
        return 1;
    return 0;
}

int remover_ini_llde(No **lista) {
    if (*lista == NULL)
        return 0;
    No *p;
    p = *lista;
    *lista = p->prox;
    free(p);
}

int remover_fim_llde(No **lista) {
    if(*lista == NULL)
        return 0;
    No *p;
    p = *lista;
    *lista = p->ant;
    free(p);

    /* Aparentemente funcionando */
}

void quantidade_elementos_llde(No **lista) {
    
    int count=0;
    No* novo;

    if(*lista != NULL) {
        for(novo = *lista; novo->prox != NULL; novo=novo->prox ) {
            count++;
        }
        printf("%d Elementos:\n", count);
    }
}

void inserir_elementos_ordenados_llde(No **lista, int vlr) {
    No* novo;

    /* incompleta...*/
}

int main() {
    No *lista = NULL;
    printf("teste1\n");

    inserir_ini_llde(&lista, 10);

    // mostrar_ini_llde(&lista);

    // if(verificar_integridade(&lista)) {
    //     printf("lista ok\n");
    // }
    // else {
    //     printf("lista quebrada\n");
    // }

    printf("teste 4\n");

    // remover_ini_llde(&lista);

    inserir_fim_llde(&lista, 80);


    //existe_llde(&lista);

    buscar_valor_llde(&lista, 10);


    //remover_por_valor_llde(&lista, 10);
    
    
    quantidade_elementos_llde(&lista);

    mostrar_llde(&lista);
}