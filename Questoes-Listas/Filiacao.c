#include <stdio.h>
#include <stdlib.h>
struct tipoFiliacao{
    char nome[80];
    char nomeMae[80];
    char nomePai[80];
};

int setaNome(char linha[240], char nome[80], int inicio );
struct tipoFiliacao separaLinhaCSV(char linha[240]);


int main(){
    char str[240];
    scanf(" %[^\n]", str);
    struct tipoFiliacao family = separaLinhaCSV(str);
    printf("filho\n%s\n", family.nome);
    printf("mae\n%s\n", family.nomeMae);
    printf("pai\n%s\n", family.nomePai);

    for(int i = 0 ; family.nome[i] != '\0'; i++)
        if(family.nome[i+1] == '\0')
            printf("filho ta correto\n");

    for(int i = 0 ; family.nomeMae[i] != '\0'; i++)
        if(family.nomeMae[i+1] == '\0')
            printf("Mae ta correto\n");

    for(int i = 0 ; family.nomePai[i] != '\0'; i++)
        if(family.nomePai[i+1] == '\0')
            printf("Pai ta correto\n");
    return 0;
}

int setaNome(char linha[], char nome[], int inicio ){
    int i = 0, j = inicio;
    while(linha[j] != '\0' && linha[j] != ','){
        nome[i++] = linha[j++];
    }
    nome[i] = '\0';

    return j + 1;

}
struct tipoFiliacao separaLinhaCSV(char linha[]){
    struct tipoFiliacao family;
    int inicio = 0;
    inicio = setaNome(linha, family.nome, inicio);
    inicio = setaNome(linha, family.nomeMae, inicio);
    inicio = setaNome(linha, family.nomePai, inicio);
    return family;
}

