#include"arvore_binaria.h"

int main() {
    //setlocale(LC_ALL,"portuguese");
    int chave,op,chaveRaiz;
    printf("\nCRIANDO UMA ARVORE:");
    printf("\n Insira a chave raiz: ");
    scanf("%d",&chaveRaiz);

    No raiz=criarArvore(chaveRaiz);
    do {
        op=menu();
        switch(op) {
        case 1:
            printf("\n Digite o elemento a inserir na arvore: ");
            scanf("%d",&chave);
            raiz=inserir(raiz,chave);
            break;

        case 2:
            printf("\n PRE ORDEM: ");
            preOrdem(raiz);
            break;

        case 3:
            printf("\n EM ORDEM: ");
            inOrdem(raiz);
            break;

        case 4:
            printf("\n POS ORDEM: ");
            posOrdem(raiz);
            break;

        case 5:
            printf("\n Digite a chave a remover: ");
            scanf("%d", &chave);
            No z = buscar_chave(raiz, chave);
            if (z != NULL) {
                raiz=remover(raiz, z);
                printf("Elemento removido!\n");
            } else {
                printf("Chave não encontrada!\n");
            }
            break;
        }
    }

    while(op!=6);

return 0;
}

//gcc main.c arvore_binaria.c