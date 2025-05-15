#include"Lista.h"

int main(){
Lista lista;
    Inicializar(&lista);

    Registro r1 = {20};
    Registro r2 = {26};

    inserir_inicio(&lista, r1);
    inserir_final(&lista, r2);

    imprimir_lista(&lista); 

    remover_chave(&lista, 20);

    printf("\nApos remover a chave 20:\n");
    imprimir_lista(&lista);

    ReinicializarLista(&lista);

    printf("\nApos reinicializar:\n");
    imprimir_lista(&lista); 
}