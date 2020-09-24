#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *ant, *prox;
}No;

typedef struct desc{
	int qtd;		// Campo para armazenar a quantidade de elementos que a lista possui.
	No *ini, *fim;
}Desc;

int remover_inicio_llde_desc(Desc *D){
	if (D->ini == NULL)
		return 0;

	No *p;
	p = D->ini;
	D->ini = p->prox;
	free(p);
	if (D->ini == NULL){
		D->fim = NULL;
	}else{
		D->ini->ant = NULL;
	}
	D->qtd--;
	return 1;
}

void inserir_inicio_llde_desc(Desc *D, int valor){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	if (novo == NULL){
		printf("Espaço de memória insuficiente.\n");
		exit(0);
	}
	novo->dado = valor;
	novo->ant = NULL;
	novo->prox = NULL;
	
	if (D->ini == NULL){
		D->ini = novo;
		D->fim = novo;
	}else{
		novo->prox = D->ini;
		D->ini->ant = novo;
		D->ini = novo;
	}
	
	D->qtd++;
}

void mostrar_llde_desc(Desc *D){
	No *p;
	if (D->ini == NULL){
		printf("Lista vazia.\n");
		return;
	}

	for (p=D->ini; p!=NULL; p=p->prox){
		printf("%i\n", p->dado);
	}
}

void mostrar_llde_desc_volta(Desc *D){
	No *p;
	if (D->ini == NULL){
		printf("Lista vazia.\n");
		return;
	}

	for (p=D->fim; p!=NULL; p=p->ant){
		printf("%i\n", p->dado);
	}
}


int main(){
	Desc D;
	D.ini = NULL;	//inicialização
	D.fim = NULL;
	D.qtd = 0;

	inserir_inicio_llde_desc(&D, 10);
	inserir_inicio_llde_desc(&D, 20);
	inserir_inicio_llde_desc(&D, 30);

	printf("Sentido de ida.\n");
	mostrar_llde_desc(&D);
	printf("\nSentido de volta.\n");
	mostrar_llde_desc_volta(&D);
	printf("Quantidade: %i\n", D.qtd);

	printf("\nRemovendo no início.\n");
	remover_inicio_llde_desc(&D);

	printf("Sentido de ida.\n");
	mostrar_llde_desc(&D);
	printf("\nSentido de volta.\n");
	mostrar_llde_desc_volta(&D);
	printf("Quantidade: %i\n", D.qtd);

	printf("\nRemovendo no início.\n");
	remover_inicio_llde_desc(&D);

	printf("Sentido de ida.\n");
	mostrar_llde_desc(&D);
	printf("\nSentido de volta.\n");
	mostrar_llde_desc_volta(&D);
	printf("Quantidade: %i\n", D.qtd);

	printf("\nRemovendo no início.\n");
	remover_inicio_llde_desc(&D);

	printf("Sentido de ida.\n");
	mostrar_llde_desc(&D);
	printf("\nSentido de volta.\n");
	mostrar_llde_desc_volta(&D);
	printf("Quantidade: %i\n", D.qtd);

}
