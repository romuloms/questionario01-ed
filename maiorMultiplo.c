#include <stdio.h>

int main() {
  int N, M;

  printf("Digite o valor de N: ");
  scanf("%d", &N);

  printf("Digite o valor de M: ");
  scanf("%d", &M);

  if (N < M) {
    printf("sem multiplos menores que %d\n", N);
  } else if ((N - M) < M) {
    printf("o múltiplo é o próprio %d\n", M);

  } else {
    int divisaoInteira = N / M;
    int resultado = divisaoInteira * M;

    printf("O maior multiplo e: %d\n", resultado);
  }

  return 0;
}