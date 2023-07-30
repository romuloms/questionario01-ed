//
//  ListaSequencialEstatica.h
//  listaSequencialEstatica
//
//  Created by Rômulo Santana on 09/07/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef LISTA_SEQ_ESTATICA
#define LISTA_SEQ_ESTATICA


typedef int ITEM;

typedef struct {
    ITEM* itens;
    int tamanho;
    int capacidade;
} LISTA;


int compare(ITEM x, ITEM y);

void criarLista(LISTA* lista, int capacidade);

int tamanho(LISTA *lista);

bool cheia(LISTA *lista);

bool vazia(LISTA *lista);

void exibirItem(ITEM item);

void exibirLista(LISTA *lista);

bool inserirNaPosicao(LISTA *lista, int i, ITEM item);

bool inserirItem(LISTA* lista, int valor);

int buscaBinaria(LISTA *lista, int item);

bool removerNaPos(LISTA* lista, int indice);

void destruirLista(LISTA *lista);


#endif // LISTA_SEQ_ESTATICA

