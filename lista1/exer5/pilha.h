#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 30

typedef int Tipochave;

typedef struct {
  Tipochave chave;
} Tipoitem;

typedef struct {
  Tipoitem item[MAXTAM];
  int topo;
} Pilha;

void Inicializa(Pilha *p);
int Vazia(Pilha p);
void Push(Tipoitem x, Pilha *p);
void Pop(Pilha *p, Tipoitem *item);
int Tamanho(Pilha p);
void Imprime(Pilha p);