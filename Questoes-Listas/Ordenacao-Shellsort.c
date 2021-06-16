#include <stdio.h>
#include <stdlib.h>

int less(int temp, int v){// v eh maior que o temp, True, senao False
    if(temp < v)
        return 1;
    return 0;
}

void insertion_sort_h(int *v, int mais_esquerda, int mais_direita, int h){// h == tamanho do salto do
    for(int i = mais_esquerda + h ; i <= mais_direita ; i++){
        int j = i, temp = v[i];
        while( j>=mais_esquerda+h && less(temp, v[j-h] ) ){
            v[j] = v[j-h];
            j-=h;
        }
        v[j] = temp;
    }
}

void shell_sort(int v[], int left, int right){
    // h = 3*h+1
    // 1, 4, 13, 40, 121, 364, ... 
    int h;
    for( h = 1 ; h < (right - left)/ 9 ; )
        h = 3*h + 1;
    for(; h > 0; h=h/3)
        insertion_sort_h(v, left, right, h);
    
}

int main(){
    int size;
    printf("insert the list size: ");
    scanf("%d", &size);
    int *vetor = malloc(size*sizeof(int));

    for(int i = 0 ; i < size ; i++){
        printf("element(%d): ", i);
        scanf("%d",&vetor[i]);
    }

    shell_sort(vetor, 0, size-1);
    printf("list sorted by shellsort: ");
    for(int i = 0; i < size ; i++){
        printf("%d", vetor[i]);
        if(i < size-1)
            printf(" ");
    }
    printf("\n");
        
    return 0;
}
