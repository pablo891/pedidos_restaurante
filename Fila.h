// Guardas para evitar inclusões múltiplas
#ifndef LISTA_ENC_H
#define LISTA_ENC_H
#include "Pedido.h"

// Estrutura opaca
typedef struct t_lista_enc ListaEnc;

// Funções básicas
ListaEnc* criar(int capacidade);
void liberar(ListaEnc* lista);

// Manipulação da lista
int inserir(ListaEnc* lista, void* c);
int remover(ListaEnc* lista, int posicao);
void* obter(ListaEnc* lista, int posicao);

// Informações sobre a lista
int cheia(ListaEnc* lista);
int vazia(ListaEnc* lista);
int tamanho(ListaEnc* lista);
int capacidade(ListaEnc* lista);

// Outras
// Função para imprimir os elementos da lista usando ponteiro para função
void imprimir(ListaEnc* lista, void (*imprimir_dado)(const void* dado));

#endif // LISTA_CONTAS_ENC_H