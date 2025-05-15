#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

typedef char TipoChave;

typedef struct {
  TipoChave vetor[max];
  int topo;
} Pilha;

void Inicializa(Pilha *p);
int Tamanho(Pilha p);
bool Vazia(Pilha p);
TipoChave topo(Pilha p);
bool Push(Pilha *p, TipoChave chave);
TipoChave Pop(Pilha *p);
void Imprime(Pilha p);