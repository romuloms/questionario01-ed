#include <stdio.h>

#define VALORES_MAX 100

void scanVetor(int vetor[VALORES_MAX], int valores) {
  printf("Digite os elementos do vetor:\n");
  for (int i = 0; i < valores; i++) {
    scanf("%d", &vetor[i]);

  }
}

void printResultados(int vetor[VALORES_MAX], int valores) {
  int menorValor = 0;  
  int posicao = 0;

  for (int i = 0; i < valores; i++) {
    if (vetor[i] < menorValor) {
      menorValor = vetor[i];
      posicao = i;
    }
  }

  printf("Menor valor: %d\n", menorValor);
  printf("Posicao: %d\n", posicao);
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