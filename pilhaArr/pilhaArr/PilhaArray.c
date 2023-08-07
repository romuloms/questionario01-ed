//
//  PilhaArray.c
//  Pilhas
//
//  Created by Rômulo Santana on 07/08/23.
//

#include "PilhaArray.h"

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


void criarPilhaArr(PILHAARR *p, int capacidade)
{
    p->tamanho = 0;
    p->capacidade = capacidade;
    p->itens = malloc(capacidade * sizeof(ITEM));
}


int tamanho(PILHAARR *p)
{
    return p->tamanho;
}


bool cheia(PILHAARR *p)
{
    if (p->tamanho == p->capacidade)
        return true;
    return false;
}


bool vazia(PILHAARR *p)
{
    return p->tamanho == 0;
}


bool empilhar(ITEM item, PILHAARR *p)
{
    if (p == NULL)
        return false;
    if (cheia(p))
        return false;
    
    p->itens[p->tamanho] = item;
    p->tamanho++;
    return true;
}


bool topo(ITEM *item, PILHAARR *p)
{
   if (vazia(p))
      return false; // Nao achou

   *item = p->itens[p->tamanho - 1];
   return true;
}


bool desempilhar(ITEM *item, PILHAARR *p)
{
   if (vazia(p))
      return false; // Nao desempilhou

   ITEM pDesempilhado = p->itens[p->tamanho - 1];
   *item = pDesempilhado;

   // Muda o topo da lista para ser o NO abaixo do Topo atual
//   p->topo = pDesempilhado->prox;
   p->tamanho--;
   free(item);
   return true;
}


//ITEM enesimo(int n, PILHA *p) {
//    NO * no = noNaPosicao(n, p);
//    if (no)
//        return no->item;
//    else
//    {
//        printf("Posicao inexistente na fila (%d)\n", n);
//        exit(EXIT_FAILURE);
//    }
//}


void exibirItem(ITEM i)
{
    printf("%d", i);
}


void exibir(PILHAARR *pilha)
{
    printf("[");
//    ITEM p = pilha->itens[pilha->tamanho - 1];
//    while (p)  // p != NULL
//    {
//        exibirItem(p->item);
//        if (p->prox)
//           printf(",");
//        p = p->prox;
//    }
    for (int i = tamanho(pilha) - 1; i >= 0;)
    {
        exibirItem(pilha->itens[i--]);
        if (i >= 0)
            printf(",");
        
    }
    printf("]");
}


void limpar(PILHAARR *p)
{
    if (p == NULL)
        return;
    
    free(p->itens);
    p->tamanho = 0;
}


void destruir(PILHAARR *p)
{
    limpar(p);
}
