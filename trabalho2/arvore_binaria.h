#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Nodo{
    int info;
    struct Nodo* esquerda;
    struct Nodo* direita;
    struct Nodo* pai;
};

typedef struct Nodo* No;

No getnode();
No Vazia();
No criarArvore(int chave);
No getEsquerda(No pai);
No getDireita(No pai);
No inserir(No raiz, int chave);
No buscar_chave(No raiz, int chave);
void inOrdem(No raiz);
void preOrdem(No raiz);
void posOrdem(No raiz);
No maximo(No raiz);
No minimo(No raiz);
No sucessor(No raiz);
No predecessor(No raiz);
No transplantar(No raiz, No u, No v);
No remover(No raiz, No z);
int menu();
