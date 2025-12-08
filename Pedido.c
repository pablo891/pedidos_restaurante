#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pedido.h"


struct pedido {
    int idPedido;
    char* observacao;
    char* nomeCliente;
    char* nomePedido; 
    double valor;
    int* prioridades;    // to usando vetor dinâmico pra conseguir dar realloc
    int qtdPrioridades; 
};

Pedido* cadastrarPedido(int idPedido, char observacao[], char nomeCliente[], char nomePedido[],double valor) 
{
    Pedido* ptr_p = (Pedido*) malloc(sizeof(Pedido));
    if (!ptr_p) return NULL;

    ptr_p->prioridades = NULL;   
    ptr_p->qtdPrioridades = 0; 
    ptr_p->idPedido = idPedido;
    ptr_p->valor = valor;

    //aloca e aloca
    ptr_p->observacao = malloc(strlen(observacao) + 1);
    if (!ptr_p->observacao) {
        free(ptr_p);
        return NULL;
    }
    strcpy(ptr_p->observacao, observacao);

    //alocando dnv
    ptr_p->nomeCliente = malloc(strlen(nomeCliente) + 1);
    if (!ptr_p->nomeCliente) {
        free(ptr_p->observacao);
        free(ptr_p);
        return NULL;
    }
    strcpy(ptr_p->nomeCliente, nomeCliente);

    //alocação kkkkkkkk
    ptr_p->nomePedido = malloc(strlen(nomePedido) + 1);
    if (!ptr_p->nomePedido) {
        free(ptr_p->observacao);
        free(ptr_p->nomeCliente);
        free(ptr_p);
        return NULL;
    }
    strcpy(ptr_p->nomePedido, nomePedido);

    return ptr_p;
}


void excluirPedido(Pedido* ptr_p){
    if(ptr_p == NULL) return;

    free(ptr_p->observacao);
    free(ptr_p->nomeCliente);
    free(ptr_p->nomePedido);
    free(ptr_p);
}

int obterIdPedido(Pedido* ptr_p){
    if(ptr_p ? ptr_p->idPedido : -1);
}

double obterValorPedido(const Pedido* ptr_p) {
    return (ptr_p ? ptr_p->valor : 0);
}

const char* obterObservacao(const Pedido* ptr_p) {
    return (ptr_p ? ptr_p->observacao : NULL);
}

const char* obterNomeCliente(const Pedido* ptr_p) {
    return (ptr_p ? ptr_p->nomeCliente : NULL);
}

const char* obterNomePedido(const Pedido* ptr_p) {
    return (ptr_p ? ptr_p->nomePedido : NULL);
}

void alterarObservacao(Pedido* ptr_p, const char novaObs[]) {
    if (!ptr_p || !novaObs) return;

    char* temp = realloc(ptr_p->observacao, strlen(novaObs) + 1);
    if (temp == NULL) return;

    ptr_p->observacao = temp;
    strcpy(ptr_p->observacao, novaObs);
}

void alterarNomeCliente(Pedido* ptr_p, const char novoNome[]) {
    if (!ptr_p || !novoNome) return;

    char* temp = realloc(ptr_p->nomeCliente, strlen(novoNome) + 1);
    if (temp == NULL) return;

    ptr_p->nomeCliente = temp;
    strcpy(ptr_p->nomeCliente, novoNome);
}

void alterarNomePedido(Pedido* ptr_p, const char novoNome[]) {
    if (!ptr_p || !novoNome) return;

    char* temp = realloc(ptr_p->nomePedido, strlen(novoNome) + 1);
    if (temp == NULL) return;

    ptr_p->nomePedido = temp;
    strcpy(ptr_p->nomePedido, novoNome);
}

void alterarValor(Pedido* ptr_p, double novoValor) {
    if (!ptr_p) return;
    ptr_p->valor = novoValor;
}


void adicionarPrioridade(Pedido* ptr_p, int** prioridades, int* qtdPrioridades) {
    // +1
    int* novaLista = realloc(*prioridades, (*qtdPrioridades + 1) * sizeof(int));
    if (!novaLista) return;

    *prioridades = novaLista;

    (*prioridades)[*qtdPrioridades] = ptr_p->idPedido;
    (*qtdPrioridades)++;
}

void removerPrioridade(int id, int** prioridades, int* qtdPrioridades) {
    int pos = -1;

    for (int i = 0; i < *qtdPrioridades; i++) {
        if ((*prioridades)[i] == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return;

    //move pra esquerd
    for (int i = pos; i < *qtdPrioridades - 1; i++) {
        (*prioridades)[i] = (*prioridades)[i + 1];
    }

    (*qtdPrioridades)--;

    if (*qtdPrioridades == 0) {
        free(*prioridades);
        *prioridades = NULL;
        return;
    }

    // reduz o tamanho do vet
    int* novaLista = realloc(*prioridades, (*qtdPrioridades) * sizeof(int));
    if (novaLista) {
        *prioridades = novaLista;
    }
}

void imprimirPedido(const Pedido* ptr_p) {
    if (!ptr_p) {
        printf("Pedido nulo.\n");
        return;
    }

    printf("====== PEDIDO %d ======\n", ptr_p->idPedido);
    printf("Nome do Pedido: %s\n", ptr_p->nomePedido);
    printf("Cliente: %s\n", ptr_p->nomeCliente);
    printf("Observação: %s\n", ptr_p->observacao);
    printf("Valor total: R$ %.2f\n", ptr_p->valor);
    printf("=======================\n");
}
