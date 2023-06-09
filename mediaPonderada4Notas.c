/*
Faça um programa que leia quatro notas (valores reais) de um aluno, calcule sua 
média ponderada utilizando, respectivamente, os pesos 1, 2, 3 e 4 para cada nota 
e imprima uma mensagem dizendo se o aluno foi aprovado com louvor, aprovado, 
reprovado ou deverá fazer prova final. Na sua solução utilize uma função chamada 
AnalisarSituacao que receba 4 parâmetros (as 4 notas) e retorne a situação do 
aluno, conforme os seguintes critérios:


aprovado com louvor (média >= 9)

aprovado (média >= 7);

reprovado (média < 3);

prova final ( 3 <= média < 7).
*/

#include <stdio.h>

void AnalisarSituacao(float nota1, float nota2, float nota3, float nota4) {
  scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);

  float somaNotas = nota1*1 + nota2*2 + nota3*3 + nota4*4;
  float media = somaNotas / 10;
  
  // printf("media: %.2f\n", media);

  if (media >= 9) {
    printf("aprovado com louvor\n");

  } else if (media >= 7 && media < 9) {
    printf("aprovado\n"); 

  } else if (media < 7 && media >= 3) {
    printf("prova final\n");

  } else {
    printf("reprovado\n");

  }
}

int main() {
  float nota1, nota2, nota3, nota4;
  AnalisarSituacao(nota1, nota2, nota3, nota4);

  return 0;
}