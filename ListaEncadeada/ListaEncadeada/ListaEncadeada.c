//
//  ListaEncadeada.c
//  ListaEncadeada
//
//  Created by Rômulo Santana on 05/08/23.
//

#include "ListaEncadeada.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char compare(ITEM x, ITEM y)
{
    return x > y ? 1 : (x < y ? -1 : 0);
}


bool igual(ITEM x, ITEM y)
{
    return compare(x,y) == 0;
}


void inicializar(LISTA *l)
{
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tamanho = 0;
}


NO* criarNo(ITEM item, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    if (pNovo == NULL)
    {
        printf("Nao foi possivel alocar memoria para pNovo\n");
        exit(EXIT_FAILURE);
    }
    pNovo->item = item;
    pNovo->prox = prox;
    return pNovo;
}


int tamanho(LISTA *l)
{
    return l->tamanho;
}


bool vazia(LISTA *l)
{
    return l->cabeca == NULL;
}


bool insercaoOrdenada(ITEM item, LISTA *l)
{
    if (l->cabeca == NULL)
    {
        insercaoListaVazia(item, l);
        return true;
    }
    NO* pAnterior = l->cabeca;
    NO* pAtual = pAnterior->prox;
    // insercao no inicio da lista
    if (compare(item, l->cabeca->item) == -1)
    {
        inserir(item, l);
        return true;
    }
    // insercao no final da lista
    if (compare(item, l->cauda->item) == 1)
    {
        inserirNoFinal(item, l);
        return true;
    }
    // insercao no meio da lista
    else
    {
        while (pAtual->item < item)
        {
            pAnterior = pAtual;
            pAtual = pAtual->prox;
        }
        NO* pNovo = criarNo(item, pAtual);
        pAnterior->prox = pNovo;
        return true;
    }
}

bool insercaoListaVazia(ITEM item, LISTA *l)
{
    l->cabeca = criarNo(item, l->cabeca);
    l->cauda = l->cabeca;
    l->tamanho++;
    return true;
}

bool inserir(ITEM item, LISTA *l)
{
    if (l->cabeca == NULL)
    {
        insercaoListaVazia(item, l);
        return true;
    }
    l->cabeca = criarNo(item, l->cabeca);
    l->tamanho++;
    return true;
}


bool inserirNoFinal(ITEM item, LISTA *l)
{
    if (l->cabeca == NULL)
    {
        insercaoListaVazia(item, l);
        return true;
    }
    NO* pNovo = criarNo(item, NULL);
    l->cauda->prox = pNovo;
    l->cauda = pNovo;
    l->tamanho++;
    return true;
}


/*
    Objetivo: Retorna o endereco do No contido na posicao informada.
              Caso a posicao seja invalida (negativa ou maior ou igual
              ao tamanho da lista, retorna NULL.
*/
NO* noNaPosicao(int n, LISTA *l)
{
    if (n < 0 || n >= tamanho(l))
        return NULL;
    
    NO* p = l->cabeca;
    for (int i = 0; i < n; i++)
        p = p->prox;
    return p;  // existe um n-esimo e p aponta para ele
}


// calcula a intersecao entre duas listas
void intersecao(LISTA *listaA, LISTA *listaB, LISTA *listaI)
{
    NO* cabecaA = listaA->cabeca;
    NO* cabecaB = listaB->cabeca;
    
    for (int i = 0; i < listaA->tamanho; i++)
    {
        cabecaB = listaB->cabeca;
        for (int j = 0; j < listaB->tamanho; j++)
        {
            if (cabecaA->item == cabecaB->item)
                inserirNoFinal(cabecaA->item, listaI);
            cabecaB = cabecaB->prox;
        }
        cabecaA = cabecaA->prox;
    }
}


int buscar(ITEM item, LISTA *l)
{
    NO* p = l->cabeca;
    int pos = 0;
    while (p)   // p != NULL
    {
        if (igual(item, p->item))
            return pos;
        p = p->prox;
        pos++;
    }
    return -1; // Nao achou
}


ITEM enesimo(int n, LISTA *l) {
    NO * no = noNaPosicao(n, l);
    if (no)
        return no->item;
    else
    {
        printf("Posicao inexistente na lista (%d)\n", n);
        exit(EXIT_FAILURE);
    }
}


bool alterar(ITEM item, int pos, LISTA *l)
{
    NO * no = noNaPosicao(pos, l);
    if (no)
    {
        no->item = item;  // existe um n-esimo e p aponta para ele
        return true;
    }
    else
        return false;
}


bool inserirNaPos(ITEM item, int i, LISTA *l)
{
    if (i < 0 || i > tamanho(l))
    {
        printf("Posicao de insercao invalida (%d)\n", i);
        exit(EXIT_FAILURE);
    }
    
    if (i == 0) // insercao na cabeca da lista
    {
        l->cabeca = criarNo(item, l->cabeca);
    }
    else // insercao no meio ou final
    {
        NO* pAnterior = noNaPosicao(i-1, l);
        pAnterior->prox = criarNo(item, pAnterior->prox);
    }
    l->tamanho++;
    return true;
}


bool removerNaPos(ITEM *elem, int i, LISTA *l)
{
    if (i < 0 || i >= tamanho(l))
        return false;
    
    else
    {
        NO* pAnterior = l->cabeca;
        
        if (i == 0)
        {
            *elem = l->cabeca->item;
            l->cabeca = l->cabeca->prox;
            l->tamanho--;
            free(pAnterior);
            return true;
        }
        else
        {
            NO* pAtual = pAnterior->prox;
            
            for (int j = 1; j < i; j++)
            {
                pAnterior = pAtual;
                pAtual = pAtual->prox;
            }
            *elem = pAtual->item;
            pAnterior->prox = pAtual->prox;
            l->tamanho--;
            free(pAtual);
            return true;
        }
    }
}


bool remover(ITEM item, LISTA *l)
{
   if (vazia(l))
      return false;

   NO* pAnterior = l->cabeca;

   if (igual(item, l->cabeca->item))
   {
       // Remove o item da cabeca da lista e a cabeca passa a ser
       // item seguinte ao removido
       l->cabeca = l->cabeca->prox;
       l->tamanho--;
       free(pAnterior);
       return true;
   }
   else
   {
      // Percorre a lista ate encontrar o item procurado.
      // Remove o item e corrige o apontador prox do NO anterior para
      // apontar para o proximo NO do item sendo removido
       while ((pAnterior->prox))  // prox != NULL
       {
         NO* pAtual = pAnterior->prox;

         if (igual(item, pAtual->item))
         {
            l->cauda = pAnterior;
            pAnterior->prox = pAtual->prox;
            free(pAtual);
            l->tamanho--;
            return true;
         }

         pAnterior = pAtual;
      }
    }
    return false; // Nao removeu
}


void exibirItem(ITEM i)
{
    printf("%d", i);
}


LISTA* clonar(LISTA *l)
{
    LISTA* listaClonada = (LISTA *)malloc(sizeof(LISTA));
    inicializar(listaClonada);
    
    NO* ponteiroAux = l->cabeca;
    
    if (l->cabeca == NULL)
        return listaClonada;
    
    listaClonada->cabeca = criarNo(ponteiroAux->item, ponteiroAux->prox);
    listaClonada->tamanho++;
    ponteiroAux = ponteiroAux->prox;
    
    if (ponteiroAux)
    {
        while (ponteiroAux->prox)
        {
            ponteiroAux = criarNo(ponteiroAux->item, ponteiroAux->prox);
            listaClonada->tamanho++;
            ponteiroAux = ponteiroAux->prox;
        }
        listaClonada->tamanho++;
    }
    return listaClonada;
}


void exibirLista(LISTA *l)
{
    printf("[");
    NO* p = l->cabeca;
    while (p)  // p != NULL
    {
        exibirItem(p->item);
        if (p->prox)
           printf(",");
        p = p->prox;
    }
    printf("]");
}

void limpar(LISTA *l)
{
    NO* atual = l->cabeca;
    while (atual) {
        NO* prox = atual->prox; // guarda proxima posicao
        free(atual);            // libera memoria apontada por atual
        atual = prox;
    }
    l->cabeca = NULL; // ajusta inicio da lista (vazia)
    l->tamanho = 0;
}

void destruir(LISTA *l)
{
    limpar(l);
}
