#include <stdio.h>

void instruction(){
    printf("Intruction\n");
    printf("\nInsert a integer and will create two pyramids\n\n");
}

int main(){
    int tam;
    instruction();
    printf("insert the size: ");
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