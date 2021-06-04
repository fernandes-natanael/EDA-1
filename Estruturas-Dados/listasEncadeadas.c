#include <stdio.h>
#include <stdlib.h>

typedef struct no{// estrutura da lista
    int dado;
    struct no* prox;
}no;
// funcoes auxiliares
void menu();
int lerInteiro();
// funcoes do programa
no* cria_lista();
int insere_no_comeco(no* le, int valor );
int remove_no_comeco(no* le, int *temporario);
no* busca_primeiro_elemento(no*le, int elemento);
void imprime_lista(no* le);



int main(){
    no* le = cria_lista();
    int opcao;
    int *temporario = malloc(sizeof(int));
    no *buscado = malloc(sizeof(no));
    menu();
    while(scanf("%d", &opcao) != EOF ){
        system("clear");
        switch (opcao){
        case 1:
            printf("insira elemento: ");
            if(insere_no_comeco(le, lerInteiro()))
                printf("Inserido com sucesso!");
            else
                printf("Erro inesperado, valor nao foi inserido");
            break;
        case 2:
            if(remove_no_comeco(le, temporario))
                printf("%d foi removido com sucesso!", *temporario);
            else
                printf("Cuidado! Lista vazia.");
            break;
        case 3:
            imprime_lista(le);
            break;
        case 4:
            printf("elemento a buscar: ");
            buscado = busca_primeiro_elemento(le, lerInteiro());
            break;
        default:
            printf("Opcao invalida! Insira novamente");
            break;
        }
        
        menu();
    }
    system("clear");
    printf("Tchau\n");
    free(temporario);
    free(buscado);
    return 0;
}

void menu(){
    printf("\n\n");
    printf("1.Insere no comeco\n");
    printf("2.Remove no comeco\n");
    printf("3.Imprime lista\n");
    printf("4.Buscar primeiro elemento\n");
    printf("Opcao: ");
}

int lerInteiro(){
    int valor = 0;
    scanf("%d", &valor);
    return valor;
}

no* cria_lista(){
    // Lista vazia
    no* novo = malloc ( sizeof(no));
    novo->prox = NULL;
    return novo;
}// Complexidade O(1)

int insere_no_comeco(no* le, int valor ){
    no* novo = malloc(sizeof(no));
    if(novo == NULL)// caso nao seja possivel alocar memoria
        return 0;// retorna que houve erro
    novo->dado = valor;
    novo->prox = le->prox;
    le->prox = novo;
    return 1;
}// Complexidade O(1)

int remove_no_comeco(no* le, int *temporario){
    if(le->prox == NULL)// caso le esteja vazio nao faca nada
        return 0;
    no* lixo = le->prox;
    le->prox = lixo->prox;
    *temporario = lixo->dado;// armazena temporariamente o valor que foi apagado
    free(lixo);
    return 1;
}// Complexidade O(1)

no* busca_primeiro_elemento(no*le, int elemento){
    le = le->prox;
    for(int i = 0 ; le != NULL; i++){
        if(le->dado == elemento){
            printf("elemento encontrado na posicao %d\n", i);
            return le;
        }
        le = le->prox;
    }
    printf("Elemento nao existe na lista");
    return NULL;
}// O(1) melhor dos casos e no pior dos casos O(n)

void imprime_lista(no* le){
    le = le->prox;
    while(le != NULL){
        printf("%d -> ", le->dado);
        le = le->prox;
    }
    printf("NULL\n");
}// Complexidade O(n)