//
//  ListaSequencialEstatica.c
//  listaSequencialEstatica
//
//  Created by Rômulo Santana on 09/07/23.
//

#include "ListaSequencialEstatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int compare(ITEM x, ITEM y)
{
    return x > y ? 1 : (x < y ? -1 : 0);
}


void criarLista(LISTA* lista, int capacidade)
{
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->itens = malloc(capacidade * sizeof(ITEM));   // itens: vetor de inteiros 
}


int tamanho(LISTA *lista)
{
    return lista->tamanho;
}


bool cheia(LISTA *lista)
{
    return tamanho(lista) == lista->capacidade;
}


bool vazia(LISTA *lista)
{
    return tamanho(lista) == 0;
}


void aumentarLista(LISTA *lista)
{
    lista->itens = realloc(lista->itens, 2 * lista->capacidade * sizeof(ITEM));
    lista->capacidade = 2 * lista->capacidade * sizeof(ITEM);
}


void exibirItem(ITEM item)
{
    printf("%d", item);
}

void exibirLista(LISTA *lista)
{
    printf("[");
    for(int i = 0; i < tamanho(lista);)
    {
        exibirItem(lista->itens[i++]);
        if (i < tamanho(lista))
           printf(",");
    }
    printf("]");
}

bool inserirNaPosicao(LISTA *lista, int i, ITEM item)
{
    if ((tamanho(lista) >= lista->capacidade) || (i < 0) || (i > tamanho(lista)))
        return false;
    
    // insercao no meio da lista
    for (int j = tamanho(lista); j > i; j--)
        lista->itens[j] = lista->itens[j-1];
    
    lista->itens[i] = item;
    lista->tamanho++;
    
    return true;
}


bool inserirItem(LISTA* lista, ITEM item)
{
    if (lista == NULL)
    {
        printf("Erro: lista nao existe.\n");
        return false;
    }
    
    if (cheia(lista))
    {
        aumentarLista(lista);
    }
    
    int i = buscaBinaria(lista, item);
    
    if (i == tamanho(lista))
        return inserirNaPosicao(lista, i, item);
    
    else
    {
        if (compare(lista->itens[i], item) == 0)    // checa se ja existe um item igual na lista
            return false;
        else
            return inserirNaPosicao(lista, i, item);
    }
}


LISTA* clonarLista(LISTA* listaOriginal, LISTA* listaClonada)
{
    criarLista(listaClonada, listaOriginal->capacidade);
    
    for (int i = 0; i < listaOriginal->tamanho; i++)
        inserirItem(listaClonada, listaOriginal->itens[i]);
    
    return listaClonada;
}


int buscaBinaria(LISTA *lista, int item)
{
    int inicio = 0;
    int fim = tamanho(lista) - 1;
    int meio, chute;
    
    while (inicio <= fim)
    {
        meio = (int)floor((inicio+fim)/2);
        chute = lista->itens[meio];
        
        if (chute == item)
            return meio;
        if (chute > item)
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    
    return inicio;  // nao achou o item, retorna posicao que deveria entrar
}


void destruirLista(LISTA *lista)
{
    if (lista == NULL)
    {
        printf("Erro: lista nao existe.\n");
        return;
    }
    
    free(lista->itens);     // libera os itens da lista que sao ponteiros
    lista->tamanho = 0;
}

