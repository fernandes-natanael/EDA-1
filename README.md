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
### [Hello World](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Hello-World.c)

Apenas mostrar "Ola Mundo!" na tela

### [EOF](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/EOF.c)
### [Maior entre 4 números](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Maior-Em-Quatro.c)

### [Maior entre N números](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Maior-Em-N.c)

### [Conta de água](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Conta-Agua.c)

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

### [Pirâmides 1](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Piramide1.c)

### [Pirâmides 2](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Piramide2.c)

### [Par ou Ímpar](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Par-Impar.c)

+ [Enunciado](https://br.spoj.com/problems/PAR.pdf)
### [Calculando](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Calculadora.c)

+ [Enunciado](https://br.spoj.com/problems/CALCULA.pdf)
### [Filiação](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Filiacao.c)

### [Potenciação](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Potenciacao-Recursao.c) - RECURSIVA

### [Régua Inglesa](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Regua-Inglesa-recursiva.c) - RECURSIVA

### [Soma dígitos](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Soma-digitos-recursivo.c) - RECURSIVA

### [String ao contrário](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/string-inversa-recursivo.c) - RECURSIVA

### [Conta 7s](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Conta7-Recursivo.c) - RECURSIVA

### [Ordenação eficiente](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Ordenacao-Shellsort.c)

### [Busca binária em lista não ordenada](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Busca-Binaria-Em-Conjunto-Nao-Ordenado.c)

### [Carteiro](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/Carteiro.c)

### [Maior substring](https://github.com/fernandes-natanael/EDA-1/blob/master/Questoes-Listas/maior-substring-recursivo.c)


### Matriz esparca// estudar novamente ;-;

## Atalhos e comandos

+ `END OF FILE ou EOF ou -1` no linux é ativado com o comando 'CTRL + D' e no windows 'CTRL + Z'
+ `gcc --version`, para ver a versão do compilador da sua máquina
+ `gcc -o arquivo arquivo.c` para compilar normalmente
+ `-o2` para questões de optimização do próprio compilador, existem outras melhorias que podem ser aplicadas, porém, não sei dizer muito sobre o assunto.
+ Para acrescentar a biblioteca math.h na compila, deve acrescentar `-lm`