typedef struct pilha Pilha;


Pilha *criar_pilha();

void remover_todos(Pilha * pilha);

int empilhar(Pilha *pilha, int valor);

int desempilhar(Pilha *pilha);

int topo(Pilha *pilha);

int pilha_vazia(Pilha *pilha);

void mostrar_pilha(Pilha *pilha);
