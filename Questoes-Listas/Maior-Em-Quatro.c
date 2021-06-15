#include <stdio.h>

int main(){
    int num, maior;
    printf("Instructions\nRead 4 integers and returns the biggest of them\n\n");
    for(int i = 0 ; i < 4 ; i++){
        printf("integer(%d): ", i+1);
        scanf("%d", &num);
        maior = (i == 0) || (num > maior) ? num : maior;            
    }
    printf("\n\nThe largest is %d\n", maior);
    return 0;
}