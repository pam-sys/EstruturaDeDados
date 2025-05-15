#include "pilha.h"

void Inicializa(Pilha *p){
  p->topo = -1;
}

int Vazia(Pilha p){
  return p.topo == -1;
}

int Tamanho(Pilha p){
  return p.topo+1;
}

void Imprime(Pilha p){
  if(Vazia(p))
    printf("pilha vazia");
  else {
    for (int i = p.topo; i >= 0; --i){
      printf("%d ", p.item[i].chave);
    }
    printf("\n");
  }
}

void Push(Tipoitem x, Pilha *p){
  if(p->topo == MAXTAM-1)
    printf("Pilha cheia");
  else {
    p->topo = p->topo + 1;
    p->item[p->topo] = x;
  }
}

void Pop(Pilha *p, Tipoitem *item){
  if(Vazia(*p))
    printf("Pilha vazia\n");
  else {
    *item = p->item[p->topo];
    p->topo = p->topo - 1;
  }
}