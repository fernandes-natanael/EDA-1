#include <stdio.h>

/* Funciona para listas ordenadas, logo caso queira utiliza-la, devesse ordenar a lista*/

void menu();
int lerInteiro();

int busca_binaria(int lista[], int n, int buscado);
void listar_lista(int lista[]);


int main(){
    int lista[] = {-20, -15, -4, 0, 2, 4, 5, 7, 11, 231};
    int opcao;
    menu();
    while(scanf("%d", &opcao) != EOF){
        system("clear");
        switch (opcao){
        case 1:
            listar_lista(lista);
            break;
        case 2:
            printf("Esta na posicao: %d\n", busca_binaria(lista, 10, lerInteiro()) );
            break;
        default:
            printf("Opcao Invalida!");
        }
        menu();
    }

    system("clear");
    printf("Sistema Finalizado\n");
    return 0;
}

void menu(){
    printf("\n\n");
    printf("1.Mostra lista\n");
    printf("2.Procura na lista\n");
    printf("Opcao: ");
}

int lerInteiro(){
    int valor;
    printf("insira inteiro:");
    scanf("%d", &valor);
    return valor;
}

int busca_binaria(int lista[], int n, int buscado){ // n == quantidade de itens da lista
    int start = -1; // menor posicao
    int end = n; // maior posicao
    while(start < end - 1){// enquanto posicao final for maior q a inicio
        int middle= (start + end) / 2;
        if( lista[middle] == buscado )
            return middle;
        else if( lista[middle] < buscado)
            start = middle;
        else 
            end = middle;
    }
    return -1; // retorna a posicao onde o valor se encontra
}// Complexidade O(lg n )

void listar_lista(int lista[]){
    for(int i = 0 ; i < 10; i++){
        printf("%d, ", lista[i]);
    }
    printf("\n");        
}