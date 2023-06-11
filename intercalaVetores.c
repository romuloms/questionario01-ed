#include <stdio.h>

#define TAMANHO_VETOR 100

void scanVetor(int vetor[TAMANHO_VETOR], int elementos) {
  for (int i = 0; i < elementos; i++) {
    scanf("%d", &vetor[i]);
  }
}

void printIntercalado(int vetor1[TAMANHO_VETOR], int vetor2[TAMANHO_VETOR], int elementos) {
  printf("vetores intercalados: \n");
  for (int i = 0; i < elementos; i++) {
    printf("%d \n%d\n", vetor1[i], vetor2[i]);
  }
}

int main() {
  int elementos;
  int vetor1[TAMANHO_VETOR];
  int vetor2[TAMANHO_VETOR];

  printf("digite o numero de elementos: ");
  scanf("%d", &elementos);

  printf("digite os elementos do vetor 1:\n");
  scanVetor(vetor1, elementos);

  printf("digite os elementos do vetor 2:\n");
  scanVetor(vetor2, elementos);

  printIntercalado(vetor1, vetor2, elementos);

  return 0;
}