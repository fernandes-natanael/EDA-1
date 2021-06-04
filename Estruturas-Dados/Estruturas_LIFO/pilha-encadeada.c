#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int dado;
    struct pilha* prox;
}pilha;

void menu();
int lerInteiro();

// funciona do mesmo modo que a insercao no inicio da lista encadeada
pilha *cria_pilha();
int empilha(pilha* p, int valor);
int desempilha(pilha* p, int* temporario);
void imprime_pilha(pilha* p);
void destruir_pilha(pilha* p);


int main(){
    int opcao;
    int* temporario = malloc(sizeof(int));
    pilha* stack = cria_pilha();

    menu();
    while(scanf("%d", &opcao) != EOF){
        system("clear");
        switch (opcao){
        case 1:
            if(empilha(stack, lerInteiro()))
                printf("Empilhado com sucesso!");
            else
                printf("Nao empilhou");
            break;
        case 2:
            if(desempilha(stack, temporario))
                printf("Desempilhado com sucesso!");
            else
                printf("Pilha vazia, nao desempilhou!");
            break;
        case 3:
            imprime_pilha(stack);
            break;
        default:
            printf("Opcao invalida");
        }
        menu();
    }
    system("clear");
    destruir_pilha(stack);
    free(temporario);
    printf("Program finalizado\n");
    return 0;
}

int lerInteiro(){
    int valor;
    printf("insira inteiro:");
    scanf("%d", &valor);
    return valor;
}

void menu(){
    printf("\n\n");
    printf("1.Inserir na pilha\n");
    printf("2.Remover da pilha\n");
    printf("3.Mostrar pilha\n");
    printf("Opcao: ");
}

pilha *cria_pilha(){
    pilha * p = malloc(sizeof(pilha));
    p->prox = NULL;
    return p;
}

// funciona do mesmo modo que a insercao no inicio da lista encadeada
int empilha(pilha* p, int valor){
    pilha* novo = malloc(sizeof(pilha));
    if(novo == NULL){// caso nao seja possivel alocar memoria
        printf("Memoria nao pode ser alocada!\n");
        return 0;// retorna que houve erro
    }
    novo->dado = valor;
    novo->prox = p->prox;
    p->prox = novo;
    return 1;
}// Complexidade O(1)

int desempilha(pilha* p, int* temporario){
    if(p->prox == NULL){// verifica se a lista esta vazia
        return 0;
    }
    pilha* lixo = p->prox; // atribui a variavel q sera apagada
    *temporario = lixo->dado;// armazena o valor do dado no temporario
    p->prox = lixo->prox;
    free(lixo);
    return 1;
}// Complexidade O(1)

void imprime_pilha(pilha* p){
    p = p->prox;
    while(p != NULL){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n");
}// Complexidade O(n)

void destruir_pilha(pilha* p){// libera toda a memoria
    p = p->prox;// para copmecar no primeiro elemento da pilha
    pilha* lixo = malloc(sizeof(pilha));// instancia da pilha auxiliar q ajuda a apagar as anteriores
    while(p != NULL){// sai quando n tiver mais nenhum elemento da pilha
        lixo = p;// atribui o elemento da vez da pilha
        p = p->prox;// passa para o proximo elemento da pilha
        free(lixo);// apaga o elemento da vez da pilha
    }
}// Complexidade O(n)