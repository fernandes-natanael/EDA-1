#include <stdio.h>
#include <stdlib.h>
struct tipoFiliacao{
    char nome[80];
    char nomeMae[80];
    char nomePai[80];
};

int setaNome(char linha[240], char nome[80], int inicio );
struct tipoFiliacao separaLinhaCSV(char linha[240]);

void instruction();

int main(){
    char str[240];
    instruction();
    printf("insert the CSV string: ");
    scanf(" %[^\n]", str);
    struct tipoFiliacao family = separaLinhaCSV(str);
    printf("son: %s\n", family.nome);
    printf("mother: %s\n", family.nomeMae);
    printf("father: %s\n", family.nomePai);
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

void instruction(){
    printf("Instruction\n\n");
    printf("Enter a CSV with your name, your mother's name and your father's name.\n");
    printf("Then the program will return a struct with the names.\n\n");
    printf("Exemple IN:  Fagner Farias Castro Filho,, Fagner Farias Castro");
    printf("Exemple OUT: son: Fagner Farias Castro Filho\nmother: \nfather: Fagner Farias Castro\n\n");
}