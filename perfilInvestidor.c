#include <stdio.h>

/* ate 10%: conservador, 10%<=arrojados<30%, agressivo>=30% */
int main() {
  double fixaNac, fixaInt, variavelNac, variavelInt;

  scanf("%lf %lf %lf %lf", &fixaNac, &fixaInt, &variavelNac, &variavelInt);

  double total = fixaInt + fixaNac + variavelInt + variavelNac;
  double somaVariavel = variavelNac + variavelInt;
  double porcentagem = (somaVariavel / total) * 100;

  if (porcentagem < 10.00) {
    printf("Conservador (%.2lf%%)", porcentagem);

  } else if (porcentagem <= 10.00 && porcentagem < 30.00) {
    printf("Arrojado (%.2lf%%)", porcentagem);

  } else {
    printf("Agressivo (%.2lf%%)", porcentagem);
  }
  
  return 0;
}