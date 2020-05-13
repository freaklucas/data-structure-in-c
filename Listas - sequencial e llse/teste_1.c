#include "lista.h"
#include <stdio.h>

int main(){
	Lista *A;
	A = criar_lista();
	if (A != NULL)
		printf("Lista A criada.\n");
	if (inserir_inicio(A, 10))
		printf("Valor 10 inserido no início de A.\n");
	if (inserir_inicio(A, 20))
		printf("Valor 20 inserido no início de A.\n");
	if (inserir_inicio(A, 30))
		printf("Valor 30 inserido no início de A.\n");
	printf("Lista A: ");
	mostrar_lista(A);
}

