#include<stdio.h>
#include<stdlib.h>

typedef struct no {
	int dado;
	struct no *ant, *prox;
}No;

void inserir_ini_llde(No **lista, int vlr){
	No *novo;

	//Preparação do nó
	novo = (No *)malloc(sizeof(No));
	novo->ant = NULL;
	novo->prox = NULL;
	novo->dado = vlr;

	if (*lista == NULL){
		*lista = novo;
	}else{
		novo->prox = *lista;
		(*lista)->ant = novo;
		*lista = novo;
	}
}

void mostrar_llde(No **lista) {
	No *p;

	if(lista != NULL){
		for ( p=*lista; p!=NULL; p=p->prox) {
			printf("%i\n", p->dado);
		}
	}
}

int verificar_integridade(No **lista) {
	if (*lista == NULL)
		return 1;

	int count=0;
	No *p;
	
	//Percurso de ida
	for ( p=*lista; p->prox != NULL; p = p->prox) {
		count++;
	}

	//Percurso de volta
	for (; p->ant != NULL; p = p->ant){
		count--;
	}

	if (count == 0)
		return 1;

	return 0;
}

void concatenar(No **lista1, No **lista2) {

    No * controle = *lista1;
    for ( ;controle->prox != NULL; controle = controle->prox);
    controle->prox = *lista2;
   (*lista2)->ant = controle;
   *lista2 = NULL;
}

int main() {

    No *lista2 = NULL;
    No *lista1 = NULL;

    printf("lista 1\n");
	
    inserir_ini_llde(&lista1, 2);
	inserir_ini_llde(&lista1, 4);
	mostrar_llde(&lista1);

    printf("lista 2\n");
	
    inserir_ini_llde(&lista2, 6);
	inserir_ini_llde(&lista2, 8);
	mostrar_llde(&lista2);
    
    printf("concatenação \n");

    concatenar(&lista1, &lista2);
	mostrar_llde(&lista1);
	mostrar_llde(&lista2);
    
 
    return 0;
}