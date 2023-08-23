//
//  ListaEncadeada.h
//  ListaEncadeada
//
//  Created by Rômulo Santana on 05/08/23.
//

#ifndef ListaEncadeada_h
#define ListaEncadeada_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef int ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
    NO* cauda;
    int tamanho;
} LISTA;

/*
   Compara o item x com o y, retornando:
     1 caso x > y
     0 caso x = y
    -1 caso x < y
*/
char compare(ITEM x, ITEM y);

// Retorna true se x = y e false caso contrario
bool igual(ITEM x, ITEM y);

// Inicializa a lista deixando-a pronta para ser utilizada.
void inicializar(LISTA *l);

// Retornar o tamanho da lista sequencial
int tamanho(LISTA *l);

// Retorna true se a lista esta vazia (Tamanho = 0)
bool vazia(LISTA *l);

/*
  Objetivo: Insere o item passado como parametro na lista passada.
            Se o tamanho da lista ja for igual ao tamanho maximo,
            a funcao Inserir retorna false.
*/
bool inserir(ITEM item, LISTA *l);

// insere itens na cauda da lista atualizando o ponteiro prox da antiga cauda
bool inserirNoFinal(ITEM item, LISTA *l);

// primeira insercao da lista (funcao criada para evitar duplicacao de codigo)
bool insercaoListaVazia(ITEM item, LISTA *l);

// insercao dos elementos inteiros em ordem crescente
bool insercaoOrdenada(ITEM item, LISTA *l);

// retorna a intersecao entre duas listas
void intersecao(LISTA *listaA, LISTA *listaB, LISTA *listaI);

// inverte a lista alvo alterando seus ponteiros
void inverter(LISTA *l);

/*
  Objetivo: Busca na lista o item passado.
            Caso encontre, retorna a posicao (entre 0 e tamanho - 1).
            Caso nao encontre, retorna o valor -1.
*/
int buscar(ITEM item, LISTA *l);

// Retornar o n-esimo elemento da lista sequencial
// Pre-condicao: 0 <= n < tamanho
ITEM enesimo(int n, LISTA *l);

/*
  Objetivo: Altera o item contido em uma dada posicao da lista.
            Caso a posicao exista, retorna true. Caso nao exista,
            a alteracao nao sera feita e retorna false.
*/
bool alterar(ITEM item, int pos, LISTA *l);

/*
  Objetivo: Inserir o item passado como parametro na posicao i da lista.
            Caso a lista nao esteja cheia e a posicao seja valida
            (0<=i<=tamanho), o item sera inserido e a funcao retorna true.
            Caso contrario, a funcao retorna false para indicar que o item
            nao foi inserido.
 */
bool inserirNaPos(ITEM item, int i, LISTA *l);

/*
  Objetivo: Remove o item passado da lista. Caso nao seja
            encontrato, retorna false. Se for removido, true.
*/
bool remover(ITEM item, LISTA *l);

// remover um item na posicao desejada
bool removerNaPos(ITEM *item, int i, LISTA *l);

// clona a lista criando uma nova lista e alocando memoria para esta
LISTA* clonar(LISTA *l);

// Exibicao de um item da lista
void exibirItem(ITEM i);

// Exibicao da lista sequencial
void exibirLista(LISTA *l);

// Remove todos os valores da lista, deixando-a vazia
void limpar(LISTA *l);

// Destruicao da lista sequencial
void destruir(LISTA *l);


#endif /* ListaEncadeada_h */
