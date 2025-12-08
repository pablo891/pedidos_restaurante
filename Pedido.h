#ifndef PEDIDO_H
#define PEDIDO_H
// definição da estrutura Pedido
typedef struct pedido Pedido;

// basicas
Pedido* cadastrarPedido(int idPedido,char observacao[],char nomeCliente[],char nomePedido[] ,double valor);
void  excluirPedido(Pedido* ptr_p);
Pedido* buscarPedido(int idPedido);
void imprimirPedido(const Pedido* ptr_p);
void adicionarPrioridade(Pedido* ptr_p, int** prioridades, int* qtdPrioridades);
void removerPrioridade(int id, int** prioridades, int* qtdPrioridades);


//getters
int obterIdPedido(Pedido* ptr_p);
const char* obterObservacao(const Pedido* ptr_p);
const char* obterNomeCliente(const Pedido* ptr_p);
const char* obterNomePedido(const Pedido* ptr_p);

//setters
void alterarObservacao(Pedido* ptr_p, const char novaObs[]);
void alterarNomeCliente(Pedido* ptr_p, const char novoNome[]);
void alterarValor(Pedido* ptr_p, double novoValor);

#endif
