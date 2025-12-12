#include <stdlib.h>
#include "fila.h"

typedef struct nodo {
    void* info;        
    struct nodo* prox;  
} Nodo;

struct fila {
    Nodo* inicio;  
    Nodo* fim; 
    int qtd; 
};

Fila* criar_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->qtd = 0;
    }
    return f;
}

void destruir_fila(Fila* f) {
    if (f == NULL) return;

    Nodo* atual = f->inicio;
    while (atual != NULL) {
        Nodo* temp = atual;
        atual = atual->prox;
        free(temp); 
    }
    free(f); 
}

int enfileirar(Fila* f, void* elemento) {
    if (f == NULL) return 0;

    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL) return 0; 

    novo->info = elemento;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo; 
    }
    
    f->fim = novo; 
    f->qtd++;
    return 1;
}

void* desenfileirar(Fila* f) {
    if (f == NULL || f->inicio == NULL) return NULL;

    Nodo* temp = f->inicio;
    void* dado = temp->info;

    f->inicio = f->inicio->prox; 
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp); 
    f->qtd--;
    return dado;
}

int vazia(Fila* f) {
    if (f == NULL) return 1;
    return (f->inicio == NULL);
}

int cheia(Fila* f) {
    return 0;
}

int tamanho(Fila* f) {
    if (f == NULL) return 0;
    return f->qtd;
}

void* primeiro_fila(Fila* f) {
    if (f == NULL || f->inicio == NULL) return NULL;
    return f->inicio->info;
}

void imprimir_fila(Fila* f, void (*imprime_elemento)(void*)) {
    if (f == NULL || f->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    Nodo* atual = f->inicio;
    while (atual != NULL) {
        imprime_elemento(atual->info); 
        atual = atual->prox;
    }
}

