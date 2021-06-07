#include <stdio.h>

#define ull unsigned long long 

ull int sum (ull int num){
    if(num % 10 == num )
        return num;
    else{
        return (num % 10) + sum(num/10); 
    }
}

int main(){
    ull int num ; 
    scanf("%llu",&num);
    //printf("%d\n", num/10);
    printf("%llu\n", sum(num));
    return 0;
}