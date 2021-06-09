#include <stdio.h>

int main(){
    int N = 0, game = 1;
    char player1[11], player2[11];
    int choice_p1, choice_p2;
    scanf("%d", &N);
    while(N > 0 ){
        scanf(" %[^\n]", player1);
        scanf(" %[^\n]", player2);
        printf("Teste %d\n", game);
        for ( int i = 0; i < N ;i++ ){
            scanf("%d%d", &choice_p1, &choice_p2);
            if( (choice_p1 + choice_p2) % 2 == 0)
                printf("%s\n",player1);
            else
                printf("%s\n",player2);
        }
        game++;
        scanf("%d", &N);
    }
    return 0;
}