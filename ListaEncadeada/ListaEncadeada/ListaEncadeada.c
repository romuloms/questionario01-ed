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


bool insercaoListaVazia(ITEM item, LISTA *l)
{
    l->cabeca = criarNo(item, NULL);
    l->cauda = l->cabeca;
    l->tamanho++;
    return true;
}


bool insercaoOrdenada(ITEM item, LISTA *l)
{
    // lista vazia
    if (l->tamanho == 0)
    {
        insercaoListaVazia(item, l);
        return true;
    }
    // insercao na cabeca
    if (l->cabeca->item > item)
    {
        NO *p = criarNo(item, l->cabeca);
        l->cabeca = p;
        l->tamanho++;
        return true;
    }
    // insercao na cauda
    if (l->cauda->item < item)
    {
        NO *p = criarNo(item, NULL);
        l->cauda->prox = p;
        l->cauda = p;
        l->tamanho++;
        return true;
    }
    // impede insercao de itens repetidos
    if ((l->cabeca->item == item) || (l->cauda->item == item))
        return false;
    else
    {
        NO *pAnterior = l->cabeca;
        NO *pAtual = l->cabeca->prox;
        // enquanto o item a ser inserido for maior que o item
        // do ponteiro atual...
        while (item > pAtual->item)
        {
            // avanca os ponteiros pAnterior e pAtual
            pAnterior = pAtual;
            pAtual = pAtual->prox;
        }
        // impede insercao de itens repetidos
        if (pAtual->item == item)
            return false;
        // cria o novo No tendo como proximo o pAtual
        NO *p = criarNo(item, pAtual);
        // o anterior do pAtual tera como proximo o novo No
        pAnterior->prox = p;
        l->tamanho++;
        return true;
    }
}


bool inserir(ITEM item, LISTA *l)
{
    if (l->cabeca == NULL)
    {
        insercaoListaVazia(item, l);
        return true;
    }
    // a nova cabeca tera como prox a antiga cabeca
    l->cabeca = criarNo(item, l->cabeca);
    l->tamanho++;
    return true;
}


bool inserirNoFinal(ITEM item, LISTA *l)
{
    // lista vazia
    if (l->cabeca == NULL)
    {
        insercaoListaVazia(item, l);
        return true;
    }
    // cria no sem ponteiro prox
    NO* pNovo = criarNo(item, NULL);
    // prox da antiga cauda sera a nova cauda
    l->cauda->prox = pNovo;
    // atualiza a cauda
    l->cauda = pNovo;
    l->tamanho++;
    return true;
}


void inverter(LISTA *l)
{
    NO* pAtual = l->cabeca;
    NO* pAnt = NULL;
    NO* pAux = NULL;
    l->cauda = l->cabeca;
    
    while (pAtual)
    {
        pAux = pAtual->prox;    // salva o ponteiro prox para poder usar depois
        pAtual->prox = pAnt;    // antigo prox sera novo ant
        pAnt = pAtual;  // avanca o ponteiro
        pAtual = pAux;  // avanca o ponteiro
    }
    
    if (pAnt)
        l->cabeca = pAnt;
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
    /*
     os for encadeados irao comparar todos os itens da lista B
     com o primeiro item da lista A, depois todos os itens da lista B
     com o segundo item da lista A e assim em diante.
    */
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
    // posicao invalida
    if (i < 0 || i >= tamanho(l))
        return false;
    
    else
    {
        NO* pAnterior = l->cabeca;
        // remocao na cabeca
        if (i == 0)
        {
            // o endereco do ponteiro elem vai ser o endereco do
            // item da cabeca para tornar possivel retornar o
            // item que foi removido
            *elem = l->cabeca->item;
            l->cabeca = l->cabeca->prox;
            l->tamanho--;
            free(pAnterior);
            return true;
        }
        else
        {
            NO* pAtual = l->cabeca->prox;
            
            for (int j = 1; j < i; j++)
            {
                pAnterior = pAtual;
                pAtual = pAtual->prox;
            }
            // mesma logica para a remocao na cabeca
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
    // alocando a devida memoria para a lista clonada
    LISTA* listaClonada = (LISTA *)malloc(sizeof(LISTA));
    // faz os sets iniciais de qualquer lista
    inicializar(listaClonada);
    
    NO* ponteiroAux = l->cabeca;
    // lista vazia
    if (l->cabeca == NULL)
        return listaClonada;
    // clona a cabeca
    listaClonada->cabeca = criarNo(ponteiroAux->item, ponteiroAux->prox);
    listaClonada->tamanho++;
    ponteiroAux = ponteiroAux->prox;
    
    if (ponteiroAux)
    {
        // enquanto o ponteiro atual tiver um prox...
        while (ponteiroAux->prox)
        {
            // clona item a item da lista original
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
