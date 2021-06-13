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
### ***OBSERVAÇÃO***: acabei perdendo algumas questões, pois formatei o computador e esqueci de fazer um backup das questões, então refiz as questões que estavam disponíveis no listão das férias.
### Hello World
Apenas mostrar "Ola Mundo!" na tela

### EOF
#### Entrada
---
Ler N inteiros até que a leitura retorne EOF.
#### Saida
---
retornar quantos inteiros foram lidos.
#### Exempo de entrada
---
```
    2 7 10 32
```
#### Exempo de saída
---
```
    4
```
### Maior entre 4 números

#### Entrada
---
Ler 4 inteiros.
#### Saida
---
retornar o valor do maior inteiro entre os 4 .
#### Exempo de entrada
---
```
    5 12 24 1
```
#### Exempo de saída
---
```
    24
```
### Maior entre N números

#### Entrada
---
Ler N inteiros até que a leitura retorne EOF.
#### Saida
---
retornar o valor do maior inteiro entre os N lidos .
#### Exempo de entrada
---
```
    5 12 24 1 13 25 42 34 12
```
#### Exempo de saída
---
```
    42
```

### Conta de água

<table class="tg">
<thead>
  <tr>
    <th class="tg-0pky">Faixa de consumo(m³)</th>
    <th class="tg-0pky"> Preço por m³</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0lax">Até 10m³</td>
    <td class="tg-0lax">franquia cobre</td>
  </tr>
  <tr>
    <td class="tg-0lax">11 a 30m³</td>
    <td class="tg-0lax">R$ 1</td>
  </tr>
  <tr>
    <td class="tg-0lax"><span style="font-weight:400;font-style:normal">31 a 100m³</span></td>
    <td class="tg-0lax">R$ 2</td>
  </tr>
  <tr>
    <td class="tg-0lax"><span style="font-weight:400;font-style:normal">101 a diante</span></td>
    <td class="tg-0lax">R$ 5</td>
  </tr>
</tbody>
</table>

#### Entrada
---
Ler um inteiro que representa a quantidade em m³.
#### Saida
---
Retornar o valor final da conta.
#### Exempo de entrada
---
```
    68
```
#### Exempo de saída
---
```
    103
```
### Pirâmides 1

#### Exempo de entrada
---
```
    8
```
#### Exempo de saída
---
```
    01
    02 02
    03 03 03
    04 04 04 04
    05 05 05 05 05
    06 06 06 06 06 06
    07 07 07 07 07 07 07
    08 08 08 08 08 08 08 08

    01
    01 02
    01 02 03
    01 02 03 04
    01 02 03 04 05
    01 02 03 04 05 06
    01 02 03 04 05 06 07
    01 02 03 04 05 06 07 08
```

### Pirâmides 2

#### Exempo de entrada
---
```
    8
```
#### Exempo de saída
---
```
           *
          ***
         *****
        *******
       *********
      ***********
     *************
    ***************
```
### Par ou Ímpar

### Calculando

### Filiação

### Potenciação - RECURSIVA

### Régua Inglesa - RECURSIVA

### Soma dígitos - RECURSIVA

### String ao contrário - RECURSIVA

### Conta 7s - RECURSIVA

### Ordenação eficiente

### Busca binária em lista não ordenada

### Carteiro

### Maior substring


### Matriz esparca// estudar novamente ;-;

## Atalhos e comandos

+ `END OF FILE ou EOF ou -1` no linux é ativado com o comando 'CNTRL + D'
+ `gcc --version`, para ver a versão do compilador da sua máquina
+ `gcc -o arquivo arquivo.c` para compilar normalmente
+ `-o2` para questões de optimização do próprio compilador, existem outras melhorias que podem ser aplicadas, porém, não sei dizer muito sobre o assunto.
+ Para acrescentar a biblioteca math.h na compila, deve acrescentar `-lm`