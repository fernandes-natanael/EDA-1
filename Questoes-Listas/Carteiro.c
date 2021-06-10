#include <stdio.h>
#include <stdlib.h>


void ordenar(int vetor[], int posicao[],int inicio, int n){
	int i, j, pivo, auxiliar, auxiliarPosicao;

	i = inicio;
	j = n-1;
	pivo = vetor[(inicio + n) / 2];

	while(i <= j){
		while(vetor[i] < pivo && i < n){
			i++;
		}
		while(vetor[j] > pivo && j > inicio){
			j--;
		}
		if(i <= j){
		    auxiliarPosicao = posicao[i];
			posicao[i] = posicao[j];
			posicao[j] = auxiliarPosicao;
			auxiliar = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = auxiliar;
			i++;
			j--;
		}
	}
	if(j > inicio)
		ordenar(vetor, posicao, inicio, j+1);
	if(i < n)
		ordenar(vetor,posicao, i, n);
}

int busca_binaria(int lista[], int n, int buscado){ // n == quantidade de itens da lista
    int start = -1; // menor posicao
    int end = n; // maior posicao
    while(start < end - 1){// enquanto posicao final for maior q a inicio
        int middle= (start + end) / 2;
        if( lista[middle] == buscado )
            return middle;
        else if( lista[middle] < buscado)
            start = middle;
        else 
            end = middle;
    }
    return -1; // retorna a posicao onde o valor se encontra
}// Complexidade O(lg n )

int main(){
    int casas, encomendas;
    scanf("%d%d", &casas, &encomendas);
    int *v_casas = malloc(casas * sizeof(int));
    int *v_posicao = malloc(casas * sizeof(int));
    int *v_encomendas = malloc(encomendas * sizeof(int));
    int *v_percurso = malloc(encomendas * sizeof(int));

    for(int i = 0 ; i < casas; i++){
        scanf("%d", &v_casas[i]);
        v_posicao[i] = i;
    }

    for(int i = 0 ; i < encomendas; i++)
        scanf("%d", &v_encomendas[i]);

    ordenar(v_casas, v_posicao, 0, casas);
    
    int percurso;
    for(int i = 0 ; i < encomendas ; i++){
       percurso = busca_binaria(v_casas, casas, v_encomendas[i]);
       v_percurso[i] = v_posicao[percurso];
    }
    int tempo = 0, comeco =0;
    for(int i = 0 ; i < encomendas; i++){
        tempo = tempo + abs(v_percurso[i] - comeco);
        comeco = v_percurso[i];
    }

    printf("%d\n", tempo);
    return 0;
}