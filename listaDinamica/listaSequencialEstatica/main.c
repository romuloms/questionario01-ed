//
//  main.c
//  listaSequencialEstatica
//
//  Created by Rômulo Santana on 09/07/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ListaSequencialEstatica.h"

// Imprime na tela o status da lista
void imprimirStatus(LISTA *lista)
{
    printf("Tamanho = %d\n", lista->tamanho);
    exibirLista(lista);
    printf("\n");
}


// Testa a insercao de valores na lista
void testarInserir(LISTA *l)
{
    printf("=> Teste de Inserir\n");
    int qtd;
    printf("Quantos itens deseja guardar na lista? ");
    scanf("%d", &qtd);

    int item;
    for (int i = 0; i < qtd; i++)
    {
        printf("Digite o valor: ");
        scanf("%d", &item);
        inserirItem(l, item);
    }

    imprimirStatus(l);
}

//// Testa a busca de valores na lista
void testarBuscar(LISTA *l)
{
   // Testa a busca por um valor existente
    printf("=> Teste de Busca\n");
    printf("Digite o valor que deseja buscar: ");
    ITEM item;
    scanf("%d", &item);
    int pos = buscaBinaria(l, item);
    if (l->itens[pos] == item)
        printf("Achou na posicao: %d\n", pos);
    else
        printf("Nao achou o item na lista\n");

}

/////////////////////////////////////////////////////

int main(){
    LISTA l;
        
    criarLista(&l, 5);
    testarInserir(&l);
    testarBuscar(&l);
    testarInserir(&l);
    destruirLista(&l);
    imprimirStatus(&l);
        
    getchar();
    return 0;
}
