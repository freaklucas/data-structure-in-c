#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct lista{
	No *cabeca;
}Lista;

Lista * criar_lista(){
	Lista *lista;
	lista = (Lista *) malloc(sizeof(Lista));

	lista->cabeca = NULL;
	return lista;
}

int remover_lista(Lista* lista){	
	// Atividade. Desenvolver essa função.
	if(lista==NULL){
		return 0;
	}
	lista->cabeca=NULL;
	return 1;
}

int inserir_inicio(Lista *lista, int valor){
	if (lista == NULL){
		return 0;
	}

	No *novo;
	novo = (No*)malloc(sizeof(No));
	novo->dado = valor;
	novo->prox = NULL;

	if (lista->cabeca == NULL){
		lista->cabeca = novo;
	}
	else{
		novo->prox = lista->cabeca;
		lista->cabeca = novo;
	}
	return 1;
}

int inserir_fim(Lista *lista, int valor){
	// Atividade. Desenvolver essa função.
	No *novo;
	novo = (No*)malloc(sizeof(No));
	if(novo == NULL){
		return 0; // memoria insuficiente
	}

	

	novo->dado = valor;
	novo->prox = NULL;

	if(lista->cabeca = NULL){
		lista->cabeca = novo;
	}
	else{
		No *n;
		for(n = lista->cabeca; n->prox !=NULL; n = n->prox);
		n->prox = novo;
		lista->cabeca = n;
		return 1;
	}
}

int remover_inicio(Lista *lista){
	// Atividade. Desenvolver essa função.
	if(lista->cabeca == NULL){
		return 0;
	}
	No* var = lista->cabeca->prox;
	free(lista->cabeca);
	lista->cabeca = var;
	return 1;
}

int remover_fim(Lista* lista){
	// Atividade. Desenvolver essa função.
	// analisar a remoção
	if(lista->cabeca ==NULL)
		return 0;

		No *p, *q=NULL;
		for(p = lista->cabeca; p->prox !=NULL; p = p->prox){
			q = p;
		}
		free(p);

		if(q == NULL){
			lista->cabeca= NULL;
		}
		else {
			q->prox=NULL;
		}

		return 1;
}

int existe_valor(Lista* lista, int valor){
	// Atividade. Desenvolver essa função.
	if(lista ->cabeca = NULL){
		printf("lista vazia!\n");
		return 0;
	}
	else {
		No* interator;
		for(interator = lista->cabeca; interator !=NULL; interator = interator->prox){
			if(interator->dado == valor){
				
			}
		}
		return 1;
	}
	return 0;
}

void mostrar_lista(Lista *lista){
	printf("LLSE: ");
	if (lista->cabeca == NULL){
		printf("A lista recebida é nula.\n");
	
	}
	else {
	
	No *p;
	for (p=lista->cabeca; p!= NULL; p=p->prox){
		printf("%i ", p->dado);
	}
	printf("\n");
}
}

