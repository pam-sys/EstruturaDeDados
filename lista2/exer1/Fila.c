#include"Fila.h"

void iniFila(Fila *f) { 
    f->ini  = 0; 
    f->fim  = 0; 
    f->cont = 0;
}

int vaziaFila(Fila *f) { 
    if (f->cont == 0){ 
        return(1); 
    } 
    else { 
        return(0); 
    } 
}

int cheia_f(Fila *f) {
    return (f->cont == MAXSIZE);
}
  
int insere_f(Fila *f, int x) { 
  
    if (cheia_f(f)){
        return(ERROFILACHEIA); 
    }else{ 
        f->item[f->fim] = x; 
        f->cont++; 

        if (f->fim == MAXSIZE -1) 
            f->fim = 0; 
        else 
            f->fim++;

        return(f->fim); 
    } 
} 

int remove_f(Fila *f, int *x) {
    if (vaziaFila(f)) {
        return 0;
    } else {
        *x = f->item[f->ini];
        f->cont--;

        if (f->ini == MAXSIZE - 1)
            f->ini = 0;
        else
            f->ini++;

        return 1; 
    }
}

void imprimirFila(Fila *f){
    if (vaziaFila(f)) {
        printf("Fila vazia\n");
        return;
    }

    int i = f->ini;
    int c = f->cont;

    printf("Fila: ");

    while (c > 0) {
        printf("%d ", f->item[i]);

        i = (i + 1) % MAXSIZE; 
        c--;
    }

    printf("\n");
}


