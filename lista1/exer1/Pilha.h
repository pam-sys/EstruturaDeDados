#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100

typedef struct {
  char dados[max];
  int topo;
}Pilha;

void Inicializar(Pilha *p);
int Vazia(Pilha *p);
int Cheia(Pilha *p);
void Push(Pilha *p, char c);
char Pop(Pilha *p);
void InverterPalavras(char *in, char *out, Pilha *p);