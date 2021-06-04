#include <stdio.h>
#include <stdlib.h>
typedef struct pilha {
    int *dados;
    int topo, N;
} pilha;

int lerInteiro();
void menu();

pilha *cria_pilha();
int realocaPilha(pilha* p);
int desempilha(pilha *p, int* temporario);
int empilha( pilha* p, int valor);
void mostrar_pilha(pilha * p);
void destruir_pilha(pilha * p);


int main(){
    pilha* stack = cria_pilha();
    int opcao;
    int * temporario = malloc(sizeof(int));

    menu();
    while(scanf("%d", &opcao) != EOF){
        system("clear");
        switch (opcao){
        case 1:
            printf("Funcao empilha\n");
            if(empilha(stack, lerInteiro()))
                printf("\nEmpilhado com sucesso!");
            else
                printf("\nNao foi possivel empilhar");
            break;
        case 2:
            printf("Funcao desempilha\n");
            if(desempilha(stack, temporario))
                printf("\nDesempilhado com sucesso!");
            else
                printf("\nPilha esta vazia");
            break;
        case 3:
            mostrar_pilha(stack);
            break;
        default:
            printf("Opcao invalida insira novamente");
            break;
        }
        menu();
    }
    system("clear");
    destruir_pilha(stack);
    free(temporario);
    printf("Program finalizado\n");
    return 0;
}

void menu(){
    printf("\n\n");
    printf("1.Inserir na pilha\n");
    printf("2.Remover da pilha\n");
    printf("3.Mostrar pilha\n");
    printf("Opcao: ");
}

int lerInteiro(){
    int valor;
    printf("insira valor:");
    scanf("%d", &valor);
    return valor;
}


pilha *cria_pilha(){
    pilha * p = malloc(sizeof(pilha));
    p->topo = -1; // pilha vazia
    p->N = 100; // capacidade da pilha inicialmente
    p->dados = malloc(p->N * sizeof(int));

    return p;
}

int realocaPilha(pilha* p){
    p->dados = realloc(p->dados, 2*p->N * sizeof(int));
    if(p->dados == NULL)
        return 0;
    p->N *= 2;// somente eh acrescentado em p->N caso verifique se realmente foi possivel realocar
    return 1;
}

int desempilha(pilha *p, int* temporario){
    if(p != NULL){// se pilha existe
        if(p->topo == -1){// pilha vazia
            return 0;
        }
        *temporario = p->dados[p->topo];// temporario assume o valor da pilha apagado
        p->topo--;// e a pilha reduz 1 de tamanho, daria pra fazer tudo em uma linha, mas assim fica mais visivel
        return 1;
    } 
    return 0;
}

int empilha( pilha* p, int valor){
    if(p != NULL){
        if(p->topo == p->N - 1){// pilha esta cheia
            printf("Pilha sera realocada! ");
           if(!realocaPilha(p)){
                printf("Nao foi possivel realocar a pilha");
                return 0;
            }
        }
            
        p->topo++;
        p->dados[p->topo] = valor;

        
        return 1;
    }
    return 0;
}

void mostrar_pilha(pilha * p){
    for(int i = p->topo ; i >= 0 ; i--){
        printf("%d", p->dados[i]);
        if(i != 0) printf(" -> ");
        else printf("\n");
    }
        
}

void destruir_pilha(pilha * p){
    free(p->dados);
    free(p);
}