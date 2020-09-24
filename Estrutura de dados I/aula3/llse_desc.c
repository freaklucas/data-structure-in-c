#include <stdio.h>
#include <stdlib.h>

typedef struct no {

    int dado;
    struct no *prox;
}No;

typedef struct  desc {
    
    No *ini, *fim;

}Desc;

void inserir_ini_llse_des(Desc *D, int vlr) {
    No *novo;
    novo = (No *) malloc(sizeof(No));
    novo->dado = vlr;
    novo->prox = NULL;

    if(D->ini == NULL) {
        
        D->ini = novo;   
        D->fim = novo;
    }

    else  {
        novo->prox = D->ini;
        D->ini = novo;

    }
}

void mostrar_llse_desc(Desc *D) {
    if(D->ini == 0) {
        printf("Lista vazi\n");
    }
    else  {
        No *p;
        for(p=D->ini; p != NULL ; p=p->prox) {
            printf("%i\n", p->dado);
        }
    }
}

void inserir_ordenado_llse_desc(Desc *D, int valor) {
    No *novo;
    if(novo == NULL ) {
        printf("Memória insuficiente\n");
        exit(0);
    }
    novo->dado = valor;
    novo->prox = NULL;

    if( D->ini == NULL) {
        D->ini = novo;
        D->fim = novo;
    }
    else  {
        No *p,*q;
        q = NULL;
        for(p=D->ini; p != NULL ; p=p->prox) {
            if(valor < p->dado) {
                break;
            }
            q = p;
        }
        if(q= NULL) { /* Inserção no início */
            novo->prox = p;
            D->ini = novo;
        }
        else  {
            if(p == NULL) { /* Inserção no final */
                q->prox = novo;
                D->fim = novo;
            }
            else { /* Inserção no meio */
                q->prox = novo;
                novo->prox = p;
            }
        }
    }
}

int main() {
    Desc D;

    D.ini = NULL;
    D.fim = NULL;

    inserir_ordenado_llse_desc(&D, 10);
    inserir_ordenado_llse_desc(&D, 30);
    inserir_ordenado_llse_desc(&D, 20);

    // inserir_ini_llse_des(&D, 10);
    // inserir_ini_llse_des(&D, 20);
    // inserir_ini_llse_des(&D, 30); 

    mostrar_llse_desc(&D);

    return 0;
}
