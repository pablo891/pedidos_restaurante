#ifndef PEDIDO_H
#define PEDIDO_H
// definição da estrutura Pedido
typedef struct pedido Pedido;

// basicas
Pedido* cadastrarPedido(int idPedido, char observacao[40], char nome[40]);
void  excluirPedido(Pedido* ptr_p);

Pedido* buscarPedido(int idPedido);
void imprimirPedido(const Pedido* ptr_p);

// movimentações
// void depositar(ContaBancaria* conta, double valor);
// void sacar(ContaBancaria* conta, double valor);
// void transferir(ContaBancaria* origem, ContaBancaria* destino, double valor);

// informações
// double obterSaldo(const ContaBancaria* conta);
// int obterNumero(const ContaBancaria* conta);
// void imprimirConta(const ContaBancaria *conta);
// int compararContasNumero(const ContaBancaria* conta1, const ContaBancaria* conta2);
// int compararContasSaldo(const ContaBancaria* conta1, const ContaBancaria* conta2);

// genéricas
// void imprimirContaGenerico(const void* conta);
// void compararContasNumGenerico(const void* conta1, const void* conta2);
// void compararContasSaldoGenerico(const void* conta1, const void* conta2);

#endif
