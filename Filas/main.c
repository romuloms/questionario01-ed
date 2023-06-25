#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "FilaEncadHeader.h"

void imprimirStatus(FILA *f) {
  printf("Tamanho = %d\n", tamanho(f));

  exibir(f);

  printf("\n");
}

void testarInserir(FILA *f) {
  printf("=> Teste de Inserir\n");

  int quantidade;

  printf("Quantos itens deseja guardar na fila? ");
  scanf("%d", &quantidade);

  ITEM item;

  for (int i = 0; i < quantidade; i++) {
    printf("Digite o valor para a posicao [%d]: ", i);
    scanf("%d", &item);
    inserir(item, f);
  }

  imprimirStatus(f);
}

void testarEnesimo(FILA *f) {
  printf("=> Teste de Enesimo \n");

  printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
  int p;
  scanf("%d", &p);

  while (p != -1) {
    ITEM item = enesimo(p, f);
    printf("Achou na posicao[%d] o valor: %d\n", p, item);

    printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
    int p;
    scanf("%d", &p);  
  }
}

void testarRetirarDaFrente(FILA *f) {
  printf("=> Teste da Frente\n");

  if (vazia(f)) {
    printf("Fila vazia. Nada a retirar.\n");
    return;
  } else {
    printf("Fila tem %d valores\n", tamanho(f));
  }

  ITEM i;
  if (frente(&i, f))
    printf("Valor contido na frente da Fila: %d\n", i);
  else
    printf("Erro: deveria haver um valor na frente da fila.");

  while (!vazia(f)) {
    ITEM item;
    if (retirar(&item, f))
      printf("Retirado um valor da frente da fila com sucesso\n");
    else
      printf("Erro na retirada da frente da fila\n");

    printf("Valor retirado da frente da fila: %d\n", item);

    imprimirStatus(f);
  }
}

int main() {
  FILA f;

  inicializar(&f);
  testarInserir(&f);
  testarEnesimo(&f);
  testarRetirarDaFrente(&f);

  destruir(&f);
  imprimirStatus(&f);

  getchar();

  return 0;
}