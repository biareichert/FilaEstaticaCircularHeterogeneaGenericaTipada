#ifndef FILA_PUBLICO_H
#define FILA_PUBLICO_H

/*Chamada da struct da fila e do elemento*/
typedef struct fila fila;
typedef struct elemento elemento;

/*Funções da fila, aqui tem-se acesso a manipulação da fila*/
fila *criar(int tamMax); //Função construtora
int inserir(fila *f, void *elem, int tamInfo, int tipo); //Função manipuladora
elemento *retirar(fila *f); //Função manipuladora
int verificarCheia(fila *f); //Função de acesso
int verificarVazia(fila *f); //Função de acesso
elemento *verInicio(fila *f); //Função de acesso
void destruir(fila *f); //Função destrutora

/*Novas funções para manipulação da struct elemento*/
void *verElemento(elemento *e);
int verTipo(elemento *e);
void destroiElemento(elemento *e);


#endif
