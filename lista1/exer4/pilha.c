#include "pilha.h"

void Inicializa(Pilha *p){
  p->topo = -1;
}

int Vazia(Pilha p){
  return (p.topo == -1);
}

int Tamanho(Pilha p){
  return (p.topo+1);
}

void Imprime(Pilha p){
  if(Vazia(p))
    printf("pilha vazia");
  else {
    for(int i = p.topo; i>=0; --i)
      printf("%d ", p.item[i].chave);
    printf("\n");
  }
}

void Push(Pilha *p, TipoItem x){
  if(p->topo == maxtam-1)
    printf("pilha cheia\n");
  else {
    p->topo = p->topo + 1;
    p->item[p->topo] = x;
  }
}

void Pop(Pilha *p, TipoItem *item){
  if(Vazia(*p))
    printf("pilha vazia\n");
  else {
    *item = p->item[p->topo];
    p->topo = p->topo - 1 ;
  }
}

void Inverte(Pilha *p){
  if(Vazia(*p))
    return;
  
  TipoItem tempo[maxtam];
  int i=0;

  while(!Vazia(*p)){
    Pop(p, &tempo[i]);
    i++;
  }

  for(int j = 0; j < i; j++){
    Push(p, tempo[j]);
  }
}