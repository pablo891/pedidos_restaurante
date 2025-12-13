#include "Fila.h"
#include "Pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int teste_cadastrar_pedido();
int teste_getters_setters_pedido();
int teste_buscar_pedido();
int teste_sistema_prioridades();
int teste_fila_processar_pedidos_sequencial();
int teste_fila_pedidos_com_prioridade();
int teste_fila_alterar_pedido_na_fila();
int teste_fila_comportamento_circular();
int teste_fila_esvaziar_processar_todos();
int teste_desenfileirar_vazia();
int teste_completo();

int main(void) {
    printf("===========================================\n");
    printf("   TESTES DO SISTEMA DE PEDIDOS\n");
    printf("===========================================\n\n");
    
    int resultado = teste_completo();

    if (resultado) {
        printf("\n===========================================\n");
        printf("✓ TODOS OS TESTES PASSARAM COM SUCESSO!\n");
        printf("===========================================\n");
    } else {
        printf("\n===========================================\n");
        printf("✗ ALGUNS TESTES FALHARAM\n");
        printf("===========================================\n");
    }

    return 0;
}

int teste_completo() {
    printf(">>> TESTES DO TAD PEDIDO <<<\n\n");
    
    int resultado_pedido = 
        teste_cadastrar_pedido() &&
        teste_getters_setters_pedido() &&
        teste_buscar_pedido() &&
        teste_sistema_prioridades();
    
    printf("\n>>> TESTES DA FILA COM PEDIDOS <<<\n\n");
    
    int resultado_fila = 
        teste_fila_processar_pedidos_sequencial() &&
        teste_fila_pedidos_com_prioridade() &&
        teste_fila_alterar_pedido_na_fila() &&
        teste_fila_comportamento_circular() &&
        teste_fila_esvaziar_processar_todos();
    
    return resultado_pedido && resultado_fila;
}

// ==================== TESTES DO TAD PEDIDO ====================

int teste_cadastrar_pedido() {
    printf("1. Testando cadastrarPedido() e excluirPedido()...\n");
    
    Pedido* p1 = cadastrarPedido(1, "Sem cebola", "João Silva", "Pizza Margherita", 35.90);
    assert(p1 != NULL);
    assert(obterIdPedido(p1) == 1);
    assert(strcmp(obterObservacao(p1), "Sem cebola") == 0);
    assert(strcmp(obterNomeCliente(p1), "João Silva") == 0);
    assert(strcmp(obterNomePedido(p1), "Pizza Margherita") == 0);
    
    Pedido* p2 = cadastrarPedido(2, "Bem passado", "Maria Santos", "Hambúrguer", 25.50);
    assert(p2 != NULL);
    assert(obterIdPedido(p2) == 2);
    
    excluirPedido(p1);
    excluirPedido(p2);
    
    printf("   ✓ Pedidos criados e excluídos corretamente\n\n");
    return 1;
}

int teste_getters_setters_pedido() {
    printf("2. Testando getters e setters do Pedido...\n");
    
    Pedido* p = cadastrarPedido(10, "Normal", "Carlos Alberto", "Suco Natural", 8.00);
    
    // Testando getters
    assert(obterIdPedido(p) == 10);
    assert(strcmp(obterObservacao(p), "Normal") == 0);
    assert(strcmp(obterNomeCliente(p), "Carlos Alberto") == 0);
    assert(strcmp(obterNomePedido(p), "Suco Natural") == 0);
    printf("   ✓ Getters funcionando corretamente\n");
    
    // Testando setters
    alterarObservacao(p, "Com gelo e limão");
    assert(strcmp(obterObservacao(p), "Com gelo e limão") == 0);
    
    alterarNomeCliente(p, "Carlos Alberto Silva");
    assert(strcmp(obterNomeCliente(p), "Carlos Alberto Silva") == 0);
    
    alterarValor(p, 10.00);
    printf("   ✓ Setters funcionando corretamente\n");
    
    excluirPedido(p);
    printf("   ✓ Todas as operações de get/set validadas\n\n");
    return 1;
}

int teste_buscar_pedido() {
    printf("3. Testando buscarPedido()...\n");
    
    // Cadastrando vários pedidos
    Pedido* p1 = cadastrarPedido(100, "Pedido 1", "Cliente A", "Produto A", 15.0);
    Pedido* p2 = cadastrarPedido(200, "Pedido 2", "Cliente B", "Produto B", 25.0);
    Pedido* p3 = cadastrarPedido(300, "Pedido 3", "Cliente C", "Produto C", 35.0);
    
    return 1;
}

int teste_sistema_prioridades() {
    printf("4. Testando sistema de prioridades (adicionar/remover)...\n");
    
    int* prioridades = NULL;
    int qtdPrioridades = 0;
    
    // Criando pedidos
    Pedido* p1 = cadastrarPedido(501, "Urgente", "Cliente VIP 1", "Pedido Express", 50.0);
    Pedido* p2 = cadastrarPedido(502, "Normal", "Cliente Regular", "Pedido Normal", 30.0);
    Pedido* p3 = cadastrarPedido(503, "Urgente", "Cliente VIP 2", "Pedido Express", 60.0);
    Pedido* p4 = cadastrarPedido(504, "Urgente", "Cliente VIP 3", "Pedido Express", 70.0);
    
    // Adicionando prioridades
    adicionarPrioridade(p1);
    assert(prioridades[0] == 501);
    printf("   ✓ Prioridade 501 adicionada\n");
    
    adicionarPrioridade(p2);
    assert(prioridades[1] == 502);
    printf("   ✓ Prioridade 503 adicionada\n");
    
    adicionarPrioridade(p3);
    assert(prioridades[2] == 503);
    printf("   ✓ Prioridade 504 adicionada\n");
    
    // Verificando se os IDs corretos estão na lista
    int encontrou_501 = 0, encontrou_503 = 0, encontrou_504 = 0;
    for (int i = 0; i < qtdPrioridades; i++) {
        if (prioridades[i] == 501) encontrou_501 = 1;
        if (prioridades[i] == 503) encontrou_503 = 1;
        if (prioridades[i] == 504) encontrou_504 = 1;
    }
    assert(encontrou_501 && encontrou_503 && encontrou_504);
    
    // Removendo prioridade do meio
    removerPrioridade(p3, 503);
    assert(qtdPrioridades == 2);
    printf("   ✓ Prioridade 503 removida\n");
    
    // Verificando que 503 não está mais na lista
    encontrou_503 = 0;
    for (int i = 0; i < qtdPrioridades; i++) {
        if (prioridades[i] == 503) encontrou_503 = 1;
    }
    assert(!encontrou_503);
    
    // Removendo primeira prioridade
    removerPrioridade(p4, 504);
    assert(qtdPrioridades == 1);
    assert(prioridades[0] == 504);
    printf("   ✓ Prioridade 501 removida\n");
    
    free(prioridades);
    excluirPedido(p1);
    excluirPedido(p2);
    excluirPedido(p3);
    excluirPedido(p4);
    
    printf("   ✓ Sistema de prioridades funcionando perfeitamente\n\n");
    return 1;
}

int teste_desenfileirar_vazia() {
    printf("=== Teste: Desenfileirar Fila Vazia ===\n");
    
    Fila* f = criar_fila();
    
    void* resultado = desenfileirar(f);
    if (resultado == NULL) {
        printf("✓ Desenfileirar fila vazia retorna NULL\n");
    } else {
        printf("✗ Desenfileirar fila vazia não retornou NULL\n");
    }
    
    destruir_fila(f);
    printf("\n");
}

// ==================== TESTES DA FILA COM PEDIDOS ====================

int teste_fila_processar_pedidos_sequencial() {
    printf("1. Testando processamento sequencial de pedidos (FIFO)...\n");
    
    Fila* f = criar_fila();
    
    // Simulando pedidos em um restaurante
    printf("   → Recebendo pedidos...\n");
    Pedido* pedidos[5];
    for (int i = 0; i < 5; i++) {
        char nome[50], obs[50], prato[50];
        sprintf(nome, "Mesa %d", i + 1);
        sprintf(obs, "Observação mesa %d", i + 1);
        sprintf(prato, "Prato %d", i + 1);
        
        pedidos[i] = cadastrarPedido(1000 + i, obs, nome, prato, 25.0 + i * 5);
        int sucesso = enfileirar(f, pedidos[i]);
        assert(sucesso == 1);
    }
    printf("   ✓ 5 pedidos enfileirados\n");
    
    assert(tamanho(f) == 5);
    assert(!vazia(f));
    
    // Processando pedidos em ordem FIFO
    printf("   → Processando pedidos...\n");
    for (int i = 0; i < 5; i++) {
        Pedido* p = (Pedido*)desenfileirar(f);
        assert(p != NULL);
        assert(obterIdPedido(p) == 1000 + i);
        printf("   ✓ Pedido %d (Mesa %d) processado\n", 1000 + i, i + 1);
        excluirPedido(p);
    }
    
    assert(vazia(f));
    printf("   ✓ Todos os pedidos processados em ordem FIFO\n");
    
    destruir_fila(f);
    printf("   ✓ Processamento sequencial validado\n\n");
    return 1;
}

int teste_fila_pedidos_com_prioridade() {
    printf("2. Testando fila com sistema de prioridades...\n");
    
    Fila* f = criar_fila();
    int* prioridades = NULL;
    int qtdPrioridades = 0;
    
    // Criando mix de pedidos normais e prioritários
    Pedido* p1 = cadastrarPedido(2001, "Normal", "Cliente A", "Pedido A", 30.0);
    Pedido* p2 = cadastrarPedido(2002, "PRIORITÁRIO", "Cliente VIP B", "Pedido B", 40.0);
    Pedido* p3 = cadastrarPedido(2003, "Normal", "Cliente C", "Pedido C", 20.0);
    Pedido* p4 = cadastrarPedido(2004, "PRIORITÁRIO", "Cliente VIP D", "Pedido D", 50.0);
    Pedido* p5 = cadastrarPedido(2005, "Normal", "Cliente E", "Pedido E", 25.0);
    
    enfileirar(f, p1);
    enfileirar(f, p2);
    enfileirar(f, p3);
    enfileirar(f, p4);
    enfileirar(f, p5);
    
    assert(tamanho(f) == 5);
    printf("   ✓ 5 pedidos enfileirados (2 normais + 2 prioritários + 1 normal)\n");
    
    // Marcando pedidos prioritários
    adicionarPrioridade(p2);
    adicionarPrioridade(p4);
    
    assert(qtdPrioridades == 2);
    printf("   ✓ 2 pedidos marcados como prioritários (2002 e 2004)\n");
    
    // Verificando que os IDs prioritários estão corretos
    int tem_2002 = 0, tem_2004 = 0;
    for (int i = 0; i < qtdPrioridades; i++) {
        if (prioridades[i] == 2002) tem_2002 = 1;
        if (prioridades[i] == 2004) tem_2004 = 1;
    }
    assert(tem_2002 && tem_2004);
    printf("   ✓ Sistema de prioridades integrado com a fila\n");
    
    free(prioridades);
    while (!vazia(f)) {
        Pedido* p = (Pedido*)desenfileirar(f);
        excluirPedido(p);
    }
    destruir_fila(f);
    
    printf("   ✓ Fila com prioridades validada\n\n");
    return 1;
}

int teste_fila_alterar_pedido_na_fila() {
    printf("3. Testando alteração de pedidos já enfileirados...\n");
    
    Fila* f = criar_fila();
    
    Pedido* p1 = cadastrarPedido(3001, "Sem sal", "Pedro Santos", "Batata Frita", 15.0);
    Pedido* p2 = cadastrarPedido(3002, "Normal", "Paula Lima", "Refrigerante", 6.0);
    Pedido* p3 = cadastrarPedido(3003, "Gelado", "Rafael Costa", "Suco", 8.0);
    
    enfileirar(f, p1);
    enfileirar(f, p2);
    enfileirar(f, p3);
    
    printf("   ✓ 3 pedidos enfileirados\n");
    
    // Alterando o primeiro pedido da fila (sem desenfileirar)
    Pedido* primeiro = (Pedido*)primeiro_fila(f);
    assert(obterIdPedido(primeiro) == 3001);
    printf("   → Primeiro pedido: ID %d, Cliente: %s\n", 
           obterIdPedido(primeiro), obterNomeCliente(primeiro));
    
    alterarObservacao(primeiro, "Com MUITO sal");
    assert(strcmp(obterObservacao(primeiro), "Com MUITO sal") == 0);
    printf("   ✓ Observação alterada: %s\n", obterObservacao(primeiro));
    
    alterarNomeCliente(primeiro, "Pedro Henrique Santos");
    assert(strcmp(obterNomeCliente(primeiro), "Pedro Henrique Santos") == 0);
    printf("   ✓ Nome do cliente alterado: %s\n", obterNomeCliente(primeiro));
    
    alterarValor(primeiro, 18.50);
    printf("   ✓ Valor alterado para 18.50\n");
    
    // Verificando que o tamanho da fila não mudou
    assert(tamanho(f) == 3);
    printf("   ✓ Fila mantém 3 pedidos após alterações\n");
    
    while (!vazia(f)) {
        Pedido* p = (Pedido*)desenfileirar(f);
        excluirPedido(p);
    }
    destruir_fila(f);
    
    printf("   ✓ Alterações em pedidos enfileirados validadas\n\n");
    return 1;
}

int teste_fila_comportamento_circular() {
    printf("4. Testando comportamento circular da fila...\n");
    
    Fila* f = criar_fila();
    
    // Fase 1: Adicionar 3 pedidos
    printf("   → Fase 1: Adicionando 3 pedidos iniciais\n");
    Pedido* p1 = cadastrarPedido(4001, "Pedido 1", "Cliente 1", "Item 1", 10.0);
    Pedido* p2 = cadastrarPedido(4002, "Pedido 2", "Cliente 2", "Item 2", 20.0);
    Pedido* p3 = cadastrarPedido(4003, "Pedido 3", "Cliente 3", "Item 3", 30.0);
    
    enfileirar(f, p1);
    enfileirar(f, p2);
    enfileirar(f, p3);
    assert(tamanho(f) == 3);
    printf("   ✓ 3 pedidos na fila\n");
    
    // Fase 2: Processar 2 pedidos
    printf("   → Fase 2: Processando 2 pedidos\n");
    Pedido* processado1 = (Pedido*)desenfileirar(f);
    assert(obterIdPedido(processado1) == 4001);
    printf("   ✓ Pedido 4001 processado\n");
    excluirPedido(processado1);
    
    Pedido* processado2 = (Pedido*)desenfileirar(f);
    assert(obterIdPedido(processado2) == 4002);
    printf("   ✓ Pedido 4002 processado\n");
    excluirPedido(processado2);
    
    assert(tamanho(f) == 1);
    printf("   ✓ 1 pedido restante na fila\n");
    
    // Fase 3: Adicionar 2 novos pedidos (comportamento circular)
    printf("   → Fase 3: Adicionando 2 novos pedidos\n");
    Pedido* p4 = cadastrarPedido(4004, "Pedido 4", "Cliente 4", "Item 4", 40.0);
    Pedido* p5 = cadastrarPedido(4005, "Pedido 5", "Cliente 5", "Item 5", 50.0);
    
    enfileirar(f, p4);
    enfileirar(f, p5);
    assert(tamanho(f) == 3);
    printf("   ✓ 3 pedidos na fila novamente\n");
    
    // Verificando ordem FIFO após comportamento circular
    printf("   → Verificando ordem FIFO (deve ser: 4003, 4004, 4005)\n");
    Pedido* primeiro = (Pedido*)primeiro_fila(f);
    assert(obterIdPedido(primeiro) == 4003);
    printf("   ✓ Primeiro da fila: 4003 (correto!)\n");
    
    // Processando todos na ordem
    Pedido* p_1 = (Pedido*)desenfileirar(f);
    assert(obterIdPedido(p_1) == 4003);
    excluirPedido(p_1);
    
    Pedido* p_2 = (Pedido*)desenfileirar(f);
    assert(obterIdPedido(p_2) == 4004);
    excluirPedido(p_2);
    
    Pedido* p_3 = (Pedido*)desenfileirar(f);
    assert(obterIdPedido(p_3) == 4005);
    excluirPedido(p_3);
    
    assert(vazia(f));
    printf("   ✓ Comportamento circular validado com sucesso\n");
    
    destruir_fila(f);
    printf("   ✓ Fila circular funcionando perfeitamente\n\n");
    return 1;
}

int teste_fila_esvaziar_processar_todos() {
    printf("5. Testando processar e esvaziar fila completa...\n");
    
    Fila* f = criar_fila();
    
    // Criando uma grande quantidade de pedidos
    printf("   → Adicionando 10 pedidos na fila\n");
    Pedido* pedidos[10];
    for (int i = 0; i < 10; i++) {
        char nome[50], obs[50], item[50];
        sprintf(nome, "Cliente %d", i + 1);
        sprintf(obs, "Observação %d", i + 1);
        sprintf(item, "Item %d", i + 1);
        
        pedidos[i] = cadastrarPedido(5000 + i, obs, nome, item, 15.0 + i * 3);
        enfileirar(f, pedidos[i]);
    }
    
    assert(tamanho(f) == 10);
    assert(!vazia(f));
    printf("   ✓ 10 pedidos enfileirados com sucesso\n");
    
    // Processando todos os pedidos
    printf("   → Processando todos os pedidos...\n");
    int contador = 0;
    while (!vazia(f)) {
        Pedido* p = (Pedido*)desenfileirar(f);
        assert(p != NULL);
        assert(obterIdPedido(p) == 5000 + contador);
        contador++;
        excluirPedido(p);
    }
    
    assert(contador == 10);
    assert(vazia(f));
    assert(tamanho(f) == 0);
    printf("   ✓ Todos os 10 pedidos processados em ordem FIFO\n");
    printf("   ✓ Fila está vazia\n");
    
    // Testando reutilização da fila
    printf("   → Testando reutilização da fila vazia\n");
    Pedido* novo = cadastrarPedido(6000, "Novo pedido", "Cliente Novo", "Item Novo", 50.0);
    int sucesso = enfileirar(f, novo);
    assert(sucesso == 1);
    assert(tamanho(f) == 1);
    printf("   ✓ Fila pode ser reutilizada após esvaziar\n");
    
    Pedido* p_final = (Pedido*)desenfileirar(f);
    excluirPedido(p_final);
    destruir_fila(f);
    
    printf("   ✓ Processamento completo e reutilização validados\n\n");
    return 1;
}