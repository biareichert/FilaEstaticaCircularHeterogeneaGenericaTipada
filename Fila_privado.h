#ifndef FILA_PRIVADO_H
#define FILA_PRIVADO_H

#include "Fila_publico.h"

/*Struct da fila*/
typedef struct fila{
    int inicio; /*armazena o índice do vetor que identifica o início da fila*/
    int fim; /*armazena o índice do vetor que identifica o fim da fila*/
    int tamAtual; /*armazena o tamanho atual da fila, quantos elementos foram inseridos*/
    int tamMax; /*armazena o tamanho máximo da fila*/
    elemento **vetor; /*vetor de dados do tipo 'elemento' que é a struct abaixo*/
} fila;

typedef struct elemento{
    void *elemento; /*armazena o dado genérico*/
    int tamInfo; /*armazena o tamanho (sizeof) do dado (elemento)*/
    int tipo; /*1: struct. 2: float. 3: caracter. 4: int. 5: string.*/
} elemento;

#endif