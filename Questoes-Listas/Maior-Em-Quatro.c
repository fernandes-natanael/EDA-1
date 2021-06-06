#include <stdio.h>

int main(){
    int num, maior;
    for(int i = 0 ; i < 4 ; i++){
        scanf("%d", &num);
        maior = (i == 0) || (num > maior) ? num : maior;            
    }
    printf("%d\n", maior);
    return 0;
}