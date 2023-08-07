//
//  main.c
//  Pilhas
//
//  Created by Rômulo Santana on 07/08/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "PilhaArray.h"


// Imprime na tela o status da pilha
void imprimirStatus(PILHAARR *p)
{
    printf("Tamanho = %d\n", tamanho(p));
    exibir(p);
    printf("\n");
}


// Testa empilhar valores na pilha
//void testarEmpilhar(PILHAARR *p)
//{
//    printf("=> Teste de Empilhar\n");
//    int qtd;
//    printf("Quantos itens deseja guardar na pilha? ");
//    scanf("%d", &qtd);
//
//    ITEM item;
//    for (int i = 0; i < qtd; i++)
//    {
//        printf("Digite o proximo valor a empilhar [%d/%d]: ", i+1, qtd);
//        scanf("%d", &item);
//        empilhar(item, p);
//    }
//
//    imprimirStatus(p);
//}


// Testa o desempilhamento de valores
//void testarDesempilhar(PILHAARR *p)
//{
//    printf("=> Teste do Topo\n");
//
//    if (vazia(p))
//    {
//        printf("Pilha vazia. Nada a desempilhar...\n");
//        return;
//    } else {
//        printf("Pilha tem %d valores\n", tamanho(p));
//    }
//
//    ITEM i;
//    if (topo(&i, p))
//       printf("Valor contido no topo da Pilha: %d\n", i);
//    else
//       printf("Erro: Deveria haver um valor no topo da Pilha.");
//
//    while (!vazia(p))
//    {
//        ITEM item;
//        if (desempilhar(&item, p))
//           printf("Retirado um valor do topo da pilha com sucesso\n");
//        else
//           printf("Erro na retirada do topo da pilha\n");
//
//        // Mostra o valor retirado da pilha
//        printf("Valor retirado do topo da pilha: %d\n", item);
//
//        imprimirStatus(p);
//    }
//}


void testarEmpArr(PILHAARR *p)
{
    printf("=> Teste de Empilhar\n");
    int qtd = 5;

    ITEM item;
    for (int i = 0; i < qtd; i++)
    {
        printf("Digite o proximo valor a empilhar [%d/%d]: ", i+1, qtd);
        scanf("%d", &item);
        empilhar(item, p);
    }

    imprimirStatus(p);
}
/////////////////////////////////////////////////////

int main(){
    PILHAARR p;
    
    criarPilhaArr(&p, 5);
    testarEmpArr(&p);
//    inicializar(&p);
//
//    testarEmpilhar(&p);
//    testarEnesimo(&p);
//    testarDesempilhar(&p);
//
    destruir(&p);
    imprimirStatus(&p);
        
    getchar();
    return 0;
}
