#include <stdio.h>


double potenciacao(int base,int exp){
    if(exp == 0)
        return 1;
    else if (exp < 0 )
        return potenciacao(base, exp + 1)/base;
    return base * potenciacao(base, exp-1);
}



int main(){
    int a, b;
    printf("Enter base and expoent: ");
    scanf("%d%d", &a, &b);

    if(a == 0  && b <= 0 )
        printf("indefinido\n");
    else{
        printf("%g\n",  potenciacao(a,b));
    }        
    return 0;
}