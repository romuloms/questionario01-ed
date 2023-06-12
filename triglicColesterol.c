#include <stdio.h>

void printTriglic(int triglicerideos) {
  if (triglicerideos < 150) {
    printf("Triglicerideos %d mg/dl: DESEJAVEL\n", triglicerideos);

  } else if (triglicerideos >= 150 && triglicerideos <= 200) {
    printf("Triglicerideos %d mg/dl: LIMITROFE\n", triglicerideos);

  } else {
    printf("Triglicerideos %d mg/dl: ALTO\n", triglicerideos);

  }
}

void printColest(float colesterol) {
  if (colesterol < 150) {
    printf("Colesterol %.1f mg/dl: DESEJAVEL\n", colesterol);

  } else if (colesterol >= 150 && colesterol <= 170) {
    printf("Colesterol %.1f mg/dl: LIMITROFE\n", colesterol);

  } else {
    printf("Colesterol %.1f mg/dl: ALTO\n", colesterol);

  }
}

int main() {
  int triglicerideos;
  float colesterol;

  printf("Insira o valor dos Triglicerideos seguido pelo valor do Colesterol:\n");
  scanf("%d", &triglicerideos);
  scanf("%f", &colesterol);
  
  if (triglicerideos < 0 || colesterol < 0) {
    printf("Valor negativo (fora da faixa)\n");
    
    return 1;

  } else {
    printTriglic(triglicerideos);
    printColest(colesterol);
    
  }

  return 0;
}