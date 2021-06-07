#include <stdio.h>

float potenciacao(int num, int exp){
    if(exp == 0)
        return 1;
    else if(exp > 0)
        return num * potenciacao(num, exp-1);
    else
        return (1.0/num) * potenciacao(num, exp+1);
}

int main(){
    int a, b;
    scanf("%d%d", &a, &b);

    if(a == 0  && b < 0 )
        printf("indefinido\n");
    else{
        printf("%g\n", potenciacao(a,b));
    }

        
    return 0;
}