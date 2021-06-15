#include <stdio.h>

int main(){
    int num, maior;
    printf("Instructions\nRead N integers and returns the biggest of them\n\n");

    printf("insert integer: ");
    if(scanf("%d", &num) != EOF){
        maior = num;
        printf("insert integer: ");
        while( scanf("%d", &num) != EOF){
            printf("insert integer: ");
            maior = (num > maior) ? num : maior;            
        }
        printf("\n\nThe biggest is %d\n", maior);
    }
    return 0;
}