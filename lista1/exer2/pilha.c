#include "pilha.h"

void Inicializa(Pilha *p){
  p->topo = -1;
}

void Reinicializa(Pilha *p){
  p->topo = -1;
}

int Tamanho(Pilha p){
  return (p.topo + 1);
}

bool Vazia(Pilha p){
  return (p.topo == -1);
}

TipoChave topo(Pilha p){
  return (p.item[p.topo].chave);
}

bool Push(Pilha *p, TipoItem item){
  if (p->topo == max - 1){
    printf("Pilha cheia\n");
    return false;
  } else {
    p->item[++p->topo] = item;
    return true;
  }
}

TipoItem Pop(Pilha *p){
  return (p->item[p->topo--]);
}

void Imprime(Pilha p){
  printf("lista: \n");
  for (int i = 0; i < p.topo+1; ++i) {
    printf("%d\n", p.item[i].chave);
  }
}