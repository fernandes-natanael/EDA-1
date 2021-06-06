#include <stdio.h>

int main(){
    int tam;
    scanf("%d", &tam);
    for(int i = 1; i <= tam ; i++){
        for(int k = 0 ; k < i ; k++)
            printf("%.2d ", i);
        printf("\n");
    }
    printf("\n");
    for(int i = 1; i <= tam ; i++){
        for(int k = 1 ; k <= i ; k++)
            printf("%.2d ", k);
        printf("\n");
    }        
    return 0;
}