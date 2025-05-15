#include "pilha.h"

int main() {
  Pilha *pilha1 = (Pilha *)malloc(sizeof(Pilha));
  Pilha *pilha2 = (Pilha *)malloc(sizeof(Pilha));

  Inicializa(pilha1);
  Inicializa(pilha2);

  char palindromo[] = "reviver";
  int i=0;

  while (palindromo[i] != '\0'){
    Push(pilha1, palindromo[i]);
    i++;
  }

  Imprime(*pilha1);
  
  i=pilha1->topo;
  while (i >= 0){
    Push(pilha2, pilha1->vetor[i]);
    i--;
  }
  
  Imprime(*pilha2);
  return 0;
}