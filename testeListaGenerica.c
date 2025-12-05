#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pedido.h"


int ler_arquivo_contas(const char* nome_arquivo, ListaEnc* lista);


int teste_inserir();
int teste_arquivo();
int teste_obter();



int main(int argc, char *argv[])
{
   printf(">>> Iniciando testes da Lista Genérica Encadeada...\n");

   printf("Teste de insercao de contas na lista:\n");
   
   
    if (!teste_inserir()) {
        printf("Teste de insercao falhou.\n");
        return 1;
    }
    printf("Teste de insercao [PASSOU].\n");  

    printf("\nTeste de leitura de contas de arquivo:\n");

    if (!teste_arquivo()) {
        printf("Teste de leitura de arquivo falhou.\n");
        return 1;
    }
    printf("Teste de leitura de arquivo [PASSOU].\n");

    printf("\nTeste de obter contas da lista:\n");
    if (!teste_obter()) {
        printf("Teste de obter contas falhou.\n");
        return 1;
    }
    printf("Teste de obter contas [PASSOU].\n");

    printf("\n>>> Todos os testes foram concluídos com sucesso.\n");

    return 0;
}




int ler_arquivo_contas(const char* nome_arquivo, ListaEnc* lista) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        return 0; // Falha ao abrir o arquivo
    }

    int numero;
    double saldo;
    while (fscanf(arquivo, "%d %lf", &numero, &saldo) == 2) {
        ContaBancaria* conta = criarConta(numero, saldo);
        if (conta == NULL || !inserir(lista, conta)) {
            fclose(arquivo);
            return 0; // Falha ao criar ou inserir a conta
        }
    }

    fclose(arquivo);
    return 1; // Sucesso
}

int teste_inserir() {
    ListaEnc* lista = criar(5);
    if (lista == NULL) {
        return 0; // Falha na criação da lista
    }
    for (int i = 0; i < 5; i++) {
        ContaBancaria* conta = criarConta(i + 1, (i + 1) * 100.0);
        if (conta == NULL || !inserir(lista, conta)) {
            return 0; // Falha ao criar ou inserir a conta
        }
    }

    imprimir(lista, imprimirContaGenerico);

    liberar(lista);
    return 1; // Sucesso
}
    
int teste_arquivo() {
    ListaEnc* lista = criar(10);
    if (lista == NULL) {
        return 0; // Falha na criação da lista
    }

    if (!ler_arquivo_contas("contas.txt", lista)) {
        return 0; // Falha ao ler o arquivo
    }

    imprimir(lista, imprimirContaGenerico);

    liberar(lista);

    
    return 1; // Sucesso
}

int teste_obter() {
    ListaEnc* lista = criar(5);
    if (lista == NULL) {
        return 0; // Falha na criação da lista
    }
    for (int i = 0; i < 5; i++) {
        ContaBancaria* conta = criarConta(i + 1, (i + 1) * 100.0);
        if (conta == NULL || !inserir(lista, conta)) {
            return 0; // Falha ao criar ou inserir a conta
        }
    }

    ContaBancaria* conta = (ContaBancaria*)obter(lista, 2);
    if (conta == NULL ) {
            return 0; // Falha ao obter a conta correta
    }
    
    imprimirConta(conta);

    
    liberar(lista);
    return 1; // Sucesso
}


