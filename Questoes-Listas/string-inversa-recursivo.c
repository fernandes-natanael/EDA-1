#include <stdio.h>

void inverso(char str[], int i){
    if(str[i] != '\0'){
        inverso(str, i+1);
        printf("%c", str[i]);
        if(i == 0)
            printf("\n");
    }
}

int main(){
    const int MAX = 500;
    char str[MAX];
    printf("Enter the string that will be reversed");
    scanf("%s", str);
    inverso(str, 0); 
    return 0;
}