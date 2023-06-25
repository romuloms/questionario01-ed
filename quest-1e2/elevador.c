#include <stdio.h>

#define TAMANHO_VETOR 1000

void controlador(int sairam[TAMANHO_VETOR], int entraram[TAMANHO_VETOR], int leituras, int capacidade) {
  int ent = 0;
  int sai = 0;
  int total = 0;
  int contador = 0;

  for (int i = 0; i < leituras; i++) {
    scanf("%d %d", &sairam[i], &entraram[i]);

    ent += entraram[i];
    sai += sairam[i];
    total = ent - sai;

    if (total > capacidade) {
      contador++;
    }
  }

  if (contador > 0) {
    printf("a capacidade foi excedida %d vez(es)\n", contador);
  } else {
    printf("a capacidade nao foi excedida\n");
  }
}

int main() {
  int leituras, capacidade;
  int sairam[TAMANHO_VETOR];
  int entraram[TAMANHO_VETOR];

  printf("digite o número de leituras feitas pelo elevador e a capacidade respectivamente: ");
  scanf("%d %d", &leituras, &capacidade);

  controlador(sairam, entraram, leituras, capacidade);

  return 0;
}