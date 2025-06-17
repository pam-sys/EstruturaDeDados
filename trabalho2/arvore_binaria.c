#include"arvore_binaria.h"

No getnode(){
    No p;
    p = (No)malloc(sizeof(struct Nodo));
    return p;
}

No Vazia(){
    return NULL;
}

No criarArvore(int chave){
    No raiz;
    raiz =getnode();
    raiz->info = chave;
    raiz->esquerda=NULL;
    raiz->direita=NULL;
    raiz->pai = NULL;
    return raiz;
}

No getEsquerda(No pai){         
    if(pai->esquerda!=NULL)
        return pai->esquerda;
    else
        return NULL;
}

No getDireita(No pai){          
     if(pai->direita!=NULL)
        return pai->direita;
    else
        return NULL;
}

No inserir(No raiz, int chave){
    if(raiz==NULL)
        return criarArvore(chave);
    else{
        if(chave<=raiz->info){
            No novo = inserir(raiz->esquerda, chave);
            raiz->esquerda = novo;
            if (novo != NULL) novo->pai = raiz;
        } else {
            No novo = inserir(raiz->direita, chave);
            raiz->direita = novo;
            if (novo != NULL) novo->pai = raiz;
        }
    }
    return raiz;
}

No buscar_chave(No raiz, int chave){
    if(raiz==NULL || chave==raiz->info)
        return raiz;

    if(chave<raiz->info)
        return buscar_chave(raiz->esquerda, chave);
    else
        return buscar_chave(raiz->direita, chave);
    }

No transplantar(No raiz, No u, No v) {
    if (u->pai == NULL) {
        raiz = v;
    } else if (u == u->pai->esquerda) {
        u->pai->esquerda = v;
    } else {
        u->pai->direita = v;
    }

    if (v != NULL) {
        v->pai = u->pai;
    }
    return raiz;
}

No remover(No raiz, No z) {
    if (z->esquerda == NULL) {
        raiz=transplantar(raiz, z, z->direita);
    } else if (z->direita == NULL) {
        raiz=transplantar(raiz, z, z->esquerda);
    } else {
        No s = z->direita;
        while (s->esquerda != NULL) {
            s = s->esquerda;
        }

        if (s->pai != z) {
            raiz=transplantar(raiz, s, s->direita);
            s->direita = z->direita;
            if (s->direita != NULL) // Adicione esta verificação!
                s->direita->pai = s;
        }

        raiz=transplantar(raiz, z, s);
        s->esquerda = z->esquerda;
         if (s->esquerda != NULL) // Adicione esta verificação!
            s->esquerda->pai = s;
    }

    free(z);
    return raiz;
}

void preOrdem(No raiz){
     if (raiz!=NULL){
        printf("%d ", raiz->info);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void inOrdem(No raiz){      
    if (raiz!=NULL){
        inOrdem(raiz->esquerda);
        printf("%d ", raiz->info);
        inOrdem(raiz->direita);
    }
    
}

void posOrdem(No raiz){
    if (raiz!=NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->info);
    }
}

No predecessor(No raiz){
    if (raiz->esquerda != NULL) {
        return maximo(raiz->esquerda);
    }

    No y =raiz->pai;
    while (y != NULL &&raiz == y->esquerda) {
       raiz = y;
        y = y->pai;
    }
    return y;
}

No sucessor(No raiz){
    if (raiz->direita != NULL) {
        return minimo(raiz->direita);
    }

    No y = raiz->pai;
    while (y != NULL && raiz == y->direita) {
        raiz = y;
        y = y->pai;
    }
    return y;
}

No maximo(No raiz){
    while (raiz->direita!=NULL)
        raiz=raiz->direita;
    return raiz;

}

No minimo(No raiz){
    while (raiz->esquerda!=NULL)
        raiz=raiz->esquerda;
    return raiz;
}

int menu(){
    int op;
    do {
        printf("\n\t MENU: \n 1- Inserir elemento na arvore \n 2- Pre-Ordem");
        printf("\n 3- In-Ordem \n 4- Pos-Ordem \n 5- Remover elemento \n 6- Sair do programa \n Digite uma opcao: ");

        scanf("%d",&op);

        (op<1||op>5)?printf("\n Por favor, escolha uma opção existente."):printf("\n");
    }

    while(op<1 || op>6);
    return op;
}
        
    
