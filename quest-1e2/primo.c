#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, number;
  int divider = 0;

  do {
    system("clear");
    printf("Type in a positive integer: ");
    scanf("%d", &number);
  } while (number <= 0);

  for (i = 1; i <= number; i++) 
    if (number%i == 0)
      divider++;

  if (divider == 2)
    printf("%d is a prime number!\n", number);
  else
    printf("%d is not a prime number.\n", number);

  return 0;
}