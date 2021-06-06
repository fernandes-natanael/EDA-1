#include <stdio.h>

int main(){
    int gasto, soma = 7;
    scanf("%d", &gasto);
    if(gasto > 10 && gasto <= 30){
        soma+= (gasto - 10);
    } else if(gasto > 30 && gasto <= 100){ 
        soma += 20 + 2*(gasto - 30); // 30 == 20 + 10
    } else if(gasto > 100 ){
        soma += 20 + 140 + 5*(gasto - 100); // 100 == 70 + 20 + 10
    }

    printf("%d\n", soma);
    return 0;
}