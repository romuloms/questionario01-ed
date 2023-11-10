#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int mdc(int num, int div)
{
  if (num == div)
  {
    return num;
  }
  else if (num < div)
  {
    return mdc(div, num);
  }
  else if (num > div)
  {
    return mdc(num-div, div);
  }
}

int main(void)
{
  int num, div;
  
  scanf("%d %d", &num, &div);

  int resultado = mdc(num, div);

  printf("MDC: %d", resultado);

  return 0;
}