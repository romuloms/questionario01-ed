#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "FilaEncadHeader.h"

char compara(ITEM x, ITEM y) {
  return x > y ? 1 : (x < y ? -1 : 0);
}

bool igual(ITEM x, ITEM y) {
  return compara(x, y) == 0;
}

void inicializar(FILA *f) {
  f->inicio = NULL;
  f->fim = NULL;
  f->tamanho = 0;
}

NO* criarNo(ITEM item, NO *prox) {
  NO* ponteiroNovo = (NO*) malloc(sizeof(NO));
  ponteiroNovo->item = item;
  ponteiroNovo->prox = prox;
  return ponteiroNovo;
}

int tamanho(FILA *f) {
  return f->tamanho;
}

bool cheia(FILA *f) {
  return false;
}

bool vazia(FILA *f) {
  return f->inicio == NULL;
}

bool inserir(ITEM item, FILA *f) {
  NO* ponteiroNovo = criarNo(item, NULL);
  
  if (f->inicio == NULL)
    f->inicio = ponteiroNovo;
  else
    f->fim->prox = ponteiroNovo;
  
  f->fim = ponteiroNovo;
  f->tamanho++;

  return true;
}

bool frente(ITEM *item, FILA *f) {
  if (frente(item, f)) {
    NO* ponteiroFrente = f->inicio;
    f->inicio = ponteiroFrente->prox;

    if (f->inicio == NULL)
      f->fim = NULL;

    f->tamanho--;
    free(ponteiroFrente);

    return true;
  }
  else
    return false;
}

NO* noNaPosicao(int n, FILA *f) {
  if (n < 0 || n > tamanho(f))
    return NULL;

  NO* p = f->inicio;
  for (int i = 0; i < n; i++)
    p = p->prox;
  
  return p;
}

ITEM enesimo(int n, FILA *f) {
  NO * no = noNaPosicao(n, f);
  if (no)
    return no->item;
  else {
    printf("Posicao inexistente na fila (%d)\n", n);
    exit(EXIT_FAILURE);
  }
}

void exibirItem(ITEM i) {
  printf("%d", i);
}

void exibir(FILA *f) {
  printf("[");
  NO* p = f->inicio;
  while (p) {
    // p != NULL
    exibirItem(p->item);
    if (p->prox)
      printf(",");
    
    p = p->prox;
  }
  printf("]");
}

void limpar(FILA *f) {
  NO* atual = f->inicio;
  
  while (atual) {
    NO* prox = atual->prox;
    free(atual);
    atual = prox;
  }

  f->inicio = NULL;
  f->fim = NULL;
  f->tamanho = 0;
}

void destruir(FILA *f) {
  limpar(f);
}