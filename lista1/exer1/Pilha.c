#include "pilha.h"

void Inicializar(Pilha *p) {
  p->topo = -1;
}

int Vazia(Pilha *p) {
  return (p->topo == -1);
}

int Cheia(Pilha *p) {
  return (p->topo == max-1);
}

void Push(Pilha *p, char c) {
  if(!Cheia(p)) {
    p->dados[++(p->topo)] = c;
  }
}

char Pop(Pilha *p) {
  if(!Vazia(p)) {
    return (p->dados[(p->topo)--]);
  }
  return '\0';
}

void InverterPalavras(char *in, char *out, Pilha *p) {
  int i=0, j=0;
  char c;

  while ((c = in[i]) != '\0') {
    if( !isspace(c) ) {
      Push(p, c);  
    } else {
      while (!Vazia(p)) {
        out[j++] = Pop(p); 
      }
      out[j++] = c; 
    }
    i++;
  }

  while (!Vazia(p)) {
    out[j++] = Pop(p);
    out[j] = '\0';
  }
  
}