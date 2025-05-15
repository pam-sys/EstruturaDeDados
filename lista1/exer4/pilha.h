#include <stdio.h>
#include <stdlib.h>

#define maxtam 30

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} TipoItem;

typedef struct {
  TipoItem item[maxtam];
  int topo;
} Pilha;

void Inicializa(Pilha *p);

int Vazia(Pilha p);

int Tamanho(Pilha p);

void Imprime(Pilha p);

void Push(Pilha *p, TipoItem x);

void Pop(Pilha *p, TipoItem *item);

void Inverte(Pilha *p);