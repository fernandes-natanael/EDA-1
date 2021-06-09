#include <stdio.h>

#define MAX_NAME 80
#define MAX_STRING 240

struct tipoFiliacao{
    char nome[MAX_NAME];
    char nomeMae[MAX_NAME];
    char nomePai[MAX_NAME];
};

struct tipoFiliacao separaLinhaCSV(char linha[MAX_STRING]);
/*
int main(){
    char str[MAX_STRING];
    scanf(" %[^\n]", str);
    struct tipoFiliacao family = separaLinhaCSV(str);;
    printf("filho\n%s\n", family.nome);
    printf("mae\n%s\n", family.nomeMae);
    printf("pai\n%s\n", family.nomePai);
    return 0;
}
*/

struct tipoFiliacao separaLinhaCSV(char linha[]){
    int select = 0;
    int i,j;
    struct tipoFiliacao family; 

    for(i = 0, j = 0; linha[i] != '\0'; i++, j++){
        if(linha[i] == ','){
            if(linha[i+1] != ','){
                if(select == 0)
                    family.nome[j] = '\0';    
                else if(select == 1)
                    family.nomeMae[j] = '\0'; 
                select += 1;
                i += 1;
            }else{
                select = 2;
                family.nome[j] = '\0'; 
                family.nomeMae[0] = '\0'; 
                i += 2;
            }
            j = 0;
        }

        if(select == 0){
            family.nome[j] = linha[i];
        }else if(select == 1){
            family.nomeMae[j] = linha[i];
        }else if(select == 2){
            family.nomePai[j] = linha[i];
        }
    }
    family.nomePai[j] = '\0';
    return family;
}