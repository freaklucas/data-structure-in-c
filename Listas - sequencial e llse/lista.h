
typedef struct lista Lista;
typedef struct no No;

Lista* criar_lista();

int remover_lista(Lista* lista);
int inserir_inicio(Lista* lista, int valor);
int inserir_fim(Lista* lista, int valor);
int remover_inicio(Lista *lista);
int remover_fim(Lista* lista);
int existe_valor(Lista* lista, int valor);
void mostrar_lista(Lista* lista);

