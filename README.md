# Conteudos EDA-1

## Alocação dinâmica em c

Bibliotecas [stdlib.h](https://pt.wikipedia.org/wiki/Stdlib.h): biblioteca padrão que possui funções de alocação de memória,processos, conversões e outras.

+ `malloc` protótipo: 
```C 
    void * malloc(size_t size);
```
+ `calloc` protótipo:
```C 
    void * calloc(size_t number_elements, size_t size);
```
### ***Malloc 🆚 Calloc***
Ambos servem para alocar memória dinamicamente, porém de diferem na forma como são iniciados, pois o malloc ele apenas aloca os blocos de memória e caso haja lixo naquela bloco ele não será apagado. Já o calloc ele inicializa cada bloco de memória igual a 0 de forma padrão.
```C
    const int MAXIMO = 20;
    int *ponteiro = malloc(MAXIMO * sizeof(int));
    //ou
    int *ponteiro = malloc(MAXIMO, sizeof(int));
```
***OBSERVAÇÃO:*** O uso de type casting, neste caso (int *), não é necessário, porém, pode ser considerado uma boa prática.
+ `realloc` protótipo: 
```C
    void* realloc(void* ptr, size_t size);
```
Como o próprio nome diz serve para realocar o ponteiro, ou seja, quando a  quantidade máxima é atingida, chama-se o realloc para realocar
```C
    int realocacao(lista *l){
        l->dados = realloc(l->dados, 2*l->MAX* sizeof(int)); // dobrando o MAX do ponteiro de inteiros
        if(l->dados == NULL)// verifica se a realocacao falhou
            return 0;
        l->MAX *= 2; // atribui o dobro ao maximo
        return 1; // retorna que a realocacao foi bem sucedida
    }
```
+ `free()`, libera a memória alocada

`size_t size`: quantidades de bytes que será alocado

## Notacao Big O

## Estruturas de ordenacao

## Estuturas de dados FIFO e LIFO

## Questões da lista

Matriz esparca// estudar novamente ;-;

## Atalhos e comandos

+ `END OF FILE ou EOF ou -1` no linux é ativado com o comando 'CNTRL + D'
+ `gcc --version`, para ver a versão do compilador da sua máquina
+ `gcc -o arquivo arquivo.c` para compilar normalmente
+ `-o2` para questões de optimização, não sei dizer muito sobre o assunto.
+ Para acrescentar a biblioteca math.h na compila, deve colocar `-lm`