#include <stdio.h>
#include <stdlib.h>



typedef struct fila{
    int *dados;
    int inicio, fim, capacidade;
}fila;

void menu();
int lerInteiro();


fila* cria_fila();
int desenfileira(fila* f, int *temporario);
int enfileira(fila *f, int valor);
int fila_cheia(fila* f);
int redimensiona(fila *f);
void mostra_fila(fila * f);
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
            if(enfileira(f, lerInteiro()))
                printf("Enfileirado com sucessor");
            else
                printf("Nao foi possivel inserir");
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
    free(temporario);
    destruir_fila(f);
    printf("Sistema Finalizado\n");
    return 0;
}

void menu(){
    printf("\n\n");
    printf("1.Inserir na fila\n");
    printf("2.Remover da fila\n");
    printf("3.Mostrar fila\n");
    printf("Opcao: ");
}

int lerInteiro(){
    int valor;
    printf("insira inteiro:");
    scanf("%d", &valor);
    return valor;
}


fila* cria_fila(){
    fila* f = malloc(sizeof(fila));
    f->inicio = 0;
    f->fim = 0;
    f->capacidade = 6;
    f->dados = malloc(f->capacidade * sizeof(int));
    return f;
}

int desenfileira(fila* f, int *temporario){
    if(f->inicio == f->fim)// fila esta vazia
        return 0;
    *temporario = f->dados[f->inicio]; // atribui a um temporario o dado removido 
    f->dados[f->inicio] = 0; // Operacao nao necessaria, porem, anula o dado removido
    f->inicio = (f->inicio + 1) % f->capacidade; // mantem a circulariadade da fila 
    return 1;
} // Complexidade O(1)

int enfileira(fila *f, int valor){
    if(fila_cheia(f))
        if(!redimensiona(f))
            return 0;
    f->dados[f->fim] = valor;// insere o  valor no final
    f->fim = (f->fim + 1) % f->capacidade; // soma um mantendo a circulariadade
    return 1; 
}

int fila_cheia(fila* f){
    if(f->inicio == 0 && f->fim == f->capacidade-1 ||
        f->inicio == f->fim + 1)// Casos que comprovam que a fila esta cheia
        return 1;
    return 0;
}

/*
 Caso 1
 se inicio < fim
 ->nao faca nada

 Caso 2
 se inicio > fim e qnt_inicio > qnt_fim
 -> coloque a qnt_fim apos a qnt_inicio
 -> atualiza o valor do fim
  | 6 | 7 |  | 1 | 2 | 3 | 4 | 5 |
  |   |   |  | 1 | 2 | 3 | 4 | 5 | 6 | 7 |  |  ...

 Caso 3
 se inicio > fim e qnt_inicio < qnt_fim
 -> coloque a qnt_inicio no final
 -> atualize o valor do inicio
  | 4 | 5 | 6 | 7 |  | 1 | 2 | 3 |
  | 4 | 5 | 6 | 7 |  |   |   |   | ... | 1 | 2 | 3 |


    qnt_inicio = f->capacidade - f->inicio
    qnt_fim = f->fim
*/
int redimensiona(fila *f){
    f->dados = realloc(f->dados, 2*f->capacidade * sizeof(int));// realoca o vetor
    if(f->dados == NULL) // caso a realocacao tenha dado errado, ponteiro retorna NULL
        return 0;
    else{
        if(f->inicio > f->fim){
            int qnt_inicio = f->capacidade - f->inicio;
            // qnt_final = f->fim
            if(qnt_inicio >= f->fim){// Caso 2
                int i = f->capacidade;
                for(int k = 0; k < f->fim ; i++, k++)
                    f->dados[i] = f->dados[k];
                f->fim = i;
            }
            else{// Caso 3
                int i = 2*f->capacidade - (qnt_inicio);// 
                for(int k = f->inicio ; k < f->capacidade; i++, k++ )
                    f->dados[i] = f->dados[k];
                f->inicio = 2*f->capacidade - (qnt_inicio);
            }
        }
    }
    f->capacidade *= 2;// caso realocacao 
    return 1;
}

void mostra_fila(fila * f){
    printf("inicio = %d\t- fim = %d\t- capacidade = %d\n", f->inicio, f->fim, f->capacidade);
    for(int i = f->inicio ; i != f->fim ;){
        printf("%d -> ", f->dados[i]);
        i = (i+1) % f->capacidade;
    }
    printf("NULL\n");
}


void destruir_fila(fila* f){
    free(f->dados);// desaloca o ponteiro dados da memoria
    free(f); // desaloca a fila
}
