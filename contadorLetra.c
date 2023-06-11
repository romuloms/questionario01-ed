#include <stdio.h>
#include <ctype.h>

int contaLetraA(const char *texto) {
  int contador = 0;

  for (int i = 0; texto[i] != '\0'; i++) {
    char c = tolower(texto[i]);

    if (c == 'a') {
      contador++;
    }
  }
  
  return contador;
}

int main() {
  char texto[1000];

  printf("digite o texto: ");
  fgets(texto, sizeof(texto), stdin);

  int numeroDeOcorrencias = contaLetraA(texto);
  printf("Numero de letras a na frase: %d\n", numeroDeOcorrencias);

  return 0;
}