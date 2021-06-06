#include <stdio.h>

int main(){
    int tam, asterisco = 1, espaco;
    scanf("%d", &tam);
    espaco = tam -1;
    for(int i = 0 ; i < tam ; i++){
        for(int k = 0 ; k < espaco; k++)
            printf(" ");
        for(int k = 0 ; k < asterisco; k++)
            printf("*");
        asterisco +=2;
        espaco--;
        printf("\n");
    }
    return 0;
}