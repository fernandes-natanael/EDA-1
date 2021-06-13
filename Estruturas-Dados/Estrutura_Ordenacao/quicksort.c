#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int *dados;
    int MAX, QNT ;
}lista;

void quicksort(int vetor[], int inicio, int final ){
    int i = inicio , 
        j = final-1 , 
        pivo, auxiliar;
    pivo = vetor[ ( inicio+final )/2 ];
    while( i <= j){
        while(vetor[i] < pivo && i < final)
            i++;
        while(vetor[j] > pivo && j > inicio)
            j--;
        if( i <= j ){
            auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;
            i++;
            j--;
        }
    }

    if(inicio < j)
        quicksort(vetor, inicio , j+1 );
    if(final > i)
        quicksort(vetor, i, final);
}



void menu(){
    printf("\n\n");
    printf("1. inserir na lista\n");
    printf("2. auto preencher lista\n");
    printf("3. Ordenar lista\n");
    printf("4. mostrar lista\n");
    printf("Opcao: ");
}

int ler_inteiro(){
    int var;
    printf("insira inteiro: ");
    scanf("%d", &var);
    return var;
}

int realoca_lista(lista * l){
    l->dados = realloc( l->dados, 2*l->MAX * sizeof(int));
    if(l->dados != NULL){
        l->MAX *= 2;
        return 1;
    }
        
    return 0;
}

int insere_lista(lista *l, int valor){
    if( l->MAX == l->QNT)
        if(!realoca_lista(l))
            return 0;
    l->dados[l->QNT++] = valor;
}

void auto_preencher(lista *l){
    while(l->QNT < l->MAX){
        l->dados[l->QNT++] = random() % 100;
    }
}

void mostra_lista(lista *l){
    for(int i = 0 ; i < l->QNT ; i++){
        printf("%d", l->dados[i]);
        if(i < l->QNT - 1)
            printf(", ");
        else
            printf("\n");
    }
}

lista * cria_lista(){
    lista * l = malloc(sizeof(lista));
    l->MAX = 128; 
    l->dados = malloc( l->MAX * sizeof(l->MAX));
    l->QNT = 0;
    return l;
}

void destruir_lista(lista* l){
    free(l->dados);
    free(l);
}

int main(){
    lista *l = cria_lista();
    int option;

    menu();
    while(scanf("%d", &option) != EOF){
        system("clear");

        switch (option){
        case 1:
            insere_lista(l, ler_inteiro());            
            break;
        case 2:
            auto_preencher(l);
            break;
        case 3:
            quicksort(l->dados, 0, l->QNT);
            break;
        case 4:
            mostra_lista(l);
            break;
        default:
            printf("Opcao Invalida!");
        }
        menu();
    }
    
    destruir_lista(l);
    system("clear");
    printf("Sistema Finalizado\n");
    return 0;
}