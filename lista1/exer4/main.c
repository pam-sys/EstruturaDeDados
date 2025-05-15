#include "pilha.h"

int main(){
  Pilha *pilha1 = (Pilha *)malloc(sizeof(Pilha));

  Inicializa(pilha1);

  TipoItem item;
  for(int i=0; i<10; ++i){
    item.chave = i;
    Push(pilha1, item);
  }

  Imprime(*pilha1);
  Inverte(pilha1);
  Imprime(*pilha1);

  return 0;
}