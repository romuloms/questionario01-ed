//
//  main.c
//  estudo_C
//
//  Created by Rômulo Santana on 08/07/23.
//

#include <stdio.h>

void sqr(float *num) {
  *num = (*num)*(*num);
}

void main(void) {
  float nro;
  printf("Enter a number: ");
  scanf("%f", &nro);
  printf("\n\nThe number was: %f\n", nro);
  sqr(&nro);
  printf("The number\'s square is: %f\n", nro);
}
