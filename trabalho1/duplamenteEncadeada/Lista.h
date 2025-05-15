#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int Tipo_Chave;
typedef struct{
    Tipo_Chave chave;
}Registro;

typedef struct Aux_Elemento{
    struct Aux_Elemento *anterior;
    Registro r;
    struct Aux_Elemento *proximo;
}Elemento;

typedef Elemento *PONT;

typedef struct{
    PONT inicio;
}Lista;

void Inicializar(Lista *L);
int retornar_tamanho(Lista *L);
void imprimir_lista(Lista *L);
void inserir_inicio(Lista *L, Registro r);
void inserir_final(Lista *L, Registro r);
PONT buscar_chave(Lista *L, Tipo_Chave chave);
bool remover_inicio(Lista *L);
bool remover_final(Lista *L);
bool remover_chave(Lista *L, Tipo_Chave chave);
void ReinicializarLista(Lista *L);