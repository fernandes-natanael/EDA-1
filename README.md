# Guia sobre alocacao dinamica em c

Bibliotecas que podem ser utilizadas:

+ stdlib.h
+ malloc.h

Como fazer alocacao dinamica?

Utilizando as funcoes de alocacao malloc e realloc

malloc vc pode instanciar o tipo de dado primitivo com o tamanho que quisermos

int * inteiro = malloc(sizeof(int)); // para ponteiro simples

const MAX = 100;
int * inteiro = malloc(MAX * sizeof(int)); // para ponteiros que apontam para vetores

int ** inteiro; // ponteiro bidimensional



Matriz esparca// estudar novamente ;-;