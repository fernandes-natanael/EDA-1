#include <stdio.h>

void instruction(){
    printf("Intruction\n");
    printf("\nThe base value is R$7\n\n");
    printf("consumption range per m^3 | Price per m^3\n");
    printf(" to 10                    | No cost\n");
    printf(" 11 to 30                 | R$ 1\n");
    printf(" 31 to 100                | R$ 2\n");
    printf(" 101 to onwards           | R$ 5\n");
    printf("\ninsert your consumption: ");
}

int main(){
    int gasto, soma = 7;
    instruction();

    scanf("%d", &gasto);
    if(gasto > 10 && gasto <= 30){
        soma+= (gasto - 10);
    } else if(gasto > 30 && gasto <= 100){ 
        soma += 20 + 2*(gasto - 30); // 30 == 20 + 10
    } else if(gasto > 100 ){
        soma += 20 + 140 + 5*(gasto - 100); // 100 == 70 + 20 + 10
    }

    printf("You will pay R$ %d\n", soma);
    return 0;
}