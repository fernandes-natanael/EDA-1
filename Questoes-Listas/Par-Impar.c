#include <stdio.h>

void instruction(){
    printf("Intruction\n\n");
    printf("Enter how many games gonna happend and the players names,\n");
    printf("then enter what each player played in each game.\nExit when enter 0 in how many games gonna happend.\n\n");
    printf("Exemple IN: 2\n");
    printf("            Pedro Paulo\n");
    printf("            0 2\n");
    printf("            5 2\n");
    printf("            0 // exit the program\n");
    printf("Exemple OUT: Teste 1\n");
    printf("             Pedro \n");
    printf("             Paulo\n");

}


int main(){
    int N = 0, game = 1;

    instruction();
    printf("enter how many games the players gonna play: ");
    scanf("%d", &N);
    
    while(N > 0 ){
        char player1[11], player2[11];
        int choice_p1 = 0, choice_p2 = 0;
        printf("enter the  player name (even): ");
        scanf(" %[^\n]", player1);
        printf("enter the  player name (odd): ");
        scanf(" %[^\n]", player2);
        printf("Teste %d\n", game++);
        for ( int i = 0; i < N ;i++ ){
            printf("%s plays: ", player1);
            scanf("%d", &choice_p1);
            printf("%s plays: ", player2);
            scanf("%d", &choice_p2);
            if( (choice_p1 + choice_p2)%2 == 0)
                printf("%s wins\n",player1);
            else
                printf("%s wins\n",player2);
        }
        printf("enter how many games the players gonna play: ");
        scanf("%d", &N);
    }
    return 0;
}