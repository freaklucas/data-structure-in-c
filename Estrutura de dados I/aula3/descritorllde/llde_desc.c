#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *ant, *prox;
}No;

typedef struct desc {
    int qtd;
    No *ini, *fim;
}Desc;

void inserir_ininio_llde_desc(Desc *D, int valor) {
    No* novo;
    novo = (No*) malloc(sizeof(No));
    if(novo == NULL) {
        printf("Espaço de memória insuficiente\n");
        exit(0);
    }

    novo->dado = valor;
    novo->ant = NULL;
    novo->prox= NULL;

    if(D->ini == NULL) {
        D->ini = novo;
        D->fim = novo;
    }

    else {
        novo->prox = D->ini;
        D->ini->ant = novo;
        D->ini = novo;
    }

    D->qtd++;
}

void mostrar_llde_desc(Desc *D) {
    No* p;
    if(D->ini == NULL) {
        printf("Lista vazia\n");
        return ;
    }
    for(p=D->ini; p!= NULL; p=p->prox) {
        printf("%i\n", p->dado);
    }

    //     for(p=D->fim; p!= NULL; p=p->ant) {
    //     printf("%i\n", p->dado);
    // }
}

void remover_ini_llde_desc(Desc* D) {
    if(D->ini == NULL) {
        return 0;
    }
    No* p;
    p = D->ini;
    D->ini = p->prox;
    free(p);

    if(D->ini == NULL) {
        D->fim = NULL;
    }
    else {
        D->ini->ant = NULL;
    }
    D->qtd--;
    
}
int main() {
    Desc D;
    D.ini = NULL;
    D.fim = NULL;
    D.qtd = 0;

    inserir_ininio_llde_desc(&D, 10);
    inserir_ininio_llde_desc(&D, 20);
    inserir_ininio_llde_desc(&D, 30);

    mostrar_llde_desc(&D);

    remover_ini_llde_desc(&D);

    mostrar_llde_desc(&D);


}

