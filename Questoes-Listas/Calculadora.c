#include <stdio.h>

void instruction(){
    printf("Intruction\n\n");
    printf("Enter how many games gonna happend and the players names,\n");
    printf("then enter what each player played in each game.\nExit when enter 0 in how many games gonna happend.\n\n");
    printf("Exemple IN: 4\n");
    printf("            2+10+40-40\n");
    printf("Exemple OUT: 12\n\n");

}

int main(){
    int num, sum, qnt, cont = 1;
    char op;

    instruction();
    printf("enter how many number to calculate: ");
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
        printf("%d\n\n", sum);
        printf("enter how many number to calculate: ");
        scanf("%d", &qnt);
        cont++;
    }  
    return 0;
}