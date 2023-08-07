//
//  PilhaArray.h
//  Pilhas
//
//  Created by Rômulo Santana on 07/08/23.
//

#ifndef PilhaArray_h
#define PilhaArray_h

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int ITEM;


typedef struct
{
    ITEM* itens;
    int tamanho;
    int capacidade;
} PILHAARR;

/*
   Compara o item x com o y, retornando:
     1 caso x > y
     0 caso x = y
    -1 caso x < y
*/
char compare(ITEM x, ITEM y);

// Retorna true se x = y e false caso contrario
bool igual(ITEM x, ITEM y);

// Inicializa a pilha deixando-a pronta para ser utilizada.
void criarPilhaArr(PILHAARR *p, int capacidade);

// Retornar o tamanho da pilha
int tamanho(PILHAARR *p);

// Nunca estara cheia pois o limite e a memoria disponivel
bool cheia(PILHAARR *p);

// Retorna true se a pilha esta vazia (Topo = NULL)
bool vazia(PILHAARR *p);

/*
  Objetivo: Empilha um ITEM no topo da pilha.
            Coloca na cabeca de uma lista encadeada.
*/
bool empilhar(ITEM item, PILHAARR *p);

/*
  Objetivo: Acessa o topo da Pilha e atribui ao parâmetro item, sem afetar
            o estado da Pilha. Retorna true quando algum item foi obtido.
*/
bool topo(ITEM *item, PILHAARR *p);

/*
  Objetivo: Retira o No do Topo da Pilha e atribui ao parametro item.
            Retorna true quando algum item foi retornado.
*/
bool desempilhar(ITEM *item, PILHAARR *p);


// Exibicao de um item da pilha
void exibirItem(ITEM i);

// Exibicao da pilha
void exibir(PILHAARR *p);

// Remove todos os valores da pilha, deixando-a vazia
void limpar(PILHAARR *p);

// Destruicao da pilha
void destruir(PILHAARR *p);

#endif /* PilhaArray_h */
