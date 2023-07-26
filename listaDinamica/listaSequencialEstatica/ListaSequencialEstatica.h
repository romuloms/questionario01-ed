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


void criarLista(LISTA* lista, int capacidade);

void exibirLista(LISTA *lista);

bool inserirItem(LISTA* lista, int valor);

int buscaBinaria(LISTA *lista, int item);

bool removerNaPos(LISTA* lista, int indice);

void destruirLista(LISTA *lista);


#endif // LISTA_SEQ_ESTATICA

