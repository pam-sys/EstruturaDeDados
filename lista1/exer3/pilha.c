#include "pilha.h"

void Inicializa(Pilha *p){
  p->topo = -1;
}

int Tamanho(Pilha p){
  return (p.topo + 1);
}

bool Vazia(Pilha p){
  return (p.topo == -1);
}

TipoChave topo(Pilha p){
  return (p.vetor[p.topo]);
}

bool Push(Pilha *p, TipoChave chave){
  if(p->topo == max-1){
    printf("Lista cheia\n");
    return false;
  } else {
    p->vetor[++p->topo] = chave;
    return true;
  }
}

TipoChave Pop(Pilha *p){
  return (p->vetor[p->topo--]);
}

void Imprime(Pilha p){
  for (int i = 0; i < p.topo+1; ++i)
    printf("%c ", p.vetor[i]);
  printf("\n");
}