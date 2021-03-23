#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define GRAU 4

typedef struct no {
	int qtd_chaves;
	int chaves[GRAU];
	struct no *filhos[GRAU+1];
}No;

No * criar_no(){
	int i;
	No *novo = (No *)malloc(sizeof(No));
	for (i=0; i<GRAU+1; i++){
		novo->filhos[i] = NULL;
	}
	novo->qtd_chaves = 0;

	return novo;
}

void mostrar_no(No **R, int nivel){
	int i;
	printf("Nivel[%i] qtd[%i]: ", nivel, (*R)->qtd_chaves);
	for(i=0; i<(*R)->qtd_chaves; i++){
		printf("%i ", (*R)->chaves[i]);
	}
	printf("\n");
}

void pre_ordem_nivel(No **R, int nivel){
	if (*R!=NULL){
		int i;
		mostrar_no(R, nivel);
		for (i=0; i<GRAU+1; i++){
			pre_ordem_nivel(&(*R)->filhos[i], nivel+1);
		}
	}
}

void pre_ordem(No **R){
	pre_ordem_nivel(R, 0);
}

void inserir_mais_um(No **R, int vlr){
	int i;
	for(i=(*R)->qtd_chaves-1; i>=0; i--){
		if (vlr > (*R)->chaves[i])
			break;
		printf("deslocando [%i] para direita.\n", (*R)->chaves[i]);
		(*R)->chaves[i+1] = (*R)->chaves[i];
		(*R)->filhos[i+2] = (*R)->filhos[i+1];
	}

	(*R)->chaves[i+1] = vlr;
	(*R)->qtd_chaves++;
}

void inserir(No **R, int vlr){
	if (*R == NULL){
		*R = criar_no();
		(*R)->chaves[0] = vlr;
		(*R)->qtd_chaves++;
		return;
	}

	if ((*R)->filhos[0] == NULL){ // Nó folha
		inserir_mais_um(R, vlr);
	}else{


		// identificar a ramificação p/ descer na árvore
	}
	
}

No * criar_irmao(No **R){
	No *irmao;
	int i, j;

	irmao = criar_no();

	for (i=ceil(GRAU/2.0), j=0; i<GRAU; i++, j++){
		irmao->qtd_chaves++;
		(*R)->qtd_chaves--;
		irmao->chaves[j] = (*R)->chaves[i];
		irmao->filhos[j] = (*R)->filhos[i];
		(*R)->filhos[i] = NULL;
	}
	irmao->filhos[j] = (*R)->filhos[i];
	(*R)->filhos[i] = NULL;

	(*R)->qtd_chaves--; // chave do elemento promovido
	return irmao;	
}

void divide_no_raiz(No **R){
	No *irmao;

	irmao = criar_irmao(R);

	//Criar nó raiz
	No *novo = criar_no();
	novo->chaves[0] = (*R)->chaves[(int) ceil(GRAU/2.0) -1 ];
	novo->qtd_chaves++;
	novo->filhos[0] = *R;
	novo->filhos[1] = irmao;

	*R = novo;
}

void inserir_B(No **R, int vlr){
	inserir(R, vlr);

	if ((*R)->qtd_chaves >= GRAU){
		printf("Divide o nó raiz.\n");
		divide_no_raiz(R);
	}

}


int main(){

	No *R=NULL;
	
	printf("inserindo 40\n");
	inserir_B(&R, 40);
	printf("inserindo 30\n");
	inserir_B(&R, 30);
	printf("inserindo 20\n");
	inserir_B(&R, 20);
	printf("inserindo 10\n");
	inserir_B(&R, 10);

	pre_ordem(&R);

}
