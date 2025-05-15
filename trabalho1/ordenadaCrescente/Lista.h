#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int chave;
    struct No* anterior;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} Lista;

void inicializar(Lista* L);
int retornar_Tamanho(Lista* L);
void imprimir_Lista(Lista* L);
void inserir_Chave(Lista* L, int chave);
No *buscarChave(Lista* L, int chave);
bool removerChave(Lista* L, int chave);
void reinicializarLista(Lista* L);