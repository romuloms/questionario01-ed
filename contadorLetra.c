#include <stdio.h>
#include <ctype.h>

int contaLetra(const char *texto, char letra) {
  int contador = 0;

  for (int i = 0; texto[i] != '\0'; i++) {
    char c = tolower(texto[i]);
    letra = tolower(letra);

    if (c == letra) {
      contador++;
    }
  }
  
  return contador;
}

int main() {
  char texto[1000];
  char letra;

  printf("digite o texto: ");
  fgets(texto, sizeof(texto), stdin);

  printf("digite a letra que quer contar: ");
  scanf("%c", &letra);

  int numeroDeOcorrencias = contaLetra(texto, letra);
  printf("Numero de letras %c na frase: %d\n", letra, numeroDeOcorrencias);

  return 0;
}