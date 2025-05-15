#include"Lista.h"

int main() {
    Lista lista;
    int opcao = 0;
    char op = 'n';
    char sair = 'n';
    int ch;

    do{
        printf("1- inicializar lista: \n");
        printf("2- Inserir um elemento na lista: \n");
        printf("3- Imprimir a lista: \n");
        printf("4- Excluir um elemento da lista: \n");
        printf("Digite a opcao: \n");

        scanf("%d",&opcao);

        printf("\n==================================\n");

        switch(opcao){
            case 1:
                   inicializar(&lista);
                   break;
            case 2:
                do{
                    printf("\nDigite a chave: ");
                    scanf("%d",&ch);

                    inserir_Chave(&lista, ch);
                    printf("\nDeseja digitar mais elementos (s/n)? ");

                    fflush(stdin);

                    scanf("%c",&op);

                 } while(op!='n');

                break;
            case 3:
                imprimir_Lista(&lista);
                break;
            case 4:
                printf("Digite a chave a remover: ");
                scanf("%d", &ch);
                removerChave(&lista, ch);
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