#include "pilha.h"

int main(){
  Pilha *pilha1 = (Pilha *)malloc(sizeof(Pilha));

  Inicializa(pilha1);

  printf("tamanho: %d\n", Tamanho(*pilha1));
  
  TipoItem item;
  for (int i = 1; i < 10; ++i){
    item.chave = i;
    Push(pilha1, item);
  }
  
  Imprime(*pilha1);
  
  Pilha *pilha2 = (Pilha *)malloc(sizeof(Pilha));

  Inicializa(pilha2);
  
  while (!Vazia(*pilha1))
    Push(pilha2, Pop(pilha1));
  
  Imprime(*pilha2);

  return 0;
}