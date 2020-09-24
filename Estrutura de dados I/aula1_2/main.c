#include "lista.h"

int main() {
    Lista *L;

    L = criar_lista_llse();
    inserir_inicio_llse(L, 10); 
    mostrar_lista_llse(L);
    remover_inicio_lista_llse(L);

}