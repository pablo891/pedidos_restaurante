// implementa lista encadeada genérica
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

// Definição do nó da lista
typedef struct t_no {
    void* dado; // ponteiro genérico para qualquer tipo de dado
    struct t_no* prox;
} No;

// Definição da estrutura da lista encadeada
struct t_lista_enc {
    No* primeiro;
    No* ultimo;
    int tamanho;
    int capacidade; // capacidade máxima da lista
};

// Funções básicas
ListaEnc* criar(int capacidade) {
    ListaEnc* lista = (ListaEnc*)malloc(sizeof(ListaEnc));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    return lista;
}
void liberar(ListaEnc* lista) {
    No* atual = lista->primeiro;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}   

// Manipulação da lista
int inserir(ListaEnc* lista, void* dado) {
    if (lista->tamanho >= lista->capacidade) {
        return 0; // lista cheia
    }
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->dado = dado;
    novo_no->prox = NULL;
    if (lista->ultimo != NULL) {
        lista->ultimo->prox = novo_no;
    } else {
        lista->primeiro = novo_no;
    }
    lista->ultimo = novo_no;
    lista->tamanho++;
    return 1; // sucesso
}
int remover(ListaEnc* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        return 0; // posição inválida
    }
    No* atual = lista->primeiro;
    No* anterior = NULL;
    for (int i = 0; i < posicao; i++) {
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior != NULL) {
        anterior->prox = atual->prox;
    } else {
        lista->primeiro = atual->prox;
    }
    if (atual == lista->ultimo) {
        lista->ultimo = anterior;
    }
    free(atual);
    lista->tamanho--;
    return 1; // sucesso
}

// ATENCAO: esta funcao retorna um ponteiro generico (void*), que pode ser
// convertido para qualquer tipo de dado conforme a necessidade do usuario.
void* obter(ListaEnc* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        return NULL; // posição inválida
    }
    No* atual = lista->primeiro;
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }
    return atual->dado;
}   

// Informações sobre a lista
int cheia(ListaEnc* lista) {
    return lista->tamanho >= lista->capacidade;
}
int vazia(ListaEnc* lista) {
    return lista->tamanho == 0;     
}
int tamanho(ListaEnc* lista) {
    return lista->tamanho;
}
int capacidade(ListaEnc* lista) {
    return lista->capacidade;
}   

// Outras

// Chama a função de impressão para cada elemento da lista generica
// ATENCAO: este codigo usa um ponteiro para função como argumento. Um ponteiro
// para função é uma variável que armazena o endereço de uma função, permitindo
// que essa função seja chamada indiretamente. Neste caso, o ponteiro para função
// 'imprimirDado' aponta para uma função que recebe um ponteiro genérico (void*)
// e não retorna nada (void). Isso permite que a função 'imprimir' seja
// genérica e possa imprimir qualquer tipo de dado, desde que uma função de
// impressão apropriada seja fornecida. (Josenildo Silva, AED I - SI/IFMA, 2025)
void imprimir(ListaEnc* lista, void (*imprimirDado)(const void*)) {
    No* atual = lista->primeiro;
    while (atual != NULL) {
        imprimirDado(atual->dado);
        atual = atual->prox;
    }
}
