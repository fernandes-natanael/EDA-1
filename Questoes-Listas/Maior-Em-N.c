#include <stdio.h>

int main(){
    int num, maior, x;
    x = scanf("%d", &num);
    maior = num;
    if( x != EOF){
        while( x != EOF){
            x = scanf("%d", &num);
            maior = (num > maior) ? num : maior;            
        }
        printf("%d\n", maior);
    }
    return 0;
}