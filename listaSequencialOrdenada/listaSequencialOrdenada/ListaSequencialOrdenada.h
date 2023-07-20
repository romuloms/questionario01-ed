//
//  ListaSequencialOrdenada.h
//  listaSequencialOrdenada
//
//  Created by Rômulo Santana on 12/07/23.
//

#ifndef ListaSequencialOrdenada_h
#define ListaSequencialOrdenada_h

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX 1000000

typedef int ITEM;

typedef struct{
    ITEM itens[MAX];
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

// Retorna true se a lista esta cheia (Tamanho = MAX)
bool cheia(LISTA *l);

// Retorna true se a lista esta vazia (Tamanho = 0)
bool vazia(LISTA *l);

/*
  Objetivo: Insere o item passado como parametro na lista passada.
            Se o tamanho da lista ja for igual ao tamanho maximo,
            a funcao Inserir retorna false.
*/
bool inserir(ITEM item, LISTA *l);

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
  Objetivo: Remove o item passado da lista. Caso nao seja
            encontrato, retorna false. Se for removido, true.
*/
bool remover(ITEM item, LISTA *l);

// Exibicao de um item da lista
void exibirItem(ITEM i);

// Exibicao da lista sequencial
void exibirLista(LISTA *l);

// Remove todos os valores da lista, deixando-a vazia
void limpar(LISTA *l);

// Destruicao da lista sequencial
void destruir(LISTA *l);


#endif /* ListaSequencialOrdenada_h */
