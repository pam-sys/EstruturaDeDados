#include"Lista.h"

void inicializar(Lista* L){
    L->inicio = NULL;
    L->tamanho = 0;
}

int retornar_Tamanho(Lista* L){
    return L->tamanho;
}

void imprimir_Lista(Lista* L){
    if (L->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = L->inicio;
    int i = 0;

    do {
        printf("%d ", atual->chave);
        atual = atual->proximo;
        i++;
    } while (atual != L->inicio && i < L->tamanho); 
}

No *buscarChave(Lista* L, int chave){
    if (L->inicio == NULL) {
        return NULL; 
    }

    No *atual = L->inicio;
    int i = 0;

    do {
        if (atual->chave == chave) {
            return atual; 
        }
        atual = atual->proximo;
        i++;
    } while (atual != L->inicio && i < L->tamanho);

    return NULL; 
}

void inserir_Chave(Lista* L, int chave){
    No* novo = malloc(sizeof(No));

    novo->chave = chave;

    if (L->inicio == NULL) {
        novo->proximo = novo;
        novo->anterior = novo;
        L->inicio = novo;
    }
    else {
        No* atual = L->inicio;

        if (chave < L->inicio->chave) {
            No* ultimo = L->inicio->anterior;

            novo->proximo = L->inicio;
            novo->anterior = ultimo;

            ultimo->proximo = novo;
            L->inicio->anterior = novo;

            L->inicio = novo;  
        }
        else {

            No* p = L->inicio;
            while (p->proximo != L->inicio && p->proximo->chave < chave) {
                p = p->proximo;
            }

            No* prox = p->proximo;

            novo->proximo = prox;
            novo->anterior = p;

            p->proximo = novo;
            prox->anterior = novo;
        }
    }

    L->tamanho++;
}

bool removerChave(Lista* L, int chave) {
    No* removido = buscarChave(L, chave);

    if (removido == NULL)
        return false; 

    if (L->tamanho == 1) {
        free(removido);
        L->inicio = NULL;
    } else {
        removido->anterior->proximo = removido->proximo;
        removido->proximo->anterior = removido->anterior;

        if (removido == L->inicio) {
            L->inicio = removido->proximo;
        }

        free(removido);
    }

    L->tamanho--;
    return true;
}

void reinicializarLista(Lista* L) {
    if (L->inicio == NULL)
        return;

    No* atual = L->inicio;
    int i = 0;

    do {
        No* prox = atual->proximo;
        free(atual);
        atual = prox;
        i++;
    } while (i < L->tamanho);

    L->inicio = NULL;
    L->tamanho = 0;
}