#include"Fila.h"
int main() {
    Fila f;

    char sair,op;
    int opcao=0;
    int ch;
    int removido;

    iniFila(&f);
    do{

        printf("1- Inserir item na FILA: \n");
        printf("2- remover item da FILA: \n");
        printf("3- listar dados da FILA: \n");
        printf("Digite a opcao: \n");

        scanf("%d",&opcao);

        printf("\n==================================\n");

        switch(opcao){
    
            case 1:
                do{
                    printf("\nDigite a chave: ");
                    scanf("%d",&ch);

                    insere_f(&f, ch) ;
                    printf("\nDeseja digitar mais elementos (s/n)? ");

                    fflush(stdin);

                    scanf("%c",&op);

                 } while(op!='n');

                break;
            case 2:
                remove_f(&f, &removido);
                break;
            case 3:
                imprimirFila(&f);
                break;
        }

        printf("\n\n==================================\n\n");

        fflush(stdin);

        printf("Deseja sair do programa (s/n): \n");

        scanf("%c",&sair);

        printf("\n\n==================================\n\n");

    } while(sair!='s');

    return 0;
}