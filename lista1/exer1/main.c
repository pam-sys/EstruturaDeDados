#include "pilha.h"

int main(){
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  Inicializar(p);

  char frase[] = "ESTE EXERCICIO E MUITO FACIL";
  char inversao[max];

  InverterPalavras(frase, inversao, p);

  printf("%s\n",frase);
  printf("%s\n", inversao);
  
  return 0;
}