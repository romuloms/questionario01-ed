#include <stdio.h>

#define VALORES_MAX 100

void scanVetor(int vetor[VALORES_MAX], int valores) {
  for (int i = 0; i < valores; i++) {
    scanf("%d", &vetor[i]);
  }
}

void printResultados(int vetor1[VALORES_MAX], int vetor2[VALORES_MAX], int valores) {
  int soma;

  printf("Soma dos vetores:\n");
  for (int i = 0; i < valores; i++) {
    soma = vetor1[i] + vetor2[i];
    printf("%d ", soma);
  }
  printf("\n");
}

int main() {
  int valores;
  int vetor1[VALORES_MAX];
  int vetor2[VALORES_MAX];

  printf("Digite o numero de valores: ");
  scanf("%d", &valores);

  printf("Digite os elementos do vetor 1:\n");
  scanVetor(vetor1, valores);

  printf("Digite os elementos do vetor 2:\n");
  scanVetor(vetor2, valores);
  printResultados(vetor1, vetor2, valores);

  return 0;
}
