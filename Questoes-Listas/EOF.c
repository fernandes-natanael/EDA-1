#include <stdio.h>

#define text "insert a integer:"

int main(){
    int temp, i = 0;
    printf("Instruction\nWindows: CTRL + Z to exit\nLinux: CTRL + D to exit\n\n");
    printf("%s", text);
    while(scanf("%d", &temp) != EOF){
        printf("%s", text);
        i++;
    }
    printf("\n\n%d integers were read\n", i);
    return 0;
}