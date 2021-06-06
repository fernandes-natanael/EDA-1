#include <stdio.h>

int main(){
    int num, sum, qnt, cont = 1;
    char op;
    scanf("%d", &qnt);
    while(qnt != 0){
        scanf("%d", &num);
        sum = num;
        for(int i = 1 ; i < qnt; i++){
            scanf("%c", &op);
            scanf("%d", &num);
            sum = (op == '+') ? sum + num : sum - num;
        } 
        printf("Teste %d\n", cont);
        printf("%d\n", sum);
        scanf("%d", &qnt);
        cont++;
    }  
    return 0;
}