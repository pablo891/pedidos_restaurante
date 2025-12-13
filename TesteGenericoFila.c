#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pedido.h"

int main() {

    Fila* filaPedidos = criar_fila();

    Pedido* p1 = cadastrarPedido(
        1,
        "Sem cebola",
        "João Silva",
        "Hambúrguer",
        25.00
    );

    Pedido* p2 = cadastrarPedido(
        2,
        "Pouco sal",
        "Maria Santos",
        "Lasanha",
        32.50
    );

    Pedido* p3 = cadastrarPedido(
        3,
        "Bem passado",
        "Carlos Lima",
        "Bife Acebolado",
        28.00
    );

    enfileirar(filaPedidos, p1);
    enfileirar(filaPedidos, p2);
    enfileirar(filaPedidos, p3);

    printf("\n--- Fila de pedidos após enfileirar ---\n");
    imprimir_fila(filaPedidos, imprimirPedido);

    printf("\nQuantidade de pedidos na fila: %d\n", tamanho(filaPedidos));

    Pedido* atendido = (Pedido*) desenfileirar(filaPedidos);
    printf("\n--- Pedido atendido ---\n");
    imprimirPedido(atendido);

    excluirPedido(atendido);

    printf("\n--- Fila após desenfileirar um pedido ---\n");
    imprimir_fila(filaPedidos, imprimirPedido);

    while (!vazia(filaPedidos)) {
        Pedido* p = (Pedido*) desenfileirar(filaPedidos);
        excluirPedido(p);
    }

    destruir_fila(filaPedidos);

    return 0;
}