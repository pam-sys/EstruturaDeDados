#include"Lista.h"

void Inicializar(Lista *L){
    L->inicio=NULL;
}

int retornar_tamanho(Lista *L){
    int cont=0;
    PONT p=L->inicio;

    while(p!=NULL){
        cont ++;
        p=p->proximo;
    }

    return cont;
}

void imprimir_lista(Lista *L){
     PONT p=L->inicio;

    while(p!=NULL){
        printf("%d\n", p->r.chave);
        p=p->proximo;
    }
}

void inserir_inicio(Lista *L, Registro r){
    PONT novo=(PONT)malloc(sizeof(Elemento));
    novo->r=r;
    novo->proximo = L->inicio;
    novo->anterior = NULL;

    if(L->inicio!=NULL)
        L->inicio->anterior=novo;
    L->inicio=novo;  
}

void inserir_final(Lista *L, Registro r){
    PONT novo=(PONT)malloc(sizeof(Elemento));
    novo->r=r;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if(L->inicio==NULL)
        L->inicio=novo;

    PONT atual=L->inicio;

    while(atual->proximo!=NULL)
        atual=atual->proximo;
    
    atual->proximo=novo;
    novo->anterior=atual;
}

PONT buscar_chave(Lista *L, Tipo_Chave chave){
    PONT atual = L->inicio;

    while (atual != NULL){
        if (atual->r.chave == chave)
            return atual; 
        
        atual = atual->proximo;
    }

    return NULL; 
}

bool remover_inicio(Lista *L){
    if (L->inicio == NULL)
        return false; 

    PONT removido = L->inicio;
    L->inicio = removido->proximo;

    if (L->inicio != NULL)
        L->inicio->anterior = NULL;

    free(removido);
    return true;
}

bool remover_final(Lista *L) {
    if (L->inicio == NULL)
        return false;

    PONT atual = L->inicio;

    if (atual->proximo == NULL) {
        free(atual);
        L->inicio = NULL;
        return true;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->anterior->proximo = NULL;
    free(atual);

    return true;
}

bool remover_chave(Lista *L, Tipo_Chave chave) {
    PONT atual = L->inicio;

    while (atual != NULL && atual->r.chave != chave) {
        atual = atual->proximo;
    }

    if (atual == NULL)
        return false; 

    if (atual->anterior == NULL) {
        L->inicio = atual->proximo;
        if (L->inicio != NULL)
            L->inicio->anterior = NULL;
    }
    
    else {
        atual->anterior->proximo = atual->proximo;
        if (atual->proximo != NULL)
            atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    return true;
}

void ReinicializarLista(Lista *L) {
    PONT atual = L->inicio;
    while (atual != NULL) {
        PONT prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    L->inicio = NULL;
}

