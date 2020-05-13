#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

#define MAXIMO 10

struct lista{
	int vet[MAXIMO];
	int qtd;
};

Lista * criar_lista(){
	Lista *lista = (Lista *) malloc(sizeof(Lista));
	lista->qtd = 0;
	return lista;
}

int remover_lista(Lista* lista){
	// Atividade. Desenvolver essa função.
	if(lista ==NULL){
		exit(0);
	}
	for(int i=0;i<MAXIMO;++i){
		lista->vet[i] = 0;
	}

}

//Função extra utilizada durante a inserção (Não faz parte das operações do TAD)
void deslocar_direita(Lista *lista){
	int i;
	for (i=lista->qtd; i>0; i--){
		lista->vet[i] = lista->vet[i-1];
	}
}

int inserir_inicio(Lista* lista, int valor){
	if (lista == NULL){
		exit(0);
	}

	if(lista->qtd + 1 > 10){
		exit(0); // lista cheia
	}
	else{
		
	}
}

int inserir_fim(Lista* lista, int valor){
	// Atividade. Desenvolver essa função.
	if(lista == NULL ){
		exit(0); // lista vazia
	}

	if(lista->qtd+1 > 10){
		exit(0); // lista cheia
	}
	else {
		deslocar_direita(lista);
		lista->vet[0] = valor;
		lista->qtd++;
	}
}

int remover_inicio(Lista *lista){
	// Atividade. Desenvolver essa função.
	if(lista == NULL){
		return 0; // LISTA VAZIA
	}
	if(lista->qtd <=0){
		return 0;
	}
	else{
		for(int i=0; i <lista->qtd;++i){
			lista->vet[i] = lista->vet[i+1];
		}
		lista->qtd--;
		return 1;
	}

}

int remover_fim(Lista* lista){
	// Atividade. Desenvolver essa função.
	if(lista == NULL){
		return 0;
	}
	
	else {
		lista->vet[lista->qtd] = 0;
		lista->qtd--;
	}
}

int existe_valor(Lista *lista, int valor){
	// Atividade. Desenvolver essa função.
	for( int i=0 ; i<lista->qtd; ++i){
		if(lista->vet[i] == valor){
			return 1; // return valor igual
		}
	}
	return 0;
}

void mostrar_lista(Lista *lista){
	for(int i=0; i < lista->qtd;++i){
		printf("[%i] : %i\n", i,lista->vet[i]);
	}
}

