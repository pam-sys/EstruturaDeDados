#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} TipoItem;

typedef struct {
  TipoItem item[max];
  int topo;
} Pilha;

void Inicializa(Pilha *p);
void Reinicializa(Pilha *p);
int Tamanho(Pilha p);
bool Vazia(Pilha p);
TipoChave topo(Pilha p);
bool Push(Pilha *p, TipoItem item);
TipoItem Pop(Pilha *p);
void Imprime(Pilha p);