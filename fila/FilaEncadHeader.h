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