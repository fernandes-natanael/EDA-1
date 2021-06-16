#include <stdio.h>

#define ull unsigned long long 

ull int sum (ull int num){
    if(num % 10 == num )
        return num == 7 ? 1 : 0;
    else{
        if(num % 10 == 7)
            return 1 + sum(num/10); 
        else
            return sum(num/10); 
    }
}

int main(){
    ull int num ; 
    printf("The program will count how many 7 exists in the integer.\n\nEnter the integer: ");
    scanf("%llu",&num);
    //printf("%d\n", num/10);
    printf("%llu\n", sum(num));
    return 0;
}