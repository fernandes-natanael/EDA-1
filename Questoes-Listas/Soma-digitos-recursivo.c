#include <stdio.h>

#define ull unsigned long long 

ull int sum (ull int num){
    if(num % 10 == num )
        return num;
    else{
        return (num % 10) + sum(num/10); 
    }
}

void instruction(){
    printf("Instruction\n\n");
    printf("Enter a integer and the program will return the sum of\n");
    printf("the elements.\n\n");
}

int main(){
    ull int num ; 
    instruction();
    printf("Enter the integer: ");
    scanf("%llu",&num);
    //printf("%d\n", num/10);
    printf("%llu\n", sum(num));
    return 0;
}