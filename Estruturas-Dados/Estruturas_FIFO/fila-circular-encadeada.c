#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int dado;
    struct fila * prox;
}fila;

int lerInteiro();
void menu();

fila* cria_fila();
fila* enfileira(fila* f, int valor);
int desenfileira(fila* f, int *temporario);
void mostra_fila(fila* f);
void destruir_fila(fila* f);

int main(){
    fila * f = cria_fila();
    int * temporario = malloc(sizeof(int));
    int opcao;
    menu();
    while(scanf("%d", &opcao) != EOF){
        system("clear");
        switch (opcao){
        case 1:
            printf("Funcao inserir\n\n");
            f = enfileira(f, lerInteiro());
            break;
        case 2:
            printf("Funcao remover\n\n");
            if(desenfileira(f, temporario))
                printf("Desenfileirado com sucessor");
            else
                printf("Nao foi possivel remover");
            break;
        case 3:
            mostra_fila(f);
            break;
        default:
            printf("Opcao invalida! insira novamente.");
            break;
        }
        menu();
    }
    system("clear");
    destruir_fila(f);
    free(temporario);
    printf("Sistema Finalizado\n");
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
    printf("1.Inserir na fila\n");
    printf("2.Remover da fila\n");
    printf("3.Mostrar fila\n");
    printf("Opcao: ");
}

fila * cria_fila(){
    fila* le = malloc(sizeof(fila));
    le->prox = le; // logo o ultimo elemento da fila apontara para o no cabeca e nao para NULL
}

fila* enfileira(fila* f, int valor){
    fila* novo = malloc(sizeof(fila));
    if(novo == NULL){// nao foi possivel alocar espaco
        printf("Espaco insuficiente de memoria!");
        return f;
    }
    novo->prox = f->prox; // novo->prox aponta para o primeiro elemento da fila 
    f->prox = novo; // f vira o ultimo elemento da fila, pois ele aponta para o No cabeca
    f->dado = valor;// insere o valor no rabo 
    printf("Enfileirado com sucesso!");
    return novo; // se torna o no cabeca da fila
}

int desenfileira(fila * f, int *temporario){
    if(f->prox == f)// pilha vazia
        return 0;
    fila* lixo = f->prox;
    *temporario = lixo->dado;// armazena o valor do dado no temporario
    f->prox = lixo->prox;
    free(lixo);
    return 1;
    
}

void mostra_fila(fila* f){
    fila* le = f;
    f = f->prox;
    while (f != le){
        printf("%d -> ", f->dado);
        f= f->prox;
    } 
    printf("NULL\n");
}

void destruir_fila(fila* f){
    fila* aux = f->prox;
    fila* lixo = malloc(sizeof(fila));
    while(aux != f){
        lixo = aux;
        aux = aux->prox;
        free(lixo);
    }
    free(f);
}
