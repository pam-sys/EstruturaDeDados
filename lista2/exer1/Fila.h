#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100 
#define ERROFILACHEIA -1
typedef struct{ 
    int item[MAXSIZE]; 
    int ini; 
    int fim; 
    int cont; 
}Fila; 

void iniFila(Fila *f);
int vaziaFila(Fila *f);
int cheia_f(Fila *f);
int insere_f(Fila *f, int x);
int remove_f(Fila *f, int *x);
void imprimirFila(Fila *f);