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
    int N, M;
    int *vector_position, *vector_values;
    scanf("%d%d", &N, &M);

    vector_values = malloc( N * sizeof(int));
    vector_position = malloc( N * sizeof(int));
    for(int i = 0; i < N ; i++){
        scanf("%d", &vector_values[i]);
        vector_position[i] = i;
    }   

    ordenar(vector_values, vector_position, 0, N);

    int buscado;
    for(int i = 0 ; i < M ; i++){
        int verificar;
        scanf("%d", &verificar);
        buscado = busca_binaria(vector_values, N, verificar);
        if(buscado != -1)
            printf("%d\n", vector_position[buscado] );
        else
            printf("-1\n");
    }  

    free(vector_position);
    free(vector_values);  
    return 0;
}