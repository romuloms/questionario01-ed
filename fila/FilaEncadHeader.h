#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef FILA_ENC
#define FILA_ENC

typedef int ITEM;

typedef struct estrutura {
  ITEM item;
  struct estrutura *prox;
} NO;

typedef struct {
  NO* inicio;
  NO* fim;
  int tamanho;
} FILA;

char compara(ITEM x, ITEM y);

bool igual(ITEM x, ITEM y);

void inicializar(FILA *f);

int tamanho(FILA *f);

bool cheia(FILA *f);

bool vazia(FILA *f);

bool inserir(ITEM item, FILA *f);

bool frente(ITEM *item, FILA *f);

bool retirar(ITEM *item, FILA *f);

ITEM enesimo(int n, FILA *f);

void exibirItem(ITEM i);

void exibir(FILA *f);

void limpar(FILA *f);

void destruir(FILA *f);

#endif // FILA_ENC
