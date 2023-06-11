#include <stdio.h>
#include <ctype.h>

int countLetterA(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char c = tolower(text[i]);  // Convertendo o caractere para minúsculo
        if (c == 'a')
            count++;
    }
    return count;
}

int main() {
    char text[1000];

    printf("Digite um texto: ");
    fgets(text, sizeof(text), stdin);

    int numOccurrences = countLetterA(text);
    printf("O número de ocorrências da letra 'a' é: %d\n", numOccurrences);

    return 0;
}
