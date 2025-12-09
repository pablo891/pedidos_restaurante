#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

Fila* criar_fila();

void destruir_fila(Fila* f);

int enfileirar(Fila* f, void* elemento);

void* desenfileirar(Fila* f);

int vazia(Fila* f);

int cheia(Fila* f);

int tamanho(Fila* f);

void* primeiro_fila(Fila* f);

void imprimir_fila(Fila* f, void (*imprime_elemento)(void*));

#endif