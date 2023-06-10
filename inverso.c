#include <stdio.h>

#define VALORES_MAX 100

void scanVetor(int vetor[VALORES_MAX], int valores) {
  printf("Digite os elementos do vetor:\n");
  for (int i = 0; i < valores; i++) {
    scanf("%d", &vetor[i]);

  }
}

void printResultados(int vetor[VALORES_MAX], int valores) {
  for (int i = valores - 1; i >= 0; i--) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int valores;
  int vetor[VALORES_MAX];

  printf("Digite o numero de valores: ");
  scanf("%d", &valores);

  scanVetor(vetor, valores);
  printResultados(vetor, valores);

  return 0;
}