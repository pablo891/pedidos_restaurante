#include <stdio.h>
#include "Pedido.h"

int main() {

    /* ===== CRIACAO ===== */
    Pedido* p1 = cadastrarPedido(
        1,
        "Sem cebola",
        "Joao",
        "X-Burguer",
        25.00
    );

    Pedido* p2 = cadastrarPedido(
        2,
        "Com queijo extra",
        "Maria",
        "X-Bacon",
        32.50
    );

    /* ===== GETTERS ===== */
    printf("ID p1: %d\n", obterIdPedido(p1));
    printf("Cliente p1: %s\n", obterNomeCliente(p1));
    printf("Pedido p1: %s\n", obterNomePedido(p1));
    printf("Obs p1: %s\n", obterObservacao(p1));
    printf("Valor p1: %.2f\n\n", obterValorPedido(p1));

    printf("ID p2: %d\n", obterIdPedido(p2));
    printf("Cliente p2: %s\n", obterNomeCliente(p2));
    printf("Pedido p2: %s\n", obterNomePedido(p2));
    printf("Obs p2: %s\n", obterObservacao(p2));
    printf("Valor p2: %.2f\n\n", obterValorPedido(p2));

    /* ===== SETTERS ===== */
    alterarObservacao(p1, "Sem cebola e sem picles");
    alterarNomeCliente(p1, "Joao Silva");
    alterarNomePedido(p1, "X-Burguer Duplo");
    alterarValor(p1, 29.90);

    printf("=== APOS ALTERACOES (p1) ===\n");
    imprimirPedido(p1);

    /* ===== PRIORIDADES ===== */
    adicionarPrioridade(p1);
    adicionarPrioridade(p1);

    removerPrioridade(p1, obterIdPedido(p1));

    /* ===== IMPRESSAO FINAL ===== */
    printf("\n=== ESTADO FINAL ===\n");
    imprimirPedido(p1);
    imprimirPedido(p2);

    /* ===== FINAL ===== */
    excluirPedido(p1);
    excluirPedido(p2);

    return 0;
}
