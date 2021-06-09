#include <stdio.h>
#include <string.h>

#define MAX 100

int ehSub(char str[],char sub[], int i, int j){
    if(sub[j] == '\0')// sao iguais, pois chegaram aqui
        return 1;
    else if(str[i] == sub[j])
        return ehSub(str, sub, i+1, j+1);
    else
        return 0;
}

int subcadeia(char str[], char sub[], int i, int comeco, int tamanho){
    if(str[i] == '\0')
        return tamanho;
    else if(str[i] == sub[0]){
        if(ehSub(str, sub, i, 0)){
            if( comeco == -1 ){
                // printf("entrou aq %d\n", i);
                comeco = i;
                tamanho = strlen(sub);
            }else{
                tamanho = strlen(sub) +  i - comeco;
            }
            
            // printf("%d\n",comeco);
        }
    }

    return subcadeia(str, sub, i+1, comeco, tamanho);

}

int main(){
    char str[MAX], sub[MAX];
    scanf(" %s", str);
    scanf(" %s", sub);
    // printf("str:%s\n", str);
    // printf("sub:%s\n", sub);
    printf("%d\n", subcadeia(str, sub, 0, -1, 0));
    return 0;
}